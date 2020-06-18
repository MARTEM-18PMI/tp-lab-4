#include<iostream>
#include"Automata.h"

int main()
{
	Automata machine;
	machine.on();
	machine.coin(20);
	machine.off();
	machine.choice(5);
	machine.cancel();
	machine.off();
	machine.choice(1);
	machine.cancel();
	machine.coin(10);
	return 0;
}