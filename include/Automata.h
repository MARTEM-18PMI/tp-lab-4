#pragma once

#include<string>
#include<vector>
using namespace std;

	enum States
	{
		OFF, WAIT, ACCEPT, CHECK, COOK
	};

	class Automata
	{
	public:
		void on();
		void off();
		void printMenu();
		void printState();
		void cancel();
		void finish();
		void choice(unsigned int);
		bool check(unsigned int);
		void coin(unsigned int);
		void cook(unsigned int);
		int change() { int buf = cash; cash = 0; return buf; }
	private:
		const vector<string> menu = { "", "Hot water", "Espresso", "Hot chocolate", "Russiano", "Americano" };
		const vector<string> stateNames = { "OFF", "WAIT", "ACCEPT", "CHECK", "COOK" };
		const vector<unsigned int> prices = { 0 ,10, 25, 25, 40, 35 };
		States state = OFF;
		unsigned int cash = 0;

	};