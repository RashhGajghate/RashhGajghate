#include<stdio.h>
int main(){
int a[3][3];
int sum =0;
printf("enter elements of first matrix");

for(int i=0 ;i<3;i++){
   for(int j=0;j<3;j++){
   scanf("%d",&a[i][j]);
   }
  }


for(int i=0 ;i<3;i++){
   for(int j=0;j<3;j++){
   printf("%d  ",a[i][j]);
    sum = sum+a[i][j];
   } 
   printf("\n");
  }

printf("\n");
int b[3][3];
for(int i=0 ;i<3;i++){                                    
   for(int j=1;j<3;j++){
	   if(i==j ){
	    printf("%d  ",b[i][j]=1);
	   }
	   else{
                 printf("%d  ",0);
   }      
}
printf("\n");
}

for(int i=0 ;i<3;i++){
   for(int j=0;j<3;j++){
	   if(a[i][j]=b[i][j] && sum==3){                      //Whether the matrix is identity or not
       printf("identity matrix");
       break;
               
   }
  else{
	     printf("not identity matrix");
	            break;
	   }   
   }

   break;
}
}
