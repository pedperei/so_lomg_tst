/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:24:59 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/03/22 22:43:23 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_map_lines(t_map *map_set)
{
	int	i;

	i = 0;
	while (i < map_set->y)
	{
		i++;
	}
	return (i);
}

int	number_of_c(t_map *map_set)
{
	int	i;
	int	j;
	int	count_colectibles;

	i = 0;
	count_colectibles = 0;
	while (i < map_set->y)
	{
		j = 0;
		while (map_set->map[i][j])
		{
			if (map_set->map[i][j] == 'C')
			{
				count_colectibles++;
			}
			j++;
		}
		i++;
	}
	return (count_colectibles);
}

char	**map_blank(int y, int x)
{
	char	**map_blank;
	int		i;

	map_blank = (char **)ft_calloc(y, sizeof(char *));
	i = 0;
	while (i < y)
	{
		map_blank[i] = (char *)ft_calloc(x + 1, sizeof(char));
		i++;
	}
	return (map_blank);
}