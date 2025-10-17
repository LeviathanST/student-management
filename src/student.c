#include "student.h"
#include "util.h"

#include <errno.h>
#include <string.h>

void student_new(Student *s, const char *id, const char *name, int birth_year,
                 const char *major) {
  if (strlen(id) > ID_MAX_LENGTH) {
    errno = OVER_MAX_ID_LENGTH;
    return;
  }
  if (strlen(name) > NAME_MAX_LENGTH) {
    errno = OVER_MAX_NAME_LENGTH;
    return;
  }
  if (strlen(major) > MAJOR_MAX_LENGTH) {
    errno = OVER_MAX_MAJOR_LENGTH;
    return;
  }

  strcpy(s->id, id);
  strcpy(s->name, name);
  strcpy(s->major, major);
  s->birth_year = birth_year;
  s->gpa = 0;
}
