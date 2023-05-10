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

static void allocate_layer_io_memory(vector_data_t& v,uint num_weights, uint dataset_size) {
    v.resize(dataset_size);
    for (uint i = 0; i < dataset_size; ++i) {
        v[i].resize(num_weights);
    }
}

static void allocate_net_io_memory(net_layer_io_data_t& layer_inputs,const net_t& net, uint dataset_size) {
    layer_inputs.resize(net.wb.size()+1);
    for (uint i = 0; i < net.wb.size(); ++i) {
        allocate_layer_io_memory(layer_inputs[i],net.wb[i][0].w.size(),dataset_size);
    }
    allocate_layer_io_memory(layer_inputs[net.wb.size()],net.wb[net.wb.size()-1].size(),dataset_size);
}

static void allocate_node_partial_derivatives(node_partial_derivatives_t& npd,uint num_weights,uint dataset_size) {
    npd.b.resize(dataset_size);
    npd.w.resize(num_weights);
    for (uint i = 0; i < num_weights; ++i) {
        npd.w[i].resize(dataset_size);
    }
}

static void allocate_layer_partial_derivatives(layer_partial_derivatives_t& lpd,const layer_wb_t& lwb,uint dataset_size) {
    #ifndef NDEBUG
    uint num_weights = lwb[0].w.size();
    #endif //NDEBUG
    lpd.resize(lwb.size());
    for (uint i = 0; i < lwb.size(); ++i) {
        assert(num_weights==lwb[i].w.size());
        allocate_node_partial_derivatives(lpd[i],lwb[i].w.size(),dataset_size);
    }
}

static void allocate_net_partial_derivatives(net_partial_derivatives_t& npd,const net_wb_t& wb,uint dataset_size) {
    npd.resize(wb.size());
    for (uint i = 0; i < wb.size(); ++i) {
        allocate_layer_partial_derivatives(npd[i],wb[i],dataset_size);
    }
}

static void allocate_forward_cache_memory(const net_t& net, net_forward_data_cache_t& fdata, uint dataset_size) {
    allocate_net_io_memory(fdata.layer_io,net,dataset_size);
    allocate_net_partial_derivatives(fdata.naive_partials,net.wb,dataset_size);
}

static void allocate_back_cache_memory(const net_t& net, net_back_data_cache_t& bdata, uint dataset_size) {

}

static void allocate_cache_memory(const net_t& net, net_forward_data_cache_t& fdata, net_back_data_cache_t& bdata) {
    uint dataset_size = net.training_dataset->x_data.size();
    assert(dataset_size==net.training_dataset->y_data.size());
    allocate_forward_cache_memory(net,fdata,dataset_size);
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
    allocate_cache_memory(net,ret.f,ret.b);
    return ret;
}