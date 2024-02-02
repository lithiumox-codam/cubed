/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/17 19:33:48 by mdekker       #+#    #+#                 */
/*   Updated: 2024/02/02 18:15:34 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <cub3d.h>

# ifndef BONUS
#  define CHECK_LENGTH 6
#  define BONUS 0
#  define VALID_MAP_CHARS " 01NSEW\n"
# else
#  define CHECK_LENGTH 8
#  define VALID_MAP_CHARS " 01NSEWDX\n"
# endif // BONUS

/**
 * @brief The different types of map elements
 *
 * EMPTY is used for the map array to indicate that the element is empty
 * FLOOR is used for the map array to indicate that the element is a floor
 * WALL is used for the map array to indicate that the element is a wall
 * PLAYER is used for the map array to indicate that the element is the player
 */
typedef enum e_map_types
{
	EMPTY = 0,
	WALL = 1,
	FLOOR = 2,
	PLAYER = 3,
	CLOSED_DOOR = 4,
	SPRITE = 5,
	OPEN_DOOR = 6
}						t_map_types;

/**
 * @brief The struct that holds the map
 *
 * @param map The map array
 * @param width The width of the map
 * @param height The height of the map
 */
typedef struct s_map
{
	t_map_types			**array;
	int					width;
	int					height;
}						t_map;

/**
 * @brief The struct that holds the player's metadata.
 *
 * @param x The x position of the player
 * @param y The y position of the player
 * @param dir The direction the player is facing
 */
typedef struct s_player
{
	double				x;
	double				y;
	double				dir;
}						t_player;

/**
 * @brief An enum to equate the directions to numbers.
 * so the directions can be used as indexes in an array.
 */
typedef enum e_info_types
{
	NONE = -1,
	N,
	S,
	E,
	W,
	F,
	C,
	D,
	SP
}						t_info_types;

/**
 * @brief A union to store the different textures for the wall.
 *
 * @param north The north wall texture
 * @param south The south wall texture
 * @param east The east wall texture
 * @param west The west wall texture
 * @param directions An array containing the different wall textures
 * that are just the directions in the order north, south, east, west
 */
typedef union u_texture
{
	struct
	{
		mlx_texture_t	*north;
		mlx_texture_t	*south;
		mlx_texture_t	*east;
		mlx_texture_t	*west;
	};
	mlx_texture_t		*directions[4];
}						t_texture;

/**
 * @brief The struct that holds the loaded textures
 * and the floor and ceiling colors.
 *
 * @param north wall The union containing the different wall textures
 * @param floor The floor color
 * @param ceiling The ceiling color
 */
typedef struct s_textures
{
	t_texture			wall;
	t_texture door; // todo: make an array of this for open & close
	int					floor;
	int					ceiling;
}						t_textures;

typedef struct s_raycast
{
	double				plane_x;
	double				plane_y;
	double				camera_x;
	double				ray_dir_x;
	double				ray_dir_y;
	int					map_x;
	int					map_y;
	double				side_dist_x;
	double				side_dist_y;
	double				delta_dist_x;
	double				delta_dist_y;
	double				perp_wall_dist;
	int					step_x;
	int					step_y;
	int					hit;
	int					side;
	t_info_types		wall_dir;
	int					line_height;
	int					draw_start;
	unsigned int		draw_end;
	double				dir_x;
	double				dir_y;

}						t_raycast;

/**
 * @brief The main data struct for the program.
 *
 * @param map The map struct containing the map array and its dimensions.
 * @param player The player struct containing the player's metadata.
 * @param strings The vector containing the strings read from the file.
 * @param textures The textures struct with the loaded textures.
 */
typedef struct s_data
{
	mlx_t				*mlx;
	mlx_image_t			*map_image;
	mlx_image_t			*ray_image;
	t_raycast			*ray;
	t_vector			*frame;
	t_map				map;
	t_player			player;
	t_vector			strings;
	bool				check[CHECK_LENGTH];
	t_textures			textures;
}						t_data;

/**
 * @brief The struct that holds the function pointers for the different
 * elements in the map file. So the parser knows which function to call
 * when it encounters a certain element. This makes the order of the elements
 * in the map file irrelevant.
 */
typedef struct s_func
{
	char				*str;
	t_info_types		type;
	bool				(*func_ptr)(char *, t_info_types, t_data *);
}						t_func;

#endif
