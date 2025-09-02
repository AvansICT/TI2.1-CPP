#include <iostream>
#include "log.hpp"
#include "rekenen.hpp"

namespace rekenen {

	int add(int x, int y) {
		LOG_DEBUG;
		return x + y;
	}
	
	Rekenen::Rekenen(void)
	{
		std::cout << "Rekenen Constructor" << std::endl;
	}

	Rekenen::~Rekenen(void)
	{
		std::cout << "Rekenen DeConstructor" << std::endl;
	}

	int Rekenen::add(int x, int y)
	{
		LOG_DEBUG;
		return x + y;
	}
}
