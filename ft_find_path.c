/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 15:52:08 by vradchen          #+#    #+#             */
/*   Updated: 2018/06/07 15:52:08 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_find_path(t_room *r, int ants)
{
	t_room	*r1;
	t_link	*path;
	t_link	*p;
	t_link	*l;
	int 	depth;

	r1 = r;
	while (r1)
	{
		if (r1->end == 1)
		{
			if (r1->depth == 0)
			{
				ft_printf("Error: No link to the end\n");
				return (0);
			}
			break ;
		}
		r1 = r1->next;
	}
	path = malloc(sizeof(t_link));
	path->next = NULL;
	path->r_n = r1;
	depth = r1->depth;
	l = r1->link;
	while(l && depth > -100)
	{
		if (l->r_n->depth == depth - 1)
		{
			depth--;
			p = malloc(sizeof(t_link));
			p->r_n = l->r_n;
			p->next = path;
			path = p;
			l = l->r_n->link;
		}
		else
			l = l->next;
	}
	ft_print_path(path, ants);
	return (1);
}
