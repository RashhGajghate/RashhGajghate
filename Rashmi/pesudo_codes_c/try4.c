        #include <stdio.h>

        int main()

        {

            int a = 10;

            if (a == a--)

		//printf("a = %d\n",a);
                printf("TRUE 1\t");

		//printf("a = %d\n",a);
            a = 10;

		printf("a = %d\n",a);
            if (a == --a)
		printf("a = %d\n",a);
                printf("TRUE 2\t");

        }
