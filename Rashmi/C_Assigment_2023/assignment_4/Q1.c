#include<stdio.h>
int dis(int*);
int main(){
	int arr[5]={1,2,3};
	printf("The given array:1 2 3\n");
	printf("The reversed array: ");
	dis(arr);
	return 0;
}
int dis(int *p){
	printf("%d",*p);
	if(*p==3){
		return 0;
	}
	dis(p+1);
}
