#include"HeaderMain.h"


int main()
{
	while (true)
	{
		Sweets sweets;
		std::ifstream in("Text.txt");
		double weight;

		std::cout << "enter weight" << std::endl;
		std::cin >> weight;
		sweets.ReadinVector(in);
		Present present;

		present.createPresentByWeight(weight, sweets);


		present.Print(std::cout);

	}
	
	
	

	return 0;
}