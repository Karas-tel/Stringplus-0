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
    char* str_cp = NULL;
    if (str) {
        str_cp =(char*) calloc(s21_strlen(str) + 1, sizeof(char));
        size_t i = 0;
        while (str[i] != '\0') {
            if (str[i] >= 'a' && str[i] <= 'z')
                str_cp[i] = str[i] - 32;
            else
                str_cp[i] = str[i];
            ++i;
        }
        str_cp[i] = '\0';
    }
    return str_cp;
}
void* to_lower(const char *str) {
    char* str_cp = NULL;
    if (str) {
        str_cp =(char*) calloc(s21_strlen(str) + 1, sizeof(char));
        int i = 0;
        while (str[i] != '\0') {
            if (str[i] >= 'A' && str[i] <= 'Z')
                str_cp[i] = str[i] + 32;
            else
                str_cp[i] = str[i];
            ++i;
        }
        str_cp[i] = '\0';
    }
    return str_cp;
}

void *insert(const char *src, const char *str, size_t start_index) {
    char* str_cp = (char*) calloc(s21_strlen(str) + s21_strlen(src) + 1, sizeof(char));
    size_t i = 0;
    if (start_index <= s21_strlen(src) && str_cp != NULL) {
        while (i < start_index) {
            str_cp[i] = src[i];
            ++i;
        }
        size_t i_temp = i, j = 0;
        while (str[j] != '\0') {
            str_cp[i++] = str[j++];
        }
        while(src[i_temp] != '\0') {
            str_cp[i++] = src[i_temp++];
        }
        str_cp[i] = '\0';
    } else {
        if (str_cp != NULL)
            free(str_cp);
        str_cp = NULL;
    }
    return str_cp;
}

void *trim(const char *src, const char *trim_chars) {
    
    char* str_cp = NULL;
    size_t left_bound = 0, right_bound = 0, flag = 1;
    
    if (src != NULL) {
        left_bound = 0;
        right_bound = s21_strlen(src) - 1;
        while(flag && left_bound != right_bound) {
            flag = 0;
            for(size_t i = 0; i < s21_strlen(trim_chars); ++i) {
                if (src[left_bound] == trim_chars[i])
                    flag = 1;
            }
            if (flag) left_bound++;
        }
        flag = 1;
        while(flag && left_bound != right_bound) {
            flag = 0;
            for(size_t i = 0; i < s21_strlen(trim_chars); ++i) {
                if (src[right_bound] == trim_chars[i])
                    flag = 1;
            }
            if (flag) right_bound--;
        }
        // printf("lb = %zu  rb = %zu", left_bound, right_bound);
        
        str_cp = calloc(right_bound - left_bound + 1, sizeof(char));
        if (str_cp) {
            int i_temp = 0;
            if (str_cp) {
                if (left_bound != right_bound) {
                    for (size_t i = left_bound; i <= right_bound; ++i)
                        str_cp[i_temp++] = src[i];
                }
                str_cp[i_temp]= '\0';
            }
        }
    }
    return str_cp;
}
