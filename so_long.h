/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:07:46 by andrefranci       #+#    #+#             */
/*   Updated: 2023/03/22 22:43:37 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/* map_set */
typedef struct s_map
{
	int		x;
	int		y;
	int		map_is_rectangular;
	int		map_is_enclosed;
	int		map_1_exit;
	int		map_1_start_pos;
	int		map_is_only_01pce;
	int		map_has_colectibles;
	int		number_of_c;
	int		map_goal_exit;
	int		map_goal_c;

	int		p_pos_y;
	int		p_pos_x;

	char	**map;
}			t_map;

/* check_arguments_input */
int			check_map_name(char *str);
int			check_arguments_input(int ac, char **av);

/* map_init.c */
int			ft_count_lines(char *argv);
char		**map_reader(char *argv);
t_map		*map_init(char *argv);

/* map_check */
int			map_1_exit(char **map, t_map *map_set);
int			map_is_enclosed(char **map, t_map *map_set);
int			map_is_rectangular(char **map, t_map *map_set);
int			map_checklist(char **map, t_map *map_set);

/* map_check2 */
int			map_is_only_01pce(char **map, t_map *map_set);
int			map_has_colectibles(char **map, t_map *map_set);
void		map_goal_possible(t_map *map_set, char **map_canvas, int p_pos_y,
				int p_pos_x);

/* map_check_utils */
int		ft_count_map_lines(t_map *map_set);
int			number_of_c(t_map *map_set);
char		**map_blank(int y, int x);

/* free_memory */
char		**free_map(char **map, int y);
t_map		*free_t_map(t_map *map_set, char error);
#endif
