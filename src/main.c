#include "student.h"
#include "util.h"
#include <errno.h>
#include <stdio.h>

int main() {
  Student s;
  student_new(&s, "hehe", "test", 2005, "SE");

  if (errno > 0) {
    print_err(app_strerror(errno));
    return 0;
  }

  printf("ID %s\n", s.id);
  printf("name %s\n", s.name);
  return 0;
}
