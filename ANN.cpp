#include "ANN.h"
#include <time.h>

#ifndef uint
typedef unsigned int uint;
#endif //uint

#include <stdbool.h>

/**
 * @brief Produces a random scalar_datum_t between -0.5 and 0.5
 */
scalar_datum_t random_scalar() {
	static bool is_first_time = true;
	if(is_first_time) {
		srand(time(NULL));
	}
	is_first_time = false;
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

void make_net(net_t& n, const std::vector<uint>& def) {
	std::vector tmp_def(def.cbegin()+1,def.cend());
	make_topology(n.wb,tmp_def);
	assert(n.wb.size()+1==def.size());
	for (uint i = 0; i < n.wb.size(); ++i) {
		allocate_ws(n.wb[i],def[i]);
	}
}