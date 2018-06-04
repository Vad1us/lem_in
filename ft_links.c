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
		//ft_printf("general kenobi");
		return (0);
	}
	r1 = rooms;
	//ft_printf("r[0] %s r[1] %s\n", r[0], r[1]);
	while (r1)
	{
		//ft_printf("n %s\n",r1->name);
		if (ft_strequ(r1->name, r[0]) || ft_strequ(r1->name, r[1]))//(r1->name == r[0] || r1->name == r[1])
			flag++;
		r1 = r1->next;
	}
	//ft_printf("%i\n", flag);
	if (flag == 2)
		return (1);
	return (0);
}

int ft_links(t_room *rooms, char *s)
{
	char	**r;
	t_link	*link;
	t_link	*links;
	t_room	*r1;
	t_room	*r2;

	link = (t_link *) malloc(sizeof(t_link));
	link->next = NULL;
	link->r_name = NULL;
	r1 = rooms;
	if (ft_valid_link(rooms, s) == 1)
	{
		r = ft_strsplit(s, '-');
		while (r1)
		{
			if (ft_strequ(r[0], r1->name) == 1)
			{
				r2 = rooms;
				if (r1->link == NULL)
				{
					r1->link = (t_link *)malloc(sizeof(t_link));
					r1->link->next = NULL;
					while (r2)
					{
						if (ft_strequ(r[1], r2->name) == 1)
						{
							r1->link->r_name = r2;
							break;
						}
						r2 = r2->next;
					}
					break ;
				}
				links = r1->link;
				while (links->next)
					links = links->next;
				while (r2)
				{
					if (ft_strequ(r[1], r2->name) == 1)
					{
						r1->link->r_name = r2;
						break;
					}
					r2 = r2->next;
				}
				links->next = link;
				break ;
			}
			r1 = r1->next;
		}
	}
	else
	{
		ft_printf("ERROR");
		return (0);
	}
	return (1);
}
