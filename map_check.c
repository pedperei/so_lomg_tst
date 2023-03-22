/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:23:48 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/03/22 22:46:44 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_1_start_pos(char **map, t_map *map_set)
{
	int	i;
	int	j;
	int	count_start_position;

	i = 0;
	count_start_position = 0;
	while (i < map_set->y)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				map_set->p_pos_y = i;
				map_set->p_pos_x = j;
				count_start_position++;
			}
			j++;
		}
		i++;
	}
	if (count_start_position != 1)
		return (0);
	map_set->map_1_start_pos = 1;
	return (1);
}

int	map_1_exit(char **map, t_map *map_set)
{
	int	i;
	int	j;
	int	count_exit;

	i = 0;
	count_exit = 0;
	while (i < map_set->y)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				count_exit++;
			j++;
		}
		i++;
	}
	if (count_exit != 1)
		return (0);
	map_set->map_1_exit = 1;
	return (1);
}

int	map_is_enclosed(char **map, t_map *map_set)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_set->y)
	{
		if (i == 0 || i == ft_count_map_lines(map_set) - 1)
		{
			j = 0;
			while (j <= (map_set->x - 2))
			{
				if (map[i][j] != '1')
					return (0);
				j++;
			}
		}
		if (map[i][0] != '1')
			return (0);
		if (map[i][ft_strlen(map[i]) - 2] != '1')
			return (0);
		i++;
	}
	map_set->map_is_enclosed = 1;
	return (1);
}

int	map_is_rectangular(char **map, t_map *map_set)
{
	int	i;
	int	line_lenght;
	int	line_lenght2;

	line_lenght = ft_strlen(map[0]);
	i = 1;
	while (i < map_set->y)
	{
		line_lenght2 = ft_strlen(map[i]);
		if (i == map_set->y - 1)
			line_lenght2 += 1;
		if (line_lenght2 != line_lenght)
			return (0);
		i++;
	}
	if (i < 3)
		return (0);
	map_set->map_is_rectangular = 1;
	return (1);
}

int	map_checklist(char **map, t_map *map_set)
{
	if (!map_is_rectangular(map, map_set))
	{
		free_t_map(map_set, 'a');
		return (0);
	}
	if (!map_is_enclosed(map, map_set))
	{
		free_t_map(map_set, 'b');
		return (0);
	}
	if (!map_1_exit(map, map_set) || !map_1_start_pos(map, map_set))
	{
		free_t_map(map_set, 'c');
		return (0);
	}
	if (!map_has_colectibles(map, map_set) || !map_is_only_01pce(map, map_set))
	{
		free_t_map(map_set, 'd');
		return (0);
	}
	return (1);
}

/* main to test map_is_rectangular */
/* int	main(void)
{
	char *map[] = {
		"11111111", 
		"100000E1", 
		"10P0C001", 
		"11111111"
		};
	printf("map is rectangular: %d \n", map_is_rectangular(map));
	printf("map is enclosed: %d \n", map_is_enclosed(map));
	printf("map has 1 exit: %d \n", map_1_exit(map));
	printf("map has 1 start_position: %d \n", map_1_start_pos(map));
	printf("map has colectibles: %d \n", map_has_colectibles(map));
	printf("map is only 01pce: %d \n", map_is_only_01pce(map));
}
 */