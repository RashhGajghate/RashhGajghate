#include<stdio.h>
unsigned short swap_bytes(unsigned short);
int main()
{
	unsigned short x;
	printf("Enter a 16 bit number : ");
	scanf("%hx",&x);
	printf("Swap bytes =%x\n",swap_bytes(x));
	return 0;
}

unsigned short swap_bytes(unsigned short x) 
{
    unsigned short bitmask = 0x00FF;
    unsigned short temp = x & bitmask;
    x = x >> 8;
    temp = temp << 8;
    x = x | temp;
    return x;
}
