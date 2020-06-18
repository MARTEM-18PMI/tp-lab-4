#include<iostream>
#include"Automata.h"

int main()
{
	Automata machine;
	machine.on();
	machine.on();
	machine.cook(2);
	machine.choice(1);
	machine.printMenu();
	machine.coin(25);
	machine.choice(5);
	machine.off();
	system("pause");
	return 0;
}