#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    int ret;
      // Call the function
      int i = 1000;
      ret = ft_printf("Testing ft_printf!%s je", "bonjour\n");
      printf("My printf value = %d\n", ret);
      ret = printf("Testing ft_printf!%s je", "bonjour\n");
      printf("My printf value = %d\n", ret);
      return (0);
}