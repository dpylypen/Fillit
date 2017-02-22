/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 18:57:05 by spetrenk          #+#    #+#             */
/*   Updated: 2016/12/14 15:01:53 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

void	resize_map(char ***map)
{
	char	**new_map;

	new_map = get_map(++g_map_size);
	free((*map)[0]);
	free(*map);
	*map = new_map;
}
