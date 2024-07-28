#include <stdio.h>

int main() {

   int mark;    
   char grade;  

   printf("Enter your mark: ");
   scanf("%d", &mark);

   switch (mark) {

   case 100: // control falls through until a break word is met
   case 90: // control falls through until a break word is met
   case 80:
      grade = 'A'; // Marks 80, 90, 100 get an 'A'
      break;

   case 70: // control falls through until a break word is met
   case 60:
      grade = 'B'; // Marks 60, 70 get a 'B'
      break;

   case 50:
      grade = 'C'; // Mark 50 gets a 'C'
      break;

   case 40:
      grade = 'D'; // Mark 40 gets a 'D'
      break;

   default:
      grade = 'F'; // Any other mark gets an 'F'
      break;

   }

   printf("The grade is %c\n", grade);

   return 0;
 
}
