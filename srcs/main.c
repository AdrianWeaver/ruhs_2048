/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 09:35:55 by aweaver           #+#    #+#             */
/*   Updated: 2022/03/20 08:22:54 by aweaver          ###   ########.fr       */
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

void	ft_color_border(t_block *board_values, void **board, int tile_nb)
{
	if (board_values[tile_nb].number == 2)
		wattron(board[tile_nb], COLOR_PAIR(1));
	if (board_values[tile_nb].number == 4)
		wattron(board[tile_nb], COLOR_PAIR(2));
	if (board_values[tile_nb].number == 8)
		wattron(board[tile_nb], COLOR_PAIR(3));
	if (board_values[tile_nb].number == 16)
		wattron(board[tile_nb], COLOR_PAIR(4));
	if (board_values[tile_nb].number == 32)
		wattron(board[tile_nb], COLOR_PAIR(5));
	if (board_values[tile_nb].number == 64)
		wattron(board[tile_nb], COLOR_PAIR(6));
	if (board_values[tile_nb].number == 128)
		wattron(board[tile_nb], COLOR_PAIR(7));
	if (board_values[tile_nb].number == 256)
		wattron(board[tile_nb], COLOR_PAIR(8));
	if (board_values[tile_nb].number == 512)
		wattron(board[tile_nb], COLOR_PAIR(9));
	if (board_values[tile_nb].number == 1024)
		wattron(board[tile_nb], COLOR_PAIR(10));
	if (board_values[tile_nb].number == 2048)
		wattron(board[tile_nb], COLOR_PAIR(11));
}

void	ft_color_letters(t_block *board_values, void **board, int tile_nb)
{
	if (board_values[tile_nb].number == 2)
		wattron(board[tile_nb], COLOR_PAIR(1));
	if (board_values[tile_nb].number == 4 || board_values[tile_nb].number == 128)
		wattron(board[tile_nb], COLOR_PAIR(2));
	if (board_values[tile_nb].number == 8 || board_values[tile_nb].number == 256)
		wattron(board[tile_nb], COLOR_PAIR(3));
	if (board_values[tile_nb].number == 16 || board_values[tile_nb].number == 512)
		wattron(board[tile_nb], COLOR_PAIR(4));
	if (board_values[tile_nb].number == 32 || board_values[tile_nb].number == 1024)
		wattron(board[tile_nb], COLOR_PAIR(5));
	if (board_values[tile_nb].number == 64 || board_values[tile_nb].number == 2048)
		wattron(board[tile_nb], COLOR_PAIR(6));
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
			ft_color_border(board_values, board, tile_nb);
			wborder(board[tile_nb], 0, 0, 0, 0, 0, 0, 0, 0);
			ft_color_letters(board_values, board, tile_nb);
			if (board_values[tile_nb].number != 0)
				mvwprintw(board[tile_nb],
					(tile_height / 2), (tile_length /2), "%d", board_values[tile_nb].number);
			else
				wattron(board[tile_nb], COLOR_PAIR(1));
			tile_nb++;
			j++;
		}
		i++;
	}
	return (board);
}

void	**ft_redraw(void *window, int size, void **board, t_block *board_values)
{
	refresh();
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

void	ft_init_color(void)
{
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);		//2 
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);	//4		|| 128
	init_pair(3, COLOR_RED, COLOR_BLACK);		//8		|| 256
	init_pair(4, COLOR_MAGENTA, COLOR_BLACK);	//16	|| 512
	init_pair(5, COLOR_CYAN, COLOR_BLACK);		//32	|| 1024
	init_pair(6, COLOR_GREEN, COLOR_BLACK);		//64	|| 2048
	init_pair(7, COLOR_YELLOW, COLOR_YELLOW);	//128 border
	init_pair(8, COLOR_RED, COLOR_RED);			//256 border
	init_pair(9, COLOR_MAGENTA, COLOR_MAGENTA);	//512 border
	init_pair(10, COLOR_CYAN, COLOR_CYAN);		//1024 border
	init_pair(11, COLOR_GREEN, COLOR_GREEN);	//2048 border
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
	ft_init_color();
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
		if (win == 2)
			break ;
		if (won == 1)
			(void)won; //print a winning message;
	}
	ft_destroy_board(window, board, size);
	clear();
	endwin();
	free(board_values);
	if (win == 2)
		ft_printf("You lost I'm afraid\n");
	exit(0);
	return (0);
}
