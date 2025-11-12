#include "student.h"
#include "util.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>

// TODO: Implementation
void writeToFile(Student s);
void getFromFile(int id);

void addInformation(Student *s, inforStudent *i, int *count) {
  if (*count < MAX) {
    printf("Enter your name: ");
    scanf(" %49[^\n]", s[*count].name);

    printf("Enter your id: ");
    scanf(" %14[^\n]", s[*count].id);
    clear();

    printf("Enter your birth year in here: ");
    scanf("%d", &i[*count].birthYear);
    clear();

    printf("Enter your major in here: ");
    scanf("%s", i[*count].major);
    clear();

    int math;
    int english;
    int history;
    printf("Enter your mark in here: \n");
    printf("Math mark: ");
    scanf("%d", &math);
    clear();
    printf("English mark: ");
    scanf("%d", &english);
    clear();
    printf("History mark: ");
    scanf("%d", &history);
    clear();

    i[*count].gpa = (math + english + history) / 3.0;
    printf("Your GPA mark is %.2f\n", i[*count].gpa);
    (*count)++;
  } else {
    printf("List full\n");
  }
}
void searchInformation(Student *s, inforStudent *i, int *count) {
  int choose;
  char searchName[50];
  char searchId[15];
  int found = 0;

going:
  printf("---------------------------\n");
  printf("You want to search by\n");
  printf("1.Follow name\n");
  printf("2.Follow id\n");
  printf("Choose: ");
  scanf("%d", &choose);
  clear();

  if (choose == 1) {
    printf("Input your name: ");
    scanf("%49[^\n]", &searchName);
    for (int j = 0; j < *count; j++) {
      if (strcmp(searchName, s[j].name) == 0) {
        printf("%s have a birth year:%d\n", s[j].name, i[j].birthYear);
        printf("Your major:%s\n", i[j].major);
        printf("Your gpa mark:%.2lf\n", i[j].gpa);
        found = 1;
        break;
      }
    }
    if (!found) {
      printf("Your name couldn't have founded\n");
      return;
    }
  } else if (choose == 2) {
    printf("Input your id: ");
    scanf("%14[^\n]", &searchId);
    for (int j = 0; j < *count; j++) {
      if (strcmp(searchId, s[j].id) == 0) {
        printf("%s have a birth year:%d\n", s[j].name, i[j].birthYear);
        printf("Your major:%s\n", i[j].major);
        printf("Your gpa mark:%.2lf\n", i[j].gpa);
        found = 1;
        break;
      }
    }
    if (!found) {
      printf("Your Id couldn't have founded\n");
      return;
    }
  } else {
    printf("Wrong input\n");
    printf("Please check again\n");
    goto going;
  }
}
void changeInformation(Student *s, inforStudent *i, int count) {
  char searchId[15];
  int found = -1;
  char option[30];
  int newBirthyear;
  char newMajor[30];
  float newGpa;
  int math;
  int english;
  int history;

  if (count == 0) {
    printf("No student information available to change\n");
    return;
  }

  printf("Enter the student ID you want to change: ");
  scanf(" %14[^\n]", searchId);
  clear();

  for (int j = 0; j < count; j++) {
    if (strcmp(searchId, s[j].id) == 0) {
      found = j;
      break;
    }
  }
  if (found == -1) {
    printf("Student with ID %s not found.\n", searchId);
    return;
  }

move:
  printf("----------------------------\n");
  printf("These are key words you should input\n");
  printf("Year or Major or GPA mark\n");
  printf("Please choose the file you want to change: ");
  scanf("%s", &option);
  clear();

  switch (*option) {
  case 'Y':
    printf("Please enter your new birth year: ");
    scanf("%d", &newBirthyear);
    clear();
    swap1(&i[found].birthYear, &newBirthyear);
    printf("You just input: %d\n", i[found].birthYear);
    break;
  case 'M':
    printf("Please enter your new major: ");
    scanf("%s", &newMajor);
    clear();
    swap2(i[found].major, newMajor);
    printf("You just input: %d\n", i[found].major);
    break;
  case 'G':
    printf("Enter your mark in here: \n");
    printf("Math mark: ");
    scanf("%d", &math);
    clear();
    printf("English mark: ");
    scanf("%d", &english);
    clear();
    printf("History mark: ");
    scanf("%d", &history);
    clear();

    newGpa = (math + english + history) / 3.0;
    swap3(&i[found].gpa, &newGpa);
    printf("You just input: %.2lf\n", i[found].gpa);
    break;
  default:
    printf("Wrong input\n");
    printf("Please check again\n");
    goto move;
  }
  printf("Change information completed successfully\n");
}
void deleteInformation(Student *s, inforStudent *i, int *count) {
  char deleteId[15];
  int found = -1;
  char confirm;

  if (*count == 0) {
    printf("Not information student to delete\n");
    return;
  }

  printf("Input your student ID you want to delete: ");
  scanf("%14[^\n]", &deleteId);
  clear();

  for (int j = 0; j < *count; j++) {
    if (strcmp(deleteId, s[j].id) == 0) {
      found = j;
      break;
    }
  }
  if (found == -1) {
    printf("Student with ID %s not found\n", deleteId);
    return;
  }

  printf("Are you sure to delete that student %s ? (Y/N): ", s[found].name);
  scanf("%c", &confirm);
  clear();

  if (toupper(confirm) != 'Y') {
    printf("Canceled delete\n");
    return;
  }

  for (int j = 0; j < *count - 1; j++) {
    s[j] = s[j + 1];
    i[j] = i[j + 1];
  }
  (*count)--;
  printf("Student information deleted successfully\n");
}
void loadFromFile(Student *s, inforStudent *i, int *count) {
  FILE *f = fopen("students.txt", "r");
  if (f == NULL) {
    f = fopen("students.txt", "w");
    if (f == NULL) {
      printf("Error: Cannot create data file!\n");
      return;
    }
    fclose(f);
    printf("Created new data file: students.txt\n");
    *count = 0;
    return;
  }
  *count = 0;
  while (fscanf(f, "%14[^|]|%49[^|]|%d|%29[^|]|%f\n", s[*count].id,
                s[*count].name, &i[*count].birthYear, i[*count].major,
                &i[*count].gpa) == 5) {
    i[*count].s = s[*count];
    (*count)++;
  }

  fclose(f);
  printf("Loaded %d student(s) from file.\n", *count);
}
void saveToFile(Student *s, inforStudent *i, int count) {
  FILE *f = fopen("students.txt", "w");
  if (f == NULL) {
    printf("Error: Cannot open file for writing!\n");
    return;
  }

  for (int j = 0; j < count; j++) {
    fprintf(f, "%s|%s|%d|%s|%.2f\n", s[j].id, s[j].name, i[j].birthYear,
            i[j].major, i[j].gpa);
  }

  fclose(f);
  printf("Data saved successfully to students.txt!\n");
}
