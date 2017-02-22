/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 09:57:08 by spetrenk          #+#    #+#             */
/*   Updated: 2016/12/14 14:58:11 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_TETRIMINOS_H
# define FILLIT_TETRIMINOS_H

# include <stdlib.h>
# include <fcntl.h>
# include "filereader.h"
# include "libft.h"

int						g_map_size;

typedef struct			s_tetrimino
{
	struct s_tetrimino	*next;
	char				letter;
	int					rows[4];
	int					columns[4];
}						t_tetrimino;

t_tetrimino				*get_tetrimino(int fd, int size, char letter);
char					**get_map(size_t size);
void					resize_map(char ***map);
t_tetrimino				*get_tetriminos(char *file);
t_tetrimino				*set_tetrimino(char *cont, char letter);
int						check_str(char *str);
void					out_solution(char **map);
char					**solve_tetriminos(t_tetrimino *head);

#endif
