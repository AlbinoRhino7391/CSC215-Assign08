/*
* Creator Information:
* Name: Eric Phelps
* Professor: Juan Rodriguez
* Class: CSC 215 - C++ I
* Assignment 08 - Functions Through Interactive Simulation
* Assignment Due Date: March 6, 2022
*/

/*
* Tasks:
* Create a new Empty C++ project.
*Your program must do something and be an interactive fiction game or simulation, it must not just demo functions.
*Add at least one function that takes a string or an int.
*Add at least one function that returns a string or an int.
*Add at least 5 functions overall in addition to the main function.
*Your main function should control all the other functions.
*/

// Included Libraries, <> is for internal libs, "" is for external libs that need to be downloaded.
#include <iostream>
#include <string>

// using namespace std, is to tell the program that i am using namespaces from standard C, and will keep me from having to type std for every line that uses standard syntax such as cout and cin.
using namespace std;

// Declaring variables, that can be used within the main function.
string playerRank;
int CurrHealth{50};

// declare the functions to be used.
void DisplayIntro();
string GetUserName();
void WelcomeMessage(string userName);
void DisplayRank();
void DisplayCurrHealth();
int InitialExplore();
int FindFood();
int FindExit();

//Main function, this is the program itself.
int main()
{

	//game logic begins

	//assigning a value to the global variable.
	playerRank = "Adventurer";
	//Calling the function to display intro
	DisplayIntro();
	//Create local varible to hold username
	string localMainUserName;
	//pass through data to assign local variable to function GetUsername.
	localMainUserName = GetUserName();
	//assgins a copy of the local variable to the Welcome message function.
	WelcomeMessage(localMainUserName);
	//Display health before entering scenario
	DisplayCurrHealth();
	system("pause");
	// Start the first player descision
	int localResultScore = InitialExplore();
	CurrHealth = CurrHealth + localResultScore;
	//Display health after scenario
	DisplayCurrHealth();
	system("pause");
	// Start second player descision
	localResultScore = FindFood();
	CurrHealth = CurrHealth + localResultScore;
	DisplayCurrHealth();
	system("pause");
	// Start Final player descision.
	localResultScore = FindExit();
	CurrHealth = CurrHealth + localResultScore;
	DisplayCurrHealth();
	//output to let the user know the sim is over.
	cout << "\nYou have finished this simulation ";
	system("pause");


	//Ends the main function, which also ends our program.
	return 0;
}

// What do the functions do?

//What do you do when you first wake up?
int InitialExplore()
{
	// This will be the number of health points higher or lower to add/sub to health.
	int pointsResults = 0;
	cout << "\n\nYou have just awoke, dazed and woozy, to a new world, you have no idea how you got here. ";
	cout << "\nYou look around and notice you are in some sort of cave system.\n\n";
	cout << "\nYou have fully come to your senses and take in your surroundings better.\n";
	cout << "\nalthough wary, you know you must find a way out, but that can take time,\n";
	cout << "\nfirst things first, you need to start exploring to hopefully find a way out.\n";
	cout << "\nTime to start exploring, your current tunnel travels East to West.\n";
	cout << "\nWhich way would you like to go? (E or W) ";
	string localPlayerChoice;
	getline(cin, localPlayerChoice);
	//calculate points based on decision
	if (localPlayerChoice == "W" || localPlayerChoice == "w" || localPlayerChoice == "west" || localPlayerChoice == "West")
	{
		cout << "\nYou are ecstatic with you discovery of an underground oasis to replinish your health,you gain 25 hp.\n";
		pointsResults = 25;
		// return +25 of currhealth;
	}
	else if (localPlayerChoice == "E" || localPlayerChoice == "e" || localPlayerChoice == "East" || localPlayerChoice == "east")
	{
		cout << "\nYou have chosen terribly, You have run into a horde of Goblins and need to run away, but not without your fair share of damage, you lose 25 hp.\n";
		pointsResults = -25;
		// return -25 of currhealth;
	}
	else
	{
		cout << "\nYou are not making clear choices and are walking in circles causing you to lose 25 hp.\n";
		pointsResults = -25;
		// return -25;
	}
	return pointsResults;
}
//Find food scenario requires player to make the correct choice to find a food source.
int FindFood()
{
	// sets the var to add or subtract health based on descision.
	int pointsResults = 0;
	cout << "\n\nAfter exploring for awhile, you notice youre are feeling weak and hungry.\n";
	cout << "\nYou realize you havent eaten anything since finding yourself in this strange world.\n";
	cout << "\nYou have come up to a split in your current path.\n";
	cout << "\nWhich path should you choose, Left or Right?\n\n";
	cout << "\nWhich way would you like to go? (L or R) ";
	string localPlayerChoice;
	getline(cin, localPlayerChoice);
	//calculate points based on decision
	if (localPlayerChoice == "L" || localPlayerChoice == "l" || localPlayerChoice == "left" || localPlayerChoice == "Left")
	{
		cout << "\nYou immediately regret your descision as you have stumbled into a bandit lair and get attacked, but try to venture forth.\n";
		pointsResults = -25;
		// return -25;
	}
	else if (localPlayerChoice == "R" || localPlayerChoice == "r" || localPlayerChoice == "Right" || localPlayerChoice == "right")
	{
		cout << "\nHappily, you discover some glowing berries growing in the cracks of the dungeon walls.\n";
		pointsResults = 25;
		// return 25;
	}
	else
	{
		cout << "\nYou are not making clear choices and are walking in circles causeing you to lose 25 hp.\n";
		pointsResults = -25;
		// return -25;
	}
	return pointsResults;
}
//Find Exit.
int FindExit()
{
	// sets the var to add or subtract health based on descision.
	int pointsResults = 0;
	cout << "\n\nYou feel that you are getting close to the verge of giving up, as you come to another possibly fatal descision.\n ";
	cout << "\nYou find an open corridor, with a random door and a ladder. \n";
	cout << "\none last coin toss you think to yourself,\n";
	cout << "\nWhat is your choice traveller?.\n";
	cout << "\nDo you take the ladder or the door?\n";
	string localPlayerChoice;
	getline(cin, localPlayerChoice);
	//calculate points based on decision
	if (localPlayerChoice == "Door" || localPlayerChoice == "door")
	{
		cout << "\nYou have made a grave mistake, and fall into a pitfall trap.\n";
		pointsResults = -100;
		// return -100, immediate death;
	}
	else if (localPlayerChoice == "Ladder" || localPlayerChoice == "ladder")
	{
		cout << "\nCongratulations, you have finally found the exit.\n";
		pointsResults = 25;
		// return 25;
	}
	else
	{
		cout << "\nYou are not making clear choices and are wandering you to lose 25 hp.\n";
		pointsResults = -25;
		// return -25;
	}
	return pointsResults;
}
//Function to display the intro description of the narrative.
void DisplayIntro()
{
	cout << "\n\n\n\t*** Dungeon Explorer ***\n\n";
	cout << "\n In this sim you are a Traveller who has found yourself within a dungeon in a strange new world.\n";
	DisplayRank();
	return;
}

//This block is to collect string data from the user.
string GetUserName()
{
	cout << "\n What is your name, Traveller?";
	string userName;
	getline(cin, userName);
	return userName;
}
// simple function to display the welcome message.
void WelcomeMessage(string localUserName)
{
	cout << "\n Welcome Adventurer " + localUserName;
}
// simple funciton to display the starting rank of the player.
void DisplayRank()
{
	cout << "\n Youre new to this world, you must start as a" + playerRank << endl;
}
// Displays players current health, will be repeated after every descision.
void DisplayCurrHealth()
{
	bool Death = (CurrHealth <= 0);

	if (Death == true)
	{
		cout << "\n\n\nYou have died on your journey.\n\n\n";
		exit(0);
	}
	else
	{
		cout << "\n Your Current Player Health is " << CurrHealth << endl;
		return;
	}

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
