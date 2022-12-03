#include <stdio.h>

int main() {
  // double num_d = 1.1;
  //  float num_f = 1.2;
  int num_i = 1;
  // char c = 'q';
  sscanf(" Age:   123456", "  Age: %d", &num_i);
  // long long int int_ll = 5;
  printf("%d\n", num_i);

  sscanf("Age: 123456", "Age: %5d", &num_i);  // ширина
  printf("%d\n", num_i);

  // точность не работает для sscanf

  sscanf("Age: 777  d 666", "Age: %*d d %d", &num_i);  // подавляет запись
  printf("%d\n", num_i);

  long int num_li = 1;
  sscanf("Age: 777666", "Age: %ld ", &num_li);  // long int
  printf("%ld\n", num_li);

  long long int num_lli = 1;
  sscanf("Age: 777666", "Age: %lld", &num_lli);  // long long int
  printf("%lld\n", num_lli);

  int num_i16 = 1;
  sscanf("Age: -0x55f5", "Age: %x", &num_i16);  // int_16 [0-f/F]
  printf("0x %x\n", num_i16);

  sscanf("Age: 0567", "Age: %o", &num_i16);  // int_8 [0-7]
  printf("0 %o %d\n\n", num_i16, num_i16);

  long double num_ld = 1;
  sscanf("Age: 776676.78989", "Age: %20Lf", &num_ld);  // long double
  printf("%Lf\n", num_ld);

  double num_d = 1.0;
  sscanf("Age: 777666", "Age: %lf", &num_d);  // double
  printf("%lf\n", num_d);

  sscanf("Age: -777666.789", "Age: %lf", &num_d);  // double
  printf("%lf\n", num_d);

  int n = 0;
  sscanf("Age: 777a666", "Age: %n%d", &num_i, &n);  // %n
  printf("%d %d\n", num_i, n);
  num_i = -1;
  sscanf("Age: +775a666", "Age: %1u", &num_i);  // %n
  printf("%d\n", num_i);
  char c;
  sscanf("Age:4 -775a666", "Age:%c", &c);  // %n
  printf("%c\n", c);
  char str[20];
  sscanf("A%ge:0123456789012345678 -775 a 666", "A%%ge:%2s",
         str);  // %n
  printf("%s\n", str);

  short int num_si = 1;
  sscanf("Age: 123456789012345678", "Age: %hd ",
         &num_si);  // short int
  printf("%hd\n", num_si);

  long int shli = 123456789012345678;
  short int shi = shli;
  printf("%hd\n", shi);
  short int o1, o3, o5;
  sscanf("+36 0x123 -123", "%hx %hx %hx", &o1, &o3, &o5);
  printf("%hx %hx %hx\n", o1, o3, o5);
  return 0;
}