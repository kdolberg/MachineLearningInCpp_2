#include "propagation.h"
/**
 * @filename propagation.cpp
 * @author Kris Dolberg
 */

void make_wb_topology(const net_wb_t& wb, )

/**
 * @brief Allocates memory for a forward data cache struct based on net
 * @param net The neural network that will be using this data cache
 * @param fdata The forward data cache struct whose memory will be allocated 
 */
void allocate_forward_data_cache_memory(const net_t& net, net_forward_data_cache_t& fdata, net_back_data_cache_t& bdata) {
    make_topology(fdata.layer_io,net);
    make_topology(fdata.naive_partials,net);
    for (uint i = 0; i < wb.size(); ++i) {
        
    }
}

void allocate_back_data_cache_memory(const net_t& net, net_forward_data_cache_t& fdata, net_back_data_cache_t& bdata) {
    make_topology(fdata.layer_io,net);
    make_topology(fdata.naive_partials,net);
    for (uint i = 0; i < wb.size(); ++i) {
        
    }
}

void forwardpropagate(const net_t& net,net_forward_data_cache_t& fdata) {

    /*Some additional memory allocation needed for naive partials*/
    for (uint i = 0; i < net.wb.size(); ++i) {
        net[i]*fdata.layer_io[i];
    }
}

void backpropagate(const net_t& net, const net_forward_data_cache_t& fdata, net_back_data_cache_t& bdata) {
}