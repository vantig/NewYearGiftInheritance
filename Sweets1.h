#pragma once
#pragma once
#include"HeaderMain.h"
std::shared_ptr<BaseSweet> getPtr(char C);
class Sweets
{
public:
	Sweets() = default;
	~Sweets() = default;
	void ReadinVector(std::istream& in);
	void Print(std::ostream& out);
	void SortbyWeight();
	void SortbyPrice();
	void SortbySugar();


	std::vector<std::shared_ptr<BaseSweet>>sweets;
};
void Sweets::SortbySugar()
{
	std::sort(sweets.begin(), sweets.end(), [](std::shared_ptr<BaseSweet>s1, std::shared_ptr<BaseSweet>s2) {return s1->getSugar() > s2->getSugar(); });

}
void Sweets::SortbyPrice()
{
	std::sort(sweets.begin(), sweets.end(), [](std::shared_ptr<BaseSweet>s1, std::shared_ptr<BaseSweet>s2) {return s1->getPrice() > s2->getPrice(); });

}
void Sweets::SortbyWeight()
{
	std::sort(sweets.begin(), sweets.end(), [](std::shared_ptr<BaseSweet>s1, std::shared_ptr<BaseSweet>s2) {return s1->getWeight() > s2->getWeight(); });
}
void Sweets::Print(std::ostream& out)
{
	std::copy(sweets.begin(), sweets.end(), std::ostream_iterator<std::shared_ptr<BaseSweet>>(out, "\n"));

}
void Sweets::ReadinVector(std::istream& in)
{


	while (!in.eof())
	{
		char simbol;
		in >> simbol;
		sweets.push_back(getPtr(simbol));
		std::string str;
		getline(in, str);
		std::istringstream input(str);
		sweets.back()->read(input);
	
	}

}
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