// Code to Find the Largest of 2 Numbers

#include<stdio.h>

int main(){
int a, b;
printf("Enter 2 numbers\n");
scanf("%d %d",&a,&b);

if(a > b){
    printf("Large is %d\t", a);
}
else{
   printf("Large is %d\t", b);
}

return 0;

}
