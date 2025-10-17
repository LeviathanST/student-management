#include "util.h"
#include <stdarg.h>
#include <stdio.h>

void print_err(const char *format, ...) {
  va_list args;
  va_start(args, format);
  printf("ERROR: ");
  vprintf(format, args);
  printf("\n");
  va_end(args);
}

const char *app_strerror(int errno) {
  switch (errno) {
  case 1001:
    return "the name length > the max name length";
  case 1002:
    return "the id length > the max id length";
  case 1003:
    return "the major length > the max major length";
  default:
    return "Unknown error";
  }
}
