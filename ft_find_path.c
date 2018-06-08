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

static void	ft_part2(t_room *r1, int ants, t_link **h_path)
{
	t_link	*l;
	int		depth;
	t_link	*path2;
	t_link	*p;

	depth = r1->depth;
	l = r1->link;
	while (l)
	{
		if (l->r_n->depth == depth - 1)
		{
			depth--;
			p = malloc(sizeof(t_link));
			p->r_n = l->r_n;
			p->next = NULL;
			path2 = *h_path;
			while (path2->next)
				path2 = path2->next;
			path2->next = p;
			l = l->r_n->link;
		}
		else
			l = l->next;
	}
	ft_print_path(*h_path, ants);
}

void		ft_find_path(t_room *r, int ants)
{
	t_room	*r1;
	t_link	*h_path;

	r1 = r;
	while (r1)
	{
		if (r1->end == 1)
		{
			if (r1->depth == 0)
			{
				ft_printf("Error: No link to the end\n");
				return ;
			}
			break ;
		}
		r1 = r1->next;
	}
	h_path = malloc(sizeof(t_link));
	h_path->next = NULL;
	h_path->r_n = r1;
	ft_part2(r1, ants, &h_path);
	return ;
}
