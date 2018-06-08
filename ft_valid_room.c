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

static	int	ft_part2(char **r)
{
	int		i;
	int		minus;
	int		plus;
	int		k;

	k = 1;
	while (r[k++])
	{
		i = 0;
		minus = 0;
		plus = 0;
		while (r[1][i])
		{
			if (r[1][i] == '+')
				plus++;
			else if (r[1][i] == '-')
				minus++;
			else if (ft_isdigit(r[1][i]) != 1)
				return (0);
			i++;
		}
		if (minus > 1 || plus > 1 || (minus == 1 && plus == 1))
			return (0);
	}
	return (1);
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

int			ft_valid_room(char *s)
{
	char	**r;

	if (ft_spaces(s) != 2)
		return (0);
	r = ft_strsplit(s, ' ');
	if (r[0] == NULL || r[1] == NULL || r[2] == NULL)
		return (0);
	return (ft_part2(r));
}
