/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 09:12:23 by spetrenk          #+#    #+#             */
/*   Updated: 2016/12/14 12:43:30 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filereader.h"

char	*read_line(int fd, int count)
{
	char	*buf;
	ssize_t	read_size;

	buf = (char *)malloc(count);
	read_size = read(fd, buf, count);
	if (read_size < count - 1)
	{
		free(buf);
		return (0);
	}
	if (buf[count - 1] == '\n')
		buf[count - 1] = 0;
	else
		return (0);
	return (buf);
}
