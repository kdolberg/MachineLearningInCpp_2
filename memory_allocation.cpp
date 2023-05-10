#include "datatypes.h"
#include <iostream>
#include <assert.h>

uint net_num_inputs(const net_t& net) {
    return net.wb[0][0].w.size();
}

static uint get_dataset_size(const xy_dataset_t& data) {
    assert(data.x_data.size()==data.y_data.size());
    return data.x_data.size();
}

static uint net_num_outputs(const net_wb_t& wb) {
    return wb[wb.size()-1].size();
}

uint net_num_outputs(const net_t& net) {
    return net_num_outputs(net.wb);
}

uint layer_num_outputs(const net_t& net, uint layer_ind) {
    return net.wb[layer_ind].size();
}

static void allocate_cache_memory(const net_t& net, net_all_data_cache_t& cache) {
    uint dataset_size = net.training_dataset->x_data.size();
    assert(dataset_size==net.training_dataset->y_data.size());
    cache.f.layer_io.resize(net.wb.size()+1);
    cache.f.act.resize(net.wb.size());
    cache.f.derivs.resize(net.wb.size());
    cache.b.naive_partials.resize(net.wb.size());
    cache.b.real_partials.resize(net.wb.size());
}

static void allocate_dataset_memory(vector_data_t& data,uint num_scalars_per_datum,uint dataset_size) {
    data.resize(dataset_size);
    for (uint i = 0; i < dataset_size; ++i) {
        data[i].resize(num_scalars_per_datum);
    }
}

xy_dataset_t make_xy_dataset(uint num_inputs,uint num_outputs,uint dataset_size) {
    xy_dataset_t ret;
    allocate_dataset_memory(ret.x_data,num_inputs,dataset_size);
    allocate_dataset_memory(ret.y_data,num_outputs,dataset_size);
    return ret;
}

net_all_data_cache_t add_training_dataset(net_t& net,const xy_dataset_t& data) {
    net.training_dataset = &data;
    net_all_data_cache_t ret;
    allocate_cache_memory(net,ret);
    return ret;
}