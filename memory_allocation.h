#include "propagation.h"
#include "topology.h"
// #include <iostream>
#include "../CppUtilities/vec_overload.h"

xy_dataset_t make_xy_dataset(uint num_inputs,uint num_outputs,uint dataset_size);

uint net_num_outputs(const net_t& net);

uint net_num_inputs(const net_t& net);

net_all_data_cache_t add_training_dataset(net_t& net,const xy_dataset_t& data);