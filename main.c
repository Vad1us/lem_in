#include "lemin.h"

static void ft_initial(t_room *r)
{
	r->start = 0;
	r->end = 0;
	r->link = NULL;
	r->name = NULL;
	r->next = NULL;
	r->x = 0;
	r->y = 0;
	r->ant = 0;
}

int		main(void)
{
	char	*s;
	char	**r;
	t_room	*room;
	t_room	*rooms;
	int		start;
	int		end;
	int 	ants;
	int 	i;

	i = 0;
	ants = 0;
	start = 0;
	end = 0;
	rooms = NULL;//(t_room*)malloc(sizeof(t_room));
	//ft_initial(rooms);
	get_next_line(0, &s);
	while (ants == 0)
	{
		while (s[i]  && ants == 0)
		{
			//ft_printf("1111");
			if (ft_isdigit(s[i]) && s[i + 1] == '\0')
			{
				ants = ft_atoi(s);
				ft_printf("ants %i\n", ants);
			}
			i++;
		}
		if (ants != 0)
			break ;
		if (ft_strequ(s, "##start") != 1 && ft_strequ(s, "##end") != 1 && ft_strncmp(s, "#", 1) == 0)
			get_next_line(0, &s);
		else
		{
			ft_printf("ERROR: wrong ants");
			return (0);
		}
	}
	while (get_next_line(0, &s))
	{
		room = (t_room*)malloc(sizeof(t_room));
		ft_initial(room);
		while (ft_strequ(s, "##start") == 0 && ft_strequ(s, "##end") == 0 && ft_strncmp(s, "#", 1) == 0)
			get_next_line(0, &s);
		if (ft_strequ(s, "##start"))
		{
			room->start = 1;
			start++;
			get_next_line(0, &s);
		}
		else if (ft_strequ(s, "##end"))
		{
			room->end = 1;
			end++;
			get_next_line(0, &s);
		}
		while (ft_strequ(s, "##start") != 1 && ft_strequ(s, "##end") != 1 && ft_strncmp(s, "#", 1) == 0)
			get_next_line(0, &s);
		if (ft_valid_room(s) == 1)
		{
			r = ft_strsplit(s, ' ');
			room->name = r[0];
			room->x = ft_atoi(r[1]);
			room->y = ft_atoi(r[2]);
		}
		else if (end != 1 || start != 1)
		{
			ft_printf("ERROR\n");
			return (0);
		}
		else
		{
			if (ft_links(rooms, s) == 0)
				break ;
		}
		room->next = rooms;
		rooms = room;
	}
	//ft_myway(rooms);
	//ft_printf("HELLO1\n");
	while (rooms)
	{
		while (rooms->link)
		{
			//ft_printf("HELLO1\n");
			ft_printf("r %s\n", rooms->name);
			//ft_printf("r %s l %s\n", rooms->name, rooms->link->r_name->name);
			rooms->link = rooms->link->next;
		}
		rooms = rooms->next;
	}
	return (0);
}