#include "student.h"
#include <stdio.h>
#include <stdlib.h>

void clear() {
  while (getchar() != '\n')
    ;
}

int main() {
  Student s[MAX];
  int click;
  int choice;
  int count = 0;
  inforStudent i[MAX];

  loadFromFile(s, i, &count);

  printf("===========MENU===========\n");
  printf("1.Add information student\n");
  printf("2.Search information student\n");
  printf("3.Change information student\n");
  printf("4.Delete information student\n");
  printf("0.Exit\n");

next:
  printf("-------------------------\n");
  printf("Choose your option: ");
  scanf("%d", &click);
  clear();

  switch (click) {
  case 1:
    addInformation(s, i, &count);
    saveToFile(s, i, count);
    printf("Your information had saved\n");
    printf("Do you want to choose other option\n");
    printf("1. Yes\n2. No\n");
    printf("Select:");
    scanf("%d", &choice);
    clear();
    if (choice == 1) {
      goto next;
    } else if (choice == 2) {
      printf("Thank you for your participate\n");
    } else {
      printf("The choice not exist\n");
      goto next;
    }
    break;
  case 2:
    searchInformation(s, i, &count);
    printf("Do you want to choose other option\n");
    printf("1. Yes\n2. No\n");
    printf("Select:");
    scanf("%d", &choice);
    clear();
    if (choice == 1) {
      goto next;
    } else if (choice == 2) {
      printf("Thank you for your participate\n");
    } else {
      printf("The choice not exist\n");
      goto next;
    }
    break;
  case 3:
    changeInformation(s, i, count);
    saveToFile(s, i, count);
    printf("Do you want to choose other option\n");
    printf("1. Yes\n2. No\n");
    printf("Select:");
    scanf("%d", &choice);
    clear();
    if (choice == 1) {
      goto next;
    } else if (choice == 2) {
      printf("Thank you for your participate\n");
    } else {
      printf("The choice not exist\n");
      goto next;
    }
    break;
  case 4:
    deleteInformation(s, i, &count);
    saveToFile(s, i, count);
    printf("Do you want to choose other option\n");
    printf("1. Yes\n2. No\n");
    printf("Select:");
    scanf("%d", &choice);
    clear();
    if (choice == 1) {
      goto next;
    } else if (choice == 2) {
      printf("Thank you for your participate\n");
    } else {
      printf("The choice not exist\n");
      goto next;
    }
    break;
  case 0:
    printf("Do you want to get out of there\n");
    printf("1.Yes\n2.No\n");
    printf("Select:");
    scanf("%d", &choice);
    clear();
    if (choice == 2) {
      goto next;
    } else if (choice == 1) {
      printf("Thank you for your participate\n");
    } else {
      printf("The choice not exist\n");
      goto next;
    }
    break;
  default:
    printf("invalid selection\n");
  }
  system("Pause");
  return 0;
}
