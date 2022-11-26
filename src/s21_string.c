#include <stdio.h>

typedef long unsigned s21_size_t;

s21_size_t s21_strlen(const char *str) {
    s21_size_t len = 0;
    for(; str[len]; len++);
    return len + 1;
}
void *s21_memchr(const void *str, int c, s21_size_t n) {
     unsigned char *ch = (unsigned char *)str;
     while(n > 0) {
        if(*ch == c) {
            return ch;
        }
        ch++;
        n--;
    }
    return NULL;
}
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
    const unsigned char *ch1 = str1;
    const unsigned char *ch2 = str2;
    while (n > 0) {
        if(*ch1 != *ch2) {
            return (*ch1 - *ch2);
        }
        ch1++;
        ch2++;
        n--;
    }
    return 0;
}
int main() {
    //s21_memchr test
    char str[] = "1234567890";
    char c = '3';
    s21_size_t n = s21_strlen(str);
    char *memchr_res;
    memchr_res = s21_memchr(str, c, n);
    printf("adress return = %s\n", memchr_res);
    //s21_memcmp test
    char str1[] = "1112151515";
    char str2[] = "1112131415";
    char str3[] = "1112131415";
    int memcmp_res = 0;
    s21_size_t n1 = s21_strlen(str2);
    if(s21_strlen(str1) >= s21_strlen(str2)) {
        n1 = s21_strlen(str1);
    }
    memcmp_res = s21_memcmp(str1, str2, n1);
    printf("equals srt = %d\n", memcmp_res);
    memcmp_res = s21_memcmp(str3, str2, n1);
    printf("equals srt = %d\n", memcmp_res);
    
    return 0;
}
