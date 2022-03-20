/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2048.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 09:38:39 by aweaver           #+#    #+#             */
/*   Updated: 2022/03/20 14:32:52 by douattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_2048_H
# define FT_2048_H
# define TRUE 1
# define HOLLOW 0
# define FALSE 0
# define MALLOC_ERROR 12

# include <time.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <curses.h>
# include "libft.h"
# include "libftprintf.h"
# include "get_next_line.h"

/****************************************************************************/
/*								Data define									*/
/****************************************************************************/

typedef struct s_block
{
	int	number;
	int	fusion;
}		t_block;

enum	e_const
{
	WIN_VALUE = 2048
};

/****************************************************************************/
/*							Functions define								*/
/****************************************************************************/

int	movement(int direction, t_block *plate, int size, int win, int *score);
int	down(t_block *plate, int size, int *score);
int	up(t_block *plate, int size, int *score);
int	left(t_block *plate, int size, int *score);
int	right(t_block *plate, int size, int *score);
int	reset(t_block *plate, int size);
void	new_block(t_block *plate, int size, unsigned int key);
int	compare(t_block *original, t_block *copy, int size);
int		get_random(void);
void	swap(int *a, int *b);
int		winning(t_block *plate, int size);
int		lose(t_block *plate, int size);
int		is_power_2(int n);
int		fusion(t_block *a, t_block *b);
t_block	*initialisation(int size);
t_block	*copy(t_block *original, int size);

/****************************************************************************/
/*								Key define									*/
/****************************************************************************/

# define KEY_ESC 27

#endif
