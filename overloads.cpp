#include <iostream>
#include <vector>
#include <stdbool.h>
#include <assert.h>

#include "overloads.h"

scalar_datum_t operator*(const node_wb_t& n, const vector_datum_t& input) {
	assert(n.w.size()==input.size());
	scalar_datum_t ret = n.b;
	for (uint32_t i = 0; i < n.w.size(); ++i) {
		ret += n.w[i]*input[i];
	}
	return ret;
}

vector_datum_t operator*(const layer_wb_t& l, const vector_datum_t& input) {
	vector_datum_t ret(l.size());
	for (uint node_index = 0; node_index < l.size(); ++node_index) {
		ret[node_index] = l[node_index]*input;
	}
	return ret;
}

vector_data_t operator*(const layer_wb_t& l, const vector_data_t& input) {
	vector_data_t ret(input.size());
	for (uint data_index = 0; data_index < input.size(); ++data_index) {
		ret[data_index] = l*input[data_index];
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

std::ostream& operator<<(std::ostream& os, const net_wb_t& wb) {
	for (uint i = 0; i < wb.size(); i++) {
		os << i << ": " << wb[i] << std::endl;
	}
	return os;
}

std::ostream& operator<<(std::ostream& os, const net_t& net) {
	os << net.wb;
	return os;
}

std::ostream& operator<<(std::ostream& os, const xy_dataset_t& xy) {
	assert(xy.x_data.size()==xy.y_data.size());
	for (uint i = 0; i < xy.x_data.size(); ++i) {
		os << i << ": " << "x" << xy.x_data[i] << " y" << xy.y_data[i] << std::endl;
	}
	return os;
}

net_wb_t& operator+=(net_wb_t& net, const gradient_t& grad) {
	net+=((net_wb_t)grad);
	return net;
}

net_t& operator+=(net_t& net, const gradient_t& grad) {
	net.wb+=grad;
	return net;
}