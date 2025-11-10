/* Define a Student structure having members name (which is char array),
 cgpa (which is float type),
 birthdate (which is a pointer to a structure date having 3 integer members 
 for storing day, month,
 and year), admission_date (which is pointer to a structure date having 3
 integer members for storing
 day, month, and year), address (which is character array). 
 Write a C program to Create an array of
 structure of type Student to store details of 'n' students. 
 Read the details of 'n' students and display
 the same in the main function. Define a function Age which takes a pointer 
 to the structure Student
 and calculates the age of the student during admission time and displays 
 the same.Test this
 function from the main.*/

 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>

 struct Date
 {
    int day;
    int month;
    int year;
 };

 struct Student
 {
    char name[50];
    float cgpa;
    struct Date* birthdate;
    struct Date* admission;
    char address[50];
 };

 void age(struct Student* s)
 {
    int age = s->admission->year - s->birthdate->year;
    printf("Age : %d\n",age);
 }

 int main()
 {
   printf("Enter no of students : ");
   int n;
   scanf("%d",&n);
   char name[50];
    float cgpa;
    struct Date* birthdate;
    struct Date* admission;
    struct Student s[n];
    char address[50];
   for(int i=0;i<n;i++)
   {
      printf("Enter name : ");
      scanf(" %[^\n]",s[i].name);
      printf("Enter cgpa : ");
      scanf("%f",&s[i].cgpa);

      s[i].birthdate = (struct Date *)malloc(sizeof(struct Date));
      s[i].admission = (struct Date *)malloc(sizeof(struct Date));

      printf("Enter birth date day,month,year : ");
      scanf("%d %d %d",&s[i].birthdate->day,&s[i].birthdate->month,&s[i].birthdate->year);

      printf("Enter admission date day,month,year : ");
      scanf("%d %d %d",&s[i].admission->day,&s[i].admission->month,&s[i].admission->year);

      printf("Enter address : ");
      scanf(" %[^\n]",s[i].address);
   }

   for(int i=0;i<n;i++)
   {
      printf("\nStudent %d\n", i + 1);
        printf("Name: %s\n", s[i].name);
        printf("CGPA: %.2f\n", s[i].cgpa);
        printf("Birthdate: %d-%d-%d\n", s[i].birthdate->day, s[i].birthdate->month, s[i].birthdate->year);
        printf("Admission: %d-%d-%d\n", s[i].admission->day, s[i].admission->month, s[i].admission->year);
        printf("Address: %s\n", s[i].address);
        age(&s[i]);
        free(s[i].birthdate);
        free(s[i].admission);
   }

   return 0;
 }