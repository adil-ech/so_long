/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:31:56 by adechaji          #+#    #+#             */
/*   Updated: 2025/01/09 21:55:11 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>

# define TILE_SIZE 75

typedef	struct s_pmap
{
	int		x;
	int		y;
}	t_pmap;

typedef	struct	s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	char		**map;
	void		*texture[7];
	int			collectme;
	int			moves;
	t_player	player;
}	t_mlx;


//from libft ig
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*get_next_line(int fd);
int		ft_printf(const char *str, ...);

//so long helpers
int		isshaped(char **map);
int		isclosed(char **map);
void	isitreachable(char **rows); // check if sur by walls not done yet
int		countit(char **map, char c);
int		ismapvalid(char **map);
int		hasanotherchar(char **map);
char	**readmap(char **av);

//utils
void	free_map(char **map);
int		acessisgood(int ac, char **av);

//mlx
void	initial_mlx(t_mlx *mlx);
void	loadtexture(t_mlx *mlx);
void	mapredring(t_mlx *mlx);
void	initialplayer(t_mlx *mlx);
int		hookwasd(int key, t_mlx *mlx);
void	moveplayer(t_mlx *mlx, int old_x, int old_y);
int		countcollects(char **map);

#endif