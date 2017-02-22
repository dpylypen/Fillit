/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetrimino.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 10:05:17 by spetrenk          #+#    #+#             */
/*   Updated: 2016/12/14 14:53:31 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

t_tetrimino			*get_tetrimino(int fd, int size, char letter)
{
	char	*str_tetriminos;
	char	*cur_tetriminos;
	int		i;

	str_tetriminos = (char *)ft_memalloc(size * size + 1);
	cur_tetriminos = 0;
	i = -1;
	if ((fd >= 0) && str_tetriminos)
	{
		while (++i < size)
		{
			cur_tetriminos = read_line(fd, size + 1);
			if (cur_tetriminos)
				ft_strcat(str_tetriminos, cur_tetriminos);
			else
				break ;
		}
	}
	if (!check_str(str_tetriminos))
	{
		free(str_tetriminos);
		str_tetriminos = 0;
	}
	free(cur_tetriminos);
	return (set_tetrimino(str_tetriminos, letter));
}
