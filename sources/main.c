




#include "wolf3d.h"

int				main(int argc, char **argv)
{
	t_dataset *data;

	if (argc < 2)
		sys_message(USAGE);
	if (argc > 2)
		sys_error(INPUT);
	if (argc == 2)
	{
		//data = tinfo_init(argv[1]);//dataset_init
		data = init_dataset(argv[1]);
		data->fd = open(argv[1], O_RDONLY);
		if ((data->row = parser(data) - 1) < 0)
			sys_error(MAP);
		close(data->fd);
		//sys_errorcheck(argv[1]);
		init_level(data);
		window(data);
	}

}


	//t_dataset	data;
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
