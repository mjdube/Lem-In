#include "lem_in.h"

int		 int_max(char *str)
{
	long long	value;
	int			sign;

	value = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
			|| *str == '\r' || *str == '\v')
		str++;
	if (*str == '-')
		sign = -1;
	else
		sign = 1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		value = value * 10 + (*str - '0');
		str++;
	}
	if ((value * sign) <= 2147483647 && (value * sign) >= -2147483648)
		return (1);
	else
		return (0);
}