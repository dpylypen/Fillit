/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 17:40:19 by spetrenk          #+#    #+#             */
/*   Updated: 2016/12/14 14:59:45 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

char	**get_map(size_t size)
{
	char	*str;
	char	**ret_arr;
	size_t	i;

	g_map_size = size;
	str = (char *)malloc(size * size + size);
	ft_memset(str, '.', size * size + size);
	str[size * size + size] = 0;
	ret_arr = (char **)malloc(sizeof(char *) * (size + 1));
	i = -1;
	while (++i < size)
	{
		ret_arr[i] = str;
		*(str + size) = 0;
		str = str + size + 1;
	}
	ret_arr[i] = 0;
	return (ret_arr);
}
