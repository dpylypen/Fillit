/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetriminos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 18:15:25 by spetrenk          #+#    #+#             */
/*   Updated: 2016/12/06 13:22:15 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

t_tetrimino		*get_tetriminos(char *file)
{
	int			fd;
	t_tetrimino	*head;
	t_tetrimino	*cur;
	char		space;
	int			letter;

	letter = 65;
	fd = open(file, O_RDONLY);
	head = get_tetrimino(fd, 4, letter);
	cur = head;
	while (1)
	{
		letter++;
		if (!(cur->letter))
			return (0);
		if (!read(fd, &space, 1))
			break ;
		cur->next = get_tetrimino(fd, 4, letter);
		if (!(cur->next))
			break ;
		cur = cur->next;
	}
	close(fd);
	return (head);
}
