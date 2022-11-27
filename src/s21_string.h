//
//  string.h
//  21_test
//
//  Created by mcbk on 09.11.2022.
//

#ifndef string_h
#define string_h
#define SIZE_M 1024

#include <stdio.h>
#include "s21_sprintf.h"

size_t s21_strlen(const char *str);
void* to_upper(const char *str);
void* to_lower(const char *str);
void *insert(const char *src, const char *str, size_t start_index);
void *trim(const char *src, const char *trim_chars);
#endif /* string_h */
