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

static void	ft_print_path2(t_link *p, int ants)
{
	t_link	*p1;

	p1 = p;
	while (p1)
	{
		if (p1->next == NULL)
		{
			if (p1->r_n->ant <= ants)
				p1->r_n->ant++;
		}
		else if (p1->next != NULL)
			p1->r_n->ant = p1->next->r_n->ant;
		p1 = p1->next;
	}
}

void		ft_print_path(t_link *p, int ants)
{
	int		a;
	t_link	*p1;

	a = 1;
	while (1)
	{
		p1 = p;
		while (p1)
		{
			if (p1->r_n->ant > 0 && p1->r_n->ant <= ants)
			{
				ft_printf("L%i-%s ", p1->r_n->ant, p1->r_n->name);
			}
			if (p1->r_n->end == 1 && p1->r_n->ant == ants + 1)
				return ;
			p1 = p1->next;
		}
		ft_print_path2(p, ants);
		a++;
		ft_printf("\n");
	}
}
