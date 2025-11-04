#include "student.h"
#include "util.h"

#include <errno.h>
#include <stdio.h>
#include <string.h>

int exec_cmd(char cmd[20]) {
  if (strcmp("hi", cmd) == 0) {
    printf("Hi there!\n");
  } else if (strcmp("exit", cmd) == 0) {
    return 1;
    printf("Bye!\n");
  } else if (strcmp("write", cmd) == 0) {
    student_new();
  } else {
    print_err("Command not found!");
  }
  return 0;
}

int main() {
  int exit = 0;
  char user_input[20];

  while (exit == 0) {
    printf("SM> ");
    scanf("%s", user_input);

    exit = exec_cmd(user_input);
  }

  if (errno > 0) {
    // Catch the error and print the error message
    print_err(app_strerror(errno));
    return 0;
  }

  return 0;
}
