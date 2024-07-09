/*
write this C program
Check whether the given string is a palindrome or not.
*/

#include <stdio.h>

int main() {

   char str[30];
   int i, j, n, flag=1;

   printf("\nEnter the string:");
   gets(str);

   for(i=0;str[i]!='\0';i++){
      n=i; //n=strlen(str);
      for(i=0;i<n/2;i++){
         if(str[i]!=str[n-i-1]){
           flag=0;
           break; 
         }
      }
   }

   if(flag==1)
      printf("\nIts a Palindrome");
   else
      printf("\nNot a Palindrome");

   return 0;

}
   

  

