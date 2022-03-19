/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2048.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 09:38:39 by aweaver           #+#    #+#             */
/*   Updated: 2022/03/19 13:00:23 by douattar         ###   ########.fr       */
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

typedef struct s_block {
	int	number;
	int	fusion;
}		t_block;

t_block	*initialisation(int size);
void	new_block(t_block *plate, int size);
int	winning(t_block *plate, int size);
t_block	*copy(t_block *original, int size);
int	lose(t_block *plate, int size);

int	get_random(void);
int	is_power_2(int n);

enum	e_const
{
	WIN_VALUE = 2048
};


#endif
