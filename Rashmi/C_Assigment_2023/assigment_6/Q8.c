#include<stdio.h>
#include<assert.h>
int main(){
int num=10;
int *ptr=&num;              //assigning num address to pointer variable
//int *ptr=NULL;            // Assert macro will abort if the condition found is false
assert(ptr!=NULL);          // using assert macro
printf("OUTPUT= %d\n",*ptr);
return 0;
}
