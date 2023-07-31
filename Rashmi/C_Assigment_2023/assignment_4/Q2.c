#include<stdio.h>
#include<string.h>
void rev(char *);
int main(){
    char arr[10];
    int i;
    printf("Enter a string you want to reverse: ");
    scanf("%s",arr);         //string array to reverse
    printf("The reverse string : ");
    rev(arr);
}
void rev(char *ptr){
    if(*ptr=='\0'){           //return from the end
        return;
    }
    rev(++ptr);            // call until null
    printf("%c",*(ptr-1));   //decrement ptr due to previous
    
}
