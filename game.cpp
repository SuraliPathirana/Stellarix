#include <iostream>
#include <windows.h>
#include <fstream>
#include <conio.h>
#include <unistd.h> // for usleep function
#include <cstdlib>
#include <string>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
string *MenuItems();
string *playItems();
string playersName;
void gotoxy(int, int);
void Start();
void Instructions();
void About();
void Exit();
void cursorStatus();
void playeasy();
void playmedium();
void level1();
void level2();
void level3();
void back();
void playDifficult();
void gameOver();
void victoryscreen();
void welcomescreen();
void levelUp();
void rocket();
void selectlevel();
void printCage();
void printLevel();

bool gameRunning = true;
bool endGame = false;
bool endGame2 = false;
int score = 0;


int main()
{

	welcomescreen();
	cursorStatus();

	return 0;
}

void rocket()
{

	char rocket[] =
		"		        /\\\n"
		"		       |==|\n"
		"		       |  |\n"
		" 		       |  |\n"
		"		       |  |\n"
		"		      /____\\\n"
		" 		      |   S|\n"
		"		      |   T|\n"
		"		      |   E|\n"
		"		      |   L|\n"
		"		      |   L|\n"
		" 		      |   A|\n"
		"		     /| | R|\\\n"
		"		    / | | I| \\\n"
		"		   /__|_|_X|__\\\n"
		"		      /_\\/_\\\n"
		" 		      ######\n"
		" 		     ########\n"
		"		      ######\n"
		"		       ####\n"
		"		       ####\n"
		"		        ##\n"
		"			##   ";
	for (int i = 0; i < 50; i++)
		cout << "\n"; // jump to bottom of console
					  //system("color 04");
	cout << rocket;
	int j = 300000;
	for (int i = 0; i < 50; i++)
	{
		usleep(j);			// move faster and faster,
		j = (int)(j * 0.9); // so sleep less each time
		cout << "\n";		// move rocket a line upward
	}
}
void welcomescreen()
{

	system("color 09");
	ifstream welcomescreen2;
	welcomescreen2.open("welcome.txt"); //displays an image at the welcome screen
	std::cout << welcomescreen2.rdbuf();

	welcomescreen2.close();
	Sleep(3000);
	system("cls");

	system("color 0F");
	cout << "\n\n\n\n\n\n\n \t\t\tARE YOU BRAVE ENOUGH TO SAVE THE PLANET EARTH FROM ALIENS?\n"

			"\n\n\t\t\t\t\t   GOOD LUCK SOLDIER!!!!\n\n";

	cout << "\t\t\t\t\t   WE WILL TAKE OFF IN ";
	for (int i = 3; i > 0; i--)
	{
		cout << i;
		Sleep(1000);
		cout << "\b";
	}
	rocket();
	system("cls");
}

void cursorStatus()
{
	typedef void (*TMenuOption)(); // typedef used for define a 'pointer to function' type

	int ItemCount = 4;	//  number of menu items
	int MenuChoice = 1; //  position of the cursor
	char key;			// user input key
	printCage();		//prints the border

	TMenuOption *MenuOption = new TMenuOption[ItemCount]; //array of pointers to functions (dynamic)
	MenuOption[0] = Start;								  //fill the array with the functions
	MenuOption[1] = Instructions;
	MenuOption[2] = About;
	MenuOption[3] = Exit;

	while (1) //this is an infinite loop(this loop will only break if we enter 'exit' option)
	{
		for (int i = 0; i < ItemCount; i++) // Draw the menu
		{
			gotoxy(40, 11 + i);
			MenuChoice == i + 1 ? cout << " -> " : cout << "    "; // if (i+1) == the cursor then '->' will be printed, else "    " will be printed
			cout << MenuItems()[i] << endl;						   // print the name of the menu item
		}														   

		key = getch(); //get the key

		switch (key) //to check the entered key
		{
		case '\r': //if the entered key is 'Enter'
			try
			{
				(*MenuOption[MenuChoice - 1])(); //call the function of the index 'cursor-1' in 
												 //the 'pointer to function' array
			}
			catch (...)
			{
			} // we have to use exception handling here because if we didn't fill that index with a function, a runtime error will appear
			 

			break;
			
			//we can use case 'P' as up arrow and case 'H' as down arrow
		case 'P':						
			MenuChoice++;				//increment the cursor by one
			if (MenuChoice > ItemCount) // if the cursor value is more than the items count, it will return back to the first item
				MenuChoice = 1;			
			break;

		case 'H': 
			MenuChoice--;
			if (MenuChoice < 1)
				MenuChoice = ItemCount;
			break;

	
		} 
	}

	delete MenuOption; //clears the heap
}

string *MenuItems() // returns a pointer to a string,used to print the list of options in line 143
{
	string *item = new string[4];
	item[0] = "START GAME";
	item[1] = "INSTRUCTIONS";
	item[2] = "ABOUT";
	item[3] = "EXIT.";

	return item;
}

void gotoxy(int xpos, int ypos) //to change the console output position
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos;
	scrn.Y = ypos;
	SetConsoleCursorPosition(hOuput, scrn);
}
//First option of the menu bar-START GAME
void Start()
{

	system("cls"); //clear the screen.
	gotoxy(25, 10);
	system("cls");
	system("color 0B");
	cout << "\t--------------------------------------------------------------------------" << endl;
	cout << "\t\t      __ _             _       ___           \n"
			"\t\t     / _| |_ __ _ _ __| |_    / _ \\__ _ _ __ ___   ___ \n"
			"\t\t     \\ \\| __/ _` | '__| __|  / /_\\/ _` | '_ ` _ \\ / _ \\\n"
			"\t\t     _\\ | || (_| | |  | |_  / /_\\| (_| | | | | | |  __/\n"
			"\t\t     \\__/\\__\\__,_|_|   \\__| \\____/\\__,_|_| |_| |_|\\___|\n"
		 << endl;
	cout << "\t--------------------------------------------------------------------------" << endl
		 << endl;
	;
	cout << "\n\n\n\n\n\t\tEnter Player's Name : ";
	getline(cin, playersName);
	system("cls");
	selectlevel();
}

//Third option of the menu bar-ABOUT THE GAME
void About()
{

	system("cls");
	system("color 0E");
	cout << "\n\n\n\t\t--------------------------------------------------------------------------" << endl;
	;
	cout << "\t\t\t\t        _   _                 _\n"
			"\t\t\t\t       /_\\ | |__   ___  _   _| |_ \n"
			"\t\t\t\t      //_\\\\| '_ \\ / _ \\| | | | __|\n"
			"\t\t\t\t     /  _  | |_) | (_) | |_| | |_ \n"
			"\t\t\t\t     \\_/ \\_|_.__/ \\___/ \\__,_|\\__|\n"
		 << endl;
	cout << "\t\t--------------------------------------------------------------------------" << endl
		 << endl;
	;
	cout << "\n\n\n\n \t\t\t <.>The Game was Developed by,\n";
	cout << " \t\t\t\t Teshan Gunasekara    - 19/ENG/024" << endl;
	cout << " \t\t\t\t Navodya Rathnasekara - 19/ENG/070" << endl;
	cout << " \t\t\t\t Surali Pathirana     - 19/ENG/073" << endl;
	cout << " \t\t\t\t Lasanjana Silva      - 19/ENG/099" << endl;

	cout << "\n\n\n\n\n";
	getch();
	system("cls");
	printCage();
}

//Second option of the menu bar-INSTRUCTIONS

void Instructions()
{
	system("cls");
	system("cls");
	system("color 06");
	cout << "\n\n\n\t\t---------------------------------------------------------------------------------" << endl;
	;
	cout << "\t\t\t     _____           _                   _   _\n"
			"\t\t\t     \\_   \\_ __  ___| |_ _ __ _   _  ___| |_(_) ___  _ __  ___ \n"
			"\t\t\t      / /\\| '_ \\/ __| __| '__| | | |/ __| __| |/ _ \\| '_ \\/ __|\n"
			"\t\t\t   /\\/ /_ | | | \\__ | |_| |  | |_| | (__| |_| | (_) | | | \\__ \\\n"
			"\t\t\t   \\____/ |_| |_|___/\\__|_|   \\__,_|\\___|\\__|_|\\___/|_| |_|___/\n"
		 << endl;
	cout << "\t\t---------------------------------------------------------------------------------" << endl
		 << endl
		 << endl;
	;
	cout << "\t\t* The enemy shuttles are represented by  '3' symbols and randomly fire missiles down the screen which \n\t\t  are indicated by + symbols.\n\n";
	cout << "\t\t* Spaceship of the player is represented by X symbol and Use LEFT and RIGHT arrow keys to control your \n\t\t  spaceship.\n\n";
	cout << "\t\t* To double shoot- Press Both LEFT and RIGHT arrow keys at once.\n\n";
	cout << "\t\t* You will receive 3 lives in level 1 and level 2 and 4 lives in level 3.\n\n\n";

	cout << "\t\t---------------------------------------------------------------------------------" << endl;

	getch();
	system("cls");
	printCage();
}

//Fourth option of the menu bar-EXIT THE GAME
void Exit()
{
	system("cls");
	exit(0);
}
void level1()
{
	playeasy();
}
void level2()
{
	playmedium();
}
void level3()
{
	playDifficult();
}
void back()
{
	system("cls");
	cursorStatus();
}
void selectlevel()  //works exactly the same as cursor status function for the main menue
{

	typedef void (*TplayOption)(); // typedef for defining a 'pointer to function' type

	int ItemCount = 4;	// number of menu items
	int playChoice = 1; //  position of the cursor
	char key;			//user input  key 

	printLevel();

	TplayOption *playOption = new TplayOption[ItemCount]; //array of pointers to functions (dynamic)
	playOption[0] = level1;								  //fill the array with the functions
	playOption[1] = level2;
	playOption[2] = level3;
	playOption[3] = back;

	while (1) //infinite loop(this loop will only break if the player enter exit option)
	{
		for (int i = 0; i < ItemCount; i++) // Draw the menu.
		{
			gotoxy(40, 11 + i);
			playChoice == i + 1 ? cout << " -> " : cout << "    "; // if (i+1) == the cursor then '->' will be printed, else "    " will be printed
																   
			cout << playItems()[i] << endl;						   // print the name of the item
		}														   // finish the drawing

		key = getch(); //get the key
		switch (key)   //check the entered key
		{
		case '\r': // if the entered key is 'Enter'
			try
			{
				(*playOption[playChoice - 1])(); // call the function of the index 'cursor-1' in
												 //     the 'pointer to function' array
			}
			catch (...)
			{
			} // we have to use try and catch because if we did'nt fill that index with a function, a runtime error will appear
			 

			break;
			
			//we can use case 'P' as up arrow and case 'H' as down arrow
			 
		case 'P':						
			playChoice++;				//increment the cursor by one.
			if (playChoice > ItemCount) // if the cursor value is more than the items count.
				playChoice = 1;			//then it will return back to the first item.
			break;

		case 'H': 
			playChoice--;
			if (playChoice < 1)
				playChoice = ItemCount;
			break;

	
		}
	}

	delete playOption;//clears the heap
}

string *playItems() //  returns a pointer to a string.
{
	string *item = new string[4];
	item[0] = "LEVEL1";
	item[1] = "LEVEL2";
	item[2] = "LEVEL3";
	item[3] = "BACK";

	return item;
}

void gameOver()
{

	system("color 0c");

	ifstream gameover;
	gameover.open("game over.txt"); //displays an image at the gameover screen
	std::cout << gameover.rdbuf();
	gameover.close();
	gotoxy(1, 1); //sends the cursor up so that the whole image is displayed
	Sleep(3000);
	system("cls");
	exit(0);

	system("cls");
}
void victoryscreen()
{

	system("color 09");
	ifstream victoryscreen;
	victoryscreen.open("winner.txt"); //displays an image at the gameover screen
	std::cout << victoryscreen.rdbuf();
	victoryscreen.close();
	gotoxy(1,1);
	Sleep(3000);
	system("cls");
	exit(0);
}

void playeasy()
{
	system("cls");
	int lives = 3;
	system("color 0A");

	char levelEasy[24][65] =

		{"_______________________________________________________________",
		 "|  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *  |",
		 "|*   * __*___*___*___*___*___*___*___*___*___*___*___*__ *   *|",
		 "|  *  |                                                 |  *  |",
		 "|*   *|              3333             3333              |*   *|",
		 "|  *  |       33333333333             33333333333       |  *  |",
		 "|*   *|         333333333333       333333333333         |*   *|",
		 "|  *  |             33333333 33333 33333333             |  *  |",
		 "|*   *|                 3333 33333 3333                 |*   *|",
		 "|  *  |                 3333 33333 3333                 |  *  |",
		 "|*   *|                      33333                      |*   *|",
		 "|  *  |                      33333                      |  *  |",
		 "|*   *|                                                 |*   *|",
		 "|  *  |                                                 |  *  |",
		 "|*   *|                                                 |*   *|",
		 "|  *  |                                                 |  *  |",
		 "|*   *|                                                 |*   *|",
		 "|  *  |                                                 |  *  |",
		 "|*   *|                                                 |*   *|",
		 "|  *  |                                                 |  *  |",
		 "|*   *|                         X                       |*   *|",
		 "|  *  |_________________________________________________|  *  |",
		 "|*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *|",
		 "|__*___*___*___*___*___*___*___*___*___*___*___*___*___*___*__|"};

	for (int y = 0; y < 24; y++)
	{
		cout << "\t\t" << levelEasy[y] << endl; //Prints the map
	}

	cout << "\n\t\t\t\tGood luck " << playersName << "!!\n";
	cout << "\t\t\t\tGame will start in \n\t\t\t\t\t";
	for (int i = 3; i > 0; i--)
	{
		cout << i;
		Sleep(1000);
		cout << "\b";
	}

	cout << "\n";

	while (endGame == false)
	{
		srand(time(0));
		system("cls");

		for (int y = 0; y < 24; y++)
		{
			cout << "\t\t" << levelEasy[y] << endl; //Prints the map
		}

		cout << "\n\t\t\t\t" << playersName << " is playing!!!\n";
		cout << "\t\t\t\tlives:" << lives << "/" << 3 << endl;
		cout << "\t\t\t\tScore: " << score << endl
			 << endl;

		for (int y = 0; y < 24; y++)
		{
			for (int x = 0; x < 65; x++)
			{
				switch (levelEasy[y][x])
				{

				case 'X':
				{
					if (GetAsyncKeyState(VK_LEFT) != 0) //moves the player to the left
					{
						int nX = x - 1;
						switch (levelEasy[y][nX])
						{

						case ' ':
							levelEasy[y][x] = ' '; //makes the old position of the player empty
							x--;
							levelEasy[y][nX] = 'X';		//new position of the player
							levelEasy[y - 1][nX] = '^'; //generating bullets
							break;
						}
					}
					if (GetAsyncKeyState(VK_RIGHT) != 0) //moves the player to the right
					{
						int nX = x + 1;
						switch (levelEasy[y][nX])
						{
						case ' ':
							levelEasy[y][x] = ' '; //makes the old position of the player empty
							x++;
							levelEasy[y][nX] = 'X';		//new position of the player
							levelEasy[y - 1][nX] = '^'; //generating bullets
							break;
						}
					}

					break;
				}
				case '^':
				{

					levelEasy[y][x] = ' ';
					y--;

					if (levelEasy[y][x] != '|' && levelEasy[y][x] != '_' && levelEasy[y][x] != '*' && levelEasy[y][x] != '3')
					{
						levelEasy[y][x] = '^';
					}
					else if (levelEasy[y][x] == '3')
					{
						levelEasy[y][x] = ' ';
						score += 20; //when a alien is hit, the score increases by 20
					}
					break;
				}
				case '3':
				{

					if (rand() % 20 + 1 == 5 && levelEasy[y + 1][x] != '3') //generating bombs from random alien ships
					{
						y++;
						levelEasy[y][x] = '+'; //  *-alien bombs
					}

					break;
				}
				case '+':
				{
					levelEasy[y][x] = ' ';
					y++;
					if (levelEasy[y][x] != '|' && levelEasy[y][x] != '_' && levelEasy[y][x] != 'X' && levelEasy[y][x] != '3')
					{
						levelEasy[y][x] = '+';
					}
					else if (levelEasy[y][x] == 'X')
					{
						Beep(256, 500); //rings a hardware sound of 256 Hz for 500ms
						lives -= 1;		//reducing lives when the player is hit
						if (lives <= 0)
						{
							endGame = true;
							system("cls");
							gameOver(); //calls the function to display gameover
						}
					}

					break;
				}
				}
				int count = 0; //checking if the player has won
				for (int checkr = 3; checkr <= 11; checkr++)
				{
					for (int checkc = 7; checkc <= 56; checkc++)
					{
						if (levelEasy[checkr][checkc] == ' ')
							count++;
					}
				}
				if (count == 441) //if count is = to 108,no alienships are present and the player wins
				{
					endGame = true; //end of easylevel
					system("cls");
					levelUp(); //function to level the player up
					cout << "\n\n\n\n\n\n\t\t\tCongratulations " << playersName << "!"
						 << "\n\n"
						 << "\t\t\tYou have Won level 1!!!"
						 << "\n\n";
					cout << "\t\t\tYour Score is: " << score << endl;
					Sleep(1000); //Delays the screen
					cout << "\n\n\t\t\t";
					system("pause");

					playmedium(); //calling the function declared to medium level
				}
			}
		}
	}
}

void playmedium()
{
	int lives = 3;

	char levelMedium[25][65] =

		{"_______________________________________________________________",
		 "|  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *  |",
		 "|*   * __*___*___*___*___*___*___*___*___*___*___*___*__ *   *|",
		 "|  *  |                                                 |  *  |",
		 "|*   *|    33333        3333333333333333        33333   |*   *|",
		 "|  *  |     333333333  333333333333333333  333333333    |  *  |",
		 "|*   *|       3333333333333          3333333333333      |*   *|",
		 "|  *  |         33333333333333333333333333333333        |  *  |",
		 "|*   *|           3333333333333333333333333333          |*   *|",
		 "|  *  |             333333333333333333333333            |  *  |",
		 "|*   *|               33333333333333333333              |*   *|",
		 "|  *  |                 3333333333333333                |  *  |",
		 "|*   *|                   333333333333                  |*   *|",
		 "|  *  |                     33333333                    |  *  |",
		 "|*   *|                       3333                      |*   *|",
		 "|  *  |                                                 |  *  |",
		 "|*   *|                                                 |*   *|",
		 "|*   *|                                                 |*   *|",
		 "|  *  |                                                 |  *  |",
		 "|*   *|                         X                       |*   *|",
		 "|  *  |_________________________________________________|  *  |",
		 "|*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *|",
		 "|__*___*___*___*___*___*___*___*___*___*___*___*___*___*___*__|"};

	system("cls");
	system("color 0B");
	for (int x = 0; x < 25; x++)
	{
		cout << "\t\t" << levelMedium[x] << endl;
	}
	cout << "\n\t\t\t\tGood Luck " << playersName << endl;
	cout << "\t\t\t\tGame will start in\n\t\t\t\t\t" << endl;
	cout << "\t\t\t\t\t";
	for (int i = 3; i > 0; i--)
	{

		cout << i;
		Sleep(1000);
		cout << "\b";
	}

	while (endGame2 == false)
	{
		srand(time(0));
		system("cls");

		for (int y = 0; y < 25; y++)
		{
			cout << "\t\t" << levelMedium[y] << endl;
		}
		cout << "\t\t\t\t" << playersName << " is playing!!!\n\n";
		cout << "\t\t\t\tlives:" << lives << "/" << 3 << endl;
		cout << "\t\t\t\tscore: " << score << endl;

		for (int y = 0; y < 25; y++)
		{
			for (int x = 0; x < 65; x++)
			{
				switch (levelMedium[y][x])
				{

				case 'X':
				{
					if (GetAsyncKeyState(VK_LEFT) != 0)
					{
						int nX = x - 1;
						switch (levelMedium[y][nX])
						{
						case ' ':
							levelMedium[y][x] = ' ';
							x--;
							levelMedium[y][nX] = 'X';
							levelMedium[y - 1][nX] = '^';
							break;
						}
					}
					if (GetAsyncKeyState(VK_RIGHT) != 0)
					{
						int nX = x + 1;
						switch (levelMedium[y][nX])
						{
						case ' ':
							levelMedium[y][x] = ' ';
							x++;
							levelMedium[y][nX] = 'X';
							levelMedium[y - 1][nX] = '^';
							break;
						}
					}

					break;
				}

				case '^':
				{

					levelMedium[y][x] = ' '; //makes the previous position empty
					y--;

					if (levelMedium[y][x] != '|' && levelMedium[y][x] != '_' && levelMedium[y][x] != '3')
					{
						levelMedium[y][x] = '^';
					}
					else if (levelMedium[y][x] == '3')
					{
						levelMedium[y][x] = ' '; //if the bullet hits a alienship,sore increases by 50
						score += 50;
					}
					break;
				}
				case '3':
				{

					if (rand() % 20 + 1 == 5 && levelMedium[y + 1][x] != '3') //generating bombs from random alien ships
					{
						y++;
						levelMedium[y][x] = '+';
					}

					break;
				}

				case '+':
				{
					levelMedium[y][x] = ' '; //makes the previous position empty
					y++;
					if (levelMedium[y][x] != '|' && levelMedium[y][x] != '_' && levelMedium[y][x] != 'X' && levelMedium[y][x] != '3')
					{
						levelMedium[y][x] = '+';
					}
					else if (levelMedium[y][x] == 'X') //bomb hits the player
					{
						Beep(500, 500); //makes a hardware sound of 500Hz for 500ms
						lives -= 1;
						if (lives <= 0) //when all the 3 lives are over
						{
							endGame = true; //player looses
							system("cls");
							gameOver();
						}
					}
					break;
				}
				}
				int count = 0;
				for (int checkr = 3; checkr <= 14; checkr++)
				{
					for (int checkc = 7; checkc <= 56; checkc++)
					{
						if (levelMedium[checkr][checkc] == ' ')
							count++;
					}
				}
				if (count == 588)
				{
					endGame2 = true; //end of level 2
					system("cls");
					levelUp(); //function to level the player up
					cout << "\n\n\n\n\n\n\t\t\tCongratulations " << playersName << "!"
						 << "\n\n"
						 << "\t\t\tYou have Won level 2!!!" << endl;
					cout << "\n\t\t\tYour Score is: " << score << endl;
					cout << "\n\n\t\t\t";
					system("pause");

					playDifficult(); //calling the function of difficult level
				}
			}
		}
		if (lives <= 0)
		{
			endGame2 = true; //when all the lives are over game is over
		}
	}
}
void playDifficult()
{
	int lives = 4;
	char levelHard[25][70] =
		{"_______________________________________________________________",
		 "|  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *  |",
		 "|*   * __*___*___*___*___*___*___*___*___*___*___*___*__ *   *|",
		 "|  *  |                                                 |  *  |",
		 "|*   *|                                                 |*   *|",
		 "|  *  |  3333333333333333             3333333333333333  |  *  |",
		 "|*   *|   333       33333             33333       333   |*   *|",
		 "|  *  |    333333333333333 333333333 333333333333333    |  *  |",
		 "|*   *|             333333 33     33 333333             |*   *|",
		 "|  *  |       333333333333 333   333 333333333333       |  *  |",
		 "|*   *|        33333        3333333        33333        |*   *|",
		 "|  *  |         333          33333          333         |  *  |",
		 "|*   *|          3            333            3          |*   *|",
		 "|  *  |                                                 |  *  |",
		 "|*   *|                                                 |*   *|",
		 "|  *  |                                                 |  *  |",
		 "|*   *|                                                 |*   *|",
		 "|  *  |                                                 |  *  |",
		 "|*   *|                                                 |*   *|",
		 "|  *  |                                                 |  *  |",
		 "|*   *|                        X                        |*   *|",
		 "|  *  |_________________________________________________|  *  |",
		 "|*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *|",
		 "|__*___*___*___*___*___*___*___*___*___*___*___*___*___*___*__|"};

	system("cls");
	system("color 0e");
	for (int y = 0; y < 25; y++)
		cout << "\t\t" << levelHard[y] << endl;

	cout << "\n\t\t\t\tGood Luck " << playersName << endl;
	cout << "\t\t\t\tGame will start in \n\t\t\t\t\t";
	for (int i = 3; i > 0; i--)
	{
		cout << i;
		Sleep(1000);
		cout << "\b";
	}

	while (gameRunning == true)
	{
		system("cls");
		srand(time(0));
		for (int y = 0; y < 25; y++)
		{
			cout << "\t\t" << levelHard[y] << endl;
		}
		cout << "\t\t\t\t" << playersName << " is playing!!!\n\n";
		cout << "\t\t\t\tlives: " << lives << "/" << 4 << endl;
		cout << "\t\t\t\tScore: " << score << endl;
		for (int y = 0; y < 25; y++)
		{
			for (int x = 0; x < 65; x++)
			{

				switch (levelHard[y][x])
				{
				case 'X':
				{
					if (GetAsyncKeyState(VK_LEFT) != 0)
					{
						if (levelHard[y][x - 1] == ' ')
						{
							levelHard[y][x] = ' ';
							x--;
							levelHard[y][x] = 'X';
							levelHard[y - 1][x] = '^'; //bullets are automatically generated
						}
					}
					else if (GetAsyncKeyState(VK_RIGHT) != 0)
					{
						if (levelHard[y][x + 1] == ' ')
						{
							levelHard[y][x] = ' ';
							x++;
							levelHard[y][x] = 'X';
							levelHard[y - 1][x] = '^';
						}
					};
					break;
				}
				case '^':
				{
					levelHard[y][x] = ' ';
					y--;
					if (levelHard[y][x] != '|' && levelHard[y][x] != '_' && levelHard[y][x] != '3')
					{
						levelHard[y][x] = '^';
					}
					else if (levelHard[y][x] == '3')
					{
						levelHard[y][x] = ' ';
						score += 50; //when a bullet hits the enemy player's score is increased by 50
					};
					break;
				}

				case '3':
				{
					int randomNumber = rand() % 20;
					if (randomNumber == 7 && levelHard[y + 1][x] != '3')
					{
						levelHard[y + 1][x] = '+';
					}
					else if (randomNumber < 5)
					{
						if (y % 2 == 0)
						{
							if (levelHard[y][x - 1] != '|' && levelHard[y][x - 1] != '3')
							{
								levelHard[y][x] = ' ';
								levelHard[y][x - 1] = '3';
							}
							else if (levelHard[y][x - 1] == '|')
							{
								levelHard[y][x] = ' ';
								levelHard[y + 1][x + 1] = '3';
							}
						}
						else
						{
							if (levelHard[y][x + 1] != '|' && levelHard[y][x + 1] != '3')
							{
								levelHard[y][x] = ' ';
								levelHard[y][x + 1] = '3';
							}
							else if (levelHard[y][x + 1] == '|')
							{
								levelHard[y][x] = ' ';
								levelHard[y + 1][x - 1] = '3';
							}
						}
					};
					break;
				}
				case '+':
				{
					levelHard[y][x] = ' ';
					y++;
					if (levelHard[y][x] != '|' && levelHard[y][x] != '_' && levelHard[y][x] != 'X' && levelHard[y][x] != '3' || levelHard[y][x] == '^')
					{
						levelHard[y][x] = '+';
					}
					else if (levelHard[y][x] == 'X')
					{
						Beep(500, 500);
						lives -= 1;
					};
					break;
				}
				}
				int count = 0;  //to ckeck if all the alien ships are defeated
				for (int row = 3; row <= 20; row++)
				{
					for (int col = 7; col <= 56; col++)
					{
						if (levelHard[row][col] == ' ')
							count++;
					}
				}
				if (count == 881) 
				{
					gameRunning = false;
					system("cls");
					victoryscreen();
				}
				if (lives == 0)
				{
					gameRunning = false;
					system("cls");
					gameOver();
				}
			}
		}
	}
}

void levelUp()
{

	system("color 0D");
	ifstream levelup;
	levelup.open("levelup2.txt"); //displays an image at the welcome screen
	std::cout << levelup.rdbuf();
	levelup.close();
	Sleep(1000);
	system("cls");
}

void printCage()
{
	system("color 03");
	cout << "\t\t .--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--.\n"
			"\t\t/ .. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\\n"
			"\t\t\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/ /\n"
			"\t\t \\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\n"
			"\t\t / /\\/ /`' /`' /`' /`' /`' /`' /`' /`' /`' /`' /`' /`' /`' /\\/ /\\\n"
			"\t\t/ /\\ \\/`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'\\ \\/\\ \\\n"
			"\t\t\\ \\/\\ \\                                                    /\\ \\/ /\n"
			"\t\t \\/ /\\ \\                     MAIN MENU                    / /\\/ /\n"
			"\t\t / /\\/ /                    -----------                   \\ \\/ /\\\n"
			"\t\t/ /\\ \\/                                                    \\ \\/\\ \\\n"
			"\t\t\\ \\/\\ \\                                                    /\\ \\/ /\n"
			"\t\t \\/ /\\ \\                                                  / /\\/ /\n"
			"\t\t / /\\/ /                                                  \\ \\/ /\\\n"
			"\t\t/ /\\ \\/                                                    \\ \\/\\ \\\n"
			"\t\t\\ \\/\\ \\                                                    /\\ \\/ /\n"
			"\t\t \\/ /\\ \\                                                  / /\\/ /\n"
			"\t\t / /\\/ /                                                  \\ \\/ /\\\n"
			"\t\t/ /\\ \\/                                                    \\ \\/\\ \\\n"
			"\t\t\\ \\/\\ \\                                                    /\\ \\/ /\n"
			"\t\t \\/ /\\ \\                                                  / /\\/ /\n"
			"\t\t / /\\/ /                                                  \\ \\/ /\\\n"
			"\t\t/ /\\ \\/                                                    \\ \\/\\ \\\n"
			"\t\t\\ \\/\\ \\.--..--..--..--..--..--..--..--..--..--..--..--..--./\\ \\/ /\n"
			"\t\t \\/ /\\/ ../ ../ ../ ../ ../ ../ ../ ../ ../ ../ ../ ../ ../ /\\/ /\n"
			"\t\t / /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\\n"
			"\t\t/ /\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\\n"
			"\t\t\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `' /\n"
			"\t\t `--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'";
}
void printLevel()
{
	system("color 0E");
	cout << "\t\t .--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--.\n"
			"\t\t/ .. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\\n"
			"\t\t\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/ /\n"
			"\t\t \\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\n"
			"\t\t / /\\/ /`' /`' /`' /`' /`' /`' /`' /`' /`' /`' /`' /`' /`' /\\/ /\\\n"
			"\t\t/ /\\ \\/`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'\\ \\/\\ \\\n"
			"\t\t\\ \\/\\ \\                                                    /\\ \\/ /\n"
			"\t\t \\/ /\\ \\                 SELECT THE LEVEL                 / /\\/ /\n"
			"\t\t / /\\/ /                   -----------                     \\ \\/ /\\\n"
			"\t\t/ /\\ \\/                                                    \\ \\/\\ \\\n"
			"\t\t\\ \\/\\ \\                                                    /\\ \\/ /\n"
			"\t\t \\/ /\\ \\                                                  / /\\/ /\n"
			"\t\t / /\\/ /                                                  \\ \\/ /\\\n"
			"\t\t/ /\\ \\/                                                    \\ \\/\\ \\\n"
			"\t\t\\ \\/\\ \\                                                    /\\ \\/ /\n"
			"\t\t \\/ /\\ \\                                                  / /\\/ /\n"
			"\t\t / /\\/ /                                                  \\ \\/ /\\\n"
			"\t\t/ /\\ \\/                                                    \\ \\/\\ \\\n"
			"\t\t\\ \\/\\ \\                                                    /\\ \\/ /\n"
			"\t\t \\/ /\\ \\                                                  / /\\/ /\n"
			"\t\t / /\\/ /                                                  \\ \\/ /\\\n"
			"\t\t/ /\\ \\/                                                    \\ \\/\\ \\\n"
			"\t\t\\ \\/\\ \\.--..--..--..--..--..--..--..--..--..--..--..--..--./\\ \\/ /\n"
			"\t\t \\/ /\\/ ../ ../ ../ ../ ../ ../ ../ ../ ../ ../ ../ ../ ../ /\\/ /\n"
			"\t\t / /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\\n"
			"\t\t/ /\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\\n"
			"\t\t\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `' /\n"
			"\t\t `--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'";
}

