/**
 * @filename propagation.cpp
 * @author Kris Dolberg
 */

#include "propagation.h"
#include "topology.h"
#include "overloads.h"
#include "activation_functions.h"
#include "memory_allocation.h"

void forwardpropagate(const net_t& net,net_forward_data_cache_t& fdata) {
    assert(fdata.layer_io.size()==(net.wb.size()+1));
    fdata.layer_io[0] = net.training_dataset->x_data;//Add raw input data to the cache
    for (uint layer_ind = 0; layer_ind < net.wb.size(); ++layer_ind) {//Iterate over each layer
        fdata.act[layer_ind] = net.wb[layer_ind]*fdata.layer_io[layer_ind];//Calc. the activation values for this layer
        fdata.layer_io[layer_ind+1] = for_each(net.af[layer_ind].func,fdata.act[layer_ind]);//Calc. outputs for this layer
        fdata.derivs[layer_ind] = for_each(net.af[layer_ind].deriv_func,fdata.act[layer_ind]);//Calc. derivatives of outputs for this layer
    }
}

void backpropagate(const net_t& net, const net_forward_data_cache_t& fdata, net_back_data_cache_t& bdata) {
    for (uint layer_ind = net.wb.size()-1; layer_ind < net.wb.size(); --layer_ind) {
        
    }
}