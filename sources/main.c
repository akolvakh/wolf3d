


#include "wolf3d.h"

int				main(int argc, char **argv)
{
	t_dataset	data;

	//проверки, парсинг, передача и запуск

	/*if (argc != 2)
		sys_error(USAGE);
	data = tinfo_init(argv[1]);
	info->fd = open(argv[1], O_RDONLY);
	if ((info->meta->row = parser(info) - 1) < 0)
		set_error(MAP);
	close(info->fd);
	info->cnt = -1;
	while (++info->cnt < info->meta->amount)
	{
		info->def[info->cnt].x = info->dot[info->cnt].x;
		info->def[info->cnt].y = info->dot[info->cnt].y;
		info->def[info->cnt].z = info->dot[info->cnt].z;
	}
*/








	if (argc < 2)
		sys_message(USAGE);
	if (argc > 2)
		sys_error(INPUT);
	if (argc == 2)
	{
		sys_errorcheck(argv[1]);
		init_level(&data);
		window(&data);
	}
}
