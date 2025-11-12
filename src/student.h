
#ifndef STUDENT_H
#define STUDENT_H

#define MAX 100
#define FILENAME "students.txt"

typedef struct {
  char id[15];
  char name[50];
} Student;

typedef struct {
  int birthYear;
  char major[30];
  float gpa;
  Student s;
} inforStudent;

void clear();
void addInformation(Student *s, inforStudent *i, int *count);
void searchInformation(Student *s, inforStudent *i, int *count);
void changeInformation(Student *s, inforStudent *i, int count);
void deleteInformation(Student *s, inforStudent *i, int *count);
void loadFromFile(Student *s, inforStudent *i, int *count);
void saveToFile(Student *s, inforStudent *i, int count);

#endif
