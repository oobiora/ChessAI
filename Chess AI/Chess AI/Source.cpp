#include <iostream>


using namespace std;

int matrix[3][3]; //initial matrix declaration

int row, column, diagonal;

int empty_r(int c);
int empty_c(int r);

bool vulnerable(int mat[3][3]);
bool winnable(int mat[3][3]);
bool finished(int mat[3][3]);

char check(void); // declaration of functions
void init_matrix(void);
void get_player_move(void);
void get_computer_move(void);
void disp_matrix(void);

void reset();


int main(void)
{
	char done; char c;
	bool CONTINUE = true;
	while (CONTINUE)
	{

		cout << "Human vs. AI Tic Tac Toe." << endl;
		cout << "You will be playing against the computer as 'X'" << endl;

		done = ' ';
		init_matrix();

		do {
			disp_matrix();
			get_player_move();
			done = check(); /* check winner */
			if (done != ' ') break; /* if winner found...*/
			get_computer_move();
			done = check(); /* check for winner again */
			if (done != ' ') break; /* if winner found...*/
			if (finished(matrix)) //we don't have a winner and there are no open spaces.
			{
				disp_matrix();
				cout << endl;
				cout << "draw\n";
				break;
			}
			reset();

		} while (done == ' ');


		if (done == 'X')
			cout << "Human won! (but AI very dumb anyway)\n";
		else
			cout << "AI so stupid still can win against you..." << endl;
		disp_matrix(); /* show final positions */
		cout << "Play again? Y/N" << endl; cin >> c;
		if (c == 'N' || c == 'n')
			CONTINUE = false;
		reset();
	}
	return 0;
}

void init_matrix(void) //matrix intitialisation
{
	int i, j;

	for (i = 0; i<3; i++)
		for (j = 0; j<3; j++) matrix[i][j] = ' ';
}


void get_player_move(void) //call function for player input
{

	int x, y;

	cout << "Enter X,Y coordinates for your move: ";
	cin >> x >> y;

	x--; y--;

	if (matrix[x][y] != ' ') {
		cout << "Invalid move, try again.\n";
		get_player_move();
	}
	else matrix[x][y] = 'X';
}

void get_computer_move(void) //AI move input
{
	char temp;
	int test[3][3], temporary[3][3];
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
		{
			test[i][j] = matrix[i][j]; temporary[i][j] = matrix[i][j];
		}
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			if (matrix[i][j] == ' ')
			{
				temp = matrix[i][j];
				if (winnable(test))
				{
					if (row > 0)
					{
						if (matrix[row - 1][empty_c(row - 1)] != 'X')
							matrix[row - 1][empty_c(row - 1)] = 'O';
						return;
					}
					if (column > 0)
					{
						if (matrix[empty_r(column - 1)][column - 1] != 'X')
							matrix[empty_r(column - 1)][column - 1] = 'O';
						return;
					}
					if (diagonal == 1)
					{
						if (matrix[0][0] != 'X' && matrix[1][1] != 'X' && matrix[2][2] != 'X')
						{
							matrix[0][0] = 'O'; matrix[1][1] = 'O'; matrix[2][2] = 'O';
						}
						return;
					}
					else
					{
						if (matrix[0][2] != 'X' && matrix[1][1] != 'X' && matrix[2][0] != 'X')
						{
							matrix[0][2] = 'O'; matrix[1][1] = 'O'; matrix[2][0] = 'O';
						}
						return;
					}
					return;
					//break;
				}
				test[i][j] = temp;
			}
		if (matrix[i][j] == ' ')
		{
			temp = matrix[i][j];
			if (winnable(test))
			{
				if (row > 0)
				{
					if (matrix[row - 1][empty_c(row - 1)] != 'X')
						matrix[row - 1][empty_c(row - 1)] = 'O';
					return;
				}
				if (column > 0)
				{
					if (matrix[empty_r(column - 1)][column - 1] != 'X')
						matrix[empty_r(column - 1)][column - 1] = 'O';
					return;
				}
				if (diagonal == 1)
				{
					if (matrix[0][0] != 'X' && matrix[1][1] != 'X' && matrix[2][2] != 'X')
					{
						matrix[0][0] = 'O'; matrix[1][1] = 'O'; matrix[2][2] = 'O';
					}
					return;
				}
				else
				{
					if (matrix[0][2] != 'X' && matrix[1][1] != 'X' && matrix[2][0] != 'X')
					{
						matrix[0][2] = 'O'; matrix[1][1] = 'O'; matrix[2][0] = 'O';
					}
					return;
				}
				return;
			}
			test[i][j] = temp;
		}
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			if (matrix[i][j] == ' ')
			{
				temp = matrix[i][j];
				test[i][j] = 'O';
				if (!vulnerable(test))
					break;
				test[i][j] = temp;
			}
		if (matrix[i][j] == ' ')
		{
			temp = matrix[i][j];
			test[i][j] = 'O';
			if (!vulnerable(test))
				break;
			test[i][j] = temp;
		}
	}
	if (column > 0)
	{
		if (matrix[empty_r(column - 1)][column - 1] != 'X')
			matrix[empty_r(column - 1)][column - 1] = 'O';
		return;
	}
	if (row > 0)
	{
		if (matrix[row - 1][empty_c(row - 1)] != 'X')
			matrix[row - 1][empty_c(row - 1)] = 'O';
		return;
	}
	if (diagonal == 1)
	{
		if (matrix[0][0] != 'X')
			matrix[0][0] = 'O';
		if (matrix[1][1] != 'X')
			matrix[1][1] = 'O';
		if (matrix[2][2] != 'X')
			matrix[2][2] = 'O';
		return;
	}
	if (diagonal == 2)
	{
		if (matrix[0][2] != 'X')
			matrix[0][2] = 'O';
		if (matrix[1][1] != 'X')
			matrix[1][1] = 'O';
		if (matrix[2][0] != 'X')
			matrix[2][0] = 'O';
		return;
	}
	if (matrix[i][j] != 'X')
		matrix[i][j] = 'O';
}

void disp_matrix(void) //matrix display
{
	int t;

	for (t = 0; t<3; t++)
	{

		cout << " " << char(matrix[t][0]) << " | " << char(matrix[t][1]) << " | " << char(matrix[t][2]);

		if (t != 2)
			cout << "\n---|---|---\n";
	}
	cout << endl;
}
char check(void) //used for identifying winner
{
	int i;

	for (i = 0; i<3; i++)  /* check rows */
		if (matrix[i][0] == matrix[i][1] &&
			matrix[i][0] == matrix[i][2]) return matrix[i][0];

	for (i = 0; i<3; i++)  /* check columns */
		if (matrix[0][i] == matrix[1][i] &&
			matrix[0][i] == matrix[2][i]) return matrix[0][i];

	/* test diagonals */
	if (matrix[0][0] == matrix[1][1] &&
		matrix[1][1] == matrix[2][2])
		return matrix[0][0];

	if (matrix[0][2] == matrix[1][1] &&
		matrix[1][1] == matrix[2][0])
		return matrix[0][2];

	return ' ';
}

bool vulnerable(int mat[3][3])
{
	char a, b, c, d, e, f, g, h, i;
	a = mat[0][0], b = mat[0][1], c = mat[0][2];
	d = mat[1][0], e = mat[1][1], f = mat[1][2];
	g = mat[2][0], h = mat[2][1], i = mat[2][2];
	if ((a == 'X' && b == 'X' && c != 'O') || (b == 'X' && c == 'X' && a != 'O') || (a == 'X' && c == 'X' && b != 'O'))
	{
		row = 1; return true;
	}
	if ((d == 'X' && e == 'X' && f != 'O') || (e == 'X' && f == 'X' && d != 'O') || (d == 'X' && f == 'X' && e != 'O'))
	{
		row = 2; return true;
	}
	if ((g == 'X' && h == 'X' && i != 'O') || (h == 'X' && i == 'X' && g != 'O') || (g == 'X' && i == 'X' && h != 'O'))
	{
		row = 3; return true;
	}
	if ((a == 'X' && d == 'X' && g != 'O') || (d == 'X' && g == 'X' && a != 'O') || (a == 'X' && g == 'X' && d != 'O'))
	{
		column = 1; return true;
	}
	if ((b == 'X' && e == 'X' && h != 'O') || (e == 'X' && h == 'X' && b != 'O') || (b == 'X' && h == 'X' && e != 'O'))
	{
		column = 2; return true;
	}
	if ((c == 'X' && f == 'X' && i != 'O') || (f == 'X' && i == 'X' && c != 'O') || (c == 'X' && i == 'X' && f != 'O'))
	{
		column = 3; return true;
	}
	if ((a == 'X' && e == 'X' && i != 'O') || (e == 'X' && i == 'X' && a != 'O') || (a == 'X' && i == 'X' && e != 'O'))
	{
		diagonal = 1; return true;
	}
	if ((g == 'X' && e == 'X' && c != 'O') || (e == 'X' && c == 'X' && g != 'O') || (g == 'X' && c == 'X' && e != 'O'))
	{
		diagonal = 2; return true;
	}
	return false;
}

bool winnable(int mat[3][3])
{
	char a, b, c, d, e, f, g, h, i;
	a = mat[0][0], b = mat[0][1], c = mat[0][2];
	d = mat[1][0], e = mat[1][1], f = mat[1][2];
	g = mat[2][0], h = mat[2][1], i = mat[2][2];
	if ((a == 'O' && b == 'O' && c != 'X') || (b == 'O' && c == 'O' && a != 'X') || (a == 'O' && c == 'O' && b != 'X'))
	{
		row = 1;
		return true;
	}
	if ((d == 'O' && e == 'O' && f != 'X') || (e == 'O' && f == 'O' && d != 'X') || (d == 'O' && f == 'O' && e != 'X'))
	{
		row = 2;
		return true;
	}
	if ((g == 'O' && h == 'O' && i != 'X') || (h == 'O' && i == 'O' && g != 'X') || (g == 'O' && i == 'O' && h != 'X'))
	{
		row = 3;
		return true;
	}
	if ((a == 'O' && d == 'O' && g != 'X') || (d == 'O' && g == 'O' && a != 'X') || (a == 'O' && g == 'O' && d != 'X'))
	{
		column = 1;
		return true;
	}
	if ((b == 'O' && e == 'O' && h != 'X') || (e == 'O' && h == 'O' && b != 'X') || (b == 'O' && h == 'O' && e != 'X'))
	{
		column = 2;
		return true;
	}
	if ((c == 'O' && f == 'O' && i != 'X') || (f == 'O' && i == 'O' && c != 'X') || (c == 'O' && i == 'O' && f != 'X'))
	{
		column = 3;
		return true;
	}
	if ((a == 'O' && e == 'O' && i != 'X') || (e == 'O' && i == 'O' && a != 'X') || (a == 'O' && i == 'O' && e != 'X'))
	{
		diagonal = 1;
		return true;
	}
	if ((g == 'O' && e == 'O' && c != 'X') || (e == 'O' && c == 'O' && g != 'X') || (g == 'O' && c == 'O' && e != 'X'))
	{
		diagonal = 2;
		return true;
	}
	return false;


}

bool finished(int mat[3][3])
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (mat[i][j] == ' ')
				return false;
		}
	}
	return true;
}

int empty_c(int r)
{
	for (int i = 0; i < 3; ++i)
	{
		if (matrix[r][i] == ' ')
			return i;
	}
}

int empty_r(int c)
{
	for (int i = 0; i < 3; ++i)
	{
		if (matrix[i][c] == ' ')
			return i;
	}
}

void reset()
{
	row = 0;
	column = 0;
	diagonal = 0;
}