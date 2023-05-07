#ifndef TOPOLOGY_H
#define TOPOLOGY_H

#include <vector>
#include <iostream>

#define NUM_INPUT_LAYERS 1

typedef unsigned int uint;

/** @brief A class template for a neural network, and all sorts of data associated with it.
 * 
 */
template <class T>
class Topology<T> : public std::vector<std::vector<T>> {
public:
	Topology(const uint * definition, uint length);
	Topology(const std::vector<uint> definition);
	~Topology();
};

// template <typename T>
// std::ostream& operator<<(std::ostream& os,const Topology<double>& t) {
// 	for (Topology<double>::const_iterator i = t.cbegin(); i != t.cend(); ++i) {
// 		os << "{"
// 		for (std::vector<double>::const_iterator j = i->cbegin(); j != i->cend(); ++j) {
// 			os << " " << *j << " ";
// 		}
// 		os << "}\n";
// 	}
// 	return os;
// }

#endif


#ifndef TOPOLOGY_H
#define TOPOLOGY_H

#include <vector>
#include <iostream>
#define NUM_INPUT_LAYERS 1
typedef unsigned int uint;

template <typename T>
class Topology : public std::vector<std::vector<T>> {
public:
    Topology(const uint *definition, uint length);
    Topology(const std::vector<uint> definition);
    ~Topology();
    // Other member functions and data members
};

#endif // TOPOLOGY_H
