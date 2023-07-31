#include<stdio.h>
int main()
{
	int i,t3=0,t1=0,t2=0,day,month,year, in_year=0,in_month=0,j,rem_days=0,total=0,rem=0;
	printf("Enter day: ");
	scanf("%d",&day);
	printf("Enter month: ");
	scanf("%d",&month);
	printf("Enter year: ");
	scanf("%d",&year);

	for(i=1970;i<year;i++)
	{
		if(i%4==0)
		{
			in_year=366;
		}
		else
		{
			in_year=365;
		}
                t1+=in_year;
	}   


	for(j=1;j<month;j++)
	{
		if(j==2)
		{
			in_month=((j%4==0)?29:28);
			if(in_month==28)
			{
				t3=28-day;
			}
			else
			{
				t3=29-day;

			}
		}

		else if(j==4 || j==6 || j==9 || j==11)
		{
			in_month=30;
			t3=30-day;
		}
		else 
		{
			in_month=31;
			t3=31-day;
		}
		t2+=in_month;

	}	
           total=t1+t2+t3;


      rem=total%7;
      if(rem==7)
      {
	      printf("It is Thursday \n");
      }
      else if(rem==2)
      {
	      printf("It is Saturday \n");
      }
      else if(rem==3)
      {
	      printf("It is Sunday \n");
      }
      else if(rem==4)
      {
	      printf("It is Monday \n");
      }
      else if(rem==6)
      {
	      printf("It is wednesday \n");
      }
      else if(rem==5)
      {
	      printf("It is Tuesday \n");
      }
      else
      {
	      printf("It is Friday \n");
      }

}
