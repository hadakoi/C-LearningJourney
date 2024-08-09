#include <stdio.h>


struct student {
    int rollno;
    int age;
    char name[10];
    float height;
};

int main() {
    
    struct student s1, s2, s3;

    printf("Enter details for student 1:\n");
    printf("Roll Number: ");
    scanf("%d", &s1.rollno);
    printf("Age: ");
    scanf("%d", &s1.age);
    printf("Name: ");
    scanf("%s", s1.name);
    printf("Height: ");
    scanf("%f", &s1.height);


    printf("Enter details for student 2:\n");
    printf("Roll Number: ");
    scanf("%d", &s2.rollno);
    printf("Age: ");
    scanf("%d", &s2.age);
    printf("Name: ");
    scanf("%s", s2.name);
    printf("Height: ");
    scanf("%f", &s2.height);

    printf("Enter details for student 3:\n");
    printf("Roll Number: ");
    scanf("%d", &s3.rollno);
    printf("Age: ");
    scanf("%d", &s3.age);
    printf("Name: ");
    scanf("%s", s3.name);
    printf("Height: ");
    scanf("%f", &s3.height);

    printf("\nDetails of student 1:\n");
    printf("Roll Number: %d\n", s1.rollno);
    printf("Age: %d\n", s1.age);
    printf("Name: %s\n", s1.name);
    printf("Height: %f\n", s1.height);

    printf("\nDetails of student 2:\n");
    printf("Roll Number: %d\n", s2.rollno);
    printf("Age: %d\n", s2.age);
    printf("Name: %s\n", s2.name);
    printf("Height: %f\n", s2.height);

    printf("\nDetails of student 3:\n");
    printf("Roll Number: %d\n", s3.rollno);
    printf("Age: %d\n", s3.age);
    printf("Name: %s\n", s3.name);
    printf("Height: %f\n", s3.height);

    return 0;
    
}

