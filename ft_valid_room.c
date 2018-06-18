/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_room.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 13:14:32 by vradchen          #+#    #+#             */
/*   Updated: 2018/06/04 13:14:34 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static	int	ft_part2(char **r2)
{
	int		i;
	int		znak;
	int		digit;
	int		k;

	k = 0;
	while (r2[++k])
	{
		digit = 0;
		i = -1;
		znak = 0;
		while (r2[k][++i])
		{
			if (r2[k][i] == '+' || r2[k][i] == '-')
				znak++;
			else if (ft_isdigit(r2[k][i]) != 1)
				return (0);
			else if (ft_isdigit(r2[k][i]) == 1)
				digit++;
		}
		if (znak > 1 || digit == 0)
			return (0);
	}
	return (1);
}

static	int	ft_spaces(char **r2)
{
	int		i;
	int		spaces;
	int		k;

	k = 0;
	spaces = 0;
	i = 0;
	while (r2[i])
	{
		while (r2[i][k])
		{
			if (r2[i][k] == ' ')
				spaces++;
			k++;
		}
		i++;
	}
	return (spaces);
}

int			ft_valid_room(char **r2, t_room *rooms)
{
	int		flag;
	t_room	*r;

	if (r2[0] == NULL || r2[1] == NULL || r2[2] == NULL || r2[3] != NULL)
		return (0);
	if (ft_spaces(r2) != 0)
		return (0);
	r = rooms;
	while (r)
	{
		if ((ft_strequ(r->name, r2[0]) == 1) || (r->x == ft_atoi(r2[1])
			&& r->y == ft_atoi(r2[2])))
			return (0);
		r = r->next;
	}
	flag = ft_part2(r2);
	return (flag);
}
