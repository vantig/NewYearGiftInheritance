#pragma once
#include"HeaderMain.h"

class Present
{
private:
	std::vector<std::shared_ptr<BaseSweet>>presentSweets;
	double weight=0;
	double cost=0;








public:
	double getWeight ()const{ return weight; }
	double getCost()const { return cost; }
	 void createPresentByWeight(double w, Sweets& s);
	
	Present() = default;
	~Present() = default;
	void Print(std::ostream&);

};
void Present::Print(std::ostream&out)
{
	std::copy(presentSweets.begin(), presentSweets.end(), std::ostream_iterator<std::shared_ptr<BaseSweet>>(out));
}
void Present::createPresentByWeight(double w,Sweets&s)
{
	Present p;

	bool flag = 1;//нужен что б не было вечного цикла
	s.SortbyWeight();
	while (w>0&&flag )
	{
		std::for_each(s.sweets.begin(), s.sweets.end(), [&w, &p,&flag,s](std::shared_ptr<BaseSweet >cur ) 
		{
			if (cur->getWeight()<=w)
			{
				w -= cur->getWeight();
				p.cost += cur->getPrice();
				p.weight += cur->getWeight();
				p.presentSweets.push_back(cur);

			}
			else if(w < s.sweets.back()->getWeight())
			{
				flag = 0;
				
			}
		});
		
	}
	
	*this = p;
}

