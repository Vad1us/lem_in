/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_links.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 13:12:38 by vradchen          #+#    #+#             */
/*   Updated: 2018/06/04 13:12:41 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int ft_valid_link(t_room *rooms, char *s)
{
	char	**r;
	t_room	*r1;
	int 	flag;

	flag = 0;
	r = ft_strsplit(s, '-');
	if (r[0] == NULL || r[1] == NULL || r[0] == r[1] || r[2] != NULL)
	{
		return (0);
	}
	r1 = rooms;
	while (r1)
	{
		if (ft_strequ(r1->name, r[0]) || ft_strequ(r1->name, r[1]))//(r1->name == r[0] || r1->name == r[1])
		{
			//ft_printf("1 %s 2 %s 3 %s\n", r1->name, r[0], r[1]);
			flag++;
		}
		r1 = r1->next;
	}
	if (flag == 2)
		return (1);
	return (0);
}

void	ft_links2(t_room *rooms, t_room *r1, char **r)
{
	t_room *r2;
	t_link	*link;

	link = malloc(sizeof(t_link));
	link->next = NULL;
	r2 = rooms;
	while (r2)
	{
		if (ft_strequ(r[1], r2->name) == 1)
		{
			link->r_n = r2;
			break;
		}
		r2 = r2->next;
	}
	link->next = r1->link;
	r1->link = link;
	link = malloc(sizeof(t_link));
	link->next = NULL;
	link->r_n = r1;
	link->next = r2->link;
	r2->link = link;
}

int ft_links(t_room *rooms, char *s)
{
	char	**r;
	t_room	*r1;

	r1 = rooms;
	if (ft_valid_link(rooms, s) == 1)
	{
		r = ft_strsplit(s, '-');
		while (r1)
		{
			if (ft_strequ(r[0], r1->name) == 1)
			{
				ft_links2(rooms, r1, r);
				return (1) ;
			}
			r1 = r1->next;
		}
	}
	else
	{
		ft_printf("ERROR: not valid link\n");
		return (0);
	}
	return (1);
}