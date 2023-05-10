/**
 * @filename propagation.cpp
 * @author Kris Dolberg
 */

#include "propagation.h"
#include "topology.h"
#include "overloads.h"

static void calculate_layer_activation_datum(vector_datum_t& dest,const vector_datum_t& src,const layer_wb_t& wb) {
    assert(dest.size()==wb.size());
    for (uint node_index = 0; node_index < wb.size(); ++node_index) {
        dest[node_index] = wb[node_index]*src;
    }
}

static void calculate_layer_activation_data(vector_data_t& dest,const vector_data_t& src,const layer_wb_t& wb) {
    assert(dest.size()==src.size());
    for (uint datum_index = 0; datum_index < dest.size(); ++datum_index) {
        calculate_layer_activation_datum(dest[datum_index],src[datum_index],wb);
    }
}

void forwardpropagate(const net_t& net,net_forward_data_cache_t& fdata) {
    assert(fdata.layer_io.size()==(net.wb.size()+1));
    fdata.layer_io[0] = net.training_dataset->x_data;
    for (uint i = 0; i < net.wb.size(); ++i) {//Iterate through each layer
        calculate_layer_activation_data(fdata.layer_io[i+1],fdata.layer_io[i],net.wb[i]);
    }
}

void backpropagate(const net_t& net, const net_forward_data_cache_t& fdata, net_back_data_cache_t& bdata) {

}