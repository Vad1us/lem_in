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

static int		ft_shortcut(char **s)
{
	if (*s == NULL)
	{
		ft_gnl(s);
		if (*s == NULL)
		{
			ft_printf("Error: Empty file\n");
			exit(11);
		}
	}
	while (ft_strequ(*s, "##start") == 0 && ft_strequ(*s, "##end") == 0 &&
		ft_strncmp(*s, "#", 1) == 0)
	{
		if (ft_gnl(s) == 0)
			return (0);
	}
	return (1);
}

static int		ft_ants(char *s)
{
	int		i;
	int		ants;

	ants = 0;
	i = -1;
	while (ants == 0)
	{
		while (s[++i] && ants == 0)
		{
			if (ft_isdigit(s[i]) && s[i + 1] == '\0')
			{
				if (ft_atoi(s) > 2147483647 || ft_atoi(s) <= 0)
					return (-1);
				ants = ft_atoi(s);
			}
		}
		if (ants != 0)
			break ;
		if (ft_strequ(s, "##start") != 1 && ft_strequ(s, "##end") != 1 &&
			ft_strncmp(s, "#", 1) == 0)
			ft_gnl(&s);
		else
			return (-1);
	}
	return (ants);
}

static int		ft_return(void)
{
	ft_printf("ERROR: wrong ants\n");
	return (-1);
}

int				main(void)
{
	char	*s;
	t_room	*rooms;
	int		flag;
	int		ants;
	t_link	*p;

	rooms = NULL;
	s = NULL;
	ft_shortcut(&s);
	ants = ft_ants(s);
	if (ants < 0)
		return (ft_return());
	while (ft_gnl(&s))
	{
		if (ft_shortcut(&s) == 0)
			break ;
		flag = ft_data(&s, &rooms);
		if (flag == 0 || flag == 43 || flag == 45)
			return (0);
		else if (flag == 2)
			break ;
	}
	ft_depth(rooms);
	p = ft_find_path(rooms, ants);
	return (1);
}
