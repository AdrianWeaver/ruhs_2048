/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aw.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 09:35:55 by aweaver           #+#    #+#             */
/*   Updated: 2022/03/19 16:45:34 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2048.h"

void	ft_destroy_board(void *window, void **board, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		delwin(board[i]);
		i++;
	}
	delwin(window);
}

void	**ft_create_box(void *window, int size)
{
	void	**board;
	int		tile_nb;
	int		i;
	int		j;

	i = 0;
	tile_nb = 0;
	board = malloc(sizeof(*board) * (size * size));
	if (board == NULL)
	{
		ft_destroy_board(window, board, 0);
		endwin();
		exit (MALLOC_ERROR);
	}
	wresize(window, 2 + (size * 6), 4 + (size * 12));
	wborder(window, 0, 0, 0, 0, 0, 0, 0, 0);
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			board[tile_nb] = subwin(window, 6, 12, 1 + (j * 6), 2 + (i * 12));
			wborder(board[tile_nb], 0, 0, 0, 0, 0, 0, 0, 0);
			tile_nb++;
			j++;
		}
		i++;
	}
	return (board);
}

void	ft_check_size(void *window, void **board, int size)
{
	int	win_col;
	int	win_line;

	getmaxyx((WINDOW *)window, win_line, win_col);
	while (win_col < 4 + (size * 12) || win_line < 2 + (size * 6))
	{
		getmaxyx((WINDOW *)window, win_line, win_col);
		ft_destroy_board(window, board, size);
		ft_printf("Incorrect terminal size, please resize to minimum %dL %dH\n\r",
			4 + (size * 6), 2 + (size * 12));
	}
}

int	main(int argc, char **argv)
{
	t_block	*board_values;
	void	*window;
	void	**board;
	int		key;
	int		size;
	int		win;
	int		won;

	if (argc != 2)
		return (1);
	size = ft_atoi(argv[1]);
	win = 0;
	won = 0;
	board_values = initialisation(size);
	if (board_values == NULL)
		return (1);
	window = initscr();
	cbreak();
	noecho();
	keypad(window, TRUE);
	nodelay(window, TRUE);
	board = ft_create_box(window, size);
	while (1)
	{
		key = wgetch(window);
		win = movement(key, board_values, size, win);
		if (key == KEY_ESC)
		{
			break ;
		}
		refresh();
		ft_check_size(window, board, size);
		if (win == 1)
			won = 1;
	}
	ft_destroy_board(window, board, size);
	endwin();
	free(board_values);
	exit(0);
	return (0);
}
