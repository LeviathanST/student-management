#include "util.h"

#include <errno.h>
#include <stdio.h>
#include <string.h>

int main() {
  int exit = 0;
  char user_input[20];

  while (exit == 0) {
    printf("SM> ");
    scanf("%s", user_input);

    if (strcmp("hi", user_input) == 0) {
      printf("Hi there!\n");
    } else if (strcmp("exit", user_input) == 0) {
      exit = 1;
      printf("Bye!\n");
    } else {
      print_err("Command not found!");
    }
  }

  if (errno > 0) {
    // Catch the error and print the error message
    print_err(app_strerror(errno));
    return 0;
  }

  return 0;
}
