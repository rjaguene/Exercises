/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojaguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 14:55:48 by rojaguen          #+#    #+#             */
/*   Updated: 2018/05/20 23:10:00 by rojaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_itoa_base(unsigned char nb, int base)
{
	char *str = "0123456789abcdef";

	write(1, &str[nb / base], 1);
	write(1, &str[nb % base], 1);
}

void	print(unsigned char *str, size_t start, size_t size)
{
	int i = start;

	while (i < start + 16 && i < size)
	{
		ft_itoa_base(str[i],16);
		if (i % 2)
			ft_putchar(' ');
		i++;
	}
	while (i < start + 16)
	{
		write(1, "  ", 2);
		if (i % 2)
			ft_putchar(' ');
		i++;
	}
	i = start;
	while (i < 16 + start && i < size)
	{
		if (str[i] > 32 && str[i] < 127)
			write(1,&str[i],1);
		else 
			ft_putchar('.');
		i++;
	}
	ft_putchar('\n');
}

void	print_memory(const void *addr, size_t size)
{
	int				start = 0;
	unsigned char	*str = (unsigned char *)addr;

	while (start < size)
	{
		print(str,start,size);
		start += 16;
	}
}

int		main(void)
{
	int tab[9] = {2147483647, 10, 150, 255,
		12, 16,  42, 36, 36};

	print_memory(tab, sizeof(tab));
	return 0;
}
