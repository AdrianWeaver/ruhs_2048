/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 09:35:55 by aweaver           #+#    #+#             */
/*   Updated: 2022/03/19 19:36:51 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2048.h"

int	g_resize = 0;

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

void	**ft_create_box(void *window, int size, t_block *board_values)
{
	void	**board;
	int		tile_nb;
	int		i;
	int		j;
	int		win_col;
	int		win_line;
	int		tile_length;
	int		tile_height;

	i = 0;
	tile_nb = 0;
	board = malloc(sizeof(*board) * (size * size));
	if (board == NULL)
	{
		ft_destroy_board(window, board, 0);
		endwin();
		exit (MALLOC_ERROR);
	}
	getmaxyx(stdscr, win_line, win_col);
	tile_length = (win_col - 4) / size;
	tile_height = (win_line - 2) / size;
	wresize(window, 2 + (size * tile_height), 4 + (size * tile_length));
	wborder(window, 0, 0, 0, 0, 0, 0, 0, 0);
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			board[tile_nb] = subwin(window, tile_height, tile_length , 1 + (j * tile_height), 2 + (i *tile_length));
			wborder(board[tile_nb], 0, 0, 0, 0, 0, 0, 0, 0);
			if (board_values[tile_nb].number != 0)
				mvwprintw(board[tile_nb],
					(tile_height / 2), (tile_length /2), "%d", board_values[tile_nb].number);
			tile_nb++;
			j++;
		}
		i++;
	}
	return (board);
}

void	**ft_redraw(void *window, int size, void **board, t_block *board_values)
{
	ft_destroy_board(window, board, size);
	return (ft_create_box(window, size, board_values));
}

void	ft_check_size(void *window, void **board, int size)
{
	int	win_col;
	int	win_line;

	getmaxyx(stdscr, win_line, win_col);
	if (win_col < 4 + (size * 12) || win_line < 2 + (size * 6))
	//while (win_col < 4 + (size * 12) || win_line < 2 + (size * 6))
	{
		refresh();
		//getmaxyx(stdscr, win_line, win_col);
		ft_destroy_board(window, board, size);
		clear();
		ft_printf("Incorrect terminal size, please resize to minimum %dL %dH\n\r",
			4 + (size * 6), 2 + (size * 12));
		g_resize = 0;
	}
	while (g_resize == 0)
		;
}

void	ft_resize_handle(int signal)
{
	(void)signal;
	g_resize = 1;
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
	signal(28, ft_resize_handle);
	board = ft_create_box(window, size, board_values);
	while (1)
	{
		if (g_resize == 1)
		{
			ft_check_size(window, board, size);
			g_resize = 0;
		}
		key = wgetch(window);
		if (key == KEY_UP || key == KEY_DOWN || key == KEY_RIGHT || key == KEY_LEFT)
		{
			win = movement(key, board_values, size, win);
			clear();
			refresh();
			ft_redraw(window, size, board, board_values);
		}
		if (key == KEY_ESC)
		{
			break ;
		}
		refresh();
		if (win == 1)
			won = 1;
	}
	ft_destroy_board(window, board, size);
	endwin();
	free(board_values);
	exit(0);
	return (0);
}
