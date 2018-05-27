/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojaguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 17:57:47 by rojaguen          #+#    #+#             */
/*   Updated: 2018/05/26 17:10:58 by rojaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include <fcntl.h>
#include "get_next_line/get_next_line.h"
#include "pars_line.h"


k_list		*ft_new_elem(char *line, k_list *new)
{
	k_list *new1;
	k_list *new2;

	if (!(new1 = (k_list*)malloc(sizeof(k_list*))))
			return (NULL);
	if (line)
		new1->stock = ft_strdup(line);
	else
		new1->stock = NULL;
	new1->nxt = NULL;
	if (!new)
		return (new1);
	new2 = new;
	while (new2->nxt)
		new2 = new2->nxt;
	new2->nxt = new1;
	return (new);
}

int main(int argc, char **argv)
{
	int		fd;
	char	*line;
	k_list	*new;

	new = NULL;
	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
	while (get_next_line(fd, &line) == 1)
		new = ft_new_elem(line, new);
	while (new)
	{
		ft_putendl(new->stock);
		free(new->stock);
		new->stock = NULL;
		free(new);
		new = new->nxt;
	}
	if (argc == 2)
		close(fd);
	while (1){}
	return (0);
}
