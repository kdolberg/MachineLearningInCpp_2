#include "activation_functions.h"

static scalar_datum_t ddxReLU_scalar(scalar_datum_t x){
	if (x>0) {
		return 1.0;
	} else {
		return 0.1;
	}
}

static scalar_datum_t ReLU_scalar(scalar_datum_t x){
	return x*ddxReLU_scalar(x);
}

scalar_data_t ReLU(scalar_data_t x){
	scalar_data_t ret(x.size());
	for (uint i = 0; i < x.size(); ++i) {
		ret[i] = ReLU_scalar(x[i]);
	}
	return ret;
}
scalar_data_t ddxReLU(scalar_data_t x){
	scalar_data_t ret(x.size());
	for (uint i = 0; i < x.size(); ++i) {
		ret[i] = ddxReLU_scalar(x[i]);
	}
	return ret;
}

node_activation_function_t get_relu() {
	return {&ReLU,&ddxReLU};
}