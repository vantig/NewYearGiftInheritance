#include"HeaderMain.h"


int main()
{
	
	std::ifstream in("Text.txt");
	Sweets sweets;
	sweets.ReadinVector(in);
	sweets.Print(std::cout);
	

	return 0;
}