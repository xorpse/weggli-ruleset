use std::fmt::Debug;
use std::path::Path;
use std::sync::Arc;

use thiserror::Error;
use tree_sitter::Parser;
use weggli::result::QueryResult;

use crate::rule::{Checker, Rule, RuleError, RuleSet};

pub struct RuleMatcher {
    rules: RuleSet,
    c_parser: Parser,
    cxx_parser: Parser,
}

pub struct RuleMatch {
    rule: Arc<Rule>,
    rule_id: usize,
    checker_id: usize,
    source: Arc<str>,
    result: QueryResult,
}

impl RuleMatch {
    pub fn rule(&self) -> &Rule {
        &self.rule
    }

    pub fn rule_id(&self) -> usize {
        self.rule_id
    }

    pub fn checker_id(&self) -> usize {
        self.checker_id
    }

    pub fn checker(&self) -> &Checker {
        &self.rule().checks()[self.checker_id]
    }

    pub fn source(&self) -> Arc<str> {
        self.source.clone()
    }

    pub fn source_ref(&self) -> &str {
        &self.source
    }

    pub fn result(&self) -> &QueryResult {
        &self.result
    }

    pub fn into_result(self) -> QueryResult {
        self.result
    }

    pub fn display(&self, before: usize, after: usize, line_numbers: bool) -> String {
        self.result
            .display(&self.source, before, after, line_numbers)
    }
}

impl Debug for RuleMatch {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        let mut m = f.debug_struct("RuleMatch");

        m.field("rule", &self.rule.id() as _);
        m.field("checker", &self.checker().name() as _);

        if let Some(ref description) = self.rule().description() {
            m.field("description", description as _);
        }

        m.field("tags", self.rule().tags() as _);
        m.field("severity", &self.rule().severity() as _);

        m.field("match", &self.result as _);

        m.finish_non_exhaustive()
    }
}

#[derive(Debug, Error)]
pub enum RuleMatcherError {
    #[error("cannot construct parser")]
    Parser(weggli::WeggliError),
    #[error(transparent)]
    Rules(#[from] RuleError),
}

impl RuleMatcher {
    pub fn new(rules: RuleSet) -> Result<Self, RuleMatcherError> {
        Ok(Self {
            rules,
            c_parser: weggli::get_parser(false).map_err(RuleMatcherError::Parser)?,
            cxx_parser: weggli::get_parser(true).map_err(RuleMatcherError::Parser)?,
        })
    }

    pub fn from_file(path: impl AsRef<Path>) -> Result<Self, RuleMatcherError> {
        Self::new(RuleSet::from_file(path)?)
    }

    pub fn from_str(rule: impl AsRef<str>) -> Result<Self, RuleMatcherError> {
        Self::new(RuleSet::from_str(rule)?)
    }

    pub fn from_directory(root: impl AsRef<Path>) -> Result<Self, RuleMatcherError> {
        Self::from_directory_with(root, true)
    }

    pub fn from_directory_with(
        root: impl AsRef<Path>,
        ignore_errors: bool,
    ) -> Result<Self, RuleMatcherError> {
        Self::new(RuleSet::from_directory(root, ignore_errors)?)
    }

    pub fn rules(&self) -> &RuleSet {
        &self.rules
    }

    pub fn matches(&mut self, source: impl AsRef<str>) -> Result<Vec<RuleMatch>, RuleMatcherError> {
        self.matches_with(source, false)
    }

    pub fn matches_with(
        &mut self,
        source: impl AsRef<str>,
        is_cxx: bool,
    ) -> Result<Vec<RuleMatch>, RuleMatcherError> {
        let source = source.as_ref();

        let checkers = self.rules.viable_checkers(source);

        if checkers.is_empty() {
            return Ok(Vec::with_capacity(0));
        }

        let tree = if is_cxx {
            self.cxx_parser.parse(source.as_bytes(), None)
        } else {
            self.c_parser.parse(source.as_bytes(), None)
        };

        // parse failed...
        let Some(tree) = tree else {
            return Ok(Vec::with_capacity(0));
        };

        let source = Arc::<str>::from(source);

        let results = checkers
            .into_iter()
            .flat_map(|(rule_id, rule, checker_id, checker)| {
                let source = source.clone();
                checker
                    .check_match(&tree, &source)
                    .into_iter()
                    .map(move |result| RuleMatch {
                        rule: rule.clone(),
                        rule_id,
                        checker_id,
                        source: source.clone(),
                        result,
                    })
            })
            .collect();

        Ok(results)
    }
}

#[cfg(test)]
mod test {
    use super::RuleMatcher;
    use std::fs;

    #[test]
    fn test_strcpy() -> Result<(), Box<dyn std::error::Error>> {
        let decompiler_output = r#"
char *__fastcall sub_XYZ(char *s, size_t a2)
{
  char *v2; // rbx
  char *v3; // rax
  const char *v4; // r15
  char *v5; // rax
  const char *v6; // r15

  v2 = s;
  v3 = j__secure_getenv("ZZZ");
  if ( !v3 || (v4 = v3, !*v3) )
  {
    v5 = j__secure_getenv("HOME");
    if ( v5 )
    {
      v6 = v5;
      if ( *v5 )
      {
        if ( strlen(v5) + 6 < a2 )
        {
          strcpy(s, v6);
          *(_WORD *)&s[strlen(s)] = 47;
          strcat(s, ".rnd");
          return v2;
        }
      }
    }
    return 0LL;
  }
  if ( strlen(v3) + 1 >= a2 )
    return 0LL;
  strcpy(s, v4);
  return v2;
}
"#;

        let rule = r#"
id: call-to-unbounded-copy-functions
description: call to unbounded copy functions
severity: medium
tags:
- CWE-120
- CWE-242
- CWE-676
check-patterns:
- name: gets
  regex: func=^gets$
  pattern: |
    { $func(); }
- name: st(r|p)(cpy|cat)
  regex: func=st(r|p)(cpy|cat)$
  pattern: |
    { $func(); }
- name: wc(r|p)(cpy|cat)
  regex: func=wc(r|p)(cpy|cat)$
  pattern: |
    { $func(); }
- name: sprintf
  regex: func=sprintf$
  pattern: |
    { $func(); }
- name: scanf
  regex: func=scanf$
  pattern: |
    { $func(); }
"#;

        let mut matcher = RuleMatcher::from_str(rule)?;

        let matches = matcher.matches_with(decompiler_output, false)?;

        println!("{matches:#?}");

        for m in matches {
            println!("\n\n{}", m.display(5, 5, true));
        }

        Ok(())
    }

    #[test]
    fn test_decomp_ls() -> Result<(), Box<dyn std::error::Error>> {
        let rule1 = r#"
id: call-to-unbounded-copy-functions
check pattern:
- name: st(r|p)(cpy|cat)
  regex: func=st(r|p)(cpy|cat)$
  pattern: |
    { $func(); }
"#;
        let mut matcher = RuleMatcher::from_str(rule1)?;
        let input = fs::read_to_string("tests/ls-main.c")?;

        let matches = matcher.matches_with(&input, false)?;

        assert_eq!(matches.len(), 1);

        Ok(())
    }

    #[test]
    fn test_decomp_objdump() -> Result<(), Box<dyn std::error::Error>> {
        let rule1 = r#"
id: simple-check
check pattern:
- name: check-var
  pattern: |
    { unsigned char $var; }
"#;
        let input = fs::read_to_string("tests/objdump-disas.c")?;

        let mut matcher = RuleMatcher::from_str(rule1)?;
        let matches = matcher.matches_with(&input, false)?;

        assert_eq!(matches.len(), 2);

        for m in matches {
            println!("\n\n{}", m.display(5, 5, true));
        }

        Ok(())
    }
}
