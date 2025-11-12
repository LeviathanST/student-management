#include "util.h"
#include <stdarg.h>
#include <string.h>

void swap1(int *birthYear, int *newBirthyear) {
  int temp = *birthYear;
  *birthYear = *newBirthyear;
  *newBirthyear = temp;
}
void swap2(char major[], char newMajor[]) {
  char word[30];
  strcpy(word, major);
  strcpy(major, newMajor);
  strcpy(newMajor, word);
}
void swap3(float *gpa, float *newGpa) {
  float number = *gpa;
  *gpa = *newGpa;
  *newGpa = number;
}
