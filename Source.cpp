//Tic Tac Toe Game
//Ian Howard
//10/16/2021

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <math.h>

using namespace std;

void printMatrix(vector<vector<string>> C)
{
	for (int i = 0; i < C.size(); i++) //Condition for printing matrix height
	{
		for (int j = 0; j < C[i].size(); j++) //Prints each ith row by size of ith row
		{
			cout << C[i][j] << " "; //Prints each value in row
		}
		cout << "\n"; //Prints next row
	}
}

int main()
{
	int i = 0, j = 0;
	string player1, player2, input;

	//Cover the Rules
	cout << "Let's play Tic Tac Toe!\nRules:\n1. Type an X or an O followed by the coordinates of the position you would like to go.\n2. The first player to get 3 X's or O's aligned wins.\n\n";
	
	//Input Player 1's Symbol
	do
	{
		player1 = "";
		cout << "First player, please enter which symbol you want to play (X or O): ";
		cin >> player1;
		cout << "\n";
	} while (player1.length() > 1 || !(player1[0] == 'X' || player1[0] == 'O'));

	//Define Player 2's Symbol based on player one's input.
	switch (player1[0])
	{
	case 'X':
		player2 = "O";
		break;
	case 'O':
		player2 = "X";
		break;
	}
	cout << "Second player, your symbol is " << player2 << "\n\n";
	//Creates blank mxn matrix for cofactor storage
	const size_t N = 3;
	const size_t M = 3;
	typedef vector<vector<string>> Matrix;
	typedef vector<string> Row;
	Matrix A;
	Row row(M);

	for (size_t i = 0; i < N; i++) //Condition for loop, inputing row till solution height x is reached
	{
		for (size_t j = 0; j < M; j++) //2nd loop condition, inputing each row 
		{
			row[j] = "+";
		}
		A.push_back(row); //Push row back for next row input
	}

	//Input instructions
	cout << "You will see the Tic Tac Toe board which will update with each turn. Please enter your turn by entering cooridinates \nwhich correspond to the row and column you wish to play (r,c).\n";
	cout << "If you wanted to play the center of the board enter (2,2)\nPlayer 1 goes first:\n\n";

	
	//Loop input until one player gets 3 in a row or until board is full
	for (int p = 1; p < 10; p++)
	{
		//Initial Conditions and Input
		int R, C, RD1 = 0, RD2 = 0, LD1 = 0, LD2 = 0;
		string input, r, c, winner;
		do
		{
			R = 0;
			C = 0;
			//Determine which players turn it is and seek input
			do
			{
				input = "";

				if (p % 2 != 0)
				{
					cout << "Player 1 GO!: ";
					cin >> input;
				}
				else if (p % 2 == 0)
				{
					cout << "Player 2 GO!: ";
					cin >> input;
				}
				else if (((input[1] != '1') || (input[1] != '2') || (input[1] != '3')) || ((input[3] != '1') || (input[3] != '2') || (input[3] != '3')))
				{
					cout << "Remember coordinates are entered in a row then column format (row, column) where r and c are between 1 and 3. Middle of board is (2,2).\n\n";
				}
			} while (((input[1] != '1') && (input[1] != '2') && (input[1] != '3')) && // Checks row input
				((input[3] != '1') && (input[3] != '2') && (input[3] != '3')));   // Checks column input
	   //Extract and Convert Coordinates
			r = input[1];
			c = input[3];
			R = stoi(r) - 1;
			C = stoi(c) - 1;

			//Checks to see if coordinate has already been played.
			if (A[R][C] == "X" || A[R][C] == "O")
			{
				cout << "Position already taken!\n";
				input = "(+,+)";
			}
		} while (input == "(+,+)");

		if (p % 2 != 0)
		{
			A[R][C] = player1;
		}
		else if (p % 2 == 0)
		{
			A[R][C] = player2;
		}

		//Check winning condition
		for (int i = 0; i < M; i++)
		{
			int R1 = 0, R2 = 0, C1 = 0, C2 = 0;
			//Rows
			for (int j = 0; j < N; j++)
			{
				if (A[i][j] == player1)
				{
					R1++;
				}
				else if (A[i][j] == player2)
				{
					R2++;
				}
			}
			//Columns
			for (int j = 0; j < N; j++)
			{
				if (A[j][i] == player1)
				{
					C1++;
				}
				else if (A[j][i] == player2)
				{
					C2++;
				}
			}
			//Right Diagonal
			if (A[i][i] == player1)
			{
				RD1++;
			}
			else if (A[i][i] == player2)
			{
				RD2++;
			}

			//Left Diagonal
			if (A[abs(i-2)][i] == player1)
			{
				LD1++;
			}
			else if (A[abs(i-2)][i] == player2)
			{
				LD2++;
			}

			//Determine Winner
			if (R1 == 3 || C1 == 3 || RD1 == 3 || LD1 == 3)
			{
				winner = player1;
			}
			else if (R2 == 3 || C2 == 3 || RD2 == 3 || LD2 == 3)
			{
				winner = player2;
			}
		}
		printMatrix(A);
		if (winner == player1)
		{
			cout << "The winner is... Player 1!\n\n";
			break;
		}
		else if (winner == player2)
		{
			cout << "The winner is... Player 2!\n\n";
			break;
		}
	}
}
