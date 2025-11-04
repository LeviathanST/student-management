#include "student.h"
#include "util.h"

#include <errno.h>
#include <stdio.h>
#include <string.h>

#define FILE_STORAGE_PATH "db/student.db"

void createFileStorageIfNotExists() {
  FILE *ptr = fopen(FILE_STORAGE_PATH, "a");
  if (ptr == NULL) {
    errno = OPEN_FILE_STORAGE_FAILED;
    return;
  }
  fclose(ptr);
}

void writeToFile(Student *s) {
  createFileStorageIfNotExists();

  FILE *f_ptr = fopen(FILE_STORAGE_PATH, "a");
  if (f_ptr == NULL) {
    errno = OPEN_FILE_STORAGE_FAILED;
    return;
  }

  int rc = fprintf(f_ptr, "%-*s|%-*s|%-*s|%d|%.2f\n", ID_MAX_LENGTH, s->id,
                   NAME_MAX_LENGTH, s->name, MAJOR_MAX_LENGTH, s->major,
                   s->birth_year, s->gpa);

  if (rc < 0) {
    errno = WRITE_TO_FILE_STORAGE_FAILED;
    fclose(f_ptr);
    return;
  }

  if (fflush(f_ptr) != 0) {
    errno = WRITE_TO_FILE_STORAGE_FAILED;
    fclose(f_ptr);
    return;
  }

  if (fclose(f_ptr) != 0) {
    errno = CLOSE_FILE_STORAGE_FAILED;
  }
}

void getFromFile(Student *s, int id);

void student_new() {
  Student t;

  printf("ID: ");
  scanf("%s", t.id);
  if (strlen(t.id) > ID_MAX_LENGTH) {
    errno = OVER_MAX_ID_LENGTH;
    return;
  }

  printf("Name: ");
  scanf("%s", t.name);
  if (strlen(t.name) > NAME_MAX_LENGTH) {
    errno = OVER_MAX_NAME_LENGTH;
    return;
  }

  printf("Major: ");
  scanf("%s", t.major);
  if (strlen(t.major) > MAJOR_MAX_LENGTH) {
    errno = OVER_MAX_MAJOR_LENGTH;
    return;
  }
  printf("Birth year: ");
  scanf("%d", &t.birth_year);

  t.gpa = 0;
  writeToFile(&t);
}
