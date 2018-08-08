#include <iostream>
#include <fstream>
#include <unistd.h>
#include <algorithm>

using namespace std;

void findStart(char**, int&, int&);			// find the starting point of the maze
void generateCells(char**);					// generates a map of cells used to generate the maze
void generateMaze(int, int, char**, int**&);// generates the maze given the initial cell map
void generatePoints(char**);				// generates the starting and ending points
bool canMove(int, int, char**);				// verify if I can move to a certain square
void printMaze(char**);						// print all the squares in the maze
bool solve(int, int, char**);				// solve the maze using backtracking
bool loadMaze(char**);						// load the maze from a text file
void saveMaze(char**);						// saves the maze matrix into a text file
void initialize(char**&, int**&);			// initialize arrays and matrixs we need
void freeMemory(char**&, int**&);			// delete maze and directions matrix

const char START = '%';
const char EMPTY = ' ';
const char WALL  = '+';
const char PATH  = '#';
const char FIND  = '$';
const int  SIZE  =  21; // impar

int main()
{
	char** maze = NULL;
	int** directions = NULL;
	int option = -1;
	int x, y;
	// random seed:
	srand(time(NULL));
	do
	{
		cout << "MENU:\n"
			<< "1) Crear laberinto\n"
			<< "2) Resolver laberinto\n"
			<< "0) Salir\n"
			<< "Seleccione una opcion: ";
		cin >> option;
		switch (option)
		{
			case 1:
				initialize(maze, directions);
				generateCells(maze);
				generateMaze(1, 1, maze, directions);
				generatePoints(maze);
				saveMaze(maze);
				freeMemory(maze, directions);
				break;

			case 2:
				initialize(maze, directions);
				if (loadMaze(maze))
				{
					findStart(maze, x, y);
					solve(x, y, maze);
				}
				else
				{
					cout << "Primero debe crear el laberinto!" << endl;
				}
				freeMemory(maze, directions);
				break;

			case 0:
				freeMemory(maze, directions);
				cout << "Saliendo..." << endl;
				break;

			default:
				cout << "Opcion no valida!\n\n";
				break;
		}
	}
	while (option != 0);
	return 0;
}

// find the starting point of the maze
void findStart(char** maze, int& x, int& y)
{
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			if (maze[i][j] == START)
			{
				x = j;
				y = i;
			}
}

// generates a map of cells used to generate the maze
void generateCells(char** grid)
{
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			if (i % 2 == 0 || j % 2 == 0)
				grid[i][j] = WALL;
			else
				grid[i][j] = EMPTY;
}

// generates the maze given the initial cell map
void generateMaze(int x, int y, char** maze, int**& directions)
{
	random_shuffle(&directions[0], &directions[4]);
	int wx, wy, dx, dy;
	usleep(50000);
	printMaze(maze);
	for (int i = 0; i < 4; i++)
	{
		// wx, wy are WALL positions
		// dx, dy are CELL positions
		wx =  x + directions[i][0];
		wy =  y + directions[i][1];

		dx = wx + directions[i][0];
		dy = wy + directions[i][1];

		if (dx >= 0 && dx < SIZE && dy >= 0 && dy < SIZE && maze[dy][dx] != PATH)
		{
			maze[wy][wx] = maze[dy][dx] = PATH;
			generateMaze(dx, dy, maze, directions);
		}
	}
}

// generates the starting and ending points
void generatePoints(char** maze)
{
	int x = rand() % SIZE;
	int y = rand() % SIZE;

	while (maze[y][x] != PATH)
	{
		x = rand() % SIZE;
		y = rand() % SIZE;
	}
	maze[y][x] = START;

	while (maze[y][x] != PATH)
	{
		x = rand() % SIZE;
		y = rand() % SIZE;
	}
	maze[y][x] = FIND;
}

// verify if I can move to a certain square
bool canMove(int x, int y, char** maze)
{
	return x >= 0 && x < SIZE && y >= 0 && y < SIZE && maze[y][x] != WALL && maze[y][x] != PATH;
}

// print all the squares in the maze
void printMaze(char** maze)
{
	cout << endl << "---------------------\n\n";
	for (int i = 0; i < SIZE; i++)
		cout << maze[i] << endl;
}

// solve the maze using backtracking
bool solve(int x, int y, char** maze)
{
	usleep(25000);
	printMaze(maze);
	if (canMove(x, y, maze))
	{
		// target square was found
		if (maze[y][x] == FIND)
			return true;

		maze[y][x] = PATH;

		// move up
		if (solve(x, y + 1, maze))
			return true;

		// move down
		if (solve(x, y - 1, maze))
			return true;

		// move left
		if (solve(x - 1, y, maze))
			return true;

		// move right
		if (solve(x + 1, y, maze))
			return true;

		// dead end, unmark solution
		maze[y][x] = EMPTY;
		return false;
	}
	else
	{
		return false;
	}
}

// load the maze from a text file
bool loadMaze(char** maze)
{
	string line;
	ifstream mazeFile("maze.txt");
	if (mazeFile.is_open())
	{
		for (int i = 0; i < SIZE; i++)
		{
			getline(mazeFile, line);
			for (int j = 0; j < SIZE; j++)
				maze[i][j] = line[j];
		}
		mazeFile.close();
		return true;
	}
	else
	{
		return false;
	}
}

// saves the maze matrix into a text file
void saveMaze(char** maze)
{
	ofstream mazeFile("maze.txt");
	if (mazeFile.is_open())
	{
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				if (maze[i][j] == PATH)
					mazeFile << EMPTY;
				else
					mazeFile << maze[i][j];
			}
			mazeFile << endl;
		}
		mazeFile.close();
	}
}

// initialize maze and directions matrix, and coords array
void initialize(char**& maze, int**& directions)
{
	// initialize maze
	maze = new char*[SIZE];
	for (int i = 0; i < SIZE; i++)
		maze[i] = new char[SIZE];

	// initialize directions
	directions = new int*[4];
	for (int i = 0; i < 4; i++)
		directions[i] = new int[2];

	// set directions values
	// up
	directions[0][0] =  0;
	directions[0][1] = -1;

	// down
	directions[1][0] =  0;
	directions[1][1] =  1;

	// left
	directions[2][0] = -1;
	directions[2][1] =  0;

	// right
	directions[3][0] =  1;
	directions[3][1] =  0;
}

// delete all the arrays and matrixs
void freeMemory(char**& maze, int**& directions)
{
	// delete maze matrix
	if (maze != NULL)
	{
		for (int i = 0; i < SIZE; i++)
		{
			delete[] maze[i];
			maze[i] = NULL;
		}
		delete[] maze;
		maze = NULL;
	}

	// delete directions matrix
	if (directions != NULL)
	{
		for (int i = 0; i < 4; i++)
		{
			delete[] directions[i];
			directions[i] = NULL;
		}
		delete[] directions;
		directions = NULL;
	}
}
