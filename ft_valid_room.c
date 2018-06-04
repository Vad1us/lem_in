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

#include <stdio.h>
#include "lemin.h"

int 	ft_valid_room(char *s)
{
	int		i;
	int		spaces;
	int		minus;
	int		plus;
	char	**r;
	int		k;

	k = 1;
	spaces = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == ' ')
			spaces++;
		i++;
	}
	if (spaces != 2)
		return (0);
	r = ft_strsplit(s, ' ');
	if (r[0] == NULL || r[1] == NULL || r[2] == NULL)
		return (0);
	while(r[k])
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
		k++;
	}
	return (1);
}