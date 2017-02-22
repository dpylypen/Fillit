/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 09:29:07 by spetrenk          #+#    #+#             */
/*   Updated: 2016/12/14 13:36:27 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tetriminos.h"

int		main(int argc, char **argv)
{
	t_tetrimino *list;

	if (argc == 2)
	{
		list = get_tetriminos(argv[1]);
		if (list)
			out_solution(solve_tetriminos(list));
		else
			ft_putendl("error");
	}
	else
		ft_putendl("usage: ./fillit source_file");
	return (0);
}
