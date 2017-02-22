/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 11:07:22 by spetrenk          #+#    #+#             */
/*   Updated: 2016/12/14 12:10:47 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

static char	get_ij(char *str, int i, int j, int size)
{
	if (i < 0 || i > 3 || j < 0 || j > 3)
		return (0);
	return (*(str + size * i + j));
}

static int	neigh_count(char *str, int i, int j)
{
	int count;

	count = 0;
	if (get_ij(str, i + 1, j, 4) == '#')
		count++;
	if (get_ij(str, i - 1, j, 4) == '#')
		count++;
	if (get_ij(str, i, j + 1, 4) == '#')
		count++;
	if (get_ij(str, i, j - 1, 4) == '#')
		count++;
	return (count);
}

static int	check_neighbor(char *str)
{
	int i;
	int j;
	int count;

	i = -1;
	count = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if (get_ij(str, i, j, 4) == '#')
				count += neigh_count(str, i, j);
	}
	if (count < 6)
		return (0);
	return (1);
}

static int	check_symb_size(char *s, int s_symb, int f_symb, size_t size)
{
	size_t	count_full_space;

	if (ft_strlen(s) > size * size || ft_strlen(s) < size * size)
		return (0);
	count_full_space = 0;
	while (*s)
	{
		if (*s == f_symb)
			count_full_space++;
		else if (*s != s_symb)
			return (0);
		s++;
	}
	if (count_full_space != size)
		return (0);
	return (1);
}

int			check_str(char *str)
{
	if (!check_symb_size(str, '.', '#', 4) || !check_neighbor(str))
		return (0);
	return (1);
}
