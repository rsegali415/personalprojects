#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <ctype.h>
using namespace std;

string PasswordPrompt();
bool LengthCheck(string password);
bool CapCheck(string password);
bool LowerCheck(string password);
bool NumCheck(string password);
void finalCheck(string password);

int main()
{

	string password = PasswordPrompt();

	finalCheck(password);

	return 0;
}

string PasswordPrompt()
{
	string password;

	cout << "Please enter a password: ";
	cin >> password;

	return password;
}

bool LengthCheck(string password)
{
	if (password.length() >= 6)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CapCheck(string password)
{
	char* pword = new char[password.length()];

	for (int i = 0; i < password.length(); i++)
	{
		pword[i] = password[i];
	}

	for (int i = 0; i < password.length(); i++)
	{
		if (isupper(pword[i]))
		{
			return true;
		}
	}
	return false;
}

bool LowerCheck(string password)
{
	char* pword = new char[password.length()];

	for (int i = 0; i < password.length(); i++)
	{
		pword[i] = password[i];
	}

	for (int i = 0; i < password.length(); i++)
	{
		if (islower(pword[i]))
		{
			return true;
		}
	}
	return false;
}

bool NumCheck(string password)
{
	char* pword = new char[password.length()];

	for (int i = 0; i < password.length(); i++)
	{
		pword[i] = password[i];
	}

	for (int i = 0; i < password.length(); i++)
	{
		if (isdigit(pword[i]))
		{
			return true;
		}
	}
	return false;
}

void finalCheck(string password)
{
	LengthCheck(password);
	CapCheck(password);
	LowerCheck(password);
	NumCheck(password);

	if (LengthCheck(password) == false)
	{
		cout << "The password is not long enough." << endl;
	}

	if (CapCheck(password) == false)
	{
		cout << "The password does not have any uppercase letters." << endl;
	}

	if (LowerCheck(password) == false)
	{
		cout << "The password does not have any lowercase letters." << endl;
	}

	if (NumCheck(password) == false)
	{
		cout << "The password does not have any numbers in it." << endl;
	}

	if (LengthCheck(password) == true && CapCheck(password) == true && LowerCheck(password) == true && NumCheck(password) == true)
	{
		cout << "Your password is valid." << endl;
	}
	else
	{
		cout << "Please reenter a valid password. ";
		cin >> password;
		finalCheck(password);
	}
}
