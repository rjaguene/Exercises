/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojaguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 17:40:27 by rojaguen          #+#    #+#             */
/*   Updated: 2018/05/21 21:26:12 by rojaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pars_flag.h"

int			ft_check_format(char **str, int argc, int i, int a)
{
	while (str[i])
	{
		if (str[i][0] != '-')
			return (0);
		if (str[i][1] == '\0')
			return (0);
		i++;
	}
	return (1);
}

int			ft_check_f(char *s, char *flag, int i, int a)
{
	while (s[i])
	{
		while (s[i] != flag[a] && flag[a])
			a++;
		if (!flag[a])
			return (0);
		a = 1;
		i++;
	}
	return (1);
}

int			ft_check(char **str, int argc, char *flag, int i)
{
	if (ft_check_format(str, argc, 1, 0) == 0)
		return (0);
	while (str[i])
	{
		if (ft_check_f(str[i], flag, 1, 0) == 0)
			return (0);
		i++;
	}
	return (1);
}

t_pars		ft_pars(char *str, char *flag, int i, t_pars res)
{
	int		a;
	char	*alph;

	alph = "abcdefghijklmnopqrstuvwxyz";
	a = 0;
	while (str[i])
	{
		while (flag[a])
		{
			if (alph[a] == str[i])
				res.s[a] = '1';
			a++;
		}
		i++;
		a = 0;
	}
	return (res);
}

t_pars		pars_flag(char **str, int argc, char *flag)
{
	t_pars	res;
	int		i;

	i = 0;
	if (ft_check(str, argc, flag, 1) == 0)
	{
		write(1, "Invalide option", 15);
		res.ok = -1;
		return (res);
	}
	while (i < 26)
		res.s[i++] = '0';
	res.s[i] = 0;
	i = 1;
	while (str[i])
	{
		res = ft_pars(str[i], flag, 1, res);
		i++;
	}
	res.ok = 1;
	return (res);
}
