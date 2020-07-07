
#pragma once
#include"base.h"
class Lollypop:public BaseSweet
{
private:
	std::string taste;
	std::string shape;



public:
	Lollypop() = default;
	~Lollypop() = default;
	std::istream& read(std::istream& in)override
	{
		BaseSweet::read(in);
		in >> taste >> shape;
		return in;
	}

	std::ostream& print(std::ostream& out)const override
	{
		BaseSweet::print(out);
		out << " taste " << taste << " shape " << shape << std::endl;
		return out;
	}
};

