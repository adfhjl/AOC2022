#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define INPUT_SIZE 138
#define MIN 0
#define MAX 1

// First answer: EPJBRKAH V

int	main(void)
{
	// int input[] = {15, -11, 6, -3, 5, -1, -8, 13, 4, 0, -1, 5, -1, 5, -1, 5, -1, 5, -1, -35, 1, 24, -19, 1, 16, -11, 0, 0, 21, -15, 0, 0, -3, 9, 1, -3, 8, 1, 5, 0, 0, 0, 0, 0, -36, 0, 1, 7, 0, 0, 0, 2, 6, 0, 0, 0, 0, 0, 1, 0, 0, 7, 1, 0, -13, 13, 7, 0, 1, -33, 0, 0, 0, 2, 0, 0, 0, 8, 0, -1, 2, 1, 0, 17, -9, 1, 1, -3, 11, 0, 0, 1, 0, 1, 0, 0, -13, -19, 1, 3, 26, -30, 12, -1, 3, 1, 0, 0, 0, -9, 18, 1, 2, 0, 0, 9, 0, 0, 0, -1, 2, -37, 1, 3, 0, 15, -21, 22, -6, 1, 0, 2, 1, 0, -10, 0, 0, 20, 1, 2, 2, -6, -11, 0, 0, 0};
	int	input[] = {1, 0, 4, 0, 0, 7, 0, 0, 0, 3, 0, 0, 5, -1, 1, 5, 3, 0, 3, 0, -1, 0, 3, 5, -38, 7, 10, -14, 5, 30, -25, 0, 2, 3, -2, 2, 5, 2, 2, -21, 22, 5, 2, 3, 0, -39, 1, 0, 0, 3, 5, 4, -5, 4, 4, 0, -9, 12, 5, 2, -1, 6, -2, 0, 3, 3, 2, -37, 39, -33, -1, 1, 8, 0, 0, 0, 2, 20, -19, 4, 0, 0, 0, 3, 2, 5, 0, 1, 4, -21, 22, -38, 0, 0, 7, 32, -27, 0, 3, -2, 2, 5, 2, 2, 3, -2, 2, 0, 3, 5, 2, 3, 0, -39, 2, 0, 4, 8, -8, 6, -1, 0, 5, 0, 0, 0, 3, 5, 2, -11, 12, 2, 0, 3, 2, 5, -6, 0};
	int	i = 0;
	int	x = 1;
	int cycle = 1;


	printf(	"---------------------------\n"
			"Advent of Code 2022: Day 10 Part Two!\n"
			"---------------------------\n");
	while (i < INPUT_SIZE)
	{
		// printf("Started cycle %d\n", cycle);
		if (input[i] != 0)
		{
			if (cycle % 40 - 1 == x || cycle % 40 - 1 == x - 1 || cycle % 40 - 1 == x + 1)
			{
				printf("#");
			}
			else
			{
				printf(".");
			}
			if (cycle % 40 == 0)
			{
				// printf("On cycle %d, signal strength is %d * %d = %d\n", cycle, cycle, x, cycle * x);
				// count += cycle * x;
				printf("\n");
			}
			cycle++;
			if (cycle % 40 - 1 == x || cycle % 40 - 1 == x - 1 || cycle % 40 - 1 == x + 1)
			{
				printf("#");
			}
			else
			{
				printf(".");
			}
			if (cycle % 40 == 0)
			{
				// printf("On cycle %d, signal strength is %d * %d = %d\n", cycle, cycle, x, cycle * x);
				// count += cycle * x;
				printf("\n");
			}
			x += input[i];
		}
		else
		{
			if (cycle % 40 - 1 == x || cycle % 40 - 1 == x - 1 || cycle % 40 - 1 == x + 1)
			{
				printf("#");
			}
			else
			{
				printf(".");
			}
			if (cycle % 40 == 0)
			{
				// printf("On cycle %d, signal strength is %d * %d = %d\n", cycle, cycle, x, cycle * x);
				// count += cycle * x;
				printf("\n");
			}
		}
		cycle++;
		i++;
	}
	// printf("%i is the answer\n", count);
	return (0);
}
