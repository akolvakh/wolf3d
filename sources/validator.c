
#include "wolf3d.h"

void	validate_param(t_dataset *ai)
{
	if (ai->row < 3)
		sys_error(ai, MAP);
	if (ai->posx >= ai->row || ai->posy >= (ai->amount/ai->row - 1))
		sys_error(ai, PLAYER);
	if (ai->posx < 0 || ai->posy < 0)
		sys_error(ai, MAP);
}

void	validate_level(t_dataset *ai)
{
	int i;
	int j;

	i = 0;
	while(i <= ai->row)
	{
		if(i == 0 || i == ai->row)
		{
			j = 0;
			while (ai->worldmap[i][j])
			{
				if (ai->worldmap[i][j] == '0')
					sys_error(ai, MAP);
				j++;
			}
		}
		if( ai->worldmap[i][0] == '0' || ai->worldmap[i][j - 1] == '0')
			sys_error(ai, MAP);
		i++;
	}
	validate_param(ai);
	i = ai->posx;
	j = ai->posy;
	if (ai->worldmap[i][j] != '0')
		sys_error(ai, PLAYER);
}