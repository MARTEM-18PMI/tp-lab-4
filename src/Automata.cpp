#include<iostream>
#include<vector>
#include"Automata.h"
#include"windows.h"

using namespace std;

void Automata::on()
{
	if (state == OFF)
	{
		state = WAIT;
		cout << "The Coffee machine is on and ready to serve a client.\n";
	}
	else
	{
		cout << "The Coffee machine is already on. You may continue.\n" ;
	}
}


void Automata::off()
{
	if (state == WAIT)
	{
		state = OFF;
		cout << "The Coffee machine is off. The change is " << change() << ".\n";
	}
	else if (state == OFF)
	{
		cout << "*No reaction*\n";
	}else
	{
		cout << "Terminate the process " << stateNames[state] << " before shutdown.\n";
	}
}


void Automata::printMenu()
{
		cout << "Drinks:\n";
		for (size_t i = 1; i < menu.size(); ++i)
		{
			cout << i << ". " << menu[i] << " - " << prices[i] << "\n";
		}
}


void Automata::coin(unsigned int new_cash)
{
	if (state == WAIT)
	{
		state = ACCEPT;
		cash += new_cash;
		cout << "The money was received. Your current balance is " << cash << ".\n";
	}
	else if (state == OFF)
	{
		cout << "*No reaction*\n";
	}
	else if (state == ACCEPT)
	{
		cash += new_cash;
		cout << "The money was received. Your current balance is " << cash << ".\n";
	}
	else cout << "You cannot deposit money right now.\n";
}


void Automata::printState()
{
	cout << "The current state is " << stateNames[state] << ".\n";
}


bool Automata::check(unsigned int drinkIndex)
{
		state = CHECK;
		return cash >= prices[drinkIndex];
}

void Automata::cancel()
{
	if (state != OFF)
	{
		cout << "Canceled.\n";
		state = WAIT;
	}
	else
	{
		cout << "*No reaction*\n";
	}
		
}

void Automata::cook(unsigned int drinkIndex)
{
	if (state == CHECK)
	{
		state = COOK;
		cout << menu[drinkIndex] << " is preparing. Please, wait...\n[";
		for (size_t i = 0; i < 60; ++i)
		{
			cout << "#";
			Sleep(30);
		}
		cout << "]\nYour drink is already prepared.\n";
		cash -= prices[drinkIndex];
		finish();
	}
	else
	{
		cout <<"Cannot prepare a drink right now.\n";
	}
}

void Automata::choice(unsigned int drinkIndex)
{
	if (state == ACCEPT && 1 <= drinkIndex && drinkIndex < prices.size())
	{
		if (check(drinkIndex))
		{
			cook(drinkIndex);
		}
		else
		{
			state = WAIT;
			cout << "Not enough money to purchase a drink.\n";
		}

	}
	else if ((1 >= drinkIndex || drinkIndex >= prices.size()) && (state == ACCEPT))
	{
		cout << "The number of drink is incorrect. Try again.\n";
	}
	else if (state == OFF)
	{
		cout << "*No reaction*\n";
	}
	else
		cout << "Sorry, but you cannot choose a drink right now.\n";

}

void Automata::finish()
{
	if (state == COOK)
	{
		state = WAIT;
	}
}