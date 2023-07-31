#include<stdio.h>
#include<stdio_ext.h>

struct employee 
{
	int empid;
	char empName[20];
	float salary;
	int yearjoin;
};

void emp_details(struct employee*, int );
void emp_details_display(struct employee*, int, int);
void emp_salary_calculation(struct employee *, int);
void emp_service_period(struct employee *, int, int);

int main()
{
	int year, num;
	printf("Enter the current year:- ");
	scanf("%d", &year);
	printf("Enter the number of employee:-\n");
	scanf("%d", &num);
	struct employee emp[num];
	emp_details(emp, num);
	emp_details_display(emp, num, year);
	emp_salary_calculation(emp, num);
	//emp_service_period(emp, num, year);
return 0;
}
void emp_details(struct employee *e, int n)
{
	for (int i =0; i< n; i++)
	{
		printf("Enter the details of the employee_%d:- \n", i+1);
		printf("Enter the employee id:- \n");
		scanf("%d", &(e+i)->empid);
		printf("Enter the employee name:- \n");
		__fpurge(stdin);
		scanf("%[^\n]s", (e+i)->empName);
		printf("Enter the salary:- \n");
		scanf("%f", &(e+i)->salary);
		printf("Enter the year of joining:- \n");
		scanf("%d", &(e+i)->yearjoin);
	}
return;
}
void emp_details_display(struct employee *e, int n, int y)
{
	int no_of_year;
	for (int i =0; i< n; i++)
	{
		printf("\nDetails of the employee_%d:- \n", i+1);
		printf("Employee_id:- %d\n",(e+i)->empid);
		printf("Employee_name:- %s\n", (e+i)->empName);
		printf("Employee_salary:- %.2f\n", (e+i)->salary);
		printf("Employee_Year_of_join:- %d\n", (e+i)->yearjoin);
		//no_of_year = emp_service_period(e, n, y);
		//printf("Employee_serviced year:- %d\n", no_of_year);
		emp_service_period(e, n, y);
	}
return;
}

void emp_salary_calculation(struct employee *e, int n)
{
	float total_salary=0;
	float avg_salary=0;
	float min_salary =e->salary;
	float max_salary=e->salary;

	for (int i=0; i<n; i++)
	{
		total_salary += (e+i)->salary;

		avg_salary=total_salary/n;

		if ((min_salary)>(e+i)->salary)
			min_salary=(e+i)->salary;

		if ((max_salary) < (e+i)->salary)
			max_salary=(e+i)->salary;
	}
	printf("Total_salary :- %.2f\n", total_salary);
	printf("average_salary :- %.2f\n", avg_salary);
	printf("Minimum_salary :- %.2f\n", min_salary);
	printf("Maximum_salary :- %.2f\n", max_salary);

return;
}

void emp_service_period(struct employee * e, int n, int y)
{
	
	int current_year= y;
	int index1, index2;
	int service_year=0;
	service_year=y-(e->yearjoin);

	int latest_join_year=e->yearjoin;
	int min_service_year=0;

	int oldest_join_year=e->yearjoin;
	int max_service_year=0;

	for(int i=0; i<n; i++)
	{
		if((latest_join_year) < (e+i)->yearjoin)
		{
			latest_join_year=(e+i)->yearjoin;
			index1= i;
		}
		if((oldest_join_year) > (e+i)->yearjoin)
		{
			oldest_join_year=(e+i)->yearjoin;
			index2=i;
		}
	}
	min_service_year= current_year - latest_join_year;
	max_service_year= current_year - oldest_join_year;

	printf("Minimum_serviced_year is employee %d :- %d\n", index1+1, min_service_year);
	printf("Maximum_serviced_year is employed %d :- %d\n",index2+1, max_service_year);
	
//	return service_year;
return;
}

