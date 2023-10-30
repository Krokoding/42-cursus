
#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"
#include <stdio.h>

void	ft_putchar_fd(char c, int fd)
{
	(write(fd, &c, 1));
}

void	ft_print_pointertst(uintptr_t ull)
{
	char							*base;

	base = "0123456789abcdef";
	if (ull > 16)
    {
		(ft_print_pointertst(ull / 16));
        printf(" div = %lu\n  ", ull);
        (ft_print_pointertst(ull % 16));
        printf(" mod = %lu\n  ", ull);
    }
    else
		    ft_putchar_fd(base[ull], 1);
}

int main()
{
    unsigned long long ft;
    ft = NULL;
    write(1, "0x", 2);
    ft_print_pointertst((uintptr_t)&ft);
    int i = printf("\n%p", &ft);
    printf("   i =      %d", i);
}
