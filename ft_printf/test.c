#include <stdio.h>

int main()
{
	int a = 5;
	void *ptr = &a;

	printf("%p\n", -100);
	printf("%p\n", &a);
}