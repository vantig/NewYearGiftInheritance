#pragma once
#include"HeaderMain.h"

class Marshmellow:public BaseSweet
{
private:
	bool inChocolate;
	std::string flavor;


public:
	Marshmellow() = default;
	~Marshmellow() = default;
	std::istream& read(std::istream& in)override
	{
		BaseSweet::read(in);
		in >> inChocolate >> flavor ;
		return in;
	}

	std::ostream& print(std::ostream& out)const override
	{
		BaseSweet::print(out);
		out << " inChocolate " << inChocolate << " flavor " << flavor <<std::endl;
		return out;
	}

};

