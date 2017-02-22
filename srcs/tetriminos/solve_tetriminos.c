/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 15:16:05 by spetrenk          #+#    #+#             */
/*   Updated: 2016/12/16 10:59:24 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

static int	is_insert(char **arr, int i, int j, t_tetrimino *tetrimino)
{
	int *rows;
	int *columns;
	int counter;

	rows = tetrimino->rows;
	columns = tetrimino->columns;
	counter = -1;
	while (++counter < 4)
	{
		if (i + rows[counter] < 0 || i + rows[counter] >= g_map_size ||
				j + columns[counter] < 0 ||
				j + columns[counter] >= g_map_size ||
				arr[i + rows[counter]][j + columns[counter]] != '.')
			return (0);
	}
	return (1);
}

static void	insert(char **arr, int i, int j, t_tetrimino *tetrimino)
{
	int *rows;
	int *columns;
	int counter;

	rows = tetrimino->rows;
	columns = tetrimino->columns;
	counter = -1;
	while (++counter < 4)
	{
		arr[i + rows[counter]][j + columns[counter]] = tetrimino->letter;
	}
}

static void	remove(char **arr, int i, int j, t_tetrimino *tetrimino)
{
	int *rows;
	int *columns;
	int counter;

	rows = tetrimino->rows;
	columns = tetrimino->columns;
	counter = -1;
	while (++counter < 4)
		arr[i + rows[counter]][j + columns[counter]] = '.';
}

static int	solve(char **map, t_tetrimino *head)
{
	int i;
	int j;

	if (!head)
		return (1);
	i = -1;
	while (++i < g_map_size)
	{
		j = -1;
		while (++j < g_map_size)
		{
			if (is_insert(map, i, j, head))
			{
				insert(map, i, j, head);
				if (solve(map, head->next))
					return (1);
				remove(map, i, j, head);
			}
		}
	}
	return (0);
}

char		**solve_tetriminos(t_tetrimino *head)
{
	char	**map;

	map = get_map(2);
	while (!solve(map, head))
		resize_map(&map);
	return (map);
}
