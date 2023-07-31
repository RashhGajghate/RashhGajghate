#include<stdio.h>
int main()
{
	int sal,tax,age,ded,gender,total;
	
	    printf("Enter your salary: ");
       		scanf("%d",&sal);
       if(sal<=250000)
       {
	       printf("No tax applied");
       }
       else if(sal>=250000 && sal<=500000)
       {
	       tax=(sal-250000)*0.05;
	       printf("Tax= %d\n",tax);
       }
       else if(sal>=500000 && sal<=750000)
       {
	       tax=12500+(sal-500000)*0.1;
	       printf("Tax= %d\n",tax);
       }
       else if(sal>=750000 && sal<=1000000)
       {
	       tax=12500+50000+(sal-750000)*0.15;
	       printf("Tax= %d\n",tax);
       }
       else if(sal>=1000000 && sal<=1500000)
       {
	       tax=12500+50000+112500+(sal-1000000)*0.2;
	       printf("Tax= %d\n",tax);
       }
       else
       {
	       printf("Default");
       }
  

       printf("Enter your age: ");
       scanf("%d",&age);
       printf("Enter your Gender-----Press 70 for Female and 77 for Male: ");
       scanf("%d",&gender);
  
       if(age>=60)
       {
	       ded=tax/2;
	       printf("The deducted tax= %d\n",ded);
	       total=tax-ded;
	       printf("The income tax= %d\n",total);
       }
       else if(gender==70 && age<60)
       {
	       ded=tax*0.1;
	       printf("The deducted tax= %d\n",ded);
	       total=tax-ded;
	       printf("The income tax= %d\n",total);
       }
       else
       {
	       printf("No deduction \n");
       }







        /* rem1=salary-250000;
	 printf("salary remain 1= %d\n",rem1); 
             
	if(rem1>250000 && rem1<500000)
	{	
		  if(rem1<=250000)
		  {
			  tax1=rem1*0.05;
			  printf("Tax1= %d\n",tax1);
		  }
		  else
		  {
           	  rem2=rem1-250000;
	 	   tax1=rem2*0.05;
	   	 printf("Tax1= %d\n",tax1);
      	 	 }
        }
	
        if(rem2>500000 && rem2<750000)
       {
	  printf("salary remain 2= %d\n",rem2);
		  if(rem2<=500000)
		  {
			  tax2=rem2*0.1;
			  printf("Tax2= %d\n",tax2);
		  }
		  else
		  {
			  rem3=rem2-500000;
			  tax2=rem3*0.1;
			  printf("salary remain 3= %d\n",rem3);
			  printf("Tax2= %d\n",tax2);
		  }
	  
       }



       if(rem3>750000 && rem3<1000000)
{
	printf("salary remain 3= %d\n",rem3);
		  if(rem3<=750000)
		  {
			  tax3=rem3*0.15;
			  printf("Tax3= %d\n",tax3);
		  }
		  else
		  {
			  rem4=rem3-750000;
			  tax3=rem4*0.15;
			  printf("salary remain 4= %d\n",rem4);
			  printf("Tax3= %d\n",tax3);
		  }
}	  
 

 if(rem4>1000000 && rem4<1500000)
{
	  printf("salary remain 4= %d\n",rem4);
		  if(rem4<=1000000)
		  {
			  tax4=rem4*0.2;
			  printf("Tax4= %d\n",tax4);
		  }
		  else
		  {
			  rem5=rem4-1000000;
			  tax4=rem5*0.2;
			  printf("salary remain 5= %d\n",rem5);
			  printf("Tax4= %d\n",tax4);
		  }
	  
}   

	       tax=tax1+tax2+tax3+tax4;
	       printf("Total Tax= %d\n",tax);
             












		 /* rem3=rem2
            tax1=rem1*0.05;
	    printf("Tax= %d\n",tax1);
	  }


	     



	  if(rem1>500000)
	  {
		 rem2=rem1-500000;
		 printf("salary remain 2= %d\n",rem2);
		 tax2=rem2*0.1;
		 printf("Tax2= %d\n",tax2);
	  }
	  else
	  {
		  rem2=rem1-250000;
		  printf("salary remain 2= %d\n",rem2);
		  tax2=rem2*0.1;
		  printf("Tax2= %d\n",tax2);
	  }

	
        
      

	 /* if(rem2>=500000 && rem2<=750000)
	  {
           tax2=rem2*0.1;
	   printf("%d\n",tax2);
	  }


	  if(rem2<750000)
	  {
		 rem3=rem2-750000;
	  }
	  else
	  {
		  rem3=rem2-500000;
	  }
        
	  if(rem3>=500000 && rem3<=750000)
	  {
           tax3=rem3*0.15;
	   printf("%d\n",tax3);
	  }


	  if(rem3<1000000)
	  {
		 rem4=rem3-1000000;
	  }
	  else
	  {
		  rem4=rem3-750000;
	  }
         
	  if(rem4>=750000 && rem4<=1000000)
	  {
		  tax4=rem4*0.2;
		  printf("%d\n",tax4);
	  }*/

	 

	

	 


         


        








   /*  else if(salary>=250000 && salary<=500000)
	{
		printf("5 percent tax required\n");
		tax=(salary-250000)*0.05;
                   if()




	}
	else if(salary>=500000 && salary<=750000)
	{
		printf("10 percent tax required\n");
		tax=12500+salary*0.1;
	}
	else if(salary>=750000 && salary<=1000000)
	{
		printf("15 percent tax required\n");
		tax=salary*0.15;
	}
	else if(salary>=1000000 && salary<=1500000)
	{
		printf("20 percent tax required\n");
		tax=salary*0.2;
	}
	else
	{
		printf("Calculation not available \n");
	} */

}
