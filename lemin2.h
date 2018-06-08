/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin2.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 15:04:29 by vradchen          #+#    #+#             */
/*   Updated: 2018/06/01 15:04:31 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN2_H
# define LEMIN2_H

# include "lemin.h"

typedef struct s_room	t_room;

typedef struct			s_link
{
	t_room				*r_n;
	struct s_link		*next;
}						t_link;

#endif
