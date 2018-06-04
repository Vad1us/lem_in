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

# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"
# include "lemin.h"

typedef struct		s_room t_room;

typedef struct		s_link
{
	t_room			*r_name;
	struct s_link	*next;
}					t_link;

#endif;
