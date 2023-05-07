#ifndef TOPOLOGY_H
#define TOPOLOGY_H

#include <vector>
#include <iostream>
// #include "../CppUtilities/vec_overload.h"

typedef unsigned int uint;
/**
 * @brief Simple class template for neural networks and all data types that must have the same topology.
 */
template <typename T>
class Topology : public std::vector<std::vector<T>> {
public:
	/**
	 * @brief Standard constructor for this class.
	 * @param *definition Defines how many elements are in each sub-array.
	 * @param length Defines the length of the definition array.
	 */
    Topology(const uint *definition, uint length) {
		this->resize(length);
		for (uint i = 0; i < this->size(); ++i) {
			(*this)[i].resize(definition[i]);
	    }
	}
    Topology(const std::vector<uint> definition) : Topology(definition.data(), definition.size()) {}
    ~Topology() {}
};

#endif // TOPOLOGY_H
