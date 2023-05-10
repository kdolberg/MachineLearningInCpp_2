#ifndef OVERLOADS_H
#define OVERLOADS_H

#include "datatypes.h"
#include "../CppUtilities/vec_overload.h"

template<typename T>
std::ostream& operator<<(std::ostream& os,const node_shape_s<T>& wb) {
	os << wb.b << " " << wb.w;
	return os;
}

std::ostream& operator<<(std::ostream& os, const net_wb_t& wb);

std::ostream& operator<<(std::ostream& os, const net_t& net);

#endif //OVERLOADS_H