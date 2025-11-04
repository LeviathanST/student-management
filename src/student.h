#ifndef STUDENT_H
#define STUDENT_H

#define ID_MAX_LENGTH 15
#define NAME_MAX_LENGTH 50
#define MAJOR_MAX_LENGTH 30

typedef struct {
  char id[ID_MAX_LENGTH];
  char name[NAME_MAX_LENGTH];
  int birth_year;
  char major[MAJOR_MAX_LENGTH];
  float gpa;
} Student;

/// Default GPA is `0`.
void student_new();

/// Get a student by ID from the file.
Student student_get(char id[15]);

/// Get all students from the file.
/// @return a student array.
Student *student_getAll();

/// Write a student to the file.
void student_add(Student s);

/// Update optional information fields of a student.
/// Assign `NULL` if that field don't need to update.
void student_update(Student s, const char *name, const int *birth_year,
                    const char *major);

enum SortType { inc, desc };

/// @return a sorted student array .
Student *student_getAllAndSort(enum SortType type);

enum SearchBy { ident, name };

/// Search a student `by` name or ID.
/// @return a student.
/// @return `NULL` value if the student not found.
Student *student_search(enum SearchBy by, const char *value);

#endif
