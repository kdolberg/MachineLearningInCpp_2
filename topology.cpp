#include "topology.h"

template <typename T>
Topology<T>::Topology(const uint * definition, uint length) {
	this->resize(length);
	for (uint i = 0; i < this->size(); ++i) {
		(*this)[i].resize(definition[i]);
	}
}

template <typename T>
Topology<T>::Topology(const std::vector<uint> definition) : Topology(definition.data(),definition.size()) {}

template <typename T>
Topology<T>::~Topology() {}