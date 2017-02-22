/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filereader.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 09:09:44 by spetrenk          #+#    #+#             */
/*   Updated: 2016/12/02 09:11:05 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_FILEREADER_H
# define FILLIT_FILEREADER_H

# include <unistd.h>
# include <stdlib.h>

char	*read_line(int fd, int count);

#endif
