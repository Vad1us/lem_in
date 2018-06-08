/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 14:58:36 by vradchen          #+#    #+#             */
/*   Updated: 2018/06/04 14:58:37 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	ft_shortcut(char **s)
{
	while (ft_strequ(*s, "##start") == 0 && ft_strequ(*s, "##end") == 0 &&
		ft_strncmp(*s, "#", 1) == 0)
	{
		get_next_line(0, s);
		ft_printf("%s\n", *s);
	}
}

static int	ft_check(t_room *rooms)
{
	t_room	*r1;
	int		start;
	int		end;

	start = 0;
	end = 0;
	r1 = rooms;
	while (r1)
	{
		if (r1->st == 1)
			start++;
		if (r1->end == 1)
			end++;
		r1 = r1->next;
	}
	if (start == 1 && end == 1)
		return (1);
	return (0);
}

static int	ft_data2(char **s, t_room **rooms, t_room *room)
{
	char **r;

	if (ft_valid_room(*s) == 1)
	{
		r = ft_strsplit(*s, ' ');
		room->name = r[0];
		room->x = ft_atoi(r[1]);
		room->y = ft_atoi(r[2]);
		room->next = *rooms;
		*rooms = room;
	}
	else if (ft_check(*rooms) == 0)
	{
		ft_printf("ERROR: not a valid room\n");
		return (0);
	}
	else
	{
		if (ft_links(*rooms, *s) == 0)
			return (2);
	}
	return (1);
}

int			ft_data(char **s, t_room **rooms)
{
	t_room *room;

	room = malloc(sizeof(t_room));
	ft_initial_room(room);
	if (ft_strequ(*s, "##start"))
	{
		room->st = 1;
		get_next_line(0, s);
		ft_printf("%s\n", *s);
	}
	else if (ft_strequ(*s, "##end"))
	{
		room->end = 1;
		get_next_line(0, s);
		ft_printf("%s\n", *s);
	}
	ft_shortcut(s);
	return (ft_data2(s, rooms, room));
}
