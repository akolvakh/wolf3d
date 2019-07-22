




#include "wolf3d.h"

int				main(int argc, char **argv)
{
	//t_dataset	data;


	t_dataset *data;

	if (argc != 2)
		sys_error(USAGE);
	data = tinfo_init(argv[1]);
	data->fd = open(argv[1], O_RDONLY);
	if ((data->row = parser(data) - 1) < 0)
		sys_error(MAP);
	close(data->fd);
	data->cnt = -1;
	while (++data->cnt < data->amount)
	{
		data->def[data->cnt].x = data->dot[data->cnt].x;
		data->def[data->cnt].y = data->dot[data->cnt].y;
		data->def[data->cnt].z = data->dot[data->cnt].z;
	}

	if (argc == 2)
	{
		sys_errorcheck(argv[1]);
		init_level(data);
		window(data);
	}

}



	/*if (argc < 2)
		sys_message(USAGE);
	if (argc > 2)
		sys_error(INPUT);
	if (argc == 2)
	{
		sys_errorcheck(argv[1]);
		init_level(&data);
		window(&data);
	}
}*/
