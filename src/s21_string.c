//
//  s21_string.c
//  test
//
//  Created by Spencer Finnigan on 11/26/22.
//

#include <stdio.h>
#include "s21_string.h"

#define BUFF_SIZE 256

    size_t s21_strlen(const char *str) {
        size_t len = 0;
        while (*(str++))
            ++len;
        return len;
    }


void* to_upper(const char *str) {
    char* str_cp =(char*) calloc(BUFF_SIZE, sizeof(char));
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z')
            str_cp[i] = str[i] - 32;
        else
            str_cp[i] = str[i];
        ++i;
        if (i + 10 >= sizeof(str_cp)) str_cp = realloc(str_cp, 2 * sizeof(str_cp));
    }
    str_cp[i] = '\0';
    return str_cp;
}
void* to_lower(const char *str) {
    char* str_cp =(char*) calloc(BUFF_SIZE, sizeof(char));
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str_cp[i] = str[i] + 32;
        else
            str_cp[i] = str[i];
        ++i;
       // if (i + 10 >= sizeof(str_cp)) str_cp = realloc(str_cp, 2 * sizeof(str_cp));
    }
    str_cp[i] = '\0';
    return str_cp;
}

void *insert(const char *src, const char *str, size_t start_index) {
    char* str_cp = (char*) calloc(BUFF_SIZE, sizeof(char));
    int i = 0;
    if (start_index > s21_strlen(src) || str_cp == NULL)
        return NULL;
    while (i < start_index) {
        str_cp[i] = src[i];
        if (i + 10 >= sizeof(str_cp))
            str_cp = (char*) realloc(str_cp, 2 * sizeof(str_cp));
        ++i;
    }
    int i_temp = i, j = 0;
    while (str[j] != '\0') {
        str_cp[i++] = str[j++];
        if (i + 10 >= sizeof(str_cp)) str_cp = (char*)realloc(str_cp, 2 * sizeof(str_cp));
    }
    while(src[i_temp] != '\0') {
        str_cp[i++] = src[i_temp++];
        if (i + 10 >= sizeof(str_cp)) str_cp = (char*)realloc(str_cp, 2 * sizeof(str_cp));
    }
    str_cp[i] = '\0';
    return str_cp;
}

void *trim(const char *src, const char *trim_chars) {
    
}
