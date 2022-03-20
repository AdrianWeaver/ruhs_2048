/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douattar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 14:22:12 by douattar          #+#    #+#             */
/*   Updated: 2022/03/20 16:58:04 by douattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2048.h"

int	new_score(int best, char *pseudo);
{
	int	fd[2];
	char	*str;
	cha	*temp;
	char	*line;
	int	i;
	int	end;

	unlink("/tmp/temp.txt");
	fd[0] = open("/tmp/temp.txt", O_WRONLY | O_CREAT);
	if (fd[0] == NULL)
		return (1);
	fd[1] = open("score.txt", O_RDONLY | O_CREAT);
	if (fd[1] == NULL)
		return (1);
	line = ft_strjoin(pseudo, " : "); 
	if (line == NULL)
		return (1);
	str = ft_itoa(best);
	if (str == NULL)
		return (1);
	temp = line;
	line = ft_strjoin(line, str);
	if (line == NULL)
		return (1);
	free(temp);
	free(str);
	end = 0;
	while ((str = get_next_line(fd[1])) != NULL)
	{
		if (end == 0 && ft_atoi(str + 6) < best)
		{
			write(fd[0], line, sizeof(str));
			end++;
		}
		write(fd[0], str, sizeof(str));
		free(str);
	}
	close(fd[1]);
	close(fd[0]);
	if (end == 0)
		return (0);
	fd[0] = open("/tmp/temp.txt", O_RDONLY | O_CREAT);
	if (fd[0] == NULL)
		return (1);
	fd[1] = open("score.txt", O_WRONLY | O_CREAT);
	if (fd[1] == NULL)
		return (1);
	i = 0;
	while (i < 5 && (str = get_next_line(fd[0])) != NULL)
	{
		write(fd[1], str, sizeof(str));
		i++;
	}
	close(fd[1]);
	close(fd[0]);
	return (0);
}
