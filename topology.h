/************************************************************************************************************************
 * 																														*
 * @file topology.h																										*
 * @brief Provides function templates for making 2-D vectors that have consistent topologies irrespective of the data 	*
 * they contain.																										*
 * 																														*
 ************************************************************************************************************************/

#ifndef TOPOLOGY_H
#define TOPOLOGY_H

#include <vector>
#include <assert.h>

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
 * @brief A "stub" function template that does nothing.
 * Supports the other function with the same name. Avoids an error when we get to the end of the recursive arrays.
 */
template <typename U,typename T>
int copy_topology(const U& u,const T& t,uint new_size) {
	assert(new_size==0);
	return 0;
}

/**
 * @brief Non-recursively resizes u to match new_size
 * @param u Vector to be resized
 * @param t Dummy argument. Does nothing
 * @param new_size New size for u 
 */
template <typename U,typename T>
void copy_topology(std::vector<U>& u,const T& t,uint new_size) {
	if(new_size!=0){
		u.resize(new_size);
	}
}

/**
 * @brief Recursively copies the dimensions of two arbitrarily-dimensioned arrays
 * @param u Destination vector
 * @param t Source vector
 * @param new_size Optional.
 */
template <typename U,typename T>
void copy_topology(std::vector<U>& u,const std::vector<T>& t, uint new_size) {
	copy_1d_topology(u,t);
	for (uint i = 0; i < u.size(); ++i) {
		copy_topology(u[i],t[i],new_size);
	}
}

/**
 * @brief Recursively copies the dimensions of two arbitrarily-dimensioned arrays
 * @param u Destination vector
 * @param t Source vector
 */
template <typename U,typename T>
void copy_topology(std::vector<U>& u,const std::vector<T>& t) {
	copy_topology(u,t,0);
}

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