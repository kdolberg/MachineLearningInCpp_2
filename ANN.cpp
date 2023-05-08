#include "ANN.h"

#ifndef uint
typedef unsigned int uint;
#endif //uint

static void allocate_ws(node_wb_t& n, uint num_weights) {
	n.w.resize(num_weights);
}

static void allocate_ws(layer_wb_t& l,uint num_weights) {
	for (uint i = 0; i < l.size(); ++i) {
		allocate_ws(l[i],num_weights);
	}
}

void ANN::make_net(net_t& n, const std::vector<uint>& def) {
	std::vector tmp_def(def.cbegin()+1,def.cend());
	make_topology(n.wb,tmp_def);
	assert(n.wb.size()+1==def.size());
	for (uint i = 0; i < n.wb.size(); ++i) {
		allocate_ws(n.wb[i],def[i]);
	}
}