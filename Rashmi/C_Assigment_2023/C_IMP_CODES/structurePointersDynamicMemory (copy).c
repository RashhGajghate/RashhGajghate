#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>	
int n;
struct form{
	char *Name;			//char name[30]
	int age;
	char *City;
	};
	
	
int main(){	
	int n;
	struct form f[n];
	struct form *p;
	p=f;
	printf("Enter the number of forms required");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		(p+i)->Name=(char*)malloc(30*sizeof(char));
		(p+i)->City=(char*)malloc(30*sizeof(char));
	
			printf(" ********Student-%d Input ******\n",i+1);
			printf("Enter the name:");
			scanf("%s",(p+i)->Name);
			printf("Enter the age:");
			scanf("%d",&f[i].age);
			printf("Enter the City:");			
			scanf("%s",(p+i)->City);
		}
	for(int i=0;i<n;i++){
			printf("\n ********Student-%d Output ******\n",i+1);	
			printf("name:%s\n",(p+i)->Name);
			printf("City:%s\n",(p+i)->City);
			printf("Age:%d\n",f[i].age);
			}
	free(p->Name);
	free(p->City);		
}			
