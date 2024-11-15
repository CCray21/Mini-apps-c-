#include <iostream>
#include <limits>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

int GenerateRandomNumber()
{
	return 1 + (rand() % 10);
}
void AskQuestions()
{
	int score = 0;
	char operations[2] = { '+', '-' }; //creates an array of the operators so that they can be randomly called at a later time
	srand(time(nullptr)); //seed for the random number generator
	for (int i = 1; i <= 10; i++)
	{
		int num1 = GenerateRandomNumber();
		int num2 = GenerateRandomNumber();
		char operation = operations[rand() % 2]; //creates the operation variable which is chosen randomly from the operations array
		cout << num1 << operation << num2 << "\n\n";
		int answer, correctAnswer;
		if (operation == '+') //if statement for calculating the correct answer
		{
			correctAnswer = num1 + num2;
		}
		else
		{
			correctAnswer = num1 - num2;
		}
		bool failedInputKeepCounting = false; //declares the variable needed for the loop to validate the input for the answer
		do //do while loop because it needs to be ran through at least once
		{
			cin >> answer;
			if (cin.fail()) //if the value entered is not an integer
			{
				cin.clear(); //clear the error flag
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discards characters in the input stream, then makes a new line so the code continues.
				failedInputKeepCounting = true;
				cout << "\nPlease enter a number\n\n";
				cout << num1 << operation << num2 << "\n\n";
			}
			else
			{
				failedInputKeepCounting = false; //if the value is valid, the loop is  exited
			}
		} while (failedInputKeepCounting);

		cout << "\n\n";
		if (answer == correctAnswer)
		{
			score++; //increases the score if the answer is correct
		}
		else
		{
			cout << "Incorrect answer. The answer is " << correctAnswer << ".\n\n";
		}
	}
	if (score == 10) //else if statement for personalised feedback
	{
		cout << "Perfect! you scored " << score << "/10\n\n";
	}
	else if (score >= 7)
	{
		cout << "Well done! you scored " << score << "/10\n\n";
	}
	else if (score >= 5)
	{
		cout << "You scored " << score << "/10\n\n";
	}
	else if (score >= 2)
	{
		cout << "Oh no, you scored " << score << "/10\n\n";
	}
	else if (score > 0)
	{
		cout << "You should try to get better at maths, you only got " << score << "/10\n\n";
	}
	else
	{
		cout << "Oh dear. you got none right.";
	}

}
void RepeatMiniApp(bool &app)
{
	bool appLoop = true;
	while (appLoop) //loop for asking if the user wants to play again
	{
		cout << "Would you like to try again?\n1) Yes\n2) No\n";
		int appLoop2;
		cin >> appLoop2;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Please try again.\n";
		}
		else
		{
			switch (appLoop2) //loop that disallows valid inputs that isnt yes or no
			{
			case 1:
				appLoop = false; //exits the input validation loop
				break;
			case 2:
				app = false; //exits the subprogram
				appLoop = false; //exits the input validation loop
				break;
			default:
				cout << "Invalid input. Please try again.\n"; // stays in the input validation loop
				break;
			}
		}
	}
}
void SquareRoot()
{
	cout << "Please input the number you want to square root\n";
	double number;
	int dp;
	cin >> number;
	double squareRoot = sqrt(number);
	cout << "Enter how many decimal places the number should be rounded to\n";
	cin >> dp;
	cout << fixed << setprecision(dp);
	cout << "The square root of " << number << " is " << squareRoot << "\n";
}
void EncryptCode()
{
	string code;
	cout << "Please enter the code you would like to encrypt\n";
	cin >> code;
	string uppercaseCode;
	uppercaseCode = code;
	for (char &c : uppercaseCode)
	{
		c = toupper(c);
	}
	
	cout << "How many places would you like to shift the code?\n";
	cin.ignore();
	getline(cin, code);
	int shift;
	cin >> shift;
	string decryptedCode;
	for (char& c : uppercaseCode)
	{
		if (c >= 'A' && c <= 'Z')
		{
			c = c + shift;
			if (c < 'A')
			{
				c = c + 26;
			}
		}
	}
	cout << "The decrypted code is: " << uppercaseCode << "\n";

}
void DecryptCode()
{
	string code;
	cout << "Please enter the code you would like to decrypt\n";
	cin >> code;
	string uppercaseCode;
	uppercaseCode = code;
	for (char& c : uppercaseCode)
	{
		c = toupper(c);
	}

	cout << "How many places would you like to shift the code?\n";
	int shift;
	cin >> shift;
	string decryptedCode;
	for (char& c : uppercaseCode)
	{
		if (c >= 'A' && c <= 'Z')
		{
			c = c - shift;
			if (c < 'A')
			{
				c = c - 26;
			}
		}
	}
	cout << "The decrypted code is: " << uppercaseCode << "\n";
}

int main()
{
	bool running = true;
	while (running)
	{
		cout << "Welcome! please enter the corresponding number to the program you would like to use\n-----------------------\n1) Keep Counting\n2) Square Root Calculator\n3) Encrypt Text (Caesar Cipher)\n4) Decrypt Text (Caesar Cipher)\n9) Quit\n";
		int x;
		cin >> x;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Try again\n";
		}
		else
		{
			switch (x)
			{
			case 1:
				bool keepCounting;
				keepCounting = true;
				cout << "Welcome to keep counting\n\n";
				while (keepCounting)//loop for the appilication
				{
					AskQuestions();
					RepeatMiniApp(keepCounting);
				}
				break;
			case 2:
				bool squareRootCalc;
				squareRootCalc = true;
				cout << "Welcome to the square root calculator\n";
				while (squareRootCalc)
				{
					SquareRoot();
					RepeatMiniApp(squareRootCalc);
				}
				
				break;
			case 3:
				bool encryptCode;
				encryptCode = true;
				cout << "Welcome to the code encrypter\n";
				while (encryptCode)
				{
					EncryptCode();
					RepeatMiniApp(encryptCode);
				}

				break;
			case 4:
				bool decryptCode;
				decryptCode = true;
				cout << "Welcome to the code decrypter\n";
				while (decryptCode)
				{
					DecryptCode();
					RepeatMiniApp(decryptCode);
				}
				break;
			case 9:
				running = false;
				break;
			default:
				cout << "Please enter a valid input\n";
				break;
			}
		}
	}
	return 0;
}