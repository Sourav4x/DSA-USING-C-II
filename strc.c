//22051031
#include <stdio.h>
#include <stdlib.h>


struct Student 
{
  int roll;
  char name[50];
  struct Date 
  {
    int dd;
    int mm;
    int yy;
  } dob;
  float marks;
};


void addstudent(struct Student *student) {
  printf("Enter the roll number: ");
  scanf("%d", &student->roll);

  printf("Enter the name: ");
  scanf("%s", student->name);

  printf("Enter the date of birth (dd mm yyyy): ");
  scanf("%d %d %d", &student->dob.dd, &student->dob.mm, &student->dob.yy);

  printf("Enter the marks: ");
  scanf("%f", &student->marks);
}


void displaystudent(struct Student *student)
{
  printf("Roll number: %d\n", student->roll);
  printf("Name: %s\n", student->name);
  printf("Date of birth: %d/%d/%d\n", student->dob.dd, student->dob.mm, student->dob.yy);
  printf("Marks: %.2f\n", student->marks);
}


int main() 
{
  struct Student student;
  int choice;

  do
  {
    printf("\n1. Add student");
    printf("\n2. Display student");
    printf("\n3. Exit");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) 
    {
      case 1:
        addstudent(&student);
        break;
      case 2:
        displaystudent(&student);
        break;
      case 3:
        printf("\nExiting\n");
        break;
      default:
        printf("\nInvalid choice!\n");
    }
  } while (choice != 3);

  return 0;
}