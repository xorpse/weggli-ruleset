void disassemble_section(bits64_t *param1, char **param2, funcptr_t **param3) {
   funcptr_t var1;
   uint32_t var2;
   funcptr_t *var3;
   char **var4;
   int64_t *var5;
   int64_t var6;
   unsigned char var7;
   unsigned char var8;
   int32_t var9;
   bits32_t var10;
   uint32_t var11;
   uint32_t var12;
   uint32_t var13;
   uint32_t var14;
   bits64_t var15;
   char *var16;
   bits64_t var17;
   uint64_t var18;
   uint64_t var19;
   unsigned char *var20;
   uint64_t var21;
   int64_t var22;
   unsigned char *var23;
   uint64_t var24;
   char *ptr;
   bits64_t *var25;
   bits64_t *var26;
   funcptr_t *var27;
   bits64_t *var28;
   funcptr_t **var29;
   void *var30;
   uint8_t var31;
   funcptr_t *var32;
   int64_t *extraoutRDX;
   bits64_t *var33;
   bits64_t *var34;
   size_t var35;
   int64_t *var36;
   uint64_t var37;
   int64_t **var38;
   int64_t *var39;
   funcptr_t *var40;
   int64_t var41;
   int32_t var42;
   int64_t var43;
   bits64_t *var44;
   uint32_t var45;
   uint64_t unaffR12;
   funcptr_t *var46;
   uint64_t var47;
   funcptr_t *var48;
   funcptr_t *var49;
   int64_t inFS_OFFSET;
   bool var50;
   funcptr_t *stack_388;
   funcptr_t *stack_380;
   bits64_t *stack_378;
   funcptr_t *stack_350;
   int64_t **stack_348;
   uint32_t stack_31c;
   int64_t **stack_318;
   char *stack_310;
   int64_t *stack_308;
   bits64_t *stack_300;
   uint8_t stack_2ed;
   int32_t stack_2ec;
   unsigned char *stack_2e0;
   funcptr_t *stack_2d0;
   uint8_t stack_2c5;
   uint64_t stack_2b8;
   uint32_t stack_29c;
   uint64_t stack_298;
   uint64_t stack_290;
   int32_t stack_288;
   int64_t **stack_280;
   uint32_t stack_274;
   uint32_t stack_270;
   uint32_t stack_26c;
   funcptr_t *stack_268;
   int64_t stack_260;
   unsigned char *stack_258;
   unsigned char *stack_250;
   void *stack_248;
   bits64_t stack_240;
   size_t stack_238;
   void *stack_228;
   bits64_t stack_220;
   bits64_t stack_218;
   funcptr_t *stack_208;
   void **stack_200;
   bits64_t stack_1f8;
   bits8_t stack_108 [88];
   int64_t stack_b0;
   unsigned char stack_78 [56];
   int64_t stack_40;
   
   var24 = *(param3 + 0xc4);
   stack_40 = *(inFS_OFFSET + 0x28);
   stack_268 = NULL;
   stack_260 = 0;
   if ((((ram0x002681a8 != 0) || (ram0x00268138 != 0)) || ((*(param2 + 5) & 0x110) == 0x110)) &&
      ((var7 = process_section_p.isra.20(param2), var7 != '\0' && (var32 = param2[8], var32 != NULL)
       ))) {
     stack_388 = NULL;
     if ((ram0x00266018 != 0xffffffffffffffff) &&
        (stack_388 = ram0x00266018 + -param2[6], ram0x00266018 < param2[6])) {
       stack_388 = NULL;
     }
     if (ram0x00266010 == 0xffffffffffffffff) {
       stack_2d0 = var32 / var24;
     } else {
       if (ram0x00266010 < param2[6]) goto label_r0x00010f20;
       stack_2d0 = ram0x00266010 + -param2[6];
       if (var32 / var24 <= ram0x00266010 + -param2[6]) {
         stack_2d0 = var32 / var24;
       }
     }
     if (stack_388 < stack_2d0) {
       var3 = param3[2];
       stack_348 = param3[0xc];
       if ((stack_348 == NULL) || (unaffR12 = ram0x002681f0, ram0x002681f0 == 0)) {
         if (((*(param2 + 5) & 4) != 0) && ((ram0x002681f4 != 0 || (*(param3 + 0x1a) != '\0')))) {
           var35 = bfd_get_reloc_upper_bound(param1, param2, var32 % var24);
           if (var35 < 0) {
label_r0x000136c5:
             bfd_fatal(*param1);
             goto label_r0x000136d5;
           }
           if (var35 != 0) {
             stack_280 = xmalloc(var35);
             var27 = bfd_canonicalize_reloc(param1, param2, stack_280, ram0x00268110);
             if (var27 < 0) goto label_r0x000136c5;
             qsort(stack_280, var27, 8, compare_relocs);
             stack_310 = NULL;
             stack_348 = stack_280;
             goto label_r0x00010b3e;
           }
         }
         stack_348 = NULL;
         stack_310 = NULL;
         stack_280 = NULL;
         stack_318 = NULL;
       } else {
         var27 = param3[0xd];
         stack_280 = NULL;
         stack_310 = param2[6];
label_r0x00010b3e:
         if (var27 == NULL) {
           stack_318 = stack_348;
         } else {
           stack_318 = stack_348 + var27;
         }
       }
       stack_2c5 = bfd_malloc_and_get_section(param1, param2, &stack_268);
       var22 = ram0x002680f8;
       if (stack_2c5 == 0) {
         var10 = bfd_get_error();
         var15 = bfd_errmsg(var10);
         var16 = *param2;
         var17 = dcgettext(0, "Reading section %s failed because: %s", 5);
         non_fatal(var17, var16, var15);
       } else {
         param3[0x14] = stack_268;
         ram0x002680a0 = param2;
         param3[0x15] = param2[6];
         param3[0x16] = var32;
         param3[6] = param2;
         if (1 < var22) {
           qsort(ram0x00268100, var22, 8, compare_symbols);
         }
         if ((stack_348 < stack_318) &&
            (var32 = stack_388 + stack_310, (*stack_348)[1] <= var32 && var32 != (*stack_348)[1])) {
           do {
             stack_348 = stack_348 + 1;
             if (stack_318 <= stack_348) break;
           } while ((*stack_348)[1] < var32);
         }
         var15 = sanitize_string(*param2);
         var16 = dcgettext(0, "\nDisassembly of section %s:\n", 5);
         __printf_chk(1, var16, var15);
         var16 = param2[6];
         var3[8] = 0x1;
         unaffR12 = find_symbol_for_address(stack_388 + var16, param3, &stack_260);
         var3[8] = 0x0;
         stack_290 = 0xffffffffffffffff;
         stack_298 = 0;
         if (((*(param1[1] + 8) == 5) && (var22 = *(param1[1] + 0x378), var22 != 0)) &&
            ((*(var22 + 0x3f1) & 1) != 0)) {
           stack_298 = 1L << (*(*(var22 + 0x340) + 10) - 1U & 0x3f);
           stack_290 = stack_298 * 2 - 1;
         }
         stack_288 = 0;
         stack_378._0_1_ = *(var3 + 0x20) == 0;
         stack_2e0 = stack_78;
         do {
           var2 = ram0x002681d8;
           stack_380 = (stack_388 + param2[6] & stack_290 ^ stack_298) - stack_298;
           if (unaffR12 == 0) {
             param3[7] = NULL;
             *(param3 + 8) = 0;
             *(param3 + 10) = 0xffffffff;
             stack_2ed = stack_2c5;
             if (var2 == 0) {
               if (stack_378 == 0) {
                 if (stack_2d0 <= stack_388) break;
               } else {
                 (*param3)(param3[1], "\n");
                 objdump_print_addr_with_sym(param1, param2, 0, stack_380, param3, 0);
                 (*param3)(param3[1], ":\n");
                 if (stack_2d0 <= stack_388) goto label_r0x0001261d;
               }
label_r0x000110c3:
               stack_2b8 = 0;
               stack_350 = stack_2d0;
               goto joined_r0x000110f0;
             }
             if (stack_388 < stack_2d0) goto label_r0x000110c3;
             if (stack_378 == 0) break;
label_r0x0001261d:
             stack_350 = stack_2d0;
             stack_2b8 = 0;
label_r0x00011112:
             var49 = stack_268;
             var32 = *(var3 + 0x10);
             stack_1f8 = 0x78;
             var2 = *(param3 + 0xc4);
             var14 = *(param3 + 0x19);
             var13 = *(param3 + 0xcc);
             var5 = param3[2];
             var27 = param3[6];
             stack_208 = xmalloc(0x78);
             stack_200 = NULL;
             stack_31c = ram0x00268198;
             if (ram0x00268198 == 0) {
               stack_31c = (-(stack_2ed == 0) & 0xc) + 4;
             }
             stack_29c = 0;
             if (((ram0x002681dc | ram0x002681d8) == 0) &&
                (bfd_sprintf_vma(*var5, stack_2e0, *(var27 + 0x40) / var2 + *(var27 + 0x30)),
                stack_78[0] == '0')) {
               var12 = 0;
               var20 = stack_2e0;
               do {
                 var11 = var12;
                 var20 = var20 + 1;
                 var12 = var11 + 1;
               } while (*var20 == '0');
               if ((*var20 != '\0') || (stack_29c = 0, *(var27 + 0x30) == 0)) {
                 stack_29c = var11 & 0xfffffffc;
               }
             }
             stack_300 = ram0x002680b0;
             *(param3 + 0xd1) = 0;
             if (stack_300 == NULL) {
               stack_308 = NULL;
               stack_2ec = -1;
             } else {
               stack_2ec = -1;
               do {
                 var28 = stack_300 + 6;
                 stack_300 = *stack_300;
                 if (stack_2ec < *var28) {
                   stack_2ec = *var28;
                 }
               } while (stack_300 != NULL);
               var35 = stack_2ec * 3 + 4;
               stack_308 = xmalloc(var35);
               *(stack_308 + (var35 - 1)) = 0;
               stack_300 = xmalloc(var35);
               *(stack_300 + (var35 - 1)) = 0;
             }
             if (stack_388 < stack_350) {
               var24 = var2;
               var18 = var24 * stack_350;
               var48 = stack_388;
label_r0x00011270:
               do {
                 stack_388 = var48;
                 var9 = ram0x002681a4;
                 var5[3] = 0;
                 if (var9 == 0) {
                   var19 = var24 * stack_388;
                   if ((var19 < var18) && (var49[var19] == 0x0)) {
                     var37 = 0;
                     do {
                       var37 += 1;
                       stack_380 = var18 - var19;
                       if (var37 == var18 - var19) break;
                       stack_380 = var37;
                     } while ((var49 + var19)[var37] == 0x0);
                   } else {
                     stack_380 = NULL;
                   }
                   if ((*(param3 + 0xd1) != '\0') && (*(param3 + 0xd2) != '\0'))
                   goto label_r0x0001128b;
                   if (stack_380 < var14) {
                     if ((var18 != var19 + stack_380) || (var37 = stack_380, var13 <= stack_380))
                     goto label_r0x0001128b;
                   } else {
                     var37 = stack_380 & 0xfffffffffffffffc;
                     if (var18 == var19 + stack_380) {
                       var37 = stack_380;
                     }
                   }
                   stack_380 = var37;
                   if (ram0x00268178 == '\0') {
label_r0x0001215e:
                     puts("\t...");
                     goto label_r0x0001216a;
                   }
                   var19 = stack_380 / var24;
                   if (stack_350 <= stack_388 + var19) goto label_r0x0001215e;
                   var22 = *(var27 + 0x98);
                   var16 = dcgettext(0, 
                                     "\t... (skipping %lu zeroes, resuming at file offset: 0x%lx)\n"
                                     , 5);
                   __printf_chk(1, var16, var19, stack_388 + var19 + var22);
                   var48 = stack_388 + var19;
                   if (stack_318 <= stack_348) goto label_r0x00011270;
label_r0x00012189:
                   var38 = *stack_348;
                   var39 = stack_310 + stack_388 + var19;
                   var31 = 0;
                   if (var38[1] < var39) {
label_r0x00011b4a:
                     do {
                       if ((ram0x002681f4 | ram0x002681f0) != 0) {
                         if (ram0x0026819c == 0) {
                           __printf_chk(1, "\t\t\t");
                           if (ram0x002681dc != 0) goto label_r0x00011a5f;
label_r0x00011b87:
                           objdump_print_value((*(var27 + 0x30) - stack_310) + var38[1], param3, 1);
                           __printf_chk(1, ": ");
                           var36 = var38[3];
                           if (var36 != NULL) goto label_r0x00011a6c;
label_r0x00011bc1:
                           __printf_chk(1, "*unknown*\t");
                           var36 = *var38;
                           if (var36 == NULL) goto label_r0x00011be0;
label_r0x00011a98:
                           var22 = *var36;
                           if (var22 == 0) goto label_r0x00011be0;
                           if ((*(var22 + 8) == NULL) || (**(var22 + 8) == '\0')) {
                             var16 = **(var22 + 0x20);
                             if (var16 == NULL) {
                               var16 = "*unknown*";
                             } else if (*var16 == '\0') {
                               var16 = "*unknown*";
                             }
                             var15 = sanitize_string(var16);
                             __printf_chk(1, "%s", var15);
                           } else {
                             objdump_print_symname(*var5, param3);
                           }
                         } else {
                           putc(9, ram0x00267b80);
                           if (ram0x002681dc == 0) goto label_r0x00011b87;
label_r0x00011a5f:
                           var36 = var38[3];
                           if (var36 == NULL) goto label_r0x00011bc1;
label_r0x00011a6c:
                           if (var36[4] == 0) {
                             __printf_chk(1, "%d\t", *var36);
                           } else {
                             __printf_chk(1, "%s\t");
                           }
                           var36 = *var38;
                           if (var36 != NULL) goto label_r0x00011a98;
label_r0x00011be0:
                           __printf_chk(1, "*unknown*");
                         }
                         var36 = var38[2];
                         if (var36 != NULL) {
                           if (var36 < 0) {
                             var36 = -var36;
                             __printf_chk(1, "-0x");
                           } else {
                             __printf_chk(1, "+0x");
                           }
                           objdump_print_value(var36, param3, 1);
                         }
                         putchar(10);
                         var31 = 0;
                       }
                       stack_348 = stack_348 + 1;
                     } while ((stack_348 < stack_318) && (var38 = *stack_348, var38[1] < var39));
                     if (var31 != 0) goto label_r0x00012038;
                   }
                 } else {
label_r0x0001128b:
                   if ((ram0x002681d4 != 0) || (ram0x002681d0 != '\0')) {
                     var22 = *var5;
                     var7 = (*(*(var22 + 8) + 0x240))
                                      (var22, ram0x00268110, var27, stack_388, &stack_258, 
                                       &stack_250, &stack_274, &stack_270);
                     if (var7 != '\0') {
                       if (stack_258 == NULL) {
label_r0x00011328:
                         if (stack_250 != NULL) {
                           if (*stack_250 == '\0') {
label_r0x0001133a:
                             stack_250 = NULL;
                           }
                           if (stack_258 != NULL) {
label_r0x0001134b:
                             var8 = *stack_258;
                             goto label_r0x0001134f;
                           }
                         }
label_r0x00011358:
                         stack_380 = NULL;
                         var7 = '\0';
                       } else {
                         var8 = *stack_258;
                         if (var8 == '\0') {
                           stack_258 = NULL;
                           goto label_r0x00011328;
                         }
                         if (stack_250 != NULL) {
                           if (*stack_250 == '\0') goto label_r0x0001133a;
                           goto label_r0x0001134b;
                         }
label_r0x0001134f:
                         var16 = stack_258;
                         if ((var8 != '/') || (ram0x00268170 == NULL)) goto label_r0x00011358;
                         var19 = strlen(stack_258);
                         stack_380 = xmalloc(var19 + 1 + ram0x00268160);
                         var35 = ram0x00268160;
                         if (ram0x00268160 != 0) {
                           memcpy(stack_380, ram0x00268170, ram0x00268160);
                         }
                         if (0 < ram0x00268168) {
                           var8 = var16[1];
                           var20 = var16 + 1;
                           if (var8 != '\0') {
                             var9 = 0;
                             do {
                               if (var8 == '/') {
                                 var9 += 1;
                                 var16 = var20;
                               }
                               var20 = var20 + 1;
                               var8 = *var20;
                             } while ((var9 < ram0x00268168) && (var8 != '\0'));
                           }
                         }
                         strcpy(stack_380 + var35, var16);
                         stack_258 = stack_380;
                       }
                       var16 = stack_250;
                       if (ram0x002681d4 != 0) {
                         if ((stack_250 != NULL) &&
                            ((ram0x00268098 == NULL ||
                             (var9 = strcmp(stack_250, ram0x00268098), var9 != 0)))) {
                           if ((ram0x002681ac == 0) ||
                              ((*var16 == '\0' ||
                               (var30 = bfd_demangle(var22, var16, ram0x0026600c), var16 = stack_250
                               , var30 == NULL)))) {
                             var30 = NULL;
                             var15 = sanitize_string(var16);
                             __printf_chk(1, "%s():\n", var15);
                           } else {
                             var15 = sanitize_string(var30);
                             __printf_chk(1, "%s:\n", var15);
                           }
                           ram0x00268094 = 0xffffffff;
                           free(var30);
                         }
                         var11 = stack_270;
                         var12 = stack_274;
                         if ((stack_274 != 0) &&
                            ((stack_274 != ram0x00268094 || (ram0x00268090 != stack_270)))) {
                           var16 = "???";
                           if (stack_270 == 0) {
                             if (stack_258 != NULL) {
                               var16 = sanitize_string();
                             }
                             __printf_chk(1, "%s:%u\n", var16, var12);
                           } else {
                             if (stack_258 != NULL) {
                               var16 = sanitize_string();
                             }
                             __printf_chk(1, "%s:%u (discriminator %u)\n", var16, var12, var11);
                           }
                         }
                         if (ram0x00268158 != '\0') {
                           while (var8 = (*(*(var22 + 8) + 0x250))
                                                   (var22, &stack_248, &stack_228, &stack_26c),
                                 var12 = stack_26c, var8 != '\0') {
                             var15 = sanitize_string(stack_248);
                             __printf_chk(1, "inlined by %s:%u", var15, var12);
                             var15 = sanitize_string(stack_228);
                             __printf_chk(1, " (%s)\n", var15);
                           }
                         }
                       }
                       if ((ram0x002681d0 == '\0') || (stack_258 == NULL)) goto label_r0x00011710;
                       if (stack_274 == 0) {
                         if (stack_250 != NULL) {
label_r0x0001171d:
                           var16 = ram0x00268098;
                           if (ram0x00268098 != NULL) {
                             var9 = strcmp(stack_250, ram0x00268098);
                             if (var9 == 0) goto label_r0x0001176a;
                             free(var16);
                           }
                           var19 = strlen(stack_250);
                           ram0x00268098 = xmalloc(var19 + 1);
                           strcpy(ram0x00268098, stack_250);
                           goto label_r0x0001176a;
                         }
                       } else {
                         if (ram0x00268088 != NULL) {
                           var38 = 0x268088;
                           var39 = ram0x00268088;
                           do {
                             var9 = filename_cmp(var39[1], stack_258);
                             var38 = *var38;
                             if (var9 == 0) {
                               if (var38 != NULL) goto label_r0x0001155f;
                               break;
                             }
                             var39 = *var38;
                           } while (var39 != NULL);
                         }
                         if (var7 != '\0') {
                           stack_258 = xstrdup(stack_258);
                         }
                         var20 = stack_258;
                         var38 = try_print_file_open(stack_258, stack_258, stack_108);
                         if (var38 == NULL) {
                           if ((ram0x00268128 != 0) && (var15 = lbasename(var20), 0 < ram0x00268128)
                              ) {
                             var41 = 0;
                             do {
                               var30 = concat(*(ram0x00268130 + var41 * 8), "/", var15, 0);
                               var38 = try_print_file_open(var20, var30, stack_108);
                               if (var38 != NULL) goto label_r0x000129e3;
                               var41 += 1;
                               free(var30);
                             } while (var41 < ram0x00268128);
                           }
                         } else {
label_r0x000129e3:
                           var22 = bfd_get_mtime(var22);
                           if (var22 < stack_b0) {
                             var15 = dcgettext(0, "source file %s is more recent than object file\n"
                                               , 5);
                             warn(var15, var20);
                           }
label_r0x0001155f:
                           var12 = stack_274;
                           if (*(var38 + 0x34) != stack_274) {
                             var39 = var38[3];
                             if ((ram0x0026817c == 0) || (*(var38 + 0x3c) == 0)) {
                               var11 = stack_274 - 5;
                               if (stack_274 < 5) {
                                 var11 = 1;
                               }
                               var45 = *(var38 + 7);
                               if (var45 < var11) goto label_r0x00011592;
                               if (var45 < stack_274) {
                                 if ((var39 != NULL) && (var11 = var45 + 1, var45 + 1 <= stack_274))
                                 goto label_r0x000115a4;
                                 goto label_r0x000116fc;
                               }
                               var11 = stack_274;
                               if (var39 != NULL) goto label_r0x000115a4;
                             } else {
                               var11 = 1;
label_r0x00011592:
                               if ((var39 != NULL) && (var11 <= stack_274)) {
label_r0x000115a4:
                                 var11 = var11 - 1;
                                 do {
                                   if (var11 <= *(var38 + 6) && *(var38 + 6) != var11) {
                                     var16 = var38[5][var11];
                                     if ((ram0x00268148 != 0) && (*var16 != '\0')) {
                                       __printf_chk(1, "%s");
                                     }
                                     var19 = strcspn(var16, "\n\r");
                                     if ((var19 == 0) ||
                                        (var19 = fwrite(var16, var19, 1, ram0x00267b80), var19 == 1)
                                        ) {
                                       putc(10, ram0x00267b80);
                                     }
                                   }
                                   var45 = var11 + 2;
                                   var11 = var11 + 1;
                                 } while (var45 <= var12);
                               }
                               if (*(var38 + 7) < stack_274) {
label_r0x000116fc:
                                 *(var38 + 7) = stack_274;
                               }
                             }
                             *(var38 + 0x34) = stack_274;
                             *(var38 + 0x3c) = 0;
                           }
                         }
label_r0x00011710:
                         if (stack_250 != NULL) goto label_r0x0001171d;
label_r0x0001176a:
                         if ((stack_274 != 0) && (stack_274 != ram0x00268094)) {
                           ram0x00268094 = stack_274;
                         }
                       }
                       if (stack_270 != ram0x00268090) {
                         ram0x00268090 = stack_270;
                       }
                       if (stack_380 != NULL) {
                         free(stack_380);
                       }
                     }
                   }
                   if (ram0x002681dc == 0) {
                     var22 = *(var27 + 0x30);
                     if (ram0x002681d8 == 0) {
                       bfd_sprintf_vma(*var5, stack_2e0, stack_388 + var22);
                       var20 = stack_2e0 + stack_29c;
                       var7 = *var20;
                       while (var7 == '0') {
                         *var20 = ' ';
                         var20 = var20 + 1;
                         var7 = *var20;
                       }
                       if (var7 == '\0') {
                         var20[-1] = '0';
                       }
                       __printf_chk(1, "%s:\t");
                     } else {
                       *(var5 + 1) = 0x1;
                       objdump_print_addr(stack_388 + var22, param3, 0);
                       *(var5 + 1) = 0x0;
                       putc(0x20, ram0x00267b80);
                     }
                   } else {
                     putchar(9);
                   }
                   var39 = stack_308;
                   if (stack_308 != NULL) {
                     print_jump_visualisation.part.27
                               (stack_388 + *(var27 + 0x30), stack_2ec, stack_308, stack_300);
                     var39 = extraoutRDX;
                   }
                   var31 = ram0x002681a8;
                   var12 = ram0x0026819c;
                   if (stack_2ed == 0) {
                     stack_380 = stack_31c;
                     var37 = var24 * stack_388;
                     var19 = var37;
                     if (stack_350 < stack_388 + stack_380 / var24) {
                       stack_380 = (stack_350 - stack_388) * var24;
                       var21 = var18;
                       if (var37 < var18) goto label_r0x0001226c;
label_r0x00012412:
                       var22 = 0;
                     } else {
                       var21 = stack_380 + var37;
                       if (stack_380 + var37 <= var37) goto label_r0x00012412;
label_r0x0001226c:
                       do {
                         while (var47 = var19, (*(var49[var47] * 2 + 0x265660) & 0x10) != 0) {
                           stack_2e0[var47 - var37] = var49[var47];
                           var19 = var47 + 1;
                           if (var47 + 1 == var21) goto label_r0x00012285;
                         }
                         stack_2e0[var47 - var37] = '.';
                         var19 = var47 + 1;
                       } while (var47 + 1 != var21);
label_r0x00012285:
                       var22 = (var47 + 1) - var37;
                     }
                     stack_78[var22] = '\0';
                   } else {
                     param3[1] = &stack_208;
                     *param3 = objdump_sprintf;
                     stack_200 = NULL;
                     param3[0x17] = NULL;
                     var11 = (var31 != 0) << 0x1e;
                     if (var12 != 0) {
                       var11 |= 0x10000000;
                     }
                     var50 = ram0x00268120 != 0;
                     param3[0xb] = var11;
                     if (var50) {
                       param3[0xb] = var11 | 0x20000000;
                     }
                     var22 = *(var27 + 0x30);
                     var48 = stack_388 + var22;
                     if (((*(param3 + 0x1a) != '\0') && ((*(*var5 + 0x44) & 0x42) == 0)) &&
                        (stack_348 < stack_318)) {
                       var39 = *stack_348;
                       var41 = var39[1] - (stack_310 + stack_388);
                       if (var41 < 1) {
                         if (var39[1] == stack_310 + stack_388) {
label_r0x00012f8e:
                           param3[0xb] = param3[0xb] | 0x80000000;
                           var5[3] = var39;
                         }
                       } else {
                         var9 = *(*(*var5 + 0xd0) + 0x50);
                         if ((var9 < 0) || (var41 <= var9)) {
                           if (ram0x00268198 == 0) {
                             *param3 = null_print;
                             var12 = var32(var48, param3);
                             *param3 = objdump_sprintf;
                             var19 = var12 % var2;
                             var22 = *(var27 + 0x30);
                             var48 = stack_388 + var22;
                             var31 = ram0x002681a8;
                           } else {
                             var19 = ram0x00268198 % var2;
                             var12 = ram0x00268198;
                           }
                           var39 = var19 & 0xffffffff;
                           if (var41 < var12 / var2) {
                             var39 = *stack_348;
                             goto label_r0x00012f8e;
                           }
                         }
                       }
                     }
                     if ((var31 == 0) && ((*(var27 + 0x28) & 0x110) == 0x110)) {
                       param3[0x1e] = stack_350 + var22;
                     }
                     param3[0x1f] = stack_350;
                     var9 = var32(var48, param3, var39);
                     var12 = ram0x00268198;
                     var48 = ram0x00265fc0;
                     param3[0x1e] = NULL;
                     stack_380 = var9;
                     *param3 = var48;
                     param3[1] = ram0x00267b80;
                     var11 = stack_31c;
                     if ((var12 == 0) && (var11 = *(param3 + 0x17), *(param3 + 0x17) == 0)) {
                       var11 = stack_31c;
                     }
                     stack_31c = var11;
                     if (var9 < var2) {
                       if (stack_200 != NULL) {
                         puts(stack_208);
                       }
                       if (-1 < var9) {
                         var15 = dcgettext(0, "disassemble_fn returned length %d", 5);
                         non_fatal(var15, var9);
                         ram0x00268210 = 1;
                       }
                       break;
                     }
                   }
                   if (ram0x002681d8 == 0) {
                     if (ram0x002681cc < 0) goto label_r0x00011990;
                     var19 = stack_380 & 0xffffffff;
                     if ((stack_31c < stack_380) && (ram0x0026819c == 0)) {
                       var19 = stack_31c;
                     }
label_r0x00011d0c:
                     var12 = *(param3 + 0xbc);
                     var11 = var19;
                     if (var12 == 0) {
                       var12 = 1;
                     }
                     var47 = var12;
                     var21 = var24 * stack_388;
                     var37 = var19 + var21;
                     var48 = var49 + (var21 - 1);
                     while (var21 < var37) {
                       var21 += var47;
                       if (var21 <= var18) {
                         var40 = var48 + 1;
                         if (*(param3 + 0x18) == 1) {
                           var40 = var48 + var47;
                           do {
                             var1 = *var40;
                             var40 = var40 + -1;
                             __printf_chk(1, "%02x", var1);
                           } while (var48 != var40);
                         } else {
                           do {
                             var1 = *var40;
                             var40 = var40 + 1;
                             __printf_chk(1, "%02x", var1);
                           } while (var49 + var21 != var40);
                         }
                       }
                       var48 = var48 + var47;
                       putc(0x20, ram0x00267b80);
                     }
                     while (var11 < stack_31c) {
                       var11 = 0;
                       do {
                         var11 += 1;
                         __printf_chk(1, "  ");
                       } while (var11 != var12);
                       var11 = var19 + var12;
                       var19 = var11;
                       putc(0x20, ram0x00267b80);
                     }
                     if (stack_2ed != 0) {
                       putc(9, ram0x00267b80);
                       goto joined_r0x000119b2;
                     }
                     __printf_chk(1, "    ");
label_r0x000121e3:
                     __printf_chk(1, "%s", stack_2e0);
                   } else {
                     if (0 < ram0x002681cc) {
                       var19 = stack_380 & 0xffffffff;
                       goto label_r0x00011d0c;
                     }
label_r0x00011990:
                     var19 = 0;
                     var12 = 0;
                     if (stack_2ed == 0) goto label_r0x000121e3;
joined_r0x000119b2:
                     if (stack_200 != NULL) {
                       __printf_chk(1, "%s", stack_208);
                     }
                   }
                   if (ram0x002681d8 == 0) {
                     if (-1 < ram0x002681cc) goto label_r0x00011e7d;
                   } else if (0 < ram0x002681cc) {
label_r0x00011e7d:
                     var20 = stack_2e0 + stack_29c;
                     while (var19 < stack_380) {
                       while( true ) {
                         putc(10, ram0x00267b80);
                         var37 = var24 * stack_388 + var19;
                         if (ram0x002681dc == 0) {
                           bfd_sprintf_vma(*var5, stack_2e0, *(var27 + 0x30) + var37 / var24);
                           var7 = *var20;
                           var23 = var20;
                           while (var7 == '0') {
                             *var23 = ' ';
                             var23 = var23 + 1;
                             var7 = *var23;
                           }
                           if (var7 == '\0') {
                             var23[-1] = '0';
                           }
                           __printf_chk(1, "%s:\t", var20);
                         } else {
                           putchar(9);
                         }
                         if (stack_308 != NULL) {
                           print_jump_visualisation.part.27
                                     (*(var27 + 0x30) + var37 / var24, stack_2ec, stack_308, 
                                      stack_300);
                         }
                         var19 = var19 + stack_31c;
                         var21 = var19;
                         if (stack_380 < var19) {
                           var19 = stack_380 & 0xffffffff;
                           var21 = stack_380;
                         }
                         var21 += var24 * stack_388;
                         if (var21 <= var37) break;
                         var47 = var12;
                         var48 = var49 + var37;
                         var40 = var49 + (var12 - 1) + var37;
                         do {
                           var37 += var47;
                           if (var37 <= var18) {
                             if (*(param3 + 0x18) == 1) {
                               var46 = var40;
                               if (var12 != 0) {
                                 do {
                                   __printf_chk(1, "%02x", *var46);
                                   var50 = var46 != var48;
                                   var46 = var46 + -1;
                                 } while (var50);
                               }
                             } else {
                               var46 = var48;
                               if (var12 != 0) {
                                 do {
                                   __printf_chk(1, "%02x", *var46);
                                   var50 = var40 != var46;
                                   var46 = var46 + 1;
                                 } while (var50);
                               }
                             }
                           }
                           var40 = var40 + var47;
                           var48 = var48 + var47;
                           putc(0x20, ram0x00267b80);
                         } while (var37 < var21);
                         if (stack_380 <= var19) goto joined_r0x000119e5;
                       }
                     }
                   }
joined_r0x000119e5:
                   if (ram0x0026819c == 0) {
                     putc(10, ram0x00267b80);
label_r0x0001216a:
                     var19 = stack_380 / var24;
                     if (stack_348 < stack_318) goto label_r0x00012189;
                   } else {
                     if (stack_348 < stack_318) {
                       var38 = *stack_348;
                       var19 = stack_380 / var24;
                       var39 = stack_310 + stack_388 + var19;
                       var31 = stack_2c5;
                       if (var38[1] < var39) goto label_r0x00011b4a;
                     }
label_r0x00012038:
                     putchar(10);
                     var19 = stack_380 / var24;
                   }
                 }
                 var48 = stack_388 + var19;
               } while (stack_388 + var19 < stack_350);
             }
             free(stack_208);
             free(stack_308);
             free(stack_300);
             for (; stack_378._0_1_ = stack_2c5, ram0x002680b0 != NULL;
                 ram0x002680b0 = jump_info_free(ram0x002680b0)) {
             }
           } else {
             var22 = *(unaffR12 + 0x20);
             var32 = *(unaffR12 + 0x10);
             if (stack_380 < var32 + *(var22 + 0x30)) {
               param3[7] = NULL;
               *(param3 + 8) = 0;
               *(param3 + 10) = 0xffffffff;
             } else {
               var42 = stack_260;
               var9 = var42;
               if ((var42 < ram0x002680f8) &&
                  (var41 = *(ram0x00268100 + var42 * 8),
                  *(var41 + 0x10) + *(*(var41 + 0x20) + 0x30) <= stack_380)) {
                 var41 = var42 + 1;
                 do {
                   var9 = var41;
                   if (ram0x002680f8 == var41) break;
                   var6 = *(ram0x00268100 + var41 * 8);
                   var41 += 1;
                 } while (*(var6 + 0x10) + *(*(var6 + 0x20) + 0x30) <= stack_380);
               }
               var27 = ram0x00268100 + stack_260 * 8;
               *(param3 + 10) = var42;
               param3[7] = var27;
               *(param3 + 8) = var9 - var42;
             }
             var16 = *(var3 + 0x20);
             if (var16 == NULL) {
               if ((ram0x002681d8 == 0) && (stack_378 != 0)) goto label_r0x00010d96;
             } else if (stack_378 == 0) {
               var20 = *(unaffR12 + 8);
               ptr = NULL;
               if ((ram0x002681ac != 0) && (*var20 != '\0')) {
                 ptr = bfd_demangle(param1, var20, ram0x0026600c);
                 var16 = *(var3 + 0x20);
                 if (ptr != NULL) {
                   var20 = ptr;
                 }
               }
               var9 = strcmp(var20, var16);
               if (var9 == 0) {
                 if ((*(unaffR12 + 0x18) & 8) == 0) {
                   free(ptr);
                   if (ram0x002681d8 != 0) {
                     var22 = *(unaffR12 + 0x20);
                     stack_288 = 2;
                     var32 = *(unaffR12 + 0x10);
                     stack_378._0_1_ = stack_2c5;
                     goto label_r0x00010def;
                   }
                   stack_288 = 2;
                 } else if ((*(param1[1] + 8) == 5) && (*(unaffR12 + 0x38) != 0)) {
                   stack_2d0 = stack_388 + *(unaffR12 + 0x38);
                   free(ptr);
                   if (ram0x002681d8 != 0) {
                     stack_288 = 0;
                     stack_378._0_1_ = stack_2c5;
                     goto label_r0x00012930;
                   }
                   stack_288 = 0;
                 } else {
                   free(ptr);
                   if (ram0x002681d8 != 0) {
                     var22 = *(unaffR12 + 0x20);
                     stack_288 = 1;
                     var32 = *(unaffR12 + 0x10);
                     stack_378._0_1_ = stack_2c5;
                     goto label_r0x00010def;
                   }
                   stack_288 = 1;
                 }
label_r0x00010d96:
                 (*param3)(param3[1], "\n");
                 objdump_print_addr_with_sym(param1, param2, unaffR12, stack_380, param3, 0);
                 (*param3)(param3[1], ":\n");
                 var22 = *(unaffR12 + 0x20);
                 var32 = *(unaffR12 + 0x10);
                 stack_378._0_1_ = stack_2c5;
               } else {
                 free(ptr);
                 var22 = *(unaffR12 + 0x20);
                 var32 = *(unaffR12 + 0x10);
               }
             } else if (stack_288 == 1) {
               if ((*(unaffR12 + 0x18) & 8) == 0) goto joined_r0x000128f6;
               stack_378._0_1_ = 0;
             } else if (stack_288 == 2) {
               stack_378._0_1_ = bfd_is_local_label(param1, unaffR12);
               if ((stack_378 != 0) && (ram0x002681d8 == 0)) goto label_r0x00010d96;
label_r0x00012930:
               var22 = *(unaffR12 + 0x20);
               var32 = *(unaffR12 + 0x10);
             } else {
               stack_288 = 0;
joined_r0x000128f6:
               if (ram0x002681d8 == 0) goto label_r0x00010d96;
             }
label_r0x00010def:
             stack_350 = var32 + *(var22 + 0x30);
             stack_2b8 = unaffR12;
             if (stack_380 < stack_350) {
label_r0x00010f78:
               stack_350 = stack_350 + -param2[6];
             } else {
               if (stack_260 < ram0x002680f8) {
                 do {
                   var22 = *(ram0x00268100 + stack_260 * 8);
                   var4 = *(var22 + 0x20);
                   var9 = strcmp(*var4, *param2);
                   if ((var9 == 0) && (stack_350 < var4[6] + *(var22 + 0x10))) {
                     var7 = param3[0x13](var22, param3);
                     if (var7 != '\0') {
                       var32 = *(unaffR12 + 0x10);
                       stack_350 = var32 + *(*(unaffR12 + 0x20) + 0x30);
                       if (stack_260 < ram0x002680f8) {
                         stack_2b8 = *(ram0x00268100 + stack_260 * 8);
                         if (stack_380 < stack_350) goto label_r0x00010f78;
                         if (stack_2b8 == 0) {
label_r0x000136d5:
                           stack_350 = stack_2d0;
                         } else {
                           stack_350 = (*(stack_2b8 + 0x10) - param2[6]) +
                                       *(*(stack_2b8 + 0x20) + 0x30);
                         }
                         goto label_r0x00010f89;
                       }
                       break;
                     }
                     var32 = *(unaffR12 + 0x10);
                     stack_350 = var32 + *(*(unaffR12 + 0x20) + 0x30);
                   }
                   stack_260 += 1;
                 } while (stack_260 < ram0x002680f8);
                 if (stack_380 < stack_350) {
                   stack_2b8 = 0;
                   goto label_r0x00010f78;
                 }
               }
               stack_2b8 = 0;
               stack_350 = stack_2d0;
             }
label_r0x00010f89:
             if ((stack_2d0 < stack_350) || (stack_350 <= stack_388)) {
               stack_350 = stack_2d0;
             }
             stack_2ed = unaffR12 == 0 | ram0x002681a8;
             if (((stack_2ed == 0) && (stack_2ed = stack_2c5, *(unaffR12 + 0x20) == param2)) &&
                (var32 + param2[6] <= stack_380)) {
               var2 = *(unaffR12 + 0x18);
               if ((var2 & 0x10000) == 0) {
                 var15 = *(unaffR12 + 8);
                 var22 = strstr(var15, "gnu_compiled");
                 if ((var22 == 0) && (var22 = strstr(var15, "gcc2_compiled"), var22 == 0))
                 goto joined_r0x000110f0;
               }
               stack_2ed = var2 >> 3 & 1;
             }
joined_r0x000110f0:
             if (stack_378 != 0) {
               if (((ram0x00268146 != '\0') && (unaffR12 != 0)) && (*(unaffR12 + 8) != NULL)) {
                 var24 = strlen(*(unaffR12 + 8));
                 stack_238 = var24 + 0x28;
                 stack_248 = xmalloc(stack_238);
                 stack_200 = &stack_248;
                 stack_240 = 0;
                 stack_208 = objdump_sprintf;
                 objdump_print_symname(param1, &stack_208, unaffR12);
                 var5 = param3[2];
                 var32 = param3[6];
                 var27 = *(var3 + 0x10);
                 var2 = *(param3 + 0xc4);
                 stack_218 = 0x78;
                 stack_228 = xmalloc(0x78);
                 *param3 = objdump_sprintf;
                 stack_220 = 0;
                 *(param3 + 0xd1) = 0;
                 param3[1] = &stack_228;
                 if (stack_388 < stack_350) {
                   var24 = var2;
                   stack_378 = NULL;
                   var49 = stack_388;
                   do {
                     var31 = ram0x002681a8;
                     var14 = ram0x0026819c;
                     var18 = ram0x0026819c;
                     stack_220 = 0;
                     param3[0x17] = NULL;
                     var13 = (var31 != 0) << 0x1e;
                     if (var14 != 0) {
                       var13 |= 0x10000000;
                     }
                     var50 = ram0x00268120 != 0;
                     param3[0xb] = var13;
                     if (var50) {
                       param3[0xb] = var13 | 0x20000000;
                     }
                     if ((((*(param3 + 0x1a) != '\0') && ((*(*var5 + 0x44) & 0x42) == 0)) &&
                         (stack_348 < stack_318)) &&
                        ((var22 = ((*stack_348)[1] - stack_310) - var49,
                         (*stack_348)[1] - stack_310 == var49 ||
                         ((0 < var22 && (var18 = var24 % var2, var22 < var24 / var2)))))) {
                       param3[0xb] = param3[0xb] | 0x80000000;
                     }
                     var22 = *(var32 + 0x30);
                     if ((var31 == 0) && ((*(var32 + 0x28) & 0x110) == 0x110)) {
                       param3[0x1e] = stack_350 + var22;
                     }
                     param3[0x1f] = stack_350;
                     *(param3 + 0xd1) = 0;
                     var14 = var27(var49 + var22, param3, var18);
                     if ((*(param3 + 0xd1) != '\0') && (*(param3 + 0xd4) - 2U < 4)) {
                       var22 = *(var32 + 0x30);
                       var48 = param3[0x1b];
                       if ((stack_388 + var22 <= var48) && (var48 < stack_350 + var22)) {
                         var28 = xmalloc(0x38);
                         *var28 = 0;
                         var28[1] = 0;
                         var29 = xmalloc(0x10);
                         var28[2] = var29;
                         *var29 = var49 + var22;
                         var28[3] = 1;
                         var28[4] = 2;
                         var28[5] = var48;
                         *(var28 + 6) = 0xffffffff;
                         *var28 = stack_378;
                         if (stack_378 != NULL) {
                           stack_378[1] = var28;
                         }
                         var28[1] = 0;
                         stack_378 = var28;
                       }
                     }
                     var24 = var14;
                     param3[0x1e] = NULL;
                     var49 = var49 + var24 / var2;
                   } while (var49 < stack_350);
                   *param3 = ram0x00265fc0;
                   param3[1] = ram0x00267b80;
                   free(stack_228);
                   var28 = stack_378;
                   if (stack_378 == NULL) {
                     stack_378 = NULL;
                   } else {
                     do {
                       var25 = *stack_378;
                       var44 = var28;
                       if (var25 == NULL) break;
                       do {
                         while (stack_378[5] != var25[5]) {
                           var25 = *var25;
                           if (var25 == NULL) goto label_r0x00012d48;
                         }
                         var22 = var25[3];
                         if (stack_378[4] < stack_378[3] + var22) {
                           var22 = stack_378[4] + var25[4];
                           stack_378[4] = var22;
                           var30 = xrealloc(stack_378[2], var22 * 8);
                           var22 = var25[3];
                           stack_378[2] = var30;
                         }
                         if (var22 != 0) {
                           var22 = var25[2];
                           var41 = stack_378[2];
                           var24 = 0;
                           do {
                             var43 = stack_378[3];
                             stack_378[3] = var43 + 1;
                             var6 = var24 * 8;
                             var24 += 1;
                             *(var41 + var43 * 8) = *(var22 + var6);
                           } while (var24 < var25[3]);
                         }
                         var44 = var25[1];
                         var26 = *var25;
                         var33 = var44;
                         if (var26 != NULL) {
                           var26[1] = var44;
                           var33 = var25[1];
                         }
                         if (var33 != NULL) {
                           *var33 = var26;
                           var26 = var28;
                         }
                         *var25 = 0;
                         var25[1] = 0;
                         jump_info_free(var25);
                         var25 = *var44;
                         var28 = var26;
                       } while (var25 != NULL);
label_r0x00012d48:
                       stack_378 = *stack_378;
                       var44 = var28;
                     } while (stack_378 != NULL);
                     while (stack_378 = var44, var25 = var28, var28 != NULL) {
                       do {
                         var28 = var25;
                         var25 = *var28;
                         var24 = jump_info_size(var28);
                         var26 = var25;
                         var44 = var28;
                         if (var25 == NULL) goto label_r0x00013148;
                         do {
                           while( true ) {
                             var33 = var26;
                             var18 = jump_info_size(var33);
                             if (var24 <= var18) break;
                             var26 = *var33;
                             var24 = var18;
                             var44 = var33;
                             if (*var33 == NULL) goto label_r0x00012db9;
                           }
                           if (var18 == var24) {
                             var18 = var33[5];
                             var22 = var33[3] + -1;
                             if (var33[3] != 0) {
                               do {
                                 var19 = *(var33[2] + var22 * 8);
                                 if (var19 < var18) {
                                   var18 = var19;
                                 }
                                 var22 += -1;
                               } while (var22 != -1);
                             }
                             var19 = var44[5];
                             var22 = var44[3] + -1;
                             if (var44[3] != 0) {
                               do {
                                 var37 = *(var44[2] + var22 * 8);
                                 if (var37 < var19) {
                                   var19 = var37;
                                 }
                                 var22 += -1;
                               } while (var22 != -1);
                             }
                             if (var18 < var19) {
                               var44 = var33;
                             }
                           }
                           var26 = *var33;
                         } while (*var33 != NULL);
label_r0x00012db9:
                       } while (var28 == var44);
                       var25 = *var44;
                       var26 = var44[1];
                       if (var25 != NULL) {
                         var25[1] = var26;
                         var26 = var44[1];
                       }
                       if (var26 != NULL) {
                         *var26 = var25;
                         var25 = stack_378;
                       }
                       stack_378 = var25;
                       var44[1] = 0;
                       var15 = var28[1];
                       *var44 = var28;
                       var44[1] = var15;
                       var28[1] = var44;
                       if (var44[1] != NULL) {
                         *var44[1] = var44;
                         var44 = stack_378;
                       }
                     }
label_r0x00013148:
                     if (stack_378 != NULL) {
                       stack_380._0_4_ = -1;
                       var28 = stack_378;
                       do {
                         stack_380 += 1;
                         *(var28 + 6) = stack_380;
                         var25 = *var28;
                         var44 = var25;
                         if (var25 == NULL) break;
                         do {
                           if (var44 != var28) {
                             var22 = var25[3];
                             var24 = var25[5];
                             var26 = var28;
                             do {
                               var6 = var26[3];
                               var18 = var26[5];
                               var41 = var6 + -1;
                               var19 = var18;
                               if (var6 != 0) {
                                 var43 = var41;
                                 do {
                                   var37 = *(var26[2] + var43 * 8);
                                   if (var19 < var37) {
                                     var19 = var37;
                                   }
                                   var43 += -1;
                                 } while (var43 != -1);
                               }
                               var37 = var24;
                               if (var22 != 0) {
                                 var43 = var22 + -1;
                                 do {
                                   var21 = *(var25[2] + var43 * 8);
                                   if (var21 < var37) {
                                     var37 = var21;
                                   }
                                   var43 += -1;
                                 } while (var43 != -1);
                               }
                               if (var37 <= var19) {
                                 if (var6 != 0) {
                                   do {
                                     var19 = *(var26[2] + var41 * 8);
                                     if (var19 < var18) {
                                       var18 = var19;
                                     }
                                     var41 += -1;
                                   } while (var41 != -1);
                                 }
                                 var19 = var24;
                                 if (var22 != 0) {
                                   var41 = var22 + -1;
                                   do {
                                     var37 = *(var25[2] + var41 * 8);
                                     if (var19 < var37) {
                                       var19 = var37;
                                     }
                                     var41 += -1;
                                   } while (var41 != -1);
                                 }
                                 if (var18 <= var19) {
                                   var26 = *var25;
                                   var33 = var44;
                                   goto label_r0x0001327d;
                                 }
                               }
                               var26 = *var26;
                             } while (var44 != var26);
                           }
                           var26 = *var25;
                           var34 = var44;
                           var33 = var26;
                           if (var44 != var25) {
                             var33 = var25[1];
                             var34 = var33;
                             if (var26 != NULL) {
                               var26[1] = var33;
                               var34 = var25[1];
                             }
                             if (var34 != NULL) {
                               *var34 = var26;
                               var26 = stack_378;
                             }
                             stack_378 = var26;
                             var25[1] = 0;
                             var15 = var44[1];
                             *var25 = var44;
                             var25[1] = var15;
                             var44[1] = var25;
                             var34 = var25;
                             if (var25[1] == NULL) {
                               var26 = *var33;
                               var33 = var44;
                               stack_378 = var25;
                             } else {
                               *var25[1] = var25;
                               var26 = *var33;
                               var33 = var44;
                             }
                           }
                           *(var34 + 6) = stack_380;
label_r0x0001327d:
                           var25 = var26;
                           var44 = var33;
                         } while (var26 != NULL);
                         var28 = var33;
                       } while (var33 != NULL);
                     }
                   }
                 } else {
                   *param3 = ram0x00265fc0;
                   param3[1] = ram0x00267b80;
                   free(stack_228);
                   stack_378 = NULL;
                 }
                 ram0x002680b0 = stack_378;
                 free(stack_248);
               }
               goto label_r0x00011112;
             }
           }
           stack_388 = stack_350;
           unaffR12 = stack_2b8;
         } while (stack_350 < stack_2d0);
         free(stack_268);
         if (stack_280 != NULL) {
           if (stack_40 == *(inFS_OFFSET + 0x28)) {
                    /* WARNING: Could not recover jumptable at 0x00008e44. Too many branches */
                    /* WARNING: Treating indirect jump as call */
             ram0x00265d48(stack_280);
             return;
           }
           goto label_r0x00013695;
         }
       }
     }
   }
label_r0x00010f20:
   if (stack_40 == *(inFS_OFFSET + 0x28)) {
     return;
   }
label_r0x00013695:
                    /* WARNING: Subroutine does not return */
   __stack_chk_fail();
}
