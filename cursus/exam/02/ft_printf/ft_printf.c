#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

#include <stdio.h>
char	*ft_itoa_base(long n, int base)
{
	char	*ret;
	int		len;
	char	*hexa;
	int		i;
	long		tmp;

	len = 0;
	if (n < 0 && base == 10)
	{
		ret += write(1, "-", 1);
		n *= -1;
	}
	tmp = n;
	while (n)
	{
		n /= base;
		len++;
	}
	ret = malloc(sizeof(char) * (len + 1));	
	hexa = "0123456789abcdef";
	i = 0;
	ret[len] = '\0';
	len--;
	while (tmp)
	{
		ret[len] = hexa[tmp % base];
		len--;
		tmp /= base; 
	}
	return (ret);
}

int	ft_printf_string(va_list *ap)
{
	int		ret;
	char	*str;

	ret = 0;
	str = va_arg(*ap, char *);
	if (str == NULL)
		str = "(null)";
	while (*str)
		ret += write(1, str++, 1);
	return (ret);
}

int	ft_printf_decimal(va_list *ap)
{
	int	ret;
	long	num;
	char	*str;
	int		i;

	i = 0;
	ret = 0;
	num = va_arg(*ap, int);
	str = ft_itoa_base(num, 10);
	while (str[i])
		ret += write(1, &str[i++], 1);
	free(str);
	return (ret);
}

int	ft_printf_hexa(va_list *ap)
{
	int	ret;
	unsigned int num;
	char	*str;

	ret = 0;
	int	i = 0;
	num = va_arg(*ap, unsigned int);
	str = ft_itoa_base(num, 16);
	while (str[i])
		ret += write(1, &str[i++], 1);
	free(str);
	return (ret);
}

int	select_specifier(char spec, va_list *ap)
{
	int	ret;

	ret = 0;
	if (spec == 's')
		ret = ft_printf_string(ap);
	else if (spec == 'd')
		ret = ft_printf_decimal(ap);
	else if (spec == 'x')
		ret = ft_printf_hexa(ap);
	return (ret);
}

int ft_printf(const char *format, ... )
{
	va_list ap;
	int		ret;

	va_start(ap, format);
	ret = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ret += select_specifier(*format, &ap);
		}
		else
			ret += write(1, format, 1);
		format++;
	}
	return (ret);
}

#include <stdio.h>

int	main()
{
	ft_printf("Hexadecimal for %d is %x\n", -2147483648, -2147483648);
	printf("Hexadecimal for %ld is %x\n", -2147483648, -2147483648);
	while(1);
}
