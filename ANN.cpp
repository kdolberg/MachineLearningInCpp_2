#include "ANN.h"
#include "activation_functions.h"
#include "topology.h"
#include <time.h>
#include <stdbool.h>

#ifndef uint
typedef unsigned int uint;
#endif //uint



#ifndef STATIC_RAND
#define SRAND() (srand(time(NULL)))
#else
#define SRAND() (srand(STATIC_RAND))
#endif

/************************************************************************************************************************
                                                    Non-Member Functions
 ************************************************************************************************************************/

void assign_relu(net_t& n) {
	n.af.resize(n.wb.size());
	for (uint i = 0; i < n.af.size(); ++i) {
		n.af[i] = get_relu();
	}
}

void make_net(net_t& n, const std::vector<uint>& def) {
	std::vector tmp_def(def.cbegin()+1,def.cend());
	make_topology(n.wb,tmp_def);
	assert(n.wb.size()+1==def.size());
	for (uint i = 0; i < n.wb.size(); ++i) {
		allocate_ws(n.wb[i],def[i]);
	}
	assign_relu(n);
	n.learning_rate = 0.1;
}

scalar_datum_t random_scalar() {
	static bool is_first_time = true;
	if(is_first_time) {
		SRAND();
		is_first_time = false;
	}
	return ((1.0*rand()/(1.0*RAND_MAX))-0.5);
}

static void randomize_node(node_wb_t& n) {
	n.b = random_scalar();
	for (uint i = 0; i < n.w.size(); ++i) {
		n.w[i] = random_scalar();
	}
}

static void allocate_ws(node_wb_t& n, uint num_weights) {
	n.w.resize(num_weights);
	randomize_node(n);
}

static void allocate_ws(layer_wb_t& l,uint num_weights) {
	for (uint i = 0; i < l.size(); ++i) {
		allocate_ws(l[i],num_weights);
	}
}

/************************************************************************************************************************
                                                    ANN Member Functions
 ************************************************************************************************************************/

ANN::set_learning_rate(scalar_datum_t rate) {
	this->net.learning_rate = rate;
}

ANN::learn() {
	forpropagate(this->net,this->fdata);
	backpropagate(this->net,this->fdata,this->bdata);
	/**
	 * TODO: Add a step here to calculate the gradient from the partial derivatives and update the weights and biases.
	 */
}