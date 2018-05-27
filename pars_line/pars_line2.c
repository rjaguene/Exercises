/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojaguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 17:57:47 by rojaguen          #+#    #+#             */
/*   Updated: 2018/05/27 17:47:57 by rojaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include <fcntl.h>
#include "get_next_line/get_next_line.h"
#include "pars_line.h"

k_list		*ajout_en_tete(char *line, k_list *s_list)
{
	k_list		*new;

	if (!(new = (k_list*)malloc(sizeof(k_list))))
		return (NULL);
	if (line)
		new->stock = ft_strdup(line);
	else
		new->stock = NULL;
	new->nxt = s_list;
	return (new);
}

k_list			*ajouterEnFin(k_list *s_list, char *line)
{
	/* On crée un nouvel élément */
	k_list *nouvelElement = malloc(sizeof(k_list));
	k_list *temp;

	/* On assigne la valeur au nouvel élément */
	if (line)
		nouvelElement->stock = ft_strdup(line);
	/* On ajoute en fin, donc aucun élément ne va suivre */
	nouvelElement->nxt = NULL;
	if (s_list == NULL)
		/* Si la liste est videé il suffit de renvoyer l'élément créé */
		return nouvelElement;
	else
	{
		/* Sinon, on parcourt la liste à l'aide d'un pointeur temporaire et on
		   indique que le dernier élément de la liste est relié au nouvel élément */
		temp = s_list;
		while (temp->nxt)
			temp = temp->nxt;
		temp->nxt = nouvelElement;
		return s_list;
	}
}

int main(int argc, char **argv)
{
	int			fd;
	char		*line;
	k_list		*s_list;

	s_list = NULL;
	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
	while (get_next_line(fd, &line) == 1)
		s_list = ajouterEnFin(s_list, line);
	while (s_list)
	{
		ft_putendl(s_list->stock);
		s_list = s_list->nxt;
	}
	if (argc == 2)
		close(fd);
	return (0);
}
