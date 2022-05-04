int	ft_isspace(char c)
{
	return ((c > 8 && c < 14) || c == 32);
}

int	ft_isdigit(int n)
{
	if (n >= 48 && n <= 57)
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	res;
	int	minus;

	minus = 1;
	res = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == 45 || *str == 43)
	{
		if (*str == 45)
			minus = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		res = res * 10 + (*str - 48);
		str++;
	}
	return (res * minus);
}