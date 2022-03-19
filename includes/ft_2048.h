/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2048.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 09:38:39 by aweaver           #+#    #+#             */
/*   Updated: 2022/03/19 13:35:38 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_2048_H
# define FT_2048_H
# define TRUE 1
# define HOLLOW 0
# define FALSE 0

# include <time.h>
# include <stdlib.h>
# include <signal.h>
# include <curses.h>
# include "libft.h"
# include "libftprintf.h"
# include "get_next_line.h"

/****************************************************************************/
/*								Data define									*/
/****************************************************************************/

typedef struct s_block {
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

int		get_random(void);
void	new_block(t_block *plate, int size);
int		winning(t_block *plate, int size);
int		is_power_2(int n);
t_block	*initialisation(int size);

/****************************************************************************/
/*								Key define									*/
/****************************************************************************/

# define KEY_ESC 27

#endif
