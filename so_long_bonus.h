/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:31:56 by adechaji          #+#    #+#             */
/*   Updated: 2025/01/12 00:58:53 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>

# define TILE_SIZE 75

typedef struct s_pdata
{
	char	**map_copy;
	size_t	r;
	size_t	c;
	int		collects;
	int		fexit;
	int		p_x;
	int		p_y;

}	t_pdata;

typedef struct s_pmap
{
	int		x;
	int		y;
}	t_pmap;

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_enemy
{
	int	x;
	int	y;
	int	look;
}	t_enemy;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	char		**map;
	void		*texture[8];
	int			collectme;
	int			moves;
	t_player	player;
	t_enemy		*enemies;
	int			num_enem;
	void		*enemleft;
	void		*enemright;
}	t_mlx;

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*get_next_line(int fd);
int		ft_printf(const char *str, ...);

int		isshaped(char **map);
int		isclosed(char **map);
int		countit(char **map, char c);
int		ismapvalid(char **map);
int		hasanotherchar(char **map);
char	**readmap(char **av);
void	isitreachable(char **rows);
void	locateplayer(char **rows, t_pdata *data);
int		duplicateme(t_pdata *data, char **rows);
void	fillmepls(char **map, int x, int y);

void	free_map(char **map);
int		acessisgood(int ac, char **av);
int		clean_exit(t_mlx *mlx);

void	initial_mlx(t_mlx *mlx);
void	loadtexture(t_mlx *mlx);
void	mapredring(t_mlx *mlx);
void	initialplayer(t_mlx *mlx);
int		hookwasd(int key, t_mlx *mlx);
void	moveplayer(t_mlx *mlx, int old_x, int old_y);
int		countcollects(char **map);

void	onscreenmoves(t_mlx *mlx);
char	*ft_itoa(int n);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
void	initialenemy(t_mlx *mlx);
int		loopenemy(t_mlx *mlx);
#endif