/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 16:46:46 by vradchen          #+#    #+#             */
/*   Updated: 2018/06/07 16:46:47 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	ft_print_path2(int a, t_link *p, int ants)
{
	int		a1;
	t_link	*p1;

	p1 = p;
	a1 = a;
	while (p1)
	{
		p1->r_n->ant = a1;
		a1--;
		if (p1->next == NULL && p1->r_n->ant > ants + 1)
			return (0);
		p1 = p1->next;
	}
	return (1);
}

void		ft_print_path(t_link *p, int ants)
{
	int		a;
	t_link	*p1;
	int		i;

	i = 0;
	a = 1;
	ft_printf("\n");
	while (1)
	{
		if (ft_print_path2(a, p, ants) == 0)
			return ;
		a++;
		p1 = p;
		if (i == 1)
			ft_printf("\n");
		while (p1)
		{
			if (p1->r_n->ant > 0 && p1->r_n->ant <= ants && p1->r_n->st != 1)
			{
				i = 1;
				ft_printf("L%i-%s ", p1->r_n->ant, p1->r_n->name);
			}
			p1 = p1->next;
		}
	}
}
