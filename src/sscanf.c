#include "sscanf.h"

#include <stdio.h>

struct Buffer {
  int b_int;
  char b_char;
  short int b_short_int;
  long int b_long_int;
  long double b_long_double;
  float b_float;
  double b_double;
};

_bool is_digit(char c) { return c <= '9' && c >= '0' ? TRUE : FALSE; }

int s21_skip(const char **string, const char **format) {
  int count = 0;
  while (**string == **format) {
    (*string)++;
    (*format)++;
    count++;
  }
  return count;
}

int skip_space(const char *str) {
  int count = 0;
  while (*str == ' ') {
    count++;
  }
  return count;
}

void print_pattern(struct Pattern patt) {
  printf("record: %s\n", patt.recording == TRUE ? "TRUE" : "FALSE");
  printf("width: %d\n", patt.width);
  printf("size_var: ");
  switch (patt.size_var) {
    case L_SIZE:
      printf("l\n");
      break;
    case L_BIG_SIZE:
      printf("L\n");
      break;
    case H_SIZE:
      printf("h\n");
      break;
    case NO_SIZE:
      printf("no\n");
      break;
    default:
      printf("ERROR\n");
      break;
  }
  printf("spec: ");
  switch (patt.spec) {
    case C_SPEC:
      printf("c\n");
      break;
    case D_SPEC:
      printf("d\n");
      break;
    case I_SPEC:
      printf("i\n");
      break;
    case E_SPEC:
      printf("e\n");
      break;
    case E_BIG_SPEC:
      printf("E\n");
      break;
    case F_SPEC:
      printf("f\n");
      break;
    case G_SPEC:
      printf("g\n");
      break;
    case G_BIG_SPEC:
      printf("G\n");
      break;
    case O_SPEC:
      printf("o\n");
      break;
    case S_SPEC:
      printf("s\n");
      break;
    case U_SPEC:
      printf("u\n");
      break;
    case X_SPEC:
      printf("x\n");
      break;
    case X_BIG_SPEC:
      printf("X\n");
      break;
    case P_SPEC:
      printf("p\n");
      break;
    case N_SPEC:
      printf("n\n");
      break;
    case DEF_SPEC:
      printf("%%\n");
      break;
    case ERROR_SPEC:
      printf("no specifier\n");
      break;
    default:
      printf("ERROR\n");
      break;
  }
}

int get_pattern(const char *format, struct Pattern *patt) {
  int displacement = 0;
  // displacement += skip_space(format);
  // format += displacement;
  if (*format == '%') {
    format++;
    displacement++;
    if (*format == '%') {
      patt->spec = DEF_SPEC;
      displacement++;
    } else {
      if (*format == '*') {
        patt->recording = FALSE;
        format++;
        displacement++;
      } else {
        patt->recording = TRUE;
      }
      if (is_digit(*format) == TRUE) {
        int size = 0;
        while (is_digit(*format) == TRUE) {
          size = *format - '0' + size * 10;
          format++;
          displacement++;
        }
        patt->width = size;
      } else {
        patt->width = 0;
      }
      switch (*format) {
        case 'l':
          patt->size_var = L_SIZE;
          format++;
          displacement++;
          break;
        case 'L':
          patt->size_var = L_BIG_SIZE;
          format++;
          displacement++;
          break;
        case 'h':
          patt->size_var = H_SIZE;
          format++;
          displacement++;
          break;
        default:
          patt->size_var = NO_SIZE;
          break;
      }
      switch (*format) {
        case 'c':
          patt->spec = C_SPEC;
          displacement++;
          break;
        case 'd':
          patt->spec = D_SPEC;
          displacement++;
          break;
        case 'i':
          patt->spec = I_SPEC;
          displacement++;
          break;
        case 'e':
          patt->spec = E_SPEC;
          displacement++;
          break;
        case 'E':
          patt->spec = E_BIG_SPEC;
          displacement++;
          break;
        case 'f':
          patt->spec = F_SPEC;
          displacement++;
          break;
        case 'g':
          patt->spec = G_SPEC;
          displacement++;
          break;
        case 'G':
          patt->spec = G_BIG_SPEC;
          displacement++;
          break;
        case 'o':
          patt->spec = O_SPEC;
          displacement++;
          break;
        case 's':
          patt->spec = S_SPEC;
          displacement++;
          break;
        case 'u':
          patt->spec = U_SPEC;
          displacement++;
          break;
        case 'x':
          patt->spec = X_SPEC;
          displacement++;
          break;
        case 'X':
          patt->spec = X_BIG_SPEC;
          displacement++;
          break;
        case 'p':
          patt->spec = P_SPEC;
          displacement++;
          break;
        case 'n':
          patt->spec = N_SPEC;
          displacement++;
          break;
        default:
          displacement = 0;
          patt->spec = ERROR_SPEC;
          break;
      }
    }
  }
  return displacement;
}

int s21_sscanf(const char *string, const char *format, ...) {
  va_list scanf_arg;
  va_start(scanf_arg, format);
  int scanf_argc = va_s21_sscanf(string, format, scanf_arg);
  va_end(scanf_arg);
  return scanf_argc;
}

int read_double(const char *string, struct Pattern patt, long double *d) {
  int displacement = 0;
}

int read_string(const char *string, struct Pattern patt, struct Buffer *buff) {
  int displacement = 0;
  switch (patt.spec) {
    case C_SPEC:

      break;
    case D_SPEC:

      break;
    case E_SPEC:
    case E_BIG_SPEC:
    case F_SPEC:
    case G_SPEC:
    case G_BIG_SPEC:
      switch (patt.size_var) {
        case L_SIZE:
          double d;
          displacement = read_double(string, patt, &d);
          buff->b_double = d;
          break;
        case L_BIG_SIZE:
          long double ld;
          displacement = read_double(string, patt, &ld);
          buff->b_long_double = ld;
          break;
        default:
          float f;
          displacement = read_double(string, patt, &f);
          buff->b_float = f;
          break;
      }
      break;
    default:
      break;
  }
}

int va_s21_sscanf(const char *string, const char *format, va_list scanf_arg) {
  int counter = 0;
  int form_diss = 0;
  int str_diss = 0;
  int form_diss_global = 0;
  int str_diss_global = 0;
  // double f;
  s21_skip(&string, &format);
  form_diss_global = skip_space(format);
  /*
  for (const char *c = format; *c;) {
    // if (*c != '%') {
    //   printf("%c\n", *c);
    //   continue;
    // }
    switch (*c) {
      case 'd':
        // printf("d counter: %d %c\n", counter, *c);
        // d = va_arg(factor, int);
        int *d = (int *)va_arg(scanf_arg, int *);
        // printf("%d\n", *d);
        *d = (int)*string - '0';
        string++;
        format += 2;
        s21_skip(&string, &format);
        c = format;
        break;
      case 'f':
        // f = va_arg(scanf_arg, float);
        //  printf("%f\n", f);
        break;
      case 'c':
        char *simbol = (char *)va_arg(scanf_arg, char *);
        // printf("%c\n", f);
        *simbol = *string;
        break;
      case '%':

        // printf("%% counter: %d %c\n", counter, *c);
        c++;
        break;
      default:
        // printf("def counter: %d %c\n", counter, *c);
        c++;
    }
    // printf("bs counter: %d %c\n", counter, *c);
    counter++;
  }
  */
  struct Pattern patt;
  struct Buffer buff;
  while ((form_diss = get_pattern(format + form_diss_global, &patt)) > 0 &&
         (str_diss = read_string(string + str_diss_global, patt, &buff)) > 0) {
    switch (patt.spec) {
      case C_SPEC:
        char *c = (char *)va_arg(scanf_arg, char *);
        *c = buff.b_char;
        break;
      case D_SPEC:
        int *i = (int *)va_arg(scanf_arg, int *);
        *i = buff.b_int;
        break;
      case E_SPEC:
      case E_BIG_SPEC:
      case F_SPEC:
      case G_SPEC:
      case G_BIG_SPEC:
        switch (patt.size_var) {
          case L_SIZE:
            double *d = (double *)va_arg(scanf_arg, double *);
            *d = buff.b_double;
            break;
          case L_BIG_SIZE:
            long double *ld = (long double *)va_arg(scanf_arg, long double *);
            *ld = buff.b_long_double;
            break;
          default:
            float *f = (float *)va_arg(scanf_arg, float *);
            *f = buff.b_float;
            break;
        }
        break;
      default:
        break;
    }
  }
  va_end(scanf_arg);
  return 0;
}

int main(void) {
  // int age = 0, wei = 0;
  // s21_sscanf("Age:1 \t Weight:2", "Age:%d \t Weight:%d", &age, &wei);
  struct Pattern patt;
  // print_pattern(patt);
  const char *str = "%l%";

  get_pattern(str, &patt);
  print_pattern(patt);
  while (*str != '\0') {
    printf("%c", *str++);
  }
  return 0;
}
