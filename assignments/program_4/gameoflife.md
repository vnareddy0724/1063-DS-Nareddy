```cpp
/**
* @ProgramName: Program-4
* @Author: Vahini Nareddy
* @Description:
*     	Game of Life uses a 2d array of values to represent  into a never ending plane.
Meaning if a life form falls off of the world at any of the extremes, it will be transported to
the opposite side and not just disappear.
* @Course: 1063 Data Structures
* @Semester: Spring 2017
* @Date: 30 04 2017
*/

#include <iostream>
#include <string>
#include <fstream>

// #ifdef __cplusplus__
// #include <cstdlib>
// #else
// #include <stdlib.h>
// #endif
#include <Windows.h>
#include<time.h>
using namespace std;

class GameOfLife {
private:
	int **Board;
	int **Board2;
	int Rows;
	int Cols;
	int value;
public:
	GameOfLife(string filename) {
		string line;
		char ch;
		ifstream fin;
		fin.open(filename);
		fin >> Rows >> Cols;
		InitBoardArray(Board);
		InitBoardArray(Board2);
		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {
				fin.get(ch);
				if (ch == 10) {
					continue;
				}
				Board[i][j] = int(ch) - 48;
			}
		}
	}

	GameOfLife(int r, int c) {
		Rows = r;
		Cols = c;
		InitBoardArray(Board);
		InitBoardArray(Board2);
		PrintBoard();
	}

	void InitBoardArray(int **&b) {
		b = new int*[Rows];
		for (int i = 0; i < Rows; i++) {
			b[i] = new int[Cols];
		}
		ResetBoardArray(b);
	}

	void ResetBoardArray(int **&b) {
		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {
				b[i][j] = 0;
			}
		}
	}

	void PrintBoard() {
		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {
				if (Board[i][j] == 1)
					cout << char('X');
				else
					cout << " ";
			}
			cout << endl;
		}
	}
	void GliderGun(GameOfLife G) {
		// Left Block
		G.SetCell(5, 1, 1);
		G.SetCell(5, 2, 1);
		G.SetCell(6, 1, 1);
		G.SetCell(6, 2, 1);
		//Left Gun
		G.SetCell(5, 11, 1);
		G.SetCell(6, 11, 1);
		G.SetCell(7, 11, 1);
		G.SetCell(4, 12, 1);
		G.SetCell(8, 12, 1);
		G.SetCell(3, 13, 1);
		G.SetCell(9, 13, 1);
		G.SetCell(3, 14, 1);
		G.SetCell(9, 14, 1);
		G.SetCell(6, 15, 1);
		G.SetCell(4, 16, 1);
		G.SetCell(8, 16, 1);
		G.SetCell(5, 17, 1);
		G.SetCell(6, 17, 1);
		G.SetCell(7, 17, 1);
		G.SetCell(6, 18, 1);
		//Right Gun
		G.SetCell(3, 21, 1);
		G.SetCell(4, 21, 1);
		G.SetCell(5, 21, 1);
		G.SetCell(3, 22, 1);
		G.SetCell(4, 22, 1);
		G.SetCell(5, 22, 1);
		G.SetCell(2, 23, 1);
		G.SetCell(6, 23, 1);
		G.SetCell(1, 25, 1);
		G.SetCell(2, 25, 1);
		G.SetCell(6, 25, 1);
		G.SetCell(7, 25, 1);
		// Right Block
		G.SetCell(3, 35, 1);
		G.SetCell(4, 35, 1);
		G.SetCell(3, 36, 1);
		G.SetCell(4, 35, 1);
	}

	/**
	* @FunctionName: CountNeightbors
	* @Description:
	*     Calculates the total number of neighbors for a cell
	* @Params:
	*    row -cell to determine neighbors 
		 col -   cell to determine neighbors 
	* @Returns:
	*    int 
	*/

	int CountNeighbors(int row, int col) {
		int neighbors = 0;
		if (Board[row][col] == 1) {
			neighbors--;
		}
		for (int i = row - 1; i <= row + 1; i++) {
			for (int j = col - 1; j <= col + 1; j++) {

				neighbors += Board[(i + Rows) % Rows][(j + Cols) % Cols];

			}
		}
		return neighbors;
	}

	bool OnBoard(int row, int col) {
		return (row >= 0 && row < Rows && col >= 0 && col < Cols);
	}

	void RandomPopulate(int num) {
		int r = 0;
		int c = 0;
		for (int i = 0; i<num; i++) {
			r = rand() % Rows;
			c = rand() % Cols;
			Board[r][c] = 1;
		}
	}

	void SetCell(int r, int c, int val) {
		Board[r][c] = val;
	}

	/**
	* @FunctionName: AddGens
	* @Description:
	*     Adds the values between board1 and board2 for next generation
	* @Params:
	*    none
	* @Returns:
	*    void
	*/

	void AddGens() {
		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {
				Board[i][j] += Board2[i][j];
			}
		}
		ResetBoardArray(Board2);
	}

	void clear_screen(int lines) {
		for (int i = 0; i<lines; i++) {
			cout << endl;
		}
	}

	void Pause(int MilliSeconds)
	{
		clock_t t;
		t = clock();
		int sum = 0;

		while ((clock() - t) < MilliSeconds) {
			sum++;
		}

	}
	/**
	* @FunctionName: Run
	* @Description:
	*	  This function makes the plane move to opposite directions 
	* @Params:
	*    generations - no. of  generations
	* @Returns:
	*    void
	*/

	void Run(int generations = 99999) {
		int neighbors = 0;
		int g = 0;
		while (g < generations) {
			value = 0;
			for (int i = 0; i < Rows; i++) {
				for (int j = 0; j < Cols; j++) {
					neighbors = CountNeighbors(i, j);
					if (Board[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
						Board2[i][j] = -1;
						value = value + 1;
					}
					if (Board[i][j] == 0 && neighbors == 3) {
						Board2[i][j] = 1;
						value = value + 1;
					}
				}
			}

			AddGens();
			PrintBoard();
			Pause(40);

			if (value == 0)
				break;

			value = 0;
			system("cls");
			g++;
		}

	}

};

int main() {
	GameOfLife G(26, 40);

	//GameOfLife G("data2.txt");

	// G.RandomPopulate(60);
	// G.SetCell(0, 5, 1);
	// G.SetCell(0, 6, 1);
	// G.SetCell(0, 7, 1);
	// G.SetCell(1, 5, 1);
	// G.SetCell(1, 6, 1);
	// G.SetCell(1, 7, 1);
	// G.SetCell(2, 5, 1);
	// G.SetCell(2, 6, 1);
	// G.SetCell(2, 7, 1);
	G.GliderGun(G);
	G.Run();
	system("pause");
	return 0;
}
```
