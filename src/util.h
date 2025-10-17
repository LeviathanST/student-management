#ifndef UTIL_H
#define UTIL_H
#endif

enum AppErrorCode {
  OVER_MAX_NAME_LENGTH = 1001,
  OVER_MAX_ID_LENGTH = 1002,
  OVER_MAX_MAJOR_LENGTH = 1003,
};

void print_err(const char *format, ...);
void print_info(const char *format, ...);
void print_debug(const char *format, ...);

const char *app_strerror(int errno);
