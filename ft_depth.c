/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_depth.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 20:34:13 by vradchen          #+#    #+#             */
/*   Updated: 2018/06/06 20:34:14 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		ft_depth2(t_room *r, t_link *l, int i2)
{
	int		i;
	t_room	*st;

	st = r;
	i = 0;
	while (st)
	{
		if (st->depth == i2)
		{
			l = st->link;
			while (l)
			{
				if (l->r_n->depth == 0 && l->r_n->st != 1)
					i = 1;
				if ((l->r_n->depth > st->depth + 1 || l->r_n->depth == 0) &&
					l->r_n->st != 1)
					l->r_n->depth = st->depth + 1;
				l = l->next;
			}
		}
		st = st->next;
	}
	return (i);
}

static t_link	*ft_part2(t_link *l)
{
	while (l)
	{
		l->r_n->depth = 1;
		l = l->next;
	}
	return (0);
}

void			ft_depth(t_room *r)
{
	t_room	*r1;
	t_link	*l;
	int		i2;

	i2 = 0;
	r1 = r;
	l = r1->link;
	while (r1)
	{
		if (r1->st == 1)
		{
			l = r1->link;
			l = ft_part2(l);
			break ;
		}
		r1 = r1->next;
	}
	while (1)
	{
		if (ft_depth2(r, l, ++i2) != 1)
			return ;
	}
}
