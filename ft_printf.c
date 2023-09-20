#include <unistd.h>
#include <stdarg.h>
#define hex "0123456789abcdef"

int ft_putchar(char c)
{
	return write(1, &c, 1);
}

int ft_putstr(char *s)
{
	int ret = 0;
	if(!s)
	{
		ret += write(1, "(null)", 6);
		return ret;
	}
	while(*s)
	{
		ret += ft_putchar(*s);
		s++;
	}
	return ret;
}

int ft_putnbr(long long n, int base)
{
	int ret = 0;
	if(n < 0)
	{
		n = -n;
		ret += ft_putchar('-');
	}
	if(n >= base)
		ret += ft_putnbr(n/base, base);
	ret += ft_putchar(hex[n%base]);
	return ret;
}

int ft_print(char *f, va_list ap)
{
	int ret = 0;
	char c;
	while(*f)
	{
		c = *f++;
		if(c != '%')
			ret += ft_putchar(c);
		else
		{
			c = *f++;
			if(c == 'c')
				ret += ft_putchar((char)va_arg(ap, int));
			if(c == 's')
				ret += ft_putstr(va_arg(ap, char*));
			if(c == 'd')
				ret += ft_putnbr((long long)va_arg(ap, int), 10);
			if(c == 'x')
				ret += ft_putnbr((long long)va_arg(ap, unsigned int), 16);
		}
	}
	return ret;
}

int ft_printf(char *f, ...)
{
	int ret = 0;
	va_list ap;
	va_start(ap, f);
	ret += ft_print(f, ap);
	va_end(ap);
	return ret;
}

/*
int main(void)
{
	ft_printf("%c%s%d%x", 'c', "salut", 3, 300);
	return 0;
}
*/
