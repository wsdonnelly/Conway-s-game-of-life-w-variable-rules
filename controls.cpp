#include <iostream>
#include "controls.hpp"

void Controls::move_low_down()
{
	if (low > 1)
	{
		low--;
		display();
	}
}

void Controls::move_low_up()
{
	if (low < 8)
	{
		if (low == high)
			high++;
		low++;
		display();
	}
}

void Controls::move_high_up()
{
	if (high < 8)
	{
		high++;
		display();
	}
}

void Controls::move_high_down()
{
	if (high > 1)
	{
		if (low == high)
			low--;
		high--;
		display();
	}
}

void Controls::set_born(int n)
{
	born = n;
	display();
}

void Controls::display()
{
	std::system("clear");
	std::cout << "press 'r' to re-seed.\n";
	std::cout << "cmd + 'q' to quit.\n";
	std::cout << "move low range down -> 'k'\n";
	std::cout << "move low range up -> 'l'\n";
	std::cout << "move high range up -> 'p'\n";
	std::cout << "move high range down -> 'o'\n";
	std::cout << "Range to continue living :\n" << "low: " << low << " high: " << high << std::endl;
	std::cout << "Number of neighbors to be born: " << born << std::endl;
}
