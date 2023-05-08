#include <iostream>
#include <vector>
#include "net.h"
#include "../CppUtilities/vec_overload.h"

int main(int argc, char const *argv[]) {
	std::vector<uint> a = {1,2,3,4};
	std::vector<std::vector<double>> vec = make_topology<double>(a);
	std::cout << vec;

	// std::cout << "The output of the overloaded operator is: " << vec.get(i);

	return 0;
}