#include "helper_functions.h"
#include "parser.h"

char	*g_equ;

int		parse_sum(void)
{
	int		product1;
	int		product2;
	char	op;

	product1 = parse_product();
	while (*g_equ == '+' || *g_equ == '-')
	{
		op = *g_equ;
		g_equ++;
		product2 = parse_product();
		if (op == '+')
			product1 = product1 + product2;
		else
			product1 = product1 - product2;
	}
	return (product1);
}

int		parse_product(void)
{
	int		factor1;
	int		factor2;
	char	op;

	factor1 = parse_factor();
	while (*g_equ == '*' || *g_equ == '/' || *g_equ == '%')
	{
		op = *g_equ;
		++g_equ;
		factor2 = parse_factor();
		if (op == '*')
			factor1 = factor1 * factor2;
		else if (op == '/')
			factor1 = factor1 / factor2;
		else
			factor1 = factor1 % factor2;
	}
	return (factor1);
}

int		parse_number(void)
{
	int	number;

	number = 0;
	while (*g_equ >= '0' && *g_equ <= '9')
	{
		number = number * 10;
		number = number + *g_equ - '0';
		++g_equ;
	}
	return (number);
}

int		parse_factor(void)
{
	int sum;

	if (*g_equ >= '0' && *g_equ <= '9')
	{
		return (parse_number());
	}
	else if (*g_equ == '(')
	{
		++g_equ;
		sum = parse_sum();
		++g_equ;
		return (sum);
	}
	return (0);
}

int		eval_expr(char *str)
{
	int result;

	result = 0;
	g_equ = remove_spaces(str);
	result = parse_sum();
	return (result);
}
