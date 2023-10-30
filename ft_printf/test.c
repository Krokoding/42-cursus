
#include <stdio.h>
#include <unistd.h>

int main()
{
    unsigned long long *ull;
    unsigned long long ft = 4242424242;

    ull = &ft;
    printf("%ull\n", ull);
    printf("%llx\n", ull);
    printf("%p", ull);
}