/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auysal <auysal@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:43:00 by auysal            #+#    #+#             */
/*   Updated: 2023/11/28 13:43:05 by auysal           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_message(char *msg)
{
	ft_printf("%s", msg);
	exit(1);
}

void	escape_line(t_game *data)
{
	data->index.i = -1;
	data->index.j = -1;
}

int	main(int argc, char **argv)
{
	t_game	data;

	if (argc == 2)
	{
		map_control(argv[1], &data);
		map_reading(&data);
		map_processing(&data);
		wall_control(&data);
		data.mlxpointer = mlx_init();//Minilibx kütüphanesinin başlatılmasını sağlar.
		data.winpointer = mlx_new_window(data.mlxpointer,//MiniLibX grafik kütüphanesinde yeni bir pencere oluşturmak için kullanılır.
				(data.map_width * RES), (data.map_height * RES), "so_long");
		images_in_game(&data);
		data.player = data.player_img;
		data.collectables = 0;
		map_bug(&data);
		adding_graphics(&data);
		placeholder(&data, data.player_y, data.player_x);
		mlx_hook(data.winpointer, 17, 0, (void *)exit, 0);//17, kapatma(exit), olayını temsil eder.
		data.counter = 0;             //mlx_hook, MiniLibX kütüphanesinde bir olay (event) işleyici fonksiyonunu belirlemek için kullanılan bir fonksiyondur.
		mlx_hook(data.winpointer, 2, 0, &controls_working, &data);//2 değeri klavye olaylarını temsil eder.
		mlx_loop(data.mlxpointer);//MiniLibX kütüphanesindeki bir işlevdir ve grafiksel bir uygulamanın ana döngüsünü oluşturur. Bu işlev, pencere olaylarını yakalamak, işlemek ve pencerenin güncel kalmasını sağlamak için kullanılır.
	}
	else
		error_message("Error..!\nWrong Argument");
}
