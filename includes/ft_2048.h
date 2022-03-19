/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2048.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 09:38:39 by aweaver           #+#    #+#             */
/*   Updated: 2022/03/19 11:46:21 by aweaver          ###   ########.fr       */
/*   Updated: 2022/03/19 10:36:56 by douattar         ###   ########.fr       */
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
# include "libftprintf.h"

enum	e_const
{
	WIN_VALUE = 2048
};

typedef struct s_block {
	int	number;
	int	fusion;
}		t_block;

#endif
