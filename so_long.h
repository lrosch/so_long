/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 12:08:30 by lrosch            #+#    #+#             */
/*   Updated: 2022/05/18 12:08:20 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include "minilibx/mlx.h"
# include "libftp/libft/libft.h"
# include "libftp/gnl/get_next_line.h"

typedef struct s_game {
	void	*wall;
	void	*player;
	void	*exit;
	void	*floor;
	void	*collect;
	void	*win;
	void	*mlx;
	char	**map;
	int		x;
	int		y;
	int		px;
	int		py;
	int		steps;
	int		nbrcollect;
	int		collected;
	int		playerput;
}				t_game;

typedef struct s_error {
	int	C;
	int	E;
	int	P;
}				t_error;

/* so_long_functions */

void				paint_sprite(t_game *game, int i, int j);
void				paint_map(t_game *game);
void				read_map(t_game *game, char **argv);
void				initiate_game(t_game *game, char **argv);
void				get_player_position(t_game *game);
void				get_dominant_player(t_game *game);

/* so_long_utils */

int					count_lines(char **argv);
void				check_for_collectible(t_game *game, char c);
void				update(t_game *game, int x, int y);
void				check_win(t_game *game);
unsigned int		ft_strlen_so_long(const char *s);

/* button_events */

int					button_event(int keycode, t_game *game);
void				event_esc(t_game *game);
void				event_w(t_game *game);
void				event_a(t_game *game);
void				event_s(t_game *game);
void				event_d(t_game *game);
int					exit_game(void);

/* checking for valid map */

void				check_valid_map(t_game *game);
int					check_char(t_game *game);
int					check_for_ele(t_game *game, t_error *error);
int					check_rectangle(t_game *game);
int					check_enclosure(t_game *game);
int					enclosure_x(t_game *game);
int					enclosure_y(t_game *game);

#endif