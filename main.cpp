#include"base.h"
#include "chocolate.h"
#include"marshmellow.h"
#include"lollypop.h"
#include<fstream>
#include<sstream>
#include<algorithm>
#include<iterator>
std::shared_ptr<BaseSweet> getPtr(char C)
{
	switch (C)
	{
	case 'c':
	{
		return std::make_shared<Chocolate>();
	}
	case 'l':
	{
		return std::make_shared<Lollypop>();
	}
	case 'm':
	{
		return std::make_shared<Marshmellow>();
	}
	default:
		break;
	}
}
int main()
{
	std::vector<std::shared_ptr<BaseSweet>>sweets;
	std::ifstream in("Text.txt");
	while (!in.eof())
	{ 
		char simbol;
		in >> simbol;
		sweets.push_back(getPtr(simbol));
		std::string str;
		getline(in, str);
		std::istringstream input(str);
		sweets.back()->read(input);
		sweets.back()->print(std::cout);
	}
	
	std::sort(sweets.begin(), sweets.end(), [](std::shared_ptr<BaseSweet>s1, std::shared_ptr<BaseSweet>s2) {return s1->getWeight() > s2->getWeight(); });
	std::copy(sweets.begin(), sweets.end(), std::ostream_iterator<std::shared_ptr<BaseSweet>>(std::cout, "\n"));
	return 0;
}