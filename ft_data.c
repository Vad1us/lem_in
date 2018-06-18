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
		ft_gnl(s);
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

static	int	ft_spaces(char *s)
{
	int		i;
	int		spaces;

	spaces = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == ' ')
			spaces++;
		i++;
	}
	return (spaces);
}

static int	ft_data2(char **s, t_room **rooms, int end, int st)
{
	int		flag;
	t_room	*room;
	char	**r;

	r = ft_strsplit(*s, ' ');
	flag = 1;
	if (ft_spaces(*s) == 2 && ft_valid_room(r, *rooms) == 1)
	{
		room = malloc(sizeof(t_room));
		ft_initial_room(room);
		room->name = ft_strdup(r[0]);
		room->x = ft_atoi(r[1]);
		room->y = ft_atoi(r[2]);
		room->next = *rooms;
		room->end = end;
		room->st = st;
		*rooms = room;
	}
	else if (ft_check(*rooms) == 0)
		flag = 0;
	else if (ft_links(*rooms, *s) == 0)
		flag = 2;
	ft_del(r);
	return (flag);
}

int			ft_data(char **s, t_room **rooms)
{
	int		flag;
	int		st;
	int		end;

	st = 0;
	end = 0;
	if (ft_strequ(*s, "##start"))
	{
		st = 1;
		if (ft_gnl(s) == 0)
			return
			(ft_printf("ERROR: no room after ##start, u cant fool me\n"));
	}
	else if (ft_strequ(*s, "##end"))
	{
		end = 1;
		if (ft_gnl(s) == 0)
			return (ft_printf("ERROR: no room after ##end, u cant fool me\n"));
	}
	ft_shortcut(s);
	flag = ft_data2(s, rooms, end, st);
	if (flag == 0)
		ft_printf("ERROR: not a valid room\n");
	return (flag);
}
