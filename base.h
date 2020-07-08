
#pragma once
#include"HeaderMain.h"

class BaseSweet
{

	std::string name;
	double weight;
	double price;
	double sugar;
public:
	virtual ~BaseSweet() = default;
	BaseSweet() = default;
	std::string getName()const { return name; }
	double getWeight()const { return weight; }
	double getPrice()const {	return price;}
	double getSugar()const { return sugar; }
	void setName(std::string m) { name = m; }
	void setWeight(double w) {  weight=w; }
	void setPrice(double p) { price =p; }
	void setSugar(double s) {  sugar=s; }
	virtual std::istream& read(std::istream& in)
	{
		in >> name >> weight >> price >> sugar;
		return in;
	}
	virtual	std::ostream&  print(std::ostream&out)const
	{
		out << " name " << name << " weight " << weight << " price " << price << " sugar " << sugar;
		return out;
	}
	
};
std::ostream& operator<<(std::ostream& out, std::shared_ptr<BaseSweet >s1 )
{
	s1->print(out);
	return out;
}