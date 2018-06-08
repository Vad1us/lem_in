/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 15:04:29 by vradchen          #+#    #+#             */
/*   Updated: 2018/06/01 15:04:31 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"
# include "lemin2.h"

typedef struct s_link	t_link;

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
	int				st;
	int				end;
	struct s_link	*link;
	struct s_room	*next;
	int				ant;
	int				depth;
}					t_room;

int					ft_data(char **s, t_room **rooms);
void				ft_print_path(t_link *p, int ants);
void				ft_find_path(t_room *r, int ants);
void				ft_depth(t_room *r);
int					ft_links(t_room *rooms, char *s);
int					ft_valid_room(char *s);
void				ft_initial_room(t_room *r);

#endif
