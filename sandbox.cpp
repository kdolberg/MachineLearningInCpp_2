#include "node.h"

std::list<layer_t> make_net(){
	std::list<layer_t> ret;


}

void forwardpropagate(const node_t& n,const layer_io_datum_t& input, scalar_t& out, node_naive_partial_derivatives_t& partials){
	scalar_t activation = n.wb*input;
	out = n.activation_function.func(activation);
	
}