/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 16:27:21 by spetrenk          #+#    #+#             */
/*   Updated: 2016/12/14 12:12:20 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

size_t	get_size(t_tetrimino *head)
{
	size_t count;

	count = 0;
	while (head)
	{
		count++;
		head = head->next;
	}
	return (count);
}
