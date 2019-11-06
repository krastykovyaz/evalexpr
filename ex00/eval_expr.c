/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 11:07:52 by lnoisome          #+#    #+#             */
/*   Updated: 2019/08/18 15:17:49 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "add_fun.h"
#include "ee.h"

int		num(char **str)
{
	int nbr;

	while (**str == ' ')
		(*str)++;
	if (**str == '(')
	{
		(*str)++;
		nbr = sum(str);
		if (**str == ')')
			(*str)++;
		return (nbr);
	}
	return (ft_atoi(str));
}

int		condit(char **str)
{
	int		nbr;
	int		nbr2;
	char	op;

	nbr = num(str);
	while (**str)
	{
		while (**str == ' ')
			(*str)++;
		op = **str;
		if (op != '/' && op != '*' && op != '%')
			return (nbr);
		(*str)++;
		nbr2 = num(str);
		if (op == '/')
			nbr /= nbr2;
		else if (op == '*')
			nbr *= nbr2;
		else
			nbr %= nbr2;
	}
	return (nbr);
}

int		sum(char **str)
{
	int		nbr;
	int		nbr2;
	char	op;

	nbr = condit(str);
	while (**str)
	{
		while (**str == ' ')
			(*str)++;
		op = **str;
		if (op != '+' && op != '-')
			return (nbr);
		(*str)++;
		nbr2 = condit(str);
		if (op == '+')
			nbr += nbr2;
		else
			nbr -= nbr2;
	}
	return (nbr);
}

int		eval_expr(char *str)
{
	return (sum(&str));
}
