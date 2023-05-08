#ifndef PROPAGATION_H
#define PROPAGATION_H

#include "datatypes.h"

template <typename U, typename T>
void node_shape_allocate(node_shape_s<U> ns, uint num) {
    ns.b = 
}

template <typename U, typename T>
void make_wb_topology(std::vector<std::vector<node_shape_s<U>>>& u,const std::vector<std::vector<node_shape_s<T>>>& t) {
    make_topology(u,t);
    for (uint i = 0; i < u.size(); ++i) {
        
    }
}

/**
 * @brief Performs a single iteration of forward propagation.
 * @param net The neural net that will be forwardpropagated.
 * @param fdata The forward propagation data cache.
 */
void forwardpropagate(const net_t& net,net_forward_data_cache_t& fdata);

/**
 * @brief Perforforms a single iteration of backpropagation
 * Only works of forwardpropagate has been run on this net first.
 * @param net Neural net that is being backpropagated
 * @param fdata Forward propagation data cache that would have been calculated using forwardpropagate
 * @param bdata Data cache for all outputs during this process.
 */
void backpropagate(const net_t& net, const net_forward_data_cache_t& fdata, net_back_data_cache_t& bdata);

#endif