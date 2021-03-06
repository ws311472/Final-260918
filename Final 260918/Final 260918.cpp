//header file pch.h
#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
//Make use of the time() function to get the number of seconds on your system time and randomly seed the rand() function
#include <ctime>
#include <string>
#include <conio.h>
#include "stdlib.h"
#include <thread>
#include <chrono>
#include "windows.h"

using namespace std;

int main()
{
	//time(0) will return the current second count, prompting the srand() function to set a different seed for the rand() function each time the program runs
	//unlike the rand() function by itself which does output a random number for the seed, but it only returns a pseudo random number, which means that each time the code is run, it generates the same number (unless you change the seed each time, but the srand() function does this for you)
	srand(time(0));
	//setting variables - pretty self explanatory...
	int iOp = 0, iNput = 0;
	int iOpInput1 = 1, iOpInput2 = 2, iOpInput3 = 3;

	cout << "Welcome to where-ever this is. \n"
		"There are a few options for you to choose from. \n"
		"Option 1: You will be given 3 random numbers.\n It will be your job to find the biggest number. \n"
		"Option 2: You will be given another 3 random numbers, but this time you need to find the smallest number. \n"
		"Option 3: You will be asked to enter your username and password to log in. \n" << endl;
	cout << "Choose Option 1, 2 or 3:  ";
	cin >> iOp;

	if (iOp == iOpInput1) {
		//Set iBiggest at the lowest number it can be.
		int iBiggest = 1;
		//A for loop can be used to generate multiple random numbers. 
		for (int iOp = 1; iOp <= 3; iOp++) {
			//Use the modulo operator to generate random numbers within a specific range e.g. 1000 
			//Assign the outputted number to a variable in order to be able to check it against the other numbers randomly outputted
			int iNumO = 1 + (rand() % 1000);
			//Output the numbers so the user can see them
			cout << iNumO << endl;
			//At the first for loop, any number generated is bigger than the inital iBiggest value of 1, so on the subsequent loops, it keeps reassigning the iBiggest variable, if the number is bigger, so you will always have the biggest number in that variable
			if (iNumO > iBiggest) {
				iBiggest = iNumO;
			}
		}
		cout << "Which one of these is the biggest number? " << endl;
		//User inputs biggest number out of the numbers generated
		cin >> iNput;
		//If the user inputs the correct number...
		if (iNput == iBiggest) {
			cout << "You're right, that is the biggest number." << endl;
		}
		else {
			cout << "No, that is not the biggest number.";
		}
	}
	//This is essentially the same as iOp1, but numbers have been changed, and some logical operators have been swapped about
	else if (iOp == iOpInput2) {
		//Set iSmallest as the largest number it can be
		int iSmallest = 1001;
		for (int iOp = 1; iOp <= 3; iOp++) {
			int iNum = 1 + (rand() % 1000);
			cout << iNum << endl;
			if (iNum < iSmallest) {
				iSmallest = iNum;
			}
		}
		cout << "Which one of these is the smallest number? " << endl;
		cin >> iNput;
		if (iNput == iSmallest) {
			cout << "You're right, that is the smallest number." << endl;
		}
		else {
			cout << "No, that is not the smallest number.";
		}
	}
	else if (iOp == iOpInput3) {
		string sUsername = "", sPassword = "";
		//Store correct passwords
		string sUserStore = "admin", sPassStore = "password";
		//Set attempt variable
		int iAttempt = 1;
		//As long as the attempt number is less than 3, the while loop will be executed
		cout << "You will have a maximum of 3 attempts to input your credentials." << endl;
		while (iAttempt <= 3)
		{
			cout << "Please enter your username: " << endl;
			cin >> sUsername;
			cout << "Please enter your password: " << endl;
			cin >> sPassword;
			//As long as the username and password matched the stored username and password, the successful login output will show
			if (sUsername == sUserStore && sPassword == sPassStore) {
				cout << "You have successfully logged in." << endl;
				iAttempt = 0;
				//If this is correct, you have to break the loop otherwise the rest of the loop will still execute. So even if you have put your password in right the first time, it will still ask you for it a gazillion times
				break;
			}
			//If the username OR the password don't match the stored username and password, it will go back to the top of the loop and ask you to start again
			else if (sUsername != sUserStore || sPassword != sPassStore) {
				cout << "Your credentials are incorrect. Try again." << endl;
				cout << "Attempt number: " << iAttempt << endl;
				//However, every time you attempt, it increments the attempt counter by 1.
				++iAttempt;
			}
			//Once you have tried 3 times:

			if (iAttempt > 3)
			{
				int x = 0;
				system("CLS");
				cout << "You have exceeded your allowed number of attempts. " << endl;
				Sleep(1000);
				cout << "Preparing to self destruct..." << endl;
				Sleep(2000);
				system("CLS");
				for (int x = 5; x > 0; x--) {
				cout << x << endl;
				Sleep(2000);
				system("CLS");
				}
				system("CLS");
				cout << "Goodbye..." << endl;
			}
		}


	}
	//Remember _getch() or getchar() otherwise it'll execute without you being able to read it :)
	getchar();

	return 0;
}