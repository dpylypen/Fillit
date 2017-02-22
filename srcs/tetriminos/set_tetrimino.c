/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tetrimino.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 13:32:10 by spetrenk          #+#    #+#             */
/*   Updated: 2016/12/14 12:15:59 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

static void	get_first_cord(int *x, int *y, char *str)
{
	int i;
	int j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (*(str + i * 4 + j) == '#')
			{
				*x = i;
				*y = j;
				return ;
			}
		}
	}
}

static void	set_cord(char *str, t_tetrimino *tetrimino)
{
	int x;
	int y;
	int i;
	int j;
	int cord;

	get_first_cord(&x, &y, str);
	i = x - 1;
	j = y;
	cord = 1;
	tetrimino->rows[cord - 1] = 0;
	tetrimino->columns[cord - 1] = 0;
	while (++i < 4)
	{
		while (++j < 4)
		{
			if (*(str + i * 4 + j) == '#')
			{
				tetrimino->rows[cord] = i - x;
				tetrimino->columns[cord] = j - y;
				cord++;
			}
		}
		j = -1;
	}
}

t_tetrimino	*set_tetrimino(char *cont, char letter)
{
	t_tetrimino *tetrimino;

	tetrimino = (t_tetrimino *)malloc(sizeof(t_tetrimino));
	if (tetrimino)
	{
		tetrimino->next = 0;
		if (!cont)
			tetrimino->letter = 0;
		else
		{
			tetrimino->letter = letter;
			set_cord(cont, tetrimino);
		}
	}
	return (tetrimino);
}
