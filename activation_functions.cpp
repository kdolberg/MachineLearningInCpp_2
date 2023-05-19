#include "activation_functions.h"

static scalar_datum_t ddxReLU(scalar_datum_t x){
	if (x>0) {
		return 1.0;
	} else {
		return 0.1;
	}
}

static scalar_datum_t ReLU(scalar_datum_t x){
	return x*ddxReLU(x);
}

activation_function_t get_relu() {
	activation_function_t ret = {&ReLU,&ddxReLU};
	return {&ReLU,&ddxReLU};
}

scalar_data_t for_each(const function_t * f, const scalar_data_t& x) {
	scalar_data_t ret(x.size());
	for (uint i = 0; i < x.size(); ++i) {
		ret[i] = f(x[i]);
	}
	return ret;
}

std::vector<scalar_data_t> for_each(const function_t * f,const std::vector<scalar_data_t>& x) {
	std::vector<scalar_data_t> ret(x.size());
	for (uint i = 0; i < x.size(); ++i) {
		ret[i] = for_each(f,x[i]);
	}
	return ret;
}