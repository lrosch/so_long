/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 13:42:31 by lrosch            #+#    #+#             */
/*   Updated: 2022/07/29 14:06:06 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
void	read_map(t_game *game, char **argv)
{
	char	*str;
	int		fd;
	int		lines;

	lines = (count_lines(argv));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error\ninvalid map\n");
		exit(0);
	}
	game->map = (char **)malloc(lines * sizeof(char *));
	lines = 0;
	while (1)
	{
		str = get_next_line(fd);
		printf("%s\n", str);
		if (str == NULL)
			break ;
		game->map[lines] = str;
		lines++;
	}
	close(fd);
	game->x = (ft_strlen(game->map[0]) - 1);
	game->y = lines;
}

void	paint_sprite(t_game *game, int i, int j)
{
	int	x;
	int	y;

	y = i * 64;
	x = j * 64;
	if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall, x, y);
	else if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->collect, x, y);
	else if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->floor, x, y);
	else if (game->map[i][j] == 'P' && game->playerput != 1)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->player, x, y);
		game->playerput = 1;
	}
	else if (game->map[i][j] == 'P' && game->playerput == 1)
		mlx_put_image_to_window(game->mlx, game->win, game->floor, x, y);
	else if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->exit, x, y);
}

void	paint_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->y)
	{
		paint_sprite(game, i, j);
		if (game->map[i][j] == 'C')
		{
			game->nbrcollect++;
		}
		if (game->map[i][j] == '\0')
		{
			i++;
			j = 0;
		}
		else if (game->map[i][0] != '\n')
			j++;
	}
}

void	update(t_game *game, int x, int y)
{
	game->collected++;
	game->map[y][x] = '0';
}
