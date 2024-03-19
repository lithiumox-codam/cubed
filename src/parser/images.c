/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   images.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/14 12:48:08 by mdekker       #+#    #+#                 */
/*   Updated: 2024/03/14 12:49:05 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/**
 * @brief Shifts the color from ARGB to RGBA. Then stores the changes in the
 * original color. So the color is changed in place.
 *
 * @param color The ARGB color to change to RGBA.
 */
static void	argb_to_rgba(uint32_t *color)
{
	int	r;
	int	g;
	int	b;
	int	a;

	r = *color & 0xFF;
	g = (*color >> 8) & 0xFF;
	b = (*color >> 16) & 0xFF;
	a = (*color >> 24) & 0xFF;
	*color = r << 24 | g << 16 | b << 8 | a;
}

/**
 * @brief Fixes the color order of the image. It changes the order from ARGB to
 * RGBA. MLX42 for some reason uses ARGB instead of RGBA. But it does use the
 * RGBA order for putting the pixels on the screen.
 *
 * @param txt The texture to fix the color order of.
 */
static void	fix_color_order(mlx_texture_t *txt)
{
	uint32_t	i;
	uint32_t	j;

	i = 0;
	while (i < txt->height)
	{
		j = 0;
		while (j < txt->width)
		{
			argb_to_rgba((uint32_t *)&txt->pixels[(txt->width * i + j) * 4]);
			j++;
		}
		i++;
	}
}

/**
 * @brief Checks if a file exists and loads it into a mlx_image_t
 * @param img The texture to load the image into.
 * @param path The path to the image.
 * @return bool True when the image is loaded, false when it is not.
 */
bool	get_image(mlx_texture_t **img, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		*img = NULL;
		return (false);
	}
	close(fd);
	*img = mlx_load_png(path);
	if (*img == NULL)
		return (false);
	fix_color_order(*img);
	return (true);
}
