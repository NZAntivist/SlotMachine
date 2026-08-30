/***********************************************************************
Bachelor of Information Technology
Media Design School at Strayer
Auckland
New Zealand
(c) [Year] Media Design School

File Name : main.cpp
Description : Main entry point for the Slot Machine game.
Author : Sophie Jennings
Mail : sophie.jennings@mds.ac.nz
**************************************************************************/

#define NOMINMAX
#include <iostream>
#include <Windows.h>
#include <array>

//Constants
enum EColour
{
	COLOUR_WHITE_ON_BLACK = 0, // White on Black.
	COLOUR_RED_ON_BLACK = 1, // Red on Black.
	COLOUR_GREEN_ON_BLACK = 2, // Green on Black.
	COLOUR_PURPLE_ON_BLACK = 3, // Purple on Black.
	COLOUR_YELLOW_ON_BLACK = 4, // Yellow on Black.
	COLOUR_PINK_ON_LIGHTBLUE = 5, // Pink on Light Blue.
	COLOUR_PURPLE_ON_ORANGE = 6, // Purple on Orange.
	COLOUR_ORANGE_ON_BLACK = 7, // Orange on Black.
	COLOUR_BLUE_ON_BLACK = 8, // Blue on Black.
	COLOUR_CYAN_ON_BLUE = 9, // Cyan on Blue.
	COLOUR_LIGHTYELLOW_ON_BLACK = 10, // Light Yellow on Black.
	COLOUR_LIGHTYELLOW_ON_PURPLE = 11, // Light Yellow on Purple.
};

const int SCREENWIDTH = 80;
const int SCREENHEIGHT = 24;

// Function Prototypes.
void clearScreen();
void setRgb(EColour colour);
std::array<int, 3> spinSlots();
EColour getColourFromSlot(int slotValue);

int main() {

	setRgb(COLOUR_PURPLE_ON_BLACK);
	std::cout << "****************************************" << std::endl << std::endl;
	std::cout << "    Welcome to Sophie's Slot Casino!    " << std::endl << std::endl;
	std::cout << "****************************************" << std::endl << std::endl;

	std::cout << "Press Enter to start the game..." << std::endl;
	std::cin.get();

	int playerChips = 2000; // Starting chips for the player.
	int menuSelection = 0;
	bool hasUsedCheatCode = false; // Track if the cheat code has been used.
	srand(static_cast<unsigned int>(time(0))); // Seed the random number generator.
	
	while (menuSelection != 3) {
		setRgb(COLOUR_YELLOW_ON_BLACK);
		std::cout << "Main Menu" << std::endl << std::endl;

		setRgb(COLOUR_GREEN_ON_BLACK);
		std::cout << "You have " << playerChips << " chips." << std::endl << std::endl;

		setRgb(COLOUR_WHITE_ON_BLACK);
		std::cout << "1) Play Game" << std::endl << std::endl;
		std::cout << "2) Credits" << std::endl << std::endl;
		std::cout << "3) Quit Game" << std::endl << std::endl;
		std::cout << "4) Gambling Helpline" << std::endl << std::endl;

		std::cin >> menuSelection;

		switch (menuSelection)
		{
		case 1:
			// Play Game
		{
			int playerBet = 0;
			while (true) {
				std::cout << std::endl << "Enter your bet: ";
				std::cin >> playerBet;
				if (std::cin.fail()) {
					std::cin.clear(); // Clear the error flag.
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input.
					std::cout << "That's not a number silly, try again." << std::endl;
					continue;
				}
				else if (playerBet > playerChips) {
					std::cout << "You cannot bet more chips than you have!" << std::endl;
				}
				else if (playerBet <= 0) {
					std::cout << "You must bet a positive amount of chips!" << std::endl;
				}
				else {
					playerChips -= playerBet; // Deduct the bet from the player's chips.
					// Call the slot machine function to get the results.
					const std::array<int, 3> slots = spinSlots();
					const int slot1 = slots[0];
					const int slot2 = slots[1];
					const int slot3 = slots[2];
					std::cout << std::endl << "Spinning..." << std::endl << std::endl;
					Sleep(1000); // Wait for 1 second to simulate spinning.
					std::cout << "Results: " << std::endl;
					std::cout << "-------------" << std::endl;
					std::cout << "| ";
					setRgb(getColourFromSlot(slot1));
					std::cout << slot1;
					setRgb(COLOUR_WHITE_ON_BLACK);
					std::cout << " | ";
					setRgb(getColourFromSlot(slot2));
					std::cout << slot2;
					setRgb(COLOUR_WHITE_ON_BLACK);
					std::cout << " | ";
					setRgb(getColourFromSlot(slot3));
					std::cout << slot3;
					setRgb(COLOUR_WHITE_ON_BLACK);
					std::cout << " |" << std::endl; 
					std::cout << "-------------" << std::endl;
					Sleep(500); // Wait for 0.5 seconds before showing the result.
					if (slot1 == slot2 && slot2 == slot3 && slot1 == 7) { // Jackpot condition: all slots are 7.
						int winnings = playerBet * 10; // Player wins 10 times their bet.
						playerChips += winnings;
						setRgb(COLOUR_RED_ON_BLACK);
						std::cout << "C";
						setRgb(COLOUR_YELLOW_ON_BLACK);
						std::cout << "O";
						setRgb(COLOUR_LIGHTYELLOW_ON_BLACK);
						std::cout << "N";
						setRgb(COLOUR_GREEN_ON_BLACK);
						std::cout << "G";
						setRgb(COLOUR_BLUE_ON_BLACK);
						std::cout << "R";
						setRgb(COLOUR_PURPLE_ON_BLACK);
						std::cout << "A";
						setRgb(COLOUR_RED_ON_BLACK);
						std::cout << "T";
						setRgb(COLOUR_ORANGE_ON_BLACK);
						std::cout << "U";
						setRgb(COLOUR_YELLOW_ON_BLACK);
						std::cout << "L";
						setRgb(COLOUR_GREEN_ON_BLACK);
						std::cout << "A";
						setRgb(COLOUR_BLUE_ON_BLACK);
						std::cout << "T";
						setRgb(COLOUR_PURPLE_ON_BLACK);
						std::cout << "I";
						setRgb(COLOUR_RED_ON_BLACK);
						std::cout << "O";
						setRgb(COLOUR_ORANGE_ON_BLACK);
						std::cout << "N";
						setRgb(COLOUR_YELLOW_ON_BLACK);
						std::cout << "S";
						setRgb(COLOUR_ORANGE_ON_BLACK);
						std::cout << "!" << std::endl;
						setRgb(COLOUR_GREEN_ON_BLACK);
						std::cout << "JACKPOT WIN" << std::endl;
						std::cout << "You won " << winnings << " chips!" << std::endl << std::endl;

						std::cout << "Press Enter to return to the main menu." << std::endl;
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						std::cin.get();

						clearScreen();
						break;
					}
					else if (slot1 == slot2 && slot2 == slot3) { // All three slots match.
						int winnings = playerBet * 5; // Player wins 5 times their bet.
						playerChips += winnings;
						setRgb(COLOUR_GREEN_ON_BLACK);
						std::cout << "Congratulations!" << std::endl;
						std::cout << "SUPER WIN" << std::endl;
						std::cout << "You won " << winnings << " chips!" << std::endl << std::endl;

						std::cout << "Press Enter to return to the main menu." << std::endl;
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						std::cin.get();

						clearScreen();
						break;
					}
					else if (slot1 == slot2 || slot2 == slot3 || slot1 == slot3) { // Any two slots match.
						int winnings = playerBet * 2; // Player wins 2 times their bet.
						playerChips += winnings;
						setRgb(COLOUR_GREEN_ON_BLACK);
						std::cout << "Congratulations! You won " << winnings << " chips!" << std::endl << std::endl;

						std::cout << "Press Enter to return to the main menu." << std::endl;
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						std::cin.get();

						clearScreen();
						break;
					}
					else { // No slots match.
						setRgb(COLOUR_RED_ON_BLACK);
						std::cout << "Sorry, you didn't win this time. Better luck next time!" << std::endl << std::endl;

						std::cout << "Press Enter to return to the main menu." << std::endl;
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						std::cin.get();

						clearScreen();
						break;
					}
				}
			}
		}
				break;
			case 2:
				// Credits
				std::cout << std::endl << "Credits:" << std::endl << std::endl;

				std::cout << "Lead Developer: ";
				setRgb(COLOUR_PINK_ON_LIGHTBLUE);
				std::cout << "Sophie Jennings";
				setRgb(COLOUR_WHITE_ON_BLACK);
				std::cout << std::endl << std::endl;

				std::cout << "Graphics Designer: ";
				setRgb(COLOUR_PINK_ON_LIGHTBLUE);
				std::cout << "Sophie Jennings";
				setRgb(COLOUR_WHITE_ON_BLACK);
				std::cout << std::endl << std::endl;

				std::cout << "Error Handling: ";
				setRgb(COLOUR_PINK_ON_LIGHTBLUE);
				std::cout << "Sophie Jennings";
				setRgb(COLOUR_WHITE_ON_BLACK);
				std::cout << std::endl << std::endl;

				std::cout << "Testing: ";
				setRgb(COLOUR_PURPLE_ON_ORANGE);
				std::cout << "Rebecca Gibson";
				setRgb(COLOUR_WHITE_ON_BLACK);
				std::cout << std::endl << std::endl;

				std::cout << "Lectures and Support: ";
				setRgb(COLOUR_LIGHTYELLOW_ON_PURPLE);
				std::cout << "Shilpa Ranjit"; 
				setRgb(COLOUR_WHITE_ON_BLACK);
				std::cout << std::endl;
				std::cout << "and ";
				setRgb(COLOUR_CYAN_ON_BLUE);
				std::cout << "Alexa O'Brien";
				setRgb(COLOUR_WHITE_ON_BLACK);
				std::cout << std::endl << std::endl;

				std::cout << "Thank you for looking at the credits!" << std::endl << std::endl;

				std::cout << "Enter 5 on the main menu for a chip boost!" << std::endl << std::endl;

				std::cout << "Press Enter to return to the main menu" << std::endl;

				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cin.get();

				clearScreen();
				break;
			case 3:
				// Quit Game
				std::cout << "Thank you for playing! Goodbye!" << std::endl;
				Sleep(2000); // Wait for 2 seconds before exiting, so that message is visable to the user.
				break;
			case 4:
				// Gambling Helpline
				std::cout << std::endl << "If you or someone you know has a gambling problem, please seek help." << std::endl;
				std::cout << "You can contact the Gambling Helpline at 0800 654 655 or visit their website at www.gamblinghelpline.co.nz." << std::endl << std::endl;

				std::cout << "Press Enter to quit the game" << std::endl;
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cin.get();

				exit(0); // Exit the program after displaying the helpline information.
				break;
			case 5:
				// Cheat Code for Chip Boost
				if (!hasUsedCheatCode) {
					hasUsedCheatCode = true; // Mark the cheat code as used.
					playerChips += 1000;

					setRgb(COLOUR_GREEN_ON_BLACK);
					std::cout << std::endl << "Cheat code activated! You now have " << playerChips << " chips." << std::endl << std::endl;
					setRgb(COLOUR_WHITE_ON_BLACK);
					std::cout << "Press Enter to continue." << std::endl << std::endl;

					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cin.get();

					clearScreen();
				}
				else {
					setRgb(COLOUR_RED_ON_BLACK);
					std::cout << std::endl << "Nice Try, The cheat code has already been used. You cannot use it again." << std::endl << std::endl;
					setRgb(COLOUR_WHITE_ON_BLACK);
					std::cout << "Press Enter to continue." << std::endl << std::endl;

					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cin.get();

					clearScreen();
				}
				break;
			default:
				std::cout << "Invalid selection. Please enter a number between 1 and 5." << std::endl;
			}
		}

	return 0;
}

void setRgb(EColour colour)
{
	switch (colour)
	{
	case COLOUR_WHITE_ON_BLACK: // White on Black.
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN |
			FOREGROUND_BLUE);
		break;
	case COLOUR_RED_ON_BLACK: // Red on Black.
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		break;
	case COLOUR_GREEN_ON_BLACK: // Green on Black.
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
		break;
	case COLOUR_PURPLE_ON_BLACK: // Purple on Black.
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
		break;
	case COLOUR_YELLOW_ON_BLACK: // Yellow on Black.
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
		break;
	case COLOUR_PINK_ON_LIGHTBLUE: // Pink on Light Blue.
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_INTENSITY | BACKGROUND_BLUE);
		break;
	case COLOUR_PURPLE_ON_ORANGE: // Purple on Orange.
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN);
		break;
	case COLOUR_ORANGE_ON_BLACK: // Orange on Black.
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
		break;
	case COLOUR_BLUE_ON_BLACK: // Blue on Black.
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
		break;
	case COLOUR_CYAN_ON_BLUE: // Cyan on Blue.
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE | BACKGROUND_INTENSITY | BACKGROUND_BLUE);
		break;
	case COLOUR_LIGHTYELLOW_ON_BLACK: // Light Yellow on Black.
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
		break;
	case COLOUR_LIGHTYELLOW_ON_PURPLE: // Light Yellow on Purple.
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_BLUE);
		break;
	}
	
};

void clearScreen()
{
	COORD coordScreen = { 0, 0 };
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD dwConSize;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
	FillConsoleOutputCharacter(hConsole, TEXT(' '), dwConSize, coordScreen, &cCharsWritten);
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);
	SetConsoleCursorPosition(hConsole, coordScreen);
};

std::array<int, 3> spinSlots()
{
	return {
		std::rand() % 6 + 2, // Random number between 2 and 7 for slot 1.
		std::rand() % 6 + 2, // Random number between 2 and 7 for slot 2.
		std::rand() % 6 + 2  // Random number between 2 and 7 for slot 3.
	};
}

EColour getColourFromSlot(int slotValue)
{
	switch (slotValue)
	{
	case 2:
		return COLOUR_RED_ON_BLACK;
	case 3:
		return COLOUR_YELLOW_ON_BLACK;
	case 4:
		return COLOUR_LIGHTYELLOW_ON_BLACK;
	case 5:
		return COLOUR_GREEN_ON_BLACK;
	case 6:
		return COLOUR_BLUE_ON_BLACK;
	case 7:
		return COLOUR_PURPLE_ON_BLACK;
	default:
		return COLOUR_WHITE_ON_BLACK; // Default colour if the slot value is out of range.
	}
}