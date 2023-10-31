#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    int ret;
      // Call the function
      unsigned i = 1000;
      ret = ft_printf(" %x ", 16);
      printf("My printf value = %d\n", ret);
      ret = printf(" %x ", 16);
      printf("printf value = %d\n", ret);
      return (0);
}