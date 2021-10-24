#include <conio.h>
#include <iostream>
#include <random>
using namespace std;
const int MAXLENGTH = 80;
const int MAX_TRIES = 5;
const int MAXROW = 7;

int letterFill(char, char[], char[]);
void initUnknown(char[], char[]);

int main()
{
	char unknown[MAXLENGTH];
	char letter;
	int num_of_wrong_guesses = 0;
	char word[MAXLENGTH];
	char words[][MAXLENGTH] =
	{
		"iran",
		"pakistan",
		"nepal",
		"malaysia",
		"iraq",
		"afghanistan",
		"india",
		"ethiopia",
		"oman",
		"indonesia"
	};
	int n;
	int random;
	int randomize();
	n = random;
	strcpy(word, words[n]);


	initUnknown(word, unknown);

	std::cout << "\n\nWelcome to hangman...Guess a country Name";
	std::cout << "\n\nEach letter is represented by a star.";
	std::cout << "\n\nYou have to type only one letter in one try";
	std::cout << "\n\nYou have " << MAX_TRIES << " tries to try and guess the word.";
	std::cout << "\n~~~~~~~~~~~~~~~~~~";


	while (num_of_wrong_guesses < MAX_TRIES)
	{
		std::cout << "\n\n" << unknown;
		std::cout << "\n\nGuess a letter: ";
		std::cin >> letter;

		if (letterFill(letter, word, unknown) == 0)
		{
			std::cout << '\n' << "Whoops! That letter isn't in there!" << '\n';
			num_of_wrong_guesses++;
		}
		else
		{
			std::cout << '\n' << "You found a letter! Isn't that exciting!" << '\n';
		}

		std::cout << "You have " << MAX_TRIES - num_of_wrong_guesses;
		std::cout << " guesses left." << '\n';
		// Check if they guessed the word.
		if (strcmp(word, unknown) == 0)
		{
			std::cout << word << '\n';
			std::cout << "Yeah! You got it!";
			break;
		}

	}
	if (num_of_wrong_guesses == MAX_TRIES)
	{
		std::cout << "\nSorry, you lose...you've been hanged." << '\n';
		std::cout << "The word was : " << word << '\n';
	}
	_getch();
	return 0;
}


int letterFill(char guess, char secretword[], char guessword[])
{
	int i;
	int matches = 0;
	for (i = 0; secretword[i] != '\0'; i++)
	{

		if (guess == guessword[i])
			return 0;

		if (guess == secretword[i])
		{
			guessword[i] = guess;
			matches++;
		}
	}
	return matches;
}


void initUnknown(char word[], char unknown[])
{
	int i;
	int length = strlen(word);
	for (i = 0; i < length; i++)
		unknown[i] = '*';
	unknown[i] = '\0';
}
