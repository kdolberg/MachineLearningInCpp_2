/**
 * @file topology.h
 * @brief Provides function templates for making 2-D vectors that have consistent topologies irrespective of the data they contain.
 */

#ifndef TOPOLOGY_H
#define TOPOLOGY_H

#include <vector>
#include <cstddef>

#ifndef uint
typedef unsigned int uint;
#endif

/**
 * @brief Function template that provides the ability to format any arbitrary 2-D vector.
 * @param top Reference to a previously-initialized std::vector<std::vector<T>> to be formatted.
 * @param def Vector specifiying the length of each sub-vector.
 */
template <typename T>
void make_topology(std::vector<std::vector<T>>& top,const std::vector<uint>& def) {
	top.resize(def.size());
	for (uint i = 0; i < top.size(); ++i) {
		top[i].resize(def[i]);
	}
}

/**
 * @brief Function template that provides the ability to format any arbitrary 2-D vector.
 * @param top Pointer to a previously-initialized std::vector<std::vector<T>> to be formatted. Assumes memory is allocated.
 * @param def Vector specifiying the length of each sub-vector.
 */
template <typename W>
void make_topology(std::vector<std::vector<W>> * top,const std::vector<uint>& def) {
	assert(top!=NULL);
	make_topology(*top,def);
}

/**
 * @brief Function template that provides the ability to make any arbitrary 2-D vector
 * @param def Vector specifiying the length of each sub-vector.
 */
template <typename U>
std::vector<std::vector<U>> make_topology(const std::vector<uint>& def) {
	std::vector<std::vector<U>> ret;
	make_topology(ret,def);
	return ret;
}

#endif