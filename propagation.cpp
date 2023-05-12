/**
 * @filename propagation.cpp
 * @author Kris Dolberg
 */

#include "propagation.h"
#include "topology.h"
#include "overloads.h"
#include "activation_functions.h"
#include "memory_allocation.h"

scalar_datum_t sum(const scalar_datum_t& x) {
    return x;
}

template <typename U>
U sum(const std::vector<U>& v) {
    U ret = v[0];
    for (uint i = 1; i < v.size(); ++i) {
        ret += v[i];
    }
    return ret;
}

void forpropagate(const net_t& net,net_for_data_cache_t& fdata) {
    assert(fdata.layer_io.size()==(net.wb.size()+1));
    fdata.layer_io[0] = net.training_dataset->x_data;//Add raw input data to the cache
    for (uint layer_ind = 0; layer_ind < net.wb.size(); ++layer_ind) {//Iterate over each layer
        fdata.act[layer_ind] = net.wb[layer_ind]*fdata.layer_io[layer_ind];//Calc. the activation values for this layer
        fdata.layer_io[layer_ind+1] = for_each(net.af[layer_ind].func,fdata.act[layer_ind]);//Calc. outputs for this layer
        fdata.derivs[layer_ind] = for_each(net.af[layer_ind].deriv_func,fdata.act[layer_ind]);//Calc. derivatives of outputs for this layer
    }
}

vector_data_t error(const vector_data_t& s, const vector_data_t& y) {
    uint N = s.size();
    assert(N==y.size());
    return (s-y)*(s-y);
}

vector_data_t derror(const vector_data_t& s, const vector_data_t& y) {
    uint N = s.size();
    assert(N==y.size());
    return 2*(s-y);
}

void backpropagate(const net_t& net, const net_for_data_cache_t& fdata, net_back_data_cache_t& bdata) {
    for (uint layer_ind = net.wb.size()-1; layer_ind < net.wb.size(); --layer_ind) {
    }
}