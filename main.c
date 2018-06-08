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

static void		ft_ants(int *ants, char *s)
{
	int		i;

	i = 0;
	while (*ants == 0)
	{
		ft_printf("%s\n", s);
		while (s[i] && *ants == 0)
		{
			if (ft_isdigit(s[i]) && s[i + 1] == '\0')
				*ants = ft_atoi(s);
			i++;
		}
		if (*ants != 0)
			break ;
		if (ft_strequ(s, "##start") != 1 && ft_strequ(s, "##end") != 1 &&
			ft_strncmp(s, "#", 1) == 0)
			get_next_line(0, &s);
		else
		{
			ft_printf("ERROR: wrong ants\n");
			return ;
		}
	}
}

static void		ft_shortcut(char **s)
{
	while (ft_strequ(*s, "##start") == 0 && ft_strequ(*s, "##end") == 0 &&
		ft_strncmp(*s, "#", 1) == 0)
	{
		get_next_line(0, s);
		ft_printf("%s\n", *s);
	}
}

int				main(void)
{
	char	*s;
	t_room	*rooms;
	int		flag;
	int		ants;

	ants = 0;
	rooms = NULL;
	get_next_line(0, &s);
	ft_ants(&ants, s);
	while (get_next_line(0, &s))
	{
		ft_printf("%s\n", s);
		ft_shortcut(&s);
		flag = ft_data(&s, &rooms);
		if (flag == 0)
			return (0);
		else if (flag == 2)
			break ;
	}
	ft_depth(rooms);
	ft_find_path(rooms, ants);
	return (0);
}
