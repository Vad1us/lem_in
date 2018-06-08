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

static int	ft_depth2(t_room *st, t_link *l, int i2)//int i, int i2 , t_link *l)
{
	int i;

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
//	if (i != 1)
//		return ;
}

void		ft_depth(t_room *st2, t_room *r)
{
	t_room	*st;
	t_room	*r1;
	t_link	*l;
	//int		i;
	int 	i2;

	i2 = 0;

	r1 = r;
	while (r1)
	{
		if (r1->st == 1)
		{
			l = r1->link;
			while (l)
			{
				l->r_n->depth = 1;
				l = l->next;
			}
			break ;
		}
		r1 = r1->next;
	}
	//r1 = r;
/*	while (r1)
//	{
//		ft_printf("room %s\n", r1->name);
//		while (r1->link)
//		{
//			ft_printf("r %s l %s d %i\n", r1->name, r1->link->r_name->name, r1->depth);
//			r1->link = r1->link->next;
//		}
//		r1 = r1->next;
	}*/
	while (1)
	{
		st = r;
		i2++;
		//i = 0;
		if (ft_depth2(st, l, i2) != 1)
			return ;
//		while (st)
//		{
//
//			if (st->depth == i2)
//			{
//				l = st->link;
//				while (l)
//				{
//					if (l->r_n->depth == 0 && l->r_n->st != 1)
//						i = 1;
//					if ((l->r_n->depth > st->depth + 1 || l->r_n->depth == 0) &&
//						l->r_n->st != 1)
//						l->r_n->depth = st->depth + 1;
//					l = l->next;
//				}
//			}
//			st = st->next;
//		}
//		if (i != 1)
//			return ;
	}
}
