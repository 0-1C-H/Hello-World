#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int main(void)
{
	int board[4][4] =
	{
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
	};

	int steps;
	steps = 0;
		
	while (1 == 1)

	{  //Whether the game is over?
		int pder1 = 0;
		int pder2 = 0;
		int pdq = 0;
		while (pder1 <= 3)
		{
			pder2 = 0;
			while (pder2 <= 3)
			{
				if (board[pder1][pder2] == 0)
				{
					pdq++;
				}
				if (board[pder1][pder2] == 2048)
				{
					system("cls");
					int k, j;
					k = 0;
					j = 0;
					while (k <= 3)
					{
						j = 0;
						while (j <= 3)
						{
							printf("%5d", board[k][j]);
							j++;
						}
						printf("\n");
						k++;
					}
					printf("\n");

					printf("CONGURATULATIONS!\n");
					goto win;
				}
					
				pder2++;
			}
			pder1++;
		}
		if (pdq == 0)
		{
			break;
		}

		//generate a random number
		srand((unsigned)time(NULL));
		int ind_x, ind_y;
		ind_x = rand() % 4;
		ind_y = rand() % 4;
		while (board[ind_x][ind_y] != 0)
		{
			srand((unsigned)time(NULL));
			ind_x = rand() % 4;
			ind_y = rand() % 4;

		}
		board[ind_x][ind_y] = 2;


		//refresh
		system("cls");
		int k, j;
		k = 0;
		j = 0;
		while (k <= 3)
		{
			j = 0;
			while (j <= 3)
			{
				printf("%5d", board[k][j]);
				j++;
			}
			printf("\n");
			k++;
		}
		printf("\n");



		//detect input and move
		char move;
		int con_x = 0, con_y = 0, jud = 0;
		printf("Waiting for command:");
		move = getchar();

		if (move == 'w')
		{
			con_x = 1;
			con_y = 0;
			jud = 0;
			while (jud <= 5)
			{
				con_y = 0;
				while (con_y <= 3)
				{
					con_x = 1;
					while (con_x <= 3)
					{
						if (board[con_x][con_y] != 0)//for every number that is not 0
						{
							if (board[con_x - 1][con_y] == 0)//if the upper one is 0
							{
								board[con_x - 1][con_y] = board[con_x][con_y];
								board[con_x][con_y] = 0;
							}
							else
							{
								if (board[con_x][con_y] == board[con_x - 1][con_y])
								{
									board[con_x - 1][con_y] = board[con_x - 1][con_y] + board[con_x - 1][con_y];
									board[con_x][con_y] = 0;
								}
							}
						}
						con_x++;
					}
					con_y++;
				}
				jud++;
			}
			
			con_x = 0;
			con_y = 0;
			jud = 0;
		}
		else  if (move == 's')
		{
			
			jud = 0;
			con_x = 2;
			con_y = 0;
			while (jud <= 5)
			{
				con_y = 0;
				while (con_y <= 3)
				{
					con_x = 2;
					while (con_x >= 0)
					{
						if (board[con_x][con_y] != 0)//for every number that is not 0
						{
							if (board[con_x + 1][con_y] == 0)//if the downer one is 0
							{
								board[con_x + 1][con_y] = board[con_x][con_y];
								board[con_x][con_y] = 0;
							}
							else
							{
								if (board[con_x][con_y] == board[con_x + 1][con_y])
								{
									board[con_x + 1][con_y] = board[con_x + 1][con_y] + board[con_x + 1][con_y];
									board[con_x][con_y] = 0;
								}
							}
						}
						con_x--;
					}
					con_y++;
				}
				jud++;
			}
			con_x = 0;
			con_y = 0;
			jud = 0;
		}
		else if (move == 'a')
		{
			con_y = 1;
			con_x = 0;
			jud = 0;

			while (jud <= 5)
			{
				con_x = 0;
				while (con_x <= 3)
				{
					con_y = 1;
					while (con_y <= 3)
					{
						if (board[con_x][con_y] != 0)//for every number that is not 0
						{
							if (board[con_x][con_y-1] == 0)//if the left one is 0
							{
								board[con_x][con_y-1] = board[con_x][con_y];
								board[con_x][con_y] = 0;
							}
							else
							{
								if (board[con_x][con_y] == board[con_x][con_y-1])
								{
									board[con_x][con_y-1] = board[con_x][con_y-1] + board[con_x][con_y-1];
									board[con_x][con_y] = 0;
								}
							}
						}
						con_y++;
					}

					con_x++;
				}
				jud++;
			}
			con_x = 0;
			con_y = 0;
			jud = 0;
		}
		if (move == 'd')
		{
			con_y = 2;
			con_x = 0;
			jud = 0;
			while (jud <= 5)
			{
				con_y = 2;
				while (con_y >= 0)
				{
					con_x = 0;
					while (con_x <= 3)
					{
						//zhuti
						if (board[con_x][con_y] != 0)//for every number that is not 0
						{
							if (board[con_x][con_y + 1] == 0)//if the right one is 0
							{
								board[con_x][con_y + 1] = board[con_x][con_y];
								board[con_x][con_y] = 0;
							}
							else
							{
								if (board[con_x][con_y] == board[con_x][con_y + 1])
								{
									board[con_x][con_y + 1] = board[con_x][con_y + 1] + board[con_x][con_y + 1];
									board[con_x][con_y] = 0;
								}
							}
						}
						con_x++;
					}
					con_y--;

				}
				jud++;
			}
			con_x = 0;
			con_y = 0;
			jud = 0;
		}
		
		steps++;
	}
	printf("\n After %d step(s) ,Game is over.",steps);
win: printf("Game over");
	system("pause");
	return 0;
}
	



