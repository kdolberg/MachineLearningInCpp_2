#ifndef OVERLOADS_H
#define OVERLOADS_H

#include "datatypes.h"
#include <ostream>
#include <fstream>
#include "../Utilities/vector_overloads.h"

template<typename T>
std::ostream& operator<<(std::ostream& os,const node_shape_s<T>& wb) {
	os << wb.b << " " << wb.w;
	return os;
}

template<typename T>
std::vector<T>& operator+=(std::vector<T>& a, const std::vector<T>& b) {
	assert(a.size()==b.size());
	for (uint i = 0; i < a.size(); ++i) {
		a[i] += b[i];
	}
	return a;
}

template<typename T>
std::vector<T>& operator-=(std::vector<T>& a, const std::vector<T>& b) {
	assert(a.size()==b.size());
	for (uint i = 0; i < a.size(); ++i) {
		a[i] -= b[i];
	}
	return a;
}

template<typename T>
std::vector<T> operator-(const std::vector<T>& a, const std::vector<T>& b) {
	std::vector<T> ret(a.cbegin(),a.cend());
	ret-=b;
	return ret;
}

template<typename T>
node_shape_s<T>& operator+=(node_shape_s<T>& a, const node_shape_s<T>& b) {
	a.w += b.w;
	a.b += b.b;
	return a;
}

template<typename T>
node_shape_s<T>& operator-=(node_shape_s<T>& a, const node_shape_s<T>& b) {
	a.w -= b.w;
	a.b -= b.b;
	return a;
}

template<typename T>
std::vector<T>& operator*=(std::vector<T>& t, const T& b){
	assert(!(t.empty()));
	for (uint i = 0; i < t.size(); ++i) {
		t[i]*=b;
	}
	return t;
}

template<typename T>
std::vector<T>& operator*=(std::vector<T>& a, const std::vector<T>& b) {
	assert(a.size()==b.size());
	for (uint i = 0; i < a.size(); ++i) {
		a[i] *= b[i];
	}
	return a;
}

template<typename T>
std::vector<T> operator*(const std::vector<T>& a, const std::vector<T>& b) {
	std::vector<T> ret(a.cbegin(),a.cend());
	ret *= b;
	return ret;
}

template<typename T>
std::vector<std::vector<T>>& operator*=(std::vector<std::vector<T>>& t, const T& b) {
	assert(!(t.empty()));
	for (uint i = 0; i < t.size(); ++i) {
		t[i]*=b;
	}
	return t;
}

template<typename T>
std::vector<T> operator*(const std::vector<T>& t, const T& b) {
	std::vector<T> ret(t.cbegin(),t.cend());
	ret*=b;
	return ret;
}

template<typename T>
std::vector<std::vector<T>> operator*(const std::vector<std::vector<T>>& t, const T& b) {
	std::vector<std::vector<T>> ret(t.cbegin(),t.cend());
	ret*=b;
	return ret;
}

std::ostream& operator<<(std::ostream& os, const net_wb_t& wb);
std::ostream& operator<<(std::ostream& os, const net_t& net);
std::ostream& operator<<(std::ostream& os, const xy_dataset_t& xy);

scalar_datum_t operator*(const node_wb_t& n, const vector_datum_t& input);
vector_datum_t operator*(const layer_wb_t& l, const vector_datum_t& input);
vector_data_t operator*(const layer_wb_t& l, const vector_data_t& input);

std::fstream& operator<<(std::fstream& os, const net_wb_t& wb);
std::fstream& operator<<(std::fstream& os, const net_t& net);

#endif //OVERLOADS_H