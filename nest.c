#include <stdio.h>
#include <stdlib.h>

// Define the Student structure
struct Student {
  int roll_number;
  char name[50];
  struct Date {
    int day;
    int month;
    int year;
  } dob;
  float marks;
};

// Function to add a student
void add_student(struct Student *student) {
  printf("Enter the roll number: ");
  scanf("%d", &student->roll_number);

  printf("Enter the name: ");
  scanf("%s", student->name);

  printf("Enter the date of birth (dd mm yyyy): ");
  scanf("%d %d %d", &student->dob.day, &student->dob.month, &student->dob.year);

  printf("Enter the marks: ");
  scanf("%f", &student->marks);
}

// Function to display the student details
void display_student(struct Student *student) {
  printf("Roll number: %d\n", student->roll_number);
  printf("Name: %s\n", student->name);
  printf("Date of birth: %d/%d/%d\n", student->dob.day, student->dob.month, student->dob.year);
  printf("Marks: %.2f\n", student->marks);
}

// Menu-driven interface
int main() {
  struct Student student;
  int choice;

  do {
    printf("\n\n1. Add student");
    printf("\n2. Display student");
    printf("\n3. Exit");

    printf("\n\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        add_student(&student);
        break;
      case 2:
        display_student(&student);
        break;
      case 3:
        printf("\nExiting...\n");
        break;
      default:
        printf("\nInvalid choice!\n");
    }
  } while (choice != 3);

  return 0;
}