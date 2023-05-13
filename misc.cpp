#include "misc.h"
#include "memory_allocation.h"

scalar_datum_t __xor__(uint a, uint b) {
	if ((a && !b) || (!a && b)) {
		return 1.0;
	} else {
		return 0.0;
	}
}

xy_dataset_t make_xor_dataset() {
	xy_dataset_t ret = make_xy_dataset(2,1,4);
	uint data_index = 0;
	for (uint i = 0; i < 2; ++i) {
		for (uint j = 0; j < 2; ++j) {
			ret.x_data[data_index] = {i*1.0,j*1.0};
			ret.y_data[data_index] = {__xor__(i,j)};
			++data_index;
		}
	}
	return ret;
}

uint char2int(const char * arg) {
	uint ret = 0;
	uint N = 0;
	uint order_of_magnitude = 1;
	while(arg[N] >= '0' && arg[N] <= '9') {
		++N;
	}
	for(uint i = 0; i < N; ++i) {
		ret += ((uint)arg[N-1-i] - (uint)'0')*order_of_magnitude;
		order_of_magnitude*=10;
	}
	return ret;
}

std::vector<uint> interpret_args(int _argc, char const *_argv[]) {
	std::vector<uint> ret(_argc-1);
	for (uint i = 1; i < _argc; ++i) {
		ret[i-1] = char2int(_argv[i]);
	}
	return ret;
}