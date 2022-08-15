/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 10:24:04 by lrosch            #+#    #+#             */
/*   Updated: 2022/07/19 15:16:06 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_valid_map(t_game *game)
{
	t_error	error;

	error.P = 0;
	error.C = 0;
	error.E = 0;
	if (check_char(game) == -1 || check_for_ele(game, &error) == -1
		|| check_rectangle(game) == -1 || check_enclosure(game) == -1)
	{
		printf("Error\ninvalid map\n");
		exit(0);
	}
}

int	check_char(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->y)
	{
		if (game->map[i][j] != '0' && game->map[i][j] != '1' && game->map[i][j]
			!= 'C' && game->map[i][j] != 'E' && game->map[i][j] != 'P' &&
			game->map[i][j] != '\0' && game->map[i][j] != '\n')
			return (-1);
		if (game->map[i][0] == '\n')
			return (-1);
		if (game->map[i][j] == '\0')
		{
			i++;
			j = 0;
		}
		else if (game->map[i][0] != '\n')
			j++;
	}
	return (0);
}

int	check_for_ele(t_game *game, t_error *error)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->y)
	{
		if (game->map[i][j] == 'P')
			error->P = 1;
		if (game->map[i][j] == 'C')
			error->C = 1;
		if (game->map[i][j] == 'E')
			error->E = 1;
		if (game->map[i][j] == '\0')
		{
			i++;
			j = 0;
		}
		else if (game->map[i][0] != '\n')
			j++;
	}
	if (error->P == 0 || error->C == 0 || error->E == 0)
		return (-1);
	return (0);
}

int	check_rectangle(t_game *game)
{
	unsigned int	i;
	int				j;

	j = 0;
	i = ft_strlen_so_long(game->map[j]);
	while (j < game->y)
	{
		if (ft_strlen_so_long(game->map[j]) != i)
			return (-1);
		j++;
	}
	return (0);
}
