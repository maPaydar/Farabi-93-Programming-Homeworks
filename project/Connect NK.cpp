
/* connect NK.cpp : Playing connect NK, enjoy the game!
finishing Date, 15th,jan,2015
MAP, Paydar
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void frame(int n, char** &pos);	 /* draws the table based on the pointer provided with, for the first time. a function, one shot!! */
void fill(int n, int player, int targetCol, int targetRow, char** &pos); /* fills the array and redraws the table */
bool winner_XY1(int n, int k, char** pos, int targetCol, int targetRow); /* checks the game over conditon for main diagonal, and if was true, replace the cells, draws the table again */
bool winner_XY2(int n, int k, char** pos, int targetCol, int targetRow); /* checks the game over conditon for minor diagonal, and if was true, replace the cells, draws the table again */
bool winner_Y(int n, int k, char** pos, int targetCol, int targetRow);	/* checks the game over condition for vertical lines, and if was true, replace the cells, draws the table again */
bool winner_X(int n, int k, char** pos, int targetCol, int targetRow);	/* checks the game over condition for Horizontal lines, and if was true, replace the cells, draws the table again */
bool equal(int n, char** pos);  // checks the situation in which, all the cells are filled and no one has won
void save(int n, int k, int player, char** pos, string savename);  /* breifly saves the current state of game by given filename (prints the whole game into a file) */
void load(int& n, int& k, int& player, char** &pos, string savename); /* loading and printing the loaded game */

int main()
{
	string enter;
	string savename;
	string Load;
	string existsave;
	ifstream finList;
	ofstream foutList;
	bool win = false;
	bool newsave;
	bool equ = 0;
	bool againsave = true;
	bool savexist = 0;
	int exsistsave = 0;
	bool filledCol = false;
	bool inRange = true;
	int n;
	int k;
	int targetRow = 0;
	int targetCol;
	int player; /// if the number assigned to player is odd, means player is X, and if the number is even, p  ///
	char** pos;	 /// we will need 2n + 1 pointers to 4n + 1 other chars, which means A 2D array of (2n + 1) * (4n + 1) /\/
	char againPlay = 'n';
	char rewrite;
	do
	{
		foutList.open("SaveList.txt", ios::app);
		cin >> n;
		cin >> k;
		while (k <= 0 || n <= 0 || k > n)
		{
			cout << "Enter N, K again: ";
			cin >> n;
			cin >> k;
		}
		pos = new char*[2 * n + 1];
		for (int i = 0; i < 2 * n + 1; i++)
		{
			pos[i] = new char[4 * n + 1];
		}
		frame(n, pos);
		player = 1;	  /// First Player is always X /\/ 
		while (true)			/// the main asking enter target column loop /\/
		{
            finList.clear();
            finList.seekg(0);
			if (filledCol == true)
			{
				cout << "Enter another Column : ";
				filledCol = false;
			}
			else if (inRange == false)
			{
				cout << "Enter a number in range 1 to " << n << " :";
				inRange = true;
			}
			cin >> enter;
			if (enter.at(0) == 'a')
			{
				finList.open("SaveList.txt");
				string load;
				while (finList >> load)
				{
					cout << load << endl;
				}
			}
			else if (enter.at(0) == 'l')
			{
				savename = enter.erase(0, 1);
				load(n, k, player, pos, savename);
				continue;
			}
			else if (enter.at(0) == 's') ///for saving 
			{
                finList.open("SaveList.txt");
                exsistsave = 0;
                finList.clear();
                finList.seekg(0);
				savename = enter.erase(0, 1);
				while (finList >> existsave)		  ///checking if savename existed in the list before /\/
				{
					if (existsave == savename)
						exsistsave++;
				}
				finList.seekg(0);
				if (exsistsave != 0)
				{
					cout << "The save name you entered DOES exist . To rewrite the previous save, Enter y/Y ,  To save with a new name, Enter n/N : ";
					cin >> rewrite;
					if (rewrite == 'y' || rewrite == 'Y')
					{
						save(n, k, player, pos, savename);
						continue;
					}
					else if (rewrite == 'n' || rewrite == 'N')		/// if it comes here, it means the user wants to save under a defferent name, so similarity of new name to names in list would not be tolerated! /\/
					{
                        newsave = false;
						while (againsave == true)
						{
                            finList.open("SaveList.txt");
							exsistsave = 0;
							cout << "Enter the New Save Name : ";
							cin >> savename;
							finList.clear();
							finList.seekg(0);	 /// going up to the beginning of file /\/
							while (finList >> existsave)
							{
								if (existsave == savename)
									exsistsave++;
							}
							finList.clear();
							finList.seekg(0);
							if (exsistsave == 0)
							{
								foutList << savename << endl;
								save(n, k, player, pos, savename);
								againsave = false;
								newsave = true;
								continue;	
							}
						}
						if(newsave == true)
						    continue;
					}
				}
				/// this else is when the user had entered a new save name in the first place /\/
				else
				{
					foutList << savename << endl;
					save(n, k, player, pos, savename);
					continue;
				}
				
			}/// if the user had not entered -1 or -2, meaning user is playing, the rest of game runs /\/
			else // in this else , it means that user enter a number as target Column 
			{
				targetCol = atoi(enter.c_str());
				if (targetCol <= 0 || targetCol > n)
				{
					inRange = false;
		     		continue;
				}
				else if (targetCol > 0 && targetCol <= n)
				{
					for (int i = 2 * n - 1; i >= 0; i -= 2) /// az in for mikhaym radifi ke khali hast baraye oon targetCol ro peyda konim ///
					{
						if (pos[i][4 * targetCol - 2] == ' ')
						{
							targetRow = i;
							filledCol = false;
							break;
						}
						else
							filledCol = true;
					}
					if (filledCol == true)
					{
						continue;
					}
					else
						fill(n, player, targetCol, targetRow, pos);
					/// just filling and drawing the table again /\/
				}
				win = winner_Y(n, k, pos, 4 * targetCol - 2, targetRow);	   /// the folowing, checks the wining condition, if true goes to asking whether to play again or not
				if (win == true)
					break;
				win = winner_X(n, k, pos, 4 * targetCol - 2, targetRow);
				if (win == true)
					break;
				win = winner_XY1(n, k, pos, 4 * targetCol - 2, targetRow);
				if (win == true)
					break;
				win = winner_XY2(n, k, pos, 4 * targetCol - 2, targetRow);
				if (win == true)
					break;
				equ = equal(n, pos);
				if (equ == true)
				{
					cout << "<<<  X & O are equal , NO WINNER :(  >>>" << endl;
					break;
				}
			}
			player++;
		}
		if (equ == true || win == true)
		{
			cout << "To Play again Enter Y/y and To Exit game N/n : ";
			cin >> againPlay;
		}
	} while (againPlay == 'y' || againPlay == 'Y');
	return 0;
}

void frame(int n, char** &pos)   /*draws the table based on the pointer provided with*/
{
	for (int row = 0; row < 2 * n + 1; row++)	  /// for each row we need 2 arrays, one for the cells and one for the line. ///
	{
		for (int col = 0; col < 4 * n + 1; col++)	/// for each column, we need 4 arrays, one for line, two for blank spaces and one for the X or O. ///
		{
			if (row % 2 == 0)
			{
				if (col % 4 == 0)
				{
					pos[row][col] = '+';  /// if the col is devided by 4 and row by 2, pos is at the joint of the table, which are drawn by "+"///
				}
				else
				{
					pos[row][col] = '-';  /// if the row is devided by 2 and the col is not devide by 4 pos is drawing lines by "-"///
				}
			}
			else
			{
				if (col % 4 == 0)		   /// if the col is not row is not divided by 2, pos contains table cells infos, which every 4 cell are "|"///
				{
					pos[row][col] = '|';
				}
				else
				{
					pos[row][col] = ' ';  /// at the other cells of pos we put " " so it may replace by X or O later///
				}
			}
		}
	}
}
void fill(int n, int player, int targetCol, int targetRow, char** &pos)   /*fills the array and redraws the table*/
{
	if (player % 2 == 1)
	{
		pos[targetRow][4 * targetCol - 2] = 'X';
	}
	else
	{
		pos[targetRow][4 * targetCol - 2] = 'O';
	}
	
	for (int row = 0; row < 2 * n + 1; row++) /// drawing the array, again ///
	{
		for (int col = 0; col < 4 * n + 1; col++)
		{
			cout << pos[row][col];
		}
		cout << endl;
	}
}
bool winner_XY1(int n, int k, char** pos, int targetCol, int targetRow)	/* checks the game over conditon for main diagonal, and if was true, replace the cells, draws the table again */
{
	int kcounter = 1; // shows the number of equal X or O next each other //
	int row = targetRow;
	int col = targetCol;
	char fristwinner = pos[targetRow][targetCol];
	row -= 2;
	col -= 4;
	while (row >= 1 && col >= 2) // checking the upper side of diagonal line //
	{
		if (pos[row][col] == fristwinner)
		{
			kcounter++;
			row -= 2;
			col -= 4;
			if (row < 1 || col < 2)
				break;
		}
		else
			break;
	}
	row = targetRow + 2;
	col = targetCol + 4;
	while (row <= 2 * n - 1 && col <= 4 * n - 2)
	{
		if (pos[row][col] == fristwinner)			 // checking if the lower side of diagonal line //
		{
			kcounter++;
			row += 2;
			col += 4;
			if (row > 2 * n - 1 || col > 4 * n - 2)
				break;
		}
		else
			break;
	}
	if (kcounter == k)
	{
		if (fristwinner == 'X')
		{
			row = targetRow;
			col = targetCol;
			while (row >= 1 && col >= 2 && pos[row][col] == fristwinner)
			{
				pos[row][col] = '*';
				row -= 2;
				col -= 4;
				if (row < 1 || col < 2)
					break;
			}
			row = targetRow + 2;
			col = targetCol + 4;
			if (row <= 2 * n - 1 && col <= 4 * n - 2)
				while (pos[row][col] == fristwinner)
				{
					pos[row][col] = '*';
					row += 2;
					col += 4;
					if (row > 2 * n - 1 || col > 4 * n - 2)
						break;
				}
			//system("CLS");
			for (int row = 0; row < 2 * n + 1; row++)
			{
				for (int col = 0; col < 4 * n + 1; col++)
				{
					cout << pos[row][col];
				}
				cout << endl;
			}
			cout << "!!!! WINNER IS : " << fristwinner << " !!!!" << endl;
			return true;
		}
		else	 // if this else operates, it means the winner was O, it repeats all upper codes, just for O and Q this time //
		{
			row = targetRow;
			col = targetCol;
			while (row >= 1 && col >= 2 && pos[row][col] == fristwinner)
			{
				pos[row][col] = 'Q';
				row -= 2;
				col -= 4;
				if (row < 1 || col < 2)
					break;
			}
			row = targetRow + 2;
			col = targetCol + 4;
			if (row <= 2 * n - 1 && col <= 4 * n - 2)
				while (pos[row][col] == fristwinner)
				{
					pos[row][col] = 'Q';
					row += 2;
					col += 4;
					if (row > 2 * n - 1 || col > 4 * n - 2)
						break;
				}
			///system("CLS");
				for (int row = 0; row < 2 * n + 1; row++)
				{
					for (int col = 0; col < 4 * n + 1; col++)
					{
						cout << pos[row][col];
					}
					cout << endl;
				}
				cout << "!!!! WINNER IS : " << fristwinner << " !!!!" << endl;
				return true;
		}
	}
	else		   // if this else operates it means not adequet number of X or O were set //
		return false;
}
bool winner_XY2(int n, int k, char** pos, int targetCol, int targetRow)	   /* same comments as upper function apply for this one as well */
{
	int kcount = 1;
	int row = targetRow;
	int col = targetCol;
	char fristwinner = pos[targetRow][targetCol];
	row += 2;
	col -= 4;
	while (row <= 2 * n - 1 && col >= 2)
	{
		if (pos[row][col] == fristwinner)
		{
			kcount++;
			row += 2;
			col -= 4;
			if (row > 2 * n - 1 || col < 2)
				break;
		}
		else
			break;
	}
	row = targetRow - 2;
	col = targetCol + 4;
	while (row >= 1 && col <= 4 * n - 2)
	{
		if (pos[row][col] == fristwinner)
		{
			kcount++;
			row -= 2;
			col += 4;
			if (row < 1 || col > 4 * n - 2)
				break;
		}
		else
			break;
	}
	if (kcount == k)
	{
		if (fristwinner == 'X')
		{
			row = targetRow;
			col = targetCol;
			while (row <= 2 * n - 1 && col >= 2 && pos[row][col] == fristwinner)
			{
				pos[row][col] = '*';
				row += 2;
				col -= 4;
				if (row > 2 * n - 1 || col < 2)
					break;
			}
			row = targetRow - 2;
			col = targetCol + 4;
			if (row >= 1 && col <= 4 * n - 2)
				while (pos[row][col] == fristwinner)
				{
					pos[row][col] = '*';
					row -= 2;
					col += 4;
					if (row < 1 || col > 4 * n - 2)
						break;
				}
		//	system("CLS");
			for (int row = 0; row < 2 * n + 1; row++)
			{
				for (int col = 0; col < 4 * n + 1; col++)
				{
					cout << pos[row][col];
				}
				cout << endl;
			}
			cout << "!!!! WINNER IS : " << fristwinner << " !!!!" << endl;
			return true;
		}
		else
		{
			row = targetRow;
			col = targetCol;
			while (row <= 2 * n - 1 && col >= 2 && pos[row][col] == fristwinner)
			{
				pos[row][col] = 'Q';
				row += 2;
				col -= 4;
				if (row > 2 * n - 1 || col < 2)
					break;
			}
			row = targetRow - 2;
			col = targetCol + 4;
			if (row >= 1 && col <= 4 * n - 2)
			while (pos[row][col] == fristwinner)
			{
				pos[row][col] = 'Q';
				row -= 2;
				col += 4;
				if (row < 1 || col > 4 * n - 2)
					break;
			}
			//system("CLS");
			for (int row = 0; row < 2 * n + 1; row++)
			{
				for (int col = 0; col < 4 * n + 1; col++)
				{
					cout << pos[row][col];
				}
				cout << endl;
			}
			cout << "!!!! WINNER IS : " << fristwinner << " !!!!" << endl;
			return true;
		}
	}
	else
		return false;
}
bool winner_Y(int n, int k, char** pos, int targetCol, int targetRow)  /* checks the game over condition for vertical lines, and if was true, replace the cells, draws the table again */
{
	int kcounter = 1; // for every equal char (X or O) it is plusplused, it's then compared by provided k //
	int row = targetRow;
	int col = targetCol;
	int temp;	// it holds the modified  targetRow
	char firstwinner = pos[targetRow][targetCol];
	row += 2;
	while (row <= 2 * n - 1)
	{
		if (pos[row][col] == firstwinner)
		{
			kcounter++;
			row += 2;
		}
		else
			break;
		if (row > 2 * n - 1)
			break;
	}
	if (kcounter == k)
	{
		if (firstwinner == 'X')
		{
			temp = targetRow;
			while (pos[temp][targetCol] == firstwinner)			// it checks if the lower cell is the same
			{
				pos[temp][targetCol] = '*';
				temp += 2;
				if (temp > 2 * n - 1)
					break;
			}
			///system("CLS");
			for (int row = 0; row < 2 * n + 1; row++)
			{
				for (int col = 0; col < 4 * n + 1; col++)
				{
					cout << pos[row][col];
				}
				cout << endl;
			}
			cout << "!!!! WINNER IS : " << firstwinner << " !!!!" << endl;
			return true;
		}
		else
		{
			temp = targetRow;
			while (pos[temp][targetCol] == firstwinner)
			{
				pos[temp][targetCol] = 'Q';
				temp += 2;
				if (temp > 2 * n - 1)
					break;
			}
			for (int row = 0; row < 2 * n + 1; row++)
			{
				for (int col = 0; col < 4 * n + 1; col++)
				{
					cout << pos[row][col];
				}
				cout << endl;
			}
			cout << "!!!! WINNER IS : " << firstwinner << " !!!!" << endl;
			return true;
		}
	}
	else
		return false;
}
bool winner_X(int n, int k, char** pos, int targetCol, int targetRow) /* checks the game over condition for Horizontal lines, and if was true, replace the cells, draws the table again */
{
	int kcounter = 1;// for every equal char (X or O) it is plusplused, it's then compared by provided k //
	int row = targetRow;
	int col = targetCol;
	char fristwinner = pos[targetRow][targetCol];
	col -= 4;
	while (col >= 2)			 // checking the cells before the provided cell in the row, to see if them are the same //
	{
		if (pos[row][col] == fristwinner)
		{
			kcounter++;
			col -= 4;
		}
		else
			break;
	}
	col = targetCol + 4;
	while (col <= 4 * n - 2)		  // checking if the cells after the given cell in the row are the same //
	{
		if (pos[row][col] == fristwinner)
		{
			kcounter++;
			col += 4;
		}
		else
			break;
	}
	if (kcounter == k)						 // turning 'X' to '*' and 'O' to 'Q' and printing the table again
	{
		if (fristwinner == 'X')
		{
			int temp = targetCol;
			while (pos[targetRow][temp] == fristwinner)
			{
				pos[targetRow][temp] = '*';
				temp += 4;
				if (temp > 4 * n - 2)
					break;
			}
			temp = targetCol - 4;
			if (temp >= 2)
			while (temp >= 2 && pos[targetRow][temp] == fristwinner)
			{
				pos[targetRow][temp] = '*';
				temp -= 4;
				if (temp < 2)
					break;
			}
		///	system("CLS");
			for (int row = 0; row < 2 * n + 1; row++)
			{
				for (int col = 0; col < 4 * n + 1; col++)
				{
					cout << pos[row][col];
				}
				cout << endl;
			}

			cout << "!!!! WINNER IS : " << fristwinner << " !!!!" << endl;
			return true;
		}
		else
		{
			int temp = targetCol;
			while (pos[targetRow][temp] == fristwinner)
			{
				pos[targetRow][temp] = 'Q';
				temp += 4;
				if (temp > 4 * n - 2)
					break;
			}
			temp = targetCol - 4;
			if (temp >= 2)
			while (temp >= 2 && pos[targetRow][temp] == fristwinner)
			{
				pos[targetRow][temp] = 'Q';
				temp -= 4;
				if (temp < 2)
					break;
			}
		   	///system("CLS");
			for (int row = 0; row < 2 * n + 1; row++)
			{
				for (int col = 0; col < 4 * n + 1; col++)
				{
					cout << pos[row][col];
				}
				cout << endl;
			}

			cout << "!!!! WINNER IS : " << fristwinner << " !!!!" << endl;
			return true;
		}
	}
	else
		return false;
}
bool equal(int n, char** pos)	// checks the situation in which, all the cells are filled and no one has won.
{
	int equ = 0;	//counts the number of filled cells which contain sth different than ' '//
	for (int row = 1; row <= 2 * n - 1; row += 2)
	{
		for (int col = 2; col <= 4 * n - 2; col += 4)
		{
			if (pos[row][col] != ' ')
				equ++;
		}
	}
	if (equ == n * n)
		return true;
	else
		return false;
}
void save(int n, int k, int player, char** pos, string savename) /* breifly saves the current state of game by given filename */
{
	ofstream fout;
	fout.open(savename.c_str() , ios::out );
	fout << n << endl << k << endl << player << endl;
	for (int row = 0; row < 2 * n + 1; row++)
	{
		for (int col = 0; col < 4 * n + 1; col++)
		{
			fout << pos[row][col];
		}
		fout << endl;
	}
}
void load(int& n, int& k, int& player, char** &pos, string savename)	 /* loading and printing the loaded game */
{
	    char enter;
	    string temp;
    	bool existLoad = false;
		ifstream fin;
		ifstream finList;
		finList.open("SaveList.txt");
		while (finList >> temp)
		{
			if (savename == temp)
			{
				existLoad = true;
			}
		}
		if (existLoad == true)
		{
			fin.open(savename.c_str(), ios::out);
			fin >> n >> k >> player;
			fin.get(enter);	   /* the enter character after player variable, should not be included in the array cells*/
			pos = new char*[2 * n + 1];
			for (int i = 0; i < 2 * n + 1; i++)
			{
				pos[i] = new char[4 * n + 1];
			}

			for (int row = 0; row < 2 * n + 1; row++)
			{
				for (int col = 0; col < 4 * n + 1; col++)
				{
					fin.get(pos[row][col]);	// using get, helped to recieve chaars
				}
				fin.get(enter);	  /* the enter charachter at the end of the lines shoul not be included in the arrays cells */
			}
			for (int row = 0; row < 2 * n + 1; row++)
			{
				for (int col = 0; col < 4 * n + 1; col++)
				{
					cout << pos[row][col];
				}
				cout << endl;
			}
		}
}

