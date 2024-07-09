/*
write this C program 
Arrange ‘n’ names in alphabetical order (hint: use string handling function-strcpy)
*/

#include <stdio.h>

int main(){
   char string[30][30],temp[30];
   int no, i, j;

   printf("Enter the no of strings:");
   scanf("%d",&no);
    
   printf("\nEnter the strings:");
   for(i=0;i<no; i++){
      gets(string[i]);
   }

   for(i=0;i<no-1;i++){
      for(j=i+1;j<no;j++){
         if(strcmp(string[i],string[j])>0){
            strcpy(temp,string[i]);
            strcpy(string[i],string[j]);
            strcpy(string[j],temp);
         }
      }
   }

   printf("Names in alphabetical order:\n");
    for (i = 0; i < no; i++) {
        printf("%s\n", string[i]);
    }

   return 0;

}








