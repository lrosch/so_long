/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 11:34:27 by lrosch            #+#    #+#             */
/*   Updated: 2021/10/27 13:47:48 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(char **argv)
{
	int		fd;
	int		lines;
	char	*str;

	fd = open(argv[1], O_RDONLY);
	lines = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		free (str);
		lines++;
	}
	close(fd);
	return (lines);
}

unsigned int	ft_strlen_so_long(const char *s)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != '\n')
			j++;
		i++;
	}
	return (j);
}

int	exit_game(void)
{
	exit (0);
}
