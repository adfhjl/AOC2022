#include <stdio.h>

int	main(void)
{
	int a[100][100][100];
	int	x = 0;
	int	y;
	int	z;

	while (x < 100)
	{
		y = 0;
		while (y < 100)
		{
			z = 0;
			while (z < 100)
			{
				if (a[x][y][z] != 0)
				{
					printf("WRONG!\n");
					return (0);
				}
				z++;
			}
			y++;
		}
		x++;
	}
	return (0);
}
