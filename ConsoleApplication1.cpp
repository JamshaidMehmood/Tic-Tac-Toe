#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
using namespace std;
void boardDisplay(char a[][3]);
void playerVsPlayerTurn(char a[][3]);
void playerVsComputerTurn(char a[][3]);
bool gameFinishing(char a[][3]);
void playerVsPlayerTurnResult(char b[][3]);
void playerVsComputerTurnResult(char c[][3]);
char turn = '1';
int i, j;
bool draw = false;


int main()
{
	cout << "Previous record is as :" << endl;
	ifstream fin;

	fin.open("C:\\Users\\mahmo\\Desktop\\project second semester\\Update Records.txt");
	if (!fin.fail())
	{
		string name1, name2, name3, dummy, name4, name5, name6, dummy2, name7, name8, name9;
		int num;
		fin >> name1;
		cout << name1 << endl;
		fin >> name2;
		cout << name2 << endl;
		fin >> name3;
		cout << name3 << endl;
		fin >> name4 >> name5 >> num >> name6 >> name7 >> name8 >> name9;
		cout << name4 << " " << name5 << " " << num << " " << name6 << " " << name7 << endl << endl;

	}
	else
	{
		cout << "Unable to open that file ";
	}
	char again = 'y';
	while (again == 'y' || again == 'Y')
	{
		char boardMaking[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
		char dummyChoice;
		cout << "Enter to whome you want to play the game " << endl;
		cout << "(C || c ) for computer and (P || p ) for player VS player :";
		cin >> dummyChoice;
		cin.ignore();
		if (dummyChoice == 'C' || dummyChoice == 'c')
		{
			playerVsComputerTurnResult(boardMaking);
		}
		else if (dummyChoice == 'P' || dummyChoice == 'p')
		{
			playerVsPlayerTurnResult(boardMaking);
		}
		cout << "Do you want to play again (press y || Y ) :";
		cin >> again;


	}
	return 0;

}
void boardDisplay(char a[][3])
{
	system("cls");
	cout << "      tick tack toe game" << endl;
	cout << "\t player1[A] \n\t player2[B]" << endl;
	cout << "\t\t     |     |     \n";
	cout << "\t\t" << a[0][0] << "    |  " << a[0][1] << "  |   " << a[0][2] << "   \n";
	cout << "\t\t_____|_____|______\n";
	cout << "\t\t     |     |     \n";
	cout << "\t\t" << a[1][0] << "    |  " << a[1][1] << "  |   " << a[1][2] << "   \n";
	cout << "\t\t_____|_____|______\n";
	cout << "\t\t     |     |     \n";
	cout << "\t\t" << a[2][0] << "    |  " << a[2][1] << "  |   " << a[2][2] << "   \n";
	cout << "\t\t     |     |     \n";
}
void playerVsComputerTurn(char a[][3])
{
	int choice, seed, dummy;
	seed = time(0);
	srand(seed);
	dummy = rand() % 9 + 1;
	if (turn == '1')
	{
		cout << "Player 1 turn (A):";
		cin >> choice;
	}
	else if (turn == '0')
	{
		cout << "Player 2 turn (B):";
		choice = dummy;
	}
	if (choice != 0)
	{
		switch (choice)
		{
		case 1:
			i = 0; j = 0;
			break;
		case 2:
			i = 0; j = 1;
			break;
		case 3:
			i = 0; j = 2;
			break;
		case 4:
			i = 1; j = 0;
			break;
		case 5:
			i = 1; j = 1;
			break;
		case 6:
			i = 1; j = 2;
			break;
		case 7:
			i = 2; j = 0;
			break;
		case 8:
			i = 2; j = 1;
			break;
		case 9:
			i = 2; j = 2;
			break;
		default:
			cout << "INVALID ENTRY AS THIS ENTERY IS ALREADY FILLED::::!" << endl;
			break;

		}
	}
	if (turn == '1' && a[i][j] != 'A' && a[i][j] != 'B')
	{
		a[i][j] = 'A';
		turn = '0';
	}
	else if (turn == '0' && a[i][j] != 'A' && a[i][j] != 'B')
	{
		a[i][j] = 'B';
		turn = '1';
	}
	else
	{
		cout << "This space is already filled" << endl;
	}
	boardDisplay(a);
}
void playerVsPlayerTurn(char a[][3])
{
	int choice;

	if (turn == '1')
	{
		cout << "Player 1 turn (A):";
	}
	else if (turn == '0')
	{
		cout << "Player 2 turn (B):";
	}
	cin >> choice;
	switch (choice)
	{
	case 1:
		i = 0; j = 0;
		break;
	case 2:
		i = 0; j = 1;
		break;
	case 3:
		i = 0; j = 2;
		break;
	case 4:
		i = 1; j = 0;
		break;
	case 5:
		i = 1; j = 1;
		break;
	case 6:
		i = 1; j = 2;
		break;
	case 7:
		i = 2; j = 0;
		break;
	case 8:
		i = 2; j = 1;
		break;
	case 9:
		i = 2; j = 2;
		break;
	default:
		cout << "INVALID ENTRY AS THIS ENTERY IS ALREADY FILLED::::!" << endl;
		break;

	}
	if (turn == '1' && a[i][j] != 'A' && a[i][j] != 'B')
	{
		a[i][j] = 'A';
		turn = '0';
	}
	else if (turn == '0' && a[i][j] != 'A' && a[i][j] != 'B')
	{
		a[i][j] = 'B';
		turn = '1';
	}
	else
	{
		cout << "This space is already filled" << endl;
	}
	boardDisplay(a);
}
bool gameFinishing(char a[][3])
{
	for (int i = 0; i < 3; i++)
	{
		if ((a[i][0] == a[i][1]) && (a[i][0] == a[i][2]) || (a[0][i] == a[1][i]) && (a[0][i] == a[2][i]))
		{
			return false;

		}
		if ((a[0][0] == a[1][1]) && (a[0][0] == a[2][2]) || (a[0][2] == a[1][1]) && (a[0][2] == a[2][0]))
		{
			return false;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (a[i][j] != 'A' && a[i][j] != 'B')
			{
				return true;
			}
		}

	}
	draw = true;
	return false;
}
void playerVsPlayerTurnResult(char b[][3])
{
	ofstream fout, fout1;

	fout.open("C:\\Users\\mahmo\\Desktop\\project second semester\\game Records.txt", ios::app);
	fout1.open("C:\\Users\\mahmo\\Desktop\\project second semester\\Update Records.txt");


	if (!fout.fail() || fout1.fail())
	{
		string name1, name2;
		cout << "Player 1 enter your name :";
		getline(cin, name1);
		fout << name1 << endl;
		fout1 << name1 << endl;
		fout << "VS" << endl;
		fout1 << "VS" << endl;
		cout << "Player 2 enter your name :";
		getline(cin, name2);
		fout << name2 << endl;
		fout1 << name2 << endl;
		cout << "DISPAYING INFORMATION ABOUT MATCH " << endl;
		cout << "Player (1) is :" << name1 << endl;
		cout << "Player (2) is :" << name2 << endl;
		cout << "Press enter key to start the match !!!!" << endl;
		cin.get();
		while (gameFinishing(b))
		{
			boardDisplay(b);
			playerVsPlayerTurn(b);

		}
		if (turn == '1' && draw == false)
		{
			cout << "Congratulations player 2 " << "(" << name2 << ")  win " << endl;
			fout << "Congratulations player 2 " << "(" << name2 << ")  win " << endl;
			fout1 << "Congratulations player 2 " << "(" << name2 << ")  win " << endl;
		}
		else if (turn == '0' && draw == false)
		{
			cout << "Congratulations player 1 " << "(" << name1 << ")  win " << endl;
			fout << "Congratulations player 1 " << "(" << name1 << ")  win " << endl;
			fout1 << "Congratulations player 1 " << "(" << name1 << ")  win " << endl;
		}
		else
		{
			cout << "Game is draw !!!!:" << endl;
			fout << "Game is draw !!!!:" << endl;
			fout1 << "Game is draw !!!!:" << endl;
		}
		fout.close();
		fout1.close();
	}
	else
	{
		cout << "Unable to open that file ";
	}
}
void playerVsComputerTurnResult(char c[][3])
{
	ofstream fout, fout1;

	fout.open("C:\\Users\\mahmo\\Desktop\\project second semester\\game Records.txt", ios::app);
	fout1.open("C:\\Users\\mahmo\\Desktop\\project second semester\\Update Records.txt");


	if (!fout.fail() || fout1.fail())
	{
		string name1, name2;
		cout << "Player (1) enter your name :";
		getline(cin, name1);
		fout << name1 << endl;
		fout << "VS" << endl;
		fout1 << name1 << endl;
		fout1 << "VS" << endl;
		name2 = "COMPUTER";
		cout << "Player (2) is :" << name2 << endl << endl;
		fout << name2 << endl;
		fout1 << name2 << endl;
		cout << "DISPAYING INFORMATION ABOUT MATCH " << endl << endl;
		cout << "Player (1) is :" << name1 << endl;
		cout << "Player (2) is :" << name2 << endl;
		cout << "Press enter key to start the match !!!!" << endl;
		cin.get();
		while (gameFinishing(c))
		{
			boardDisplay(c);
			playerVsComputerTurn(c);

		}
		if (turn == '1' && draw == false)
		{
			cout << "Congratulations player 2 " << "(" << name2 << ")  win " << endl;
			fout << "Congratulations player 2 " << "(" << name2 << ")  win " << endl;
			fout1 << "Congratulations player 2 " << "(" << name2 << ")  win " << endl;
		}

		else if (turn == '0' && draw == false)
		{
			cout << "Congratulations player 1 " << "(" << name1 << ")  win " << endl;
			fout << "Congratulations player 1 " << "(" << name1 << ")  win " << endl;
			fout1 << "Congratulations player 1 " << "(" << name1 << ")  win " << endl;
		}
		else
		{
			cout << "Game is draw !!!!:" << endl;
			fout << "Game is draw !!!!:" << endl;
			fout1 << "Game is draw !!!!:" << endl;
		}
		fout.close();
		fout1.close();
	}
	else
	{
		cout << "Unable to open that file ";
	}

}