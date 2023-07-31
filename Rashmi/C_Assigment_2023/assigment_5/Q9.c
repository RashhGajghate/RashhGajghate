#include<stdio.h>

int main()
	{
	int a[3][3],b[2][2];
	int i,j,n,det,det1,det2,det3;
		printf("for 2*2 matrix enter 1\n for 3*3 matrix enter 2\n");   
		scanf("%d",&n);
		switch(n)
		{
		       //Finding determinant of 2X2 matrix
			case 1:
			{
				printf("enter the value in 2*2 matrix\n");
			    
				for(int i=0;i<2;i++)
			   	 {	
				    for(int j=0;j<2;j++)
				    {
					    scanf("%d",&a[i][j]);
				    }
				 }
			    	printf("the above matrix is\n");
				 
			     	for(int i=0;i<2;i++)
				    {
				    printf(" %d",a[i][0]);
				    printf(" %d\n",a[i][1]);
				     }

				det=(a[0][0])*(a[1][1])-((a[0][1])*(a[1][0]));
				printf("determinant of above matrix is %d\n", det);
				break;
			}
                 
                 
                       //Finding determinant of 3X3 matrix
			case 2:
			{

			    printf("enter the value in 3*3 matrix \n");
			    for(int i=0;i<3;i++)
			    {
				    for(int j=0;j<3;j++)
				    {
					    scanf("%d",&a[i][j]);
				    }
			    }
			    
				printf("the above matrix is\n");
				    for(int i=0;i<3;i++){
				    printf(" %d",a[i][0]);
				    printf(" %d",a[i][1]);
				    printf(" %d\n",a[i][2]);
				    }
		           	
				det1=a[0][0]*(((a[1][1])*(a[2][2])) -((a[1][2])*(a[2][1])));
				det2=a[0][1]*(((a[1][0])*(a[2][2]))-((a[1][2])*(a[2][0])));
				det3=a[0][2]*(((a[1][0])*(a[2][1]))-((a[1][1])*(a[2][0])));
			
				det=det1-det2+det3;
				printf("determinant of above matrix is %d\n", det);
			    	break;
			}
		}
		}
