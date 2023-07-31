#include<stdio.h>
int add(int,int);
int sub(int,int);
int mul(int,int);
float div(int,int);
int main()
{
	int op,inp1,inp2,out;
	float output;
	    printf("Enter two input number : ");
	    scanf("%d%d",&inp1,&inp2);
	    printf("Enter the operation you want to perform--- 1.add,2.sub,3.mul,4.div :");
	    scanf("%d",&op);
	    switch(op)
	    {
		    case 1:
			    out=add(inp1,inp2);
			    printf("Sum= %d\n",out);
			    break;
                    
	            case 2:
			    out=sub(inp1,inp2);
			    printf("Sub= %d\n",out);
			    break;

	            case 3:

			    out=mul(inp1,inp2);
			    printf("mul=%d\n",out);
			    break;
		    case 4:
			    output=div(inp1,inp2);
			    printf("div=%f\n",output);
			    break;
              
	            default :
			    printf("default \n");   		    
	    
	    } 
}             
            
	   	int add(int inp1, int inp2)
		{
	        return inp1+inp2;
	    	}

          	int sub(int inp1,int inp2)
          	{
             	return inp1-inp2;
          	}

  		int mul(int inp1,int inp2)
		{	
		 return inp1*inp2;
		}

		float div(int inp1,int inp2)
		{
		 return inp1/inp2;
		}



