//
//  func.c
//  test
//
//  Created by mcbk on 14.11.2022.
//

#include "func.h"

size_t s21_strlen(const char *str) {
    size_t len = 0;
    while (*(str++))
        ++len;
    return len;
}
