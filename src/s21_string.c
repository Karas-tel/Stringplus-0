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
  for (; str[len]; len++)
    ;
  return len;
}
////Выполняет поиск первого вхождения символа c (беззнаковый тип) в первых n байтах строки, на которую указывает аргумент str.
//
//void *s21_memchr(const void *str, int c, size_t n) {
//  unsigned char *ch = (unsigned char *)str;
//  unsigned char *res = NULL;
//  while (n-- > 0) {
//    if (*ch == c) {
//      res = ch;
//      break;
//    }
//    ch++;
//  }
//  return res;
//}
//
////Сравнивает первые n байтов str1 и str2.
//
//int s21_memcmp(const void *str1, const void *str2, size_t n) {
//  int res = 0;
//  const unsigned char *ch1 = str1;
//  const unsigned char *ch2 = str2;
//  while (n-- > 0) {
//    if (*ch1 != *ch2) {
//      res = *ch1 - *ch2;
//      break;
//    }
//    ch1++;
//    ch2++;
//  }
//  return res;
//}
//
////Копирует n символов из src в dest.
//void *s21_memcpy(void *dest, const void *src, size_t n) {
//char* ch_dest = (char*) dest;
// char *ch_src = (char*) src;
//  while (n-- > 0 && *ch_src != '\0') {
//    *(ch_dest++) = *(ch_src++);
//  }
//  *ch_dest = '\0';
//  return dest;
//}
//
////Еще одна функция для копирования n символов из src в dest.
//void *s21_memmove(void *dest, const void *src, size_t n) {
//  // более безопасная memcpy - отрабатывает перехлесты памяти
//  if (dest <= src) {
//    s21_memcpy(dest, src, n);
//  } else {
//    unsigned char *ch_end_dest = dest + (n - 1);
//    const unsigned char *ch_end_src = src + (n - 1);
//    while (n-- > 0) {
//      *ch_end_dest-- = *ch_end_src--;
//    }
//  }
//  return dest;
//}
//
////Копирует символ c (беззнаковый тип) в первые n символов строки, на которую указывает аргумент str.
//void *s21_memset(void *str, int c, size_t n) {
//  char *ch = str;
//  while (n-- > 0) {
//    *ch++ = c;
//  }
//  return str;
//}
//
////Добавляет строку, на которую указывает src, в конец строки, на которую указывает dest.
//char *s21_strcat(char *dest, const char *src) {
//  size_t len_src = s21_strlen(src);
//  char *ch_end_dest = dest + (s21_strlen(dest) - 1);
//  while (len_src-- > 0) {
//    *ch_end_dest++ = *src++;
//  }
//  *ch_end_dest = '\0';
//  return dest;
//}
//char *s21_strncat(char *dest, const char *src, size_t n) {
//  char *ch_end_dest = dest + (s21_strlen(dest) - 1);
//  while (n-- > 0 && *src != '\0') {
//    *ch_end_dest++ = *src++;
//  }
//  *ch_end_dest = '\0';  //если не ставить бывает лезет мусор
//  return dest;
//}
//char *s21_strchr(const char *str, int c) {
//  char *res = NULL;
//  while (*str++) {
//    if (*str == c) {
//      res = (char *)str;
//      break;
//    }
//  }
//  return res;
//}
//int s21_strcmp(const char *str1, const char *str2) {
//  for (; *str1 && *str1 == *str2; str1++, str2++)
//    ;
//  return *str1 - *str2;
//}
//int s21_strncmp(const char *str1, const char *str2, size_t n) {
//  for (; *str1 && *str1 == *str2 && n > 0; str1++, str2++, n--)
//    ;
//  return *str1 - *str2;
//}
//char *s21_strcpy(char *dest, const char *src) {
//  char *ch_dest = dest;
//  while (*src != '\0') {
//    *ch_dest++ = *src++;
//  }
//  *ch_dest = '\0';
//  return dest;
//}
//char *s21_strncpy(char *dest, const char *src, size_t n) {
//  char *ch_dest = dest;
//  while (n > 0 && *src != '\0') {
//    *ch_dest++ = *src++;
//    n--;
//  }
//  *ch_dest = '\0';
//  return dest;
//}
//size_t s21_strcspn(const char *str1, const char *str2) {
//  size_t res = 0;
//  for (size_t i = 0; i < s21_strlen(str1); i++) {
//    for (size_t j = 0; j < s21_strlen(str2); j++) {
//      if (str1[i] == str2[j]) {
//        res = i;
//        j = s21_strlen(str2);
//        i = s21_strlen(str1);
//      } else {
//        res = s21_strlen(str1);
//      }
//    }
//  }
//  return res;
//}
//char *s21_strerror(int errnum) {
//  char *res = NULL;
//  if (errnum < 0 || errnum > 134) {       // smenit dla MACA potom
//    printf("Unknown error: %d", errnum);  // zamenit' na s21_sprintf;
//  } else {
//    res = (char *)s21_errlist[errnum];
//  }
//  return res;
//}
//char *s21_strpbrk(const char *str1, const char *str2) {
//  char *res = NULL;
//  for (size_t i = 0; i < s21_strlen(str1); i++) {
//    for (size_t j = 0; j < s21_strlen(str2); j++) {
//      if (str1[i] == str2[j]) {
//        res = (char *)(str1 + i);
//        j = s21_strlen(str2);
//        i = s21_strlen(str1);
//      }
//    }
//  }
//  return res;
//}
//char *s21_strrchr(const char *str, int c) {
//  char *res = NULL;
//  while (*str++) {
//    if (*str == c) {
//      res = (char *)str;
//    }
//  }
//  return res;
//}
//size_t s21_strspn(const char *str1, const char *str2) {
//  size_t res = 0;
//  for (size_t i = 0; i < s21_strlen(str1); i++) {
//    res = 0;
//    for (size_t j = 0; j < s21_strlen(str2); j++) {
//      if ((str1[i] == str2[j]) && i != (s21_strlen(str1) - 1)){
//        break;
//      }
//      if(str1[i] != str2[j]) {
//        res++;
//        if(res == s21_strlen(str2)) {
//          res = i;
//          j = s21_strlen(str2);
//          i = s21_strlen(str1);
//        }
//      }
//      if((str1[i] == str2[j]) && i == (s21_strlen(str1) - 1)){
//        res = s21_strlen(str1) - 1;
//        }
//    }
//  }
//  return res;
//}
//-----------------------------------------------------------------------



//    size_t s21_strlen(const char *str) {
//        size_t len = 0;
//        while (*(str++))
//            ++len;
//        return len;
//    }


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
