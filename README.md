

# weggli-ruleset

This is a utility crate to help manage weggli patterns. To do so, it provides a
yaml-based rule format that allows different (related) patterns to be grouped
along with metadata useful for categorising and triaging matches. For example,
we can encode the patterns from
[here](https://github.com/0xdea/weggli-patterns?tab=readme-ov-file#call-to-unbounded-copy-functions-cwe-120-cwe-242-cwe-676),
as follows:

```yaml
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
```

## Usage

```rust
use std::fs;
use weggli_ruleset::matcher::RuleMatcher;

let mut matcher = RuleMatcher::from_directory("rules")?;
let source = fs::read_to_string("tests/test.c")?;

let matches = matcher.matches(source)?;
```
