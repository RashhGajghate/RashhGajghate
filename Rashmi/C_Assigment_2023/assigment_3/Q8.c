#include<stdio.h>

 void add(int []); 	
 void avg(int []);	
 void min(int []);	
 void max(int []);	

int main()
{
  int arr[5]= {1,2,3,4,5};
  
  add(arr);
  avg(arr);
  min(arr);
  max(arr);
  return 0;
   }
   
   
   
   
 void add(int arr[])            
   {
    int i,sum2=0;
      for(int i=0; i<5 ;i++)
         {
            sum2=sum2+arr[i];
           }
            printf("Addition is=%d\n",sum2);
   }
   
   
   void avg(int arr[])		 
   {
    int i,sum2=0,sum3;
      for(int i=0; i<5 ;i++)
         {
            sum2=sum2+arr[i];
           }
           sum3=sum2/5;
            printf("Average is=%d\n",sum3);
   }
   
   
   void min(int arr[])		 
   {
    int  i;
      for(int i=0; i<5 ;i++)
         {
         if(arr[0]>arr[i])
           {
            arr[0]=arr[i];
           }
            }
           printf("Min number is=%d\n",arr[0]);
   }
   
   
   
   
   void max(int arr[])		
   {
    int  i;
      for(int i=0; i<5 ;i++)
         {
         if(arr[0]<arr[i])
           {
            arr[0]=arr[i];
           }
            }
           printf("Max number is=%d\n",arr[0]);
   }
   
   
