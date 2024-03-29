#include <stdio.h>
#include <stdbool.h>

#if windows
#define u64 "%I64i"
#else
#define u64 "%zu"
#endif

#define INPUT_SIZE 502

// First attempt: RLFNRTNFB V

void	init_stack(char stacks[9][100])
{
	size_t	i = 0;
	size_t	j;

	while (i < 9)
	{
		j = 0;
		while (j < 100)
		{
			stacks[i][j] = 0;
			j++;
		}
		i++;
	}

	stacks[0][0] = 'S';
	stacks[0][1] = 'L';
	stacks[0][2] = 'W';
	stacks[1][0] = 'J';
	stacks[1][1] = 'T';
	stacks[1][2] = 'N';
	stacks[1][3] = 'Q';
	stacks[2][0] = 'S';
	stacks[2][1] = 'C';
	stacks[2][2] = 'H';
	stacks[2][3] = 'F';
	stacks[2][4] = 'J';
	stacks[3][0] = 'T';
	stacks[3][1] = 'R';
	stacks[3][2] = 'M';
	stacks[3][3] = 'W';
	stacks[3][4] = 'N';
	stacks[3][5] = 'G';
	stacks[3][6] = 'B';
	stacks[4][0] = 'T';
	stacks[4][1] = 'R';
	stacks[4][2] = 'L';
	stacks[4][3] = 'S';
	stacks[4][4] = 'D';
	stacks[4][5] = 'H';
	stacks[4][6] = 'Q';
	stacks[4][7] = 'B';
	stacks[5][0] = 'M';
	stacks[5][1] = 'J';
	stacks[5][2] = 'B';
	stacks[5][3] = 'V';
	stacks[5][4] = 'F';
	stacks[5][5] = 'H';
	stacks[5][6] = 'R';
	stacks[5][7] = 'L';
	stacks[6][0] = 'D';
	stacks[6][1] = 'W';
	stacks[6][2] = 'R';
	stacks[6][3] = 'N';
	stacks[6][4] = 'J';
	stacks[6][5] = 'M';
	stacks[7][0] = 'B';
	stacks[7][1] = 'Z';
	stacks[7][2] = 'T';
	stacks[7][3] = 'F';
	stacks[7][4] = 'H';
	stacks[7][5] = 'N';
	stacks[7][6] = 'D';
	stacks[7][7] = 'J';
	stacks[8][0] = 'H';
	stacks[8][1] = 'L';
	stacks[8][2] = 'Q';
	stacks[8][3] = 'N';
	stacks[8][4] = 'B';
	stacks[8][5] = 'F';
	stacks[8][6] = 'T';
}

char	*get_top_ptr(char stack[100])
{
	size_t	i;

	i = 0;
	while (stack[i + 1] != 0)
		i++;
	return (&(stack[i]));
}

char	pop(char stack[100])
{
	char	tmp;
	char	*ptr;

	ptr = get_top_ptr(stack);
	tmp = *ptr;
	*ptr = 0;
	return (tmp);
}

void	move(int n, char a[100], char b[100])
{
	char	*ptr;

	while (n > 0)
	{
		ptr = get_top_ptr(b);
		if (*ptr == 0)
			ptr[0] = pop(a);
		else
			ptr[1] = pop(a);
		n--;
	}
}

void	print_stacks(char stacks[9][100])
{
	size_t	i;
	size_t	j;
	bool	update;

	i = 0;
	update = true;
	printf(" 1   2   3   4   5   6   7   8   9\n");
	while (update)
	{
		update = false;
		j = 0;
		while (j < 9)
		{
			if (stacks[j][i] == 0)
				printf("    ");
			else
			{
				update = true;
				printf("[%c] ", stacks[j][i]);
			}
			j++;
		}
		printf("\n");
		i++;
	}
}

int	main(void)
{
	char	stacks[9][100];
	int		input[INPUT_SIZE][3] = {
		{5, 4, 5},
		{2, 5, 8},
		{2, 9, 1},
		{2, 9, 1},
		{1, 5, 3},
		{10, 5, 8},
		{1, 4, 7},
		{1, 1, 2},
		{5, 3, 7},
		{1, 2, 8},
		{21, 8, 5},
		{13, 5, 7},
		{2, 9, 4},
		{1, 7, 4},
		{5, 1, 4},
		{1, 5, 7},
		{2, 2, 7},
		{1, 3, 2},
		{1, 1, 6},
		{7, 5, 9},
		{16, 7, 4},
		{7, 9, 3},
		{1, 7, 5},
		{1, 3, 8},
		{3, 2, 7},
		{1, 8, 9},
		{3, 3, 6},
		{21, 4, 9},
		{1, 5, 7},
		{4, 4, 9},
		{8, 6, 3},
		{6, 7, 1},
		{12, 9, 8},
		{6, 7, 2},
		{3, 6, 5},
		{1, 6, 9},
		{4, 8, 6},
		{3, 8, 5},
		{4, 1, 8},
		{4, 6, 1},
		{2, 1, 3},
		{1, 5, 8},
		{2, 2, 8},
		{5, 8, 3},
		{4, 2, 7},
		{5, 8, 1},
		{2, 1, 7},
		{1, 8, 2},
		{2, 1, 7},
		{11, 9, 2},
		{1, 8, 5},
		{2, 9, 4},
		{3, 9, 5},
		{2, 5, 1},
		{6, 5, 8},
		{2, 4, 2},
		{1, 5, 6},
		{7, 1, 8},
		{2, 2, 7},
		{13, 8, 1},
		{16, 3, 1},
		{3, 2, 1},
		{12, 7, 6},
		{15, 1, 8},
		{2, 3, 8},
		{16, 1, 2},
		{24, 2, 8},
		{1, 1, 5},
		{1, 5, 8},
		{3, 6, 7},
		{26, 8, 3},
		{20, 3, 9},
		{1, 2, 9},
		{16, 9, 3},
		{14, 3, 1},
		{13, 1, 6},
		{3, 3, 4},
		{3, 9, 4},
		{1, 7, 8},
		{5, 8, 2},
		{8, 8, 5},
		{18, 6, 1},
		{4, 8, 5},
		{6, 4, 1},
		{2, 2, 5},
		{5, 3, 8},
		{5, 8, 7},
		{2, 5, 8},
		{5, 5, 4},
		{3, 2, 8},
		{22, 1, 2},
		{1, 1, 2},
		{5, 8, 2},
		{2, 5, 2},
		{1, 1, 6},
		{5, 5, 2},
		{1, 9, 8},
		{5, 4, 1},
		{6, 6, 9},
		{3, 1, 9},
		{1, 1, 7},
		{8, 9, 6},
		{6, 7, 1},
		{5, 6, 5},
		{27, 2, 1},
		{4, 5, 7},
		{9, 1, 5},
		{1, 9, 1},
		{3, 6, 2},
		{9, 2, 1},
		{2, 7, 2},
		{1, 8, 7},
		{10, 5, 9},
		{1, 9, 7},
		{25, 1, 8},
		{6, 7, 4},
		{11, 1, 7},
		{3, 8, 1},
		{3, 2, 6},
		{3, 8, 9},
		{11, 8, 6},
		{1, 2, 6},
		{12, 6, 4},
		{13, 4, 5},
		{1, 6, 1},
		{3, 7, 5},
		{5, 8, 7},
		{1, 7, 1},
		{5, 1, 6},
		{3, 6, 4},
		{3, 8, 6},
		{2, 5, 2},
		{12, 5, 9},
		{5, 6, 2},
		{2, 5, 9},
		{6, 4, 9},
		{11, 7, 3},
		{1, 2, 5},
		{1, 7, 8},
		{1, 5, 7},
		{1, 7, 1},
		{1, 8, 1},
		{2, 4, 7},
		{2, 6, 8},
		{5, 3, 6},
		{2, 7, 2},
		{2, 2, 9},
		{1, 2, 9},
		{1, 1, 6},
		{35, 9, 7},
		{2, 8, 7},
		{3, 3, 8},
		{5, 2, 4},
		{3, 3, 7},
		{2, 4, 7},
		{4, 6, 5},
		{4, 5, 9},
		{3, 4, 5},
		{1, 8, 3},
		{4, 9, 8},
		{1, 9, 6},
		{38, 7, 2},
		{1, 3, 5},
		{1, 1, 7},
		{4, 7, 3},
		{3, 6, 1},
		{22, 2, 7},
		{1, 5, 8},
		{7, 8, 4},
		{8, 2, 8},
		{3, 5, 1},
		{4, 3, 9},
		{1, 8, 3},
		{1, 3, 7},
		{2, 2, 3},
		{5, 8, 9},
		{3, 9, 1},
		{2, 1, 7},
		{6, 2, 3},
		{6, 3, 1},
		{2, 3, 6},
		{1, 6, 1},
		{14, 7, 2},
		{4, 1, 6},
		{8, 1, 3},
		{4, 3, 6},
		{3, 9, 5},
		{1, 8, 6},
		{1, 8, 4},
		{9, 7, 1},
		{8, 2, 4},
		{4, 2, 9},
		{2, 2, 1},
		{3, 5, 8},
		{1, 8, 6},
		{1, 7, 8},
		{1, 6, 5},
		{3, 9, 5},
		{2, 9, 5},
		{4, 3, 9},
		{3, 6, 3},
		{3, 6, 9},
		{9, 4, 1},
		{1, 9, 8},
		{3, 3, 6},
		{2, 7, 4},
		{4, 8, 5},
		{7, 5, 6},
		{19, 1, 9},
		{5, 9, 3},
		{2, 1, 6},
		{1, 4, 6},
		{4, 3, 2},
		{21, 9, 7},
		{1, 1, 2},
		{1, 9, 1},
		{1, 1, 8},
		{16, 7, 6},
		{24, 6, 5},
		{7, 4, 5},
		{1, 8, 3},
		{2, 2, 8},
		{31, 5, 8},
		{1, 4, 6},
		{2, 6, 9},
		{1, 7, 4},
		{3, 7, 9},
		{1, 4, 8},
		{2, 3, 5},
		{1, 2, 3},
		{1, 3, 7},
		{1, 7, 9},
		{24, 8, 6},
		{1, 8, 1},
		{30, 6, 1},
		{2, 5, 2},
		{1, 6, 9},
		{6, 9, 7},
		{1, 6, 4},
		{1, 4, 6},
		{23, 1, 3},
		{21, 3, 4},
		{4, 2, 6},
		{3, 6, 1},
		{1, 5, 1},
		{4, 1, 9},
		{3, 9, 6},
		{8, 1, 6},
		{4, 8, 5},
		{2, 7, 5},
		{7, 4, 3},
		{3, 4, 9},
		{9, 3, 9},
		{1, 7, 6},
		{6, 5, 8},
		{14, 6, 2},
		{4, 8, 4},
		{7, 4, 5},
		{1, 7, 9},
		{6, 4, 3},
		{13, 2, 6},
		{5, 3, 7},
		{1, 3, 8},
		{1, 8, 2},
		{4, 8, 3},
		{6, 6, 4},
		{2, 2, 8},
		{5, 4, 7},
		{3, 7, 5},
		{1, 7, 9},
		{2, 3, 9},
		{3, 7, 3},
		{1, 7, 9},
		{1, 7, 9},
		{3, 4, 1},
		{6, 6, 1},
		{2, 7, 5},
		{1, 3, 5},
		{11, 9, 4},
		{9, 4, 5},
		{3, 3, 4},
		{1, 3, 9},
		{2, 8, 1},
		{9, 1, 8},
		{22, 5, 8},
		{2, 1, 3},
		{3, 4, 6},
		{14, 8, 9},
		{1, 3, 9},
		{19, 9, 3},
		{3, 9, 4},
		{2, 7, 2},
		{1, 4, 6},
		{1, 3, 8},
		{8, 3, 1},
		{2, 9, 6},
		{1, 2, 5},
		{3, 4, 9},
		{1, 2, 3},
		{20, 8, 3},
		{4, 9, 5},
		{1, 4, 2},
		{26, 3, 5},
		{1, 8, 3},
		{8, 1, 4},
		{1, 3, 7},
		{1, 2, 1},
		{1, 1, 6},
		{1, 6, 7},
		{4, 5, 3},
		{3, 4, 2},
		{5, 5, 3},
		{2, 2, 6},
		{3, 3, 5},
		{2, 4, 8},
		{5, 3, 9},
		{5, 9, 8},
		{19, 5, 9},
		{1, 5, 2},
		{2, 7, 1},
		{1, 1, 7},
		{1, 7, 4},
		{13, 9, 3},
		{8, 6, 2},
		{10, 3, 5},
		{14, 5, 4},
		{7, 8, 4},
		{1, 6, 2},
		{6, 3, 8},
		{4, 9, 7},
		{2, 9, 8},
		{1, 7, 1},
		{3, 2, 7},
		{1, 5, 3},
		{7, 8, 6},
		{5, 6, 2},
		{8, 4, 5},
		{3, 5, 8},
		{3, 8, 6},
		{5, 7, 9},
		{5, 3, 6},
		{1, 9, 4},
		{17, 4, 7},
		{1, 8, 1},
		{12, 7, 8},
		{3, 1, 4},
		{2, 4, 6},
		{8, 6, 1},
		{4, 6, 3},
		{1, 7, 8},
		{5, 5, 8},
		{4, 7, 1},
		{3, 2, 6},
		{2, 5, 1},
		{6, 1, 6},
		{4, 3, 5},
		{4, 5, 3},
		{1, 4, 8},
		{3, 3, 2},
		{17, 8, 4},
		{6, 6, 3},
		{14, 4, 9},
		{1, 3, 8},
		{1, 7, 4},
		{3, 8, 3},
		{5, 2, 5},
		{6, 1, 7},
		{2, 6, 4},
		{4, 5, 7},
		{1, 1, 5},
		{1, 6, 3},
		{10, 7, 4},
		{1, 5, 4},
		{1, 2, 3},
		{15, 4, 5},
		{3, 3, 1},
		{6, 2, 6},
		{1, 2, 3},
		{2, 4, 7},
		{2, 7, 8},
		{1, 4, 2},
		{2, 1, 7},
		{1, 7, 2},
		{12, 9, 1},
		{4, 9, 5},
		{4, 6, 2},
		{1, 7, 3},
		{6, 2, 4},
		{1, 8, 5},
		{2, 4, 2},
		{11, 1, 7},
		{3, 1, 4},
		{17, 5, 6},
		{15, 6, 4},
		{1, 8, 9},
		{10, 4, 1},
		{1, 3, 9},
		{2, 6, 5},
		{1, 2, 6},
		{4, 5, 6},
		{4, 1, 2},
		{6, 6, 7},
		{2, 2, 6},
		{9, 4, 9},
		{6, 1, 2},
		{3, 4, 1},
		{10, 9, 8},
		{4, 2, 1},
		{1, 1, 2},
		{5, 8, 6},
		{1, 2, 7},
		{1, 9, 4},
		{2, 6, 9},
		{13, 7, 2},
		{5, 7, 5},
		{2, 5, 2},
		{1, 4, 5},
		{4, 8, 4},
		{17, 2, 6},
		{3, 4, 6},
		{2, 9, 1},
		{7, 6, 8},
		{1, 5, 2},
		{1, 4, 1},
		{2, 9, 4},
		{1, 3, 9},
		{4, 3, 7},
		{2, 8, 5},
		{3, 7, 5},
		{10, 5, 8},
		{2, 2, 4},
		{6, 1, 2},
		{4, 6, 3},
		{8, 2, 6},
		{1, 7, 4},
		{5, 4, 5},
		{7, 6, 7},
		{5, 3, 5},
		{5, 5, 2},
		{4, 8, 1},
		{6, 1, 6},
		{3, 3, 2},
		{22, 6, 2},
		{1, 9, 7},
		{8, 8, 6},
		{1, 7, 6},
		{2, 5, 7},
		{4, 8, 5},
		{7, 6, 7},
		{2, 6, 4},
		{14, 2, 1},
		{7, 1, 3},
		{12, 7, 3},
		{1, 4, 3},
		{2, 5, 8},
		{2, 8, 1},
		{1, 4, 3},
		{6, 2, 9},
		{6, 9, 2},
		{2, 2, 7},
		{6, 7, 5},
		{13, 3, 5},
		{5, 2, 6},
		{5, 6, 1},
		{2, 3, 6},
		{1, 6, 5},
		{1, 6, 1},
		{3, 1, 9},
		{6, 2, 7},
		{1, 2, 3},
		{24, 5, 2},
		{7, 3, 7},
		{13, 7, 9},
		{4, 1, 9},
		{4, 1, 6},
		{1, 5, 6},
		{16, 9, 5},
		{1, 6, 4},
		{1, 5, 2},
		{5, 1, 3},
		{11, 2, 1},
		{4, 9, 6},
		{1, 4, 7},
		{2, 3, 4},
		{6, 6, 9},
		{1, 1, 3},
		{2, 9, 4},
		{1, 7, 9},
		{4, 2, 9},
		{8, 9, 2},
		{3, 3, 2},
		{1, 9, 4},
		{5, 1, 7},
		{1, 4, 8},
		{2, 1, 9},
		{1, 8, 7},
		{6, 5, 3},
		{1, 5, 1},
		{5, 2, 3},
		{4, 1, 5},
		{4, 7, 1},
		{8, 5, 8}
	};
	size_t	i;

	printf(	"---------------------------\n"
			"Advent of Code 2022: Day 5 Part One!\n"
			"---------------------------\n");
	init_stack(stacks);
	i = 0;
	while (i < INPUT_SIZE)
	{
		printf("["u64"] Moving %i from %i to %i...\n", i, input[i][0], input[i][1], input[i][2]);
		move(input[i][0], stacks[input[i][1] - 1], stacks[input[i][2] - 1]);
		i++;
	}
	printf("These are the stacks (upside down):\n");
	print_stacks(stacks);
	return (0);
}
