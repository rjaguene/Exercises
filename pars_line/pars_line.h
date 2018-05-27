/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_line.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojaguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 17:59:38 by rojaguen          #+#    #+#             */
/*   Updated: 2018/05/26 19:12:05 by rojaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARS_LINE_H
# define PARS_LINE_H
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"

typedef struct		g_list
{
	char			*stock;
	struct g_list	*nxt;
}					k_list;

#endif 
