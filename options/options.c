/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 10:04:32 by exam              #+#    #+#             */
/*   Updated: 2018/05/22 20:14:25 by rojaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1 ,&c, 1);
}

int 	ft_invalid()
{
	write (1, "Invalid Option", 14);
	write (1,"\n",1);
	return 0;
}

int 	ft_option()
{
	write (1, "options: abcdefghijklmnopqrstuvwxyz", 35); 
	write (1,"\n",1);
	return 0;
}

int		ft_check_format(char **str)
{
	int i = 1;
	while (str[i] != '\0')
	{
		if (str[i][0] != '-')
			return 0;
		i++;
	}
	return (1);
}

int 	ft_chouch(char c)
{
	char *alph;
	int i = 0;

	alph = "abcdefghijklmnopqrstuvwxyz";
	while (alph[i])
	{
		if (alph[i] == c)
			return 1;
		i++;
	}
	return 0;
}

int		ft_check_flag(char *str)
{
	int i = 1;

	while (str[i])
	{
		if (ft_chouch(str[i]) == 0)
			return 0;
		i++;	
	}
	return 1;
}

int		ft_check(char **str)
{
	int i = 1;

	if (ft_check_format(str) == 0)
		return (0);
	while (str[i])
	{
		if (ft_check_flag(str[i]) == 0)
			return 0;
		i++;	
	}
	return 1;
}

int		ft_h(char **str, int bool)
{
	int i = 1;
	int a = 1;

	while (str[i])
	{
		while (str[i][a])
		{
			if (str[i][a] == 'h' && bool == 1)
				return 0;
			a++;
		}
		if (a == 1)
			return (-1);
		a = 1;
		i++;
	}
	return 1;
}

int		ft_index(char c)
{
	char *alph;
	int i = 0;
	alph = "zyxwvutsrqponmlkjihgfedcba";
	while (alph[i])
	{
		if (alph[i] == c)
			return (i);
		i++;	
	}
	return (0);
}

int main (int argc, char **argv)
{
	int i = 0;
	int a = 1;
	char bit[32];

	while (i < 32)
		bit[i++] = '0';
	bit[i] = 0;
	i = 1;
	if (argc <= 1)
		return (ft_option());
	if (ft_h(argv,0) == -1)
		return (ft_invalid());
	if (ft_check(argv) == 0)
		return (ft_invalid());
	if (ft_h(argv,1) == 0)
		return (ft_option());
	while (argv[i])
	{
		while (argv[i][a])
		{
			bit[ft_index(argv[i][a]) + 6] = '1';
			a++;
		}
		a = 1;
		i++;
	}
	i = 0;
	a = 0;
	while (bit[i] != '\0')
	{
		ft_putchar(bit[i]);
		i++;
		a++;
		if (a == 8)
		{
			ft_putchar(' ');
			a = 0;
		}
	}
	ft_putchar('\n');
	return 0;
}
