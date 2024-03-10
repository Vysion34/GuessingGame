// GuessingGame.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>


std::vector<int> numbers;
std::vector<char> operators;

int answer = 0;

// (number1 operator number2 = answer)
int number1Guess = 0;
char operatorGuess = ' ';
int number2Guess = 0;
int answerGuess = 0;

char again;

void guessFirstNumber(int guess, std::vector<int> numbers);
void guessOperator(char guess, std::vector<char> operators);
void guessSecondNumber(int guess, std::vector<int> numbers);
void guessAnswer(int guess, int answer);

void fillNumbersList();
void fillOperatorsList();
void shuffleOperatorsList();


int main(int argc, _TCHAR* argv[])
{
	fillOperatorsList();

	do {
		system("cls");

		shuffleOperatorsList();

		fillNumbersList();

		// Pick 2 random elements to display 1, 2, 3, or 4. They cannot be the same element.
		// element 1 = number1, element 2 = operator, element 3 = number2, and element 4 = answer.
		int element1;
		int element2;
		do {
			element1 = rand() % 4 + 1;
			element2 = rand() % 4 + 1;
		} while (element1 == element2);

		if (operators[0] == '+') {
			answer = numbers[0] + numbers[1];
		}
		else if (operators[0] == '-') {
			answer = numbers[0] - numbers[1];
		}
		else if (operators[0] == '*') {
			answer = numbers[0] * numbers[1];
		}
		else if (operators[0] == '/') {
			answer = numbers[0] / numbers[1];
		}

		std::cout << "Try to guess the missing elements" << std::endl << std::endl;

		if (element1 == 1 || element2 == 1) {
			std::cout << "\t" << numbers[0];
		}
		else {
			std::cout << "\t" << "?";
		}

		if (element1 == 2 || element2 == 2) {
			std::cout << " " << operators[0];
		}
		else {
			std::cout << " " << "?";
		}

		if (element1 == 3 || element2 == 3) {
			std::cout << " " << numbers[1];
		}
		else {
			std::cout << " " << "?";
		}

		if (element1 == 4 || element2 == 4) {
			std::cout << " = " << answer << std::endl << std::endl;
		}
		else {
			std::cout << " = " << "?" << std::endl << std::endl;
		}

		if (element1 != 1 && element2 != 1) {
			guessFirstNumber(number1Guess, numbers);
		}

		if (element1 != 2 && element2 != 2) {
			guessOperator(operatorGuess, operators);
		}

		if (element1 != 3 && element2 != 3) {
			guessSecondNumber(number2Guess, numbers);
		}

		if (element1 != 4 && element2 != 4) {
			guessAnswer(answerGuess, answer);
		}

		std::cout << "\t" << numbers[0] << " " << operators[0] << " " << numbers[1] << " = " << answer << std::endl;

		// Clear the numbers vector
		numbers.clear();

		std::cout << std::endl;
		std::cout << "Would you like to play again? (Y/N): ";
		std::cin >> again;
	} while (again == 'Y' || again == 'y');

	std::cout << std::endl;
	system("pause");
	return 0;
}


void guessFirstNumber(int number1Guess, std::vector<int> numbers) {
	do {
		std::cout << "Enter your guess for the first number." << std::endl;
		std::cin >> number1Guess;

		if (numbers[0] < number1Guess) {
			std::cout << "Too high try again" << std::endl;

		}
		else if (numbers[0] > number1Guess) {
			std::cout << "Too low try again" << std::endl;

		}
		else if (numbers[0] == number1Guess) {
			std::cout << "Congratulations, you guessed the first number!" << std::endl << std::endl;
		}
	} while (numbers[0] != number1Guess);
}


void guessOperator(char operatorGuess, std::vector<char> operators) {
	do {
		std::cout << "Enter your guess for the operator (+, -, *, /)." << std::endl;
		std::cin >> operatorGuess;

		if (operators[0] != operatorGuess) {
			std::cout << "Wrong operator try again" << std::endl;
		}
		else if (operators[0] == operatorGuess) {
			std::cout << "Congratulations, you guessed the correct operator!" << std::endl << std::endl;
		}
	} while (operators[0] != operatorGuess);
}


void guessSecondNumber(int number2Guess, std::vector<int> numbers) {
	do {
		std::cout << "Enter your guess for the second number." << std::endl;
		std::cin >> number2Guess;

		if (numbers[1] < number2Guess) {
			std::cout << "Too high try again" << std::endl;
		}
		else if (numbers[1] > number2Guess) {
			std::cout << "Too low try again" << std::endl;
		}
		else if (numbers[1] == number2Guess) {
			std::cout << "Congratulations, you guessed the second number!" << std::endl << std::endl;
		}
	} while (numbers[1] != number2Guess);
}


void guessAnswer(int answerGuess, int answer) {
	do {
		std::cout << "Enter your guess for the Answer." << std::endl;
		std::cin >> answerGuess;

		if (answer < answerGuess) {
			std::cout << "Too high try again" << std::endl;
		}
		else if (answer > answerGuess) {
			std::cout << "Too low try again" << std::endl;
		}
		else if (answer == answerGuess) {
			std::cout << "Congratulations, you guessed the answer!" << std::endl << std::endl;
		}
	} while (answer != answerGuess);
}


void fillNumbersList() {
	for (int i = 0; i < 2; i++) {
		int randomNumber = rand() % 100 + 1;
		numbers.push_back(randomNumber);
	}
}


void fillOperatorsList() {
	operators.push_back('+');
	operators.push_back('-');
	operators.push_back('*');
	operators.push_back('/');
}


void shuffleOperatorsList() {
	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(operators.begin(), operators.end());
}
