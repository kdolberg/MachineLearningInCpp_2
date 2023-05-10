/**
 * @file topology.h
 * @brief Provides function templates for making 2-D vectors that have consistent 
 * topologies irrespective of the data they contain.
 */

#ifndef TOPOLOGY_H
#define TOPOLOGY_H

#include <vector>
#include <assert.h>
#include <iostream>
#include "../CppUtilities/vec_overload.h"
#include "overloads.h"
#include "datatypes.h"

#ifndef uint
typedef unsigned int uint;
#endif

/**
 * @brief Non-recursively resizes u to be the same size as t
 * @param u Destination vector
 * @param t Source vector
 */
template <typename U,typename T>
void copy_1d_topology(std::vector<U>& u,const std::vector<T>& t) {
	u.resize(t.size());
}

/**
 * @brief Dummy function. Does nothing.
 * @param u Does nothing
 * @param t Does nothing
 */
template <typename U,typename T>
void copy_topology(const U& u,const T& t) {
    std::cout << u << std::endl;
    std::cout << t << std::endl;
}
// template <typename U,typename T>
// void copy_topology(const node_shape_s<U>& u,const T& t) {}
// template <typename U,typename T>
// void copy_topology(const U& u,const node_shape_s<T>& t) {}

/**
 * @brief Recursively copies the dimensions of two arbitrarily-dimensioned arrays
 * @param u Destination vector
 * @param t Source vector
 * @param new_size Optional.
 */
template <typename U,typename T>
void copy_topology(std::vector<U>& u,const std::vector<T>& t) {
	copy_1d_topology(u,t);
	for (uint i = 0; i < u.size(); ++i) {
		copy_topology(u[i],t[i]);
	}
}

/**
 * @brief Function template that provides the ability to format any arbitrary 2-D vector.
 * @param top Reference to a previously-initialized std::vector<std::vector<T>> to be formatted.
 * @param def Vector specifiying the length of each sub-vector.
 */
template <typename T>
void make_topology(std::vector<std::vector<T>>& top,const std::vector<uint>& def) {
	copy_1d_topology(top,def);
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