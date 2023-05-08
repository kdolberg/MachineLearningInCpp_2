#ifndef OVERLOADS_H
#define OVERLOADS_H

#include "datatypes.h"

template<typename T>
std::ostream& operator<<(std::ostream& os,const node_shape_s<T>& wb) {
	assert(wb.w.size()>0);
	os << wb.b << " " << wb.w;
	return os;
}

#endif //OVERLOADS_H