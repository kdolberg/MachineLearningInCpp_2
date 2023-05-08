#include <iostream>
#include <vector>
#include <stdbool.h>
#include <assert.h>

#include "datatypes.h"

std::vector<scalar_datum_t> for_each_scalar(const scalar_function_t& af,const std::vector<scalar_datum_t>& input) {
	std::vector<scalar_datum_t> ret(input.size());
	for (uint32_t i = 0; i < input.size(); ++i) {
		ret[i] = af(input[i]);
	}
	return ret;
}

scalar_datum_t operator*(const node_wb_t& n, const vector_datum_t& input) {
	assert(n.w.size()==input.size());
	scalar_datum_t ret = n.b;
	for (uint32_t i = 0; i < n.w.size(); ++i)
	{
		ret += n.w[i]*input[i];
	}
	return ret;
}

std::ostream& operator<<(std::ostream& os, std::vector<scalar_datum_t> v) {
	os << "{";
	for (uint32_t i = 0; i < v.size(); ++i) {
		os << v[i];
		if(i>=v.size()-1){
			os << "}";
		} else {
			os << ", ";
		}
	}
	return os;
}

std::ostream& operator<<(std::ostream& os,const node_wb_t& wb) {
	os << wb.b << " " << wb.w;
	return os;
}

