#include <iostream>

//include for cin.ignore()
#include <limits>

//include for osstringstream
#include <sstream>

#define cout std::cout
#define cin std::cin

void PrintMenu();
short CheckInput(short /*difficulty*/);
void Game(short /*difficulty*/);

int main() {

	bool exit = false;
	short difficulty;

	while (exit == false)
	{
		PrintMenu();

		cin >> difficulty;

		difficulty = CheckInput(difficulty);
		Game(difficulty);

	}

	return 0;
}

void PrintMenu() {
	// change the random seed to system time to change the number patterns regulary
	std::srand(std::time(0));

	cout << "Multiplication Trainer | 0.1\n";
	cout << "Input a Number to choose the difficulty.\n";
	cout << "1 | Easy (Range 1-10)\n";
	cout << "2 | Medium (Range 1-20)\n";
	cout << "3 | Hard (Range 10-100\n";
}

short CheckInput(short diff) {
	// while input out of range or something diffrent, get new input
	while (diff < 1 || diff > 3 || !cin.good()) {

		cout << "That input is invalid!\n" << "Please try again.\n";
		cout << "Press any button to continue . . .\n";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cin.get();

		printf("\033c");
		PrintMenu();

		cin >> diff;
	}
	return diff;
}

void Game(short difficulty) {

	int number1 = NULL;
	int number2 = NULL;
	int result = NULL;

	const char* diffString[3] = { "Easy", "Medium", "Hard" };
	std::ostringstream statusBarStream;
	statusBarStream << diffString[difficulty - 1] << " Mode\t|";
	std::string statusString = statusBarStream.str();

	int highscore = 0;
	short highscoreMod = 1;
	int counter = 1;
	int counterRight = 0;
	int counterWrong = 0;


	do {
		switch (difficulty)
		{
		case 1: // Easy Mode
			number1 = std::rand() % 10 + 1;
			number2 = std::rand() % 10 + 1;
			break;
		case 2: // Medium Mode
			highscoreMod = 2;
			number1 = std::rand() % 10 + 1;
			number2 = std::rand() % 20 + 1;
			while (number2 < 10) {
				number2 = std::rand() % 20 + 1;
			}
			break;
		case 3: // Hard Mode
			highscoreMod = 4;
			number1 = std::rand() % 100 + 1;
			number2 = std::rand() % 100 + 1;
			while (number1 < 10 || number2 < 10) {
				number1 = std::rand() % 100 + 1;
				number2 = std::rand() % 100 + 1;
			}
			break;
		default:
			cout << "Something went wrong. | switch(difficulty) in Game(difficulty)\n";
			break;
		}
		printf("\033c");

		cout << statusString << " Highscore: " << highscore << std::endl;
		cout << "Excersice: " << counter << "\t| Right: " << counterRight << " ; Wrong: " << counterWrong << std::endl;
		cout << "Enter '0' to quit to the main menu.\n\n";
		cout << number1 << " * " << number2 << " = ";
		cin >> result;
		cout << std::endl;

		if (result == (number1 * number2)) {
			highscore = highscore + 10 * highscoreMod;
			counterRight++;
		}
		else {
			counterWrong++;
		}
		counter++;
	} while (result != 0);
}