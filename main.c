/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 20:34:32 by vradchen          #+#    #+#             */
/*   Updated: 2018/06/06 20:34:34 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		main(void)
{
	char	*s;
	char	**r;
	t_room	*room;
	t_room	*rooms;
	t_room	*r1;
	int		start;
	int		end;
	int 	ants;
	int 	i;

	i = 0;
	ants = 0;
	start = 0;
	end = 0;
	rooms = NULL;
	get_next_line(0, &s);
	while (ants == 0)
	{
		ft_printf("%s\n", s);
		while (s[i]  && ants == 0)
		{
			if (ft_isdigit(s[i]) && s[i + 1] == '\0')
				ants = ft_atoi(s);
			i++;
		}
		if (ants != 0)
			break ;
		if (ft_strequ(s, "##start") != 1 && ft_strequ(s, "##end") != 1 && ft_strncmp(s, "#", 1) == 0)
			get_next_line(0, &s);
		else
		{
			ft_printf("ERROR: wrong ants\n");
			return (0);
		}
	}
	while (get_next_line(0, &s))
	{
		ft_printf("%s\n", s);
		while (ft_strequ(s, "##start") == 0 && ft_strequ(s, "##end") == 0 && ft_strncmp(s, "#", 1) == 0)
		{
			get_next_line(0, &s);
			ft_printf("%s\n", s);
		}
		room = malloc(sizeof(t_room));
		ft_initial_room(room);
		if (ft_strequ(s, "##start"))
		{
			room->st = 1;
			start++;
			get_next_line(0, &s);
			ft_printf("%s\n", s);
		}
		else if (ft_strequ(s, "##end"))
		{
			room->end = 1;
			end++;
			get_next_line(0, &s);
			ft_printf("%s\n", s);
		}
		while (ft_strequ(s, "##start") != 1 && ft_strequ(s, "##end") != 1 && ft_strncmp(s, "#", 1) == 0)
		{
			get_next_line(0, &s);
			ft_printf("%s\n", s);
		}
		if (ft_valid_room(s) == 1)
		{
			r = ft_strsplit(s, ' ');
			room->name = r[0];
			room->x = ft_atoi(r[1]);
			room->y = ft_atoi(r[2]);
			room->next = rooms;
			rooms = room;
		}
//		else if (end == 1 && start == 1)
//		{
//			ft_printf("ERROR: not a valid room\n");//bad line, no start or no end\n");
//			return (0);
//		}
		else if (end != 1 || start != 1)
		{
			ft_printf("ERROR: not a valid room\n");
			return (0);
		}
		else
		{
			if (ft_links(rooms, s) == 0)
				break ;
		}
	}
	r1 = rooms;
	while (r1)
	{
		if (r1->st == 1)
		{
			ft_depth(r1, rooms);
			break ;
		}
		r1 = r1->next;
	}
	if (ft_find_path(rooms, ants) == 0)
		return (0);
	return (0);
}
