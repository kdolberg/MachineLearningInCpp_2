/**
 * @filename propagation.h
 * @brief Functions used in forward and backpropagation
 * @author Kris Dolberg
 */

#ifndef PROPAGATION_H
#define PROPAGATION_H

#include "datatypes.h"

#define MAKE_VECTORS_SAME_SIZE(dest_,src_) (dest_).resize((src_).size())

/**
 * @brief Allocates the same number of memory spots for dest as there are in src
 * @param dest The node-shaped object to be formatted/memallocated
 * @param src The node-shaped object whose format will be copied
 */
template <typename U, typename T>
void node_shape_allocate(node_shape_s<std::vector<U>> dest,const node_shape_s<std::vector<T>>& src) {
    MAKE_VECTORS_SAME_SIZE(dest.b,src.b);
    MAKE_VECTORS_SAME_SIZE(dest.w,src.w);
    for (uint i = 0; i < dest.w.size(); ++i) {
        MAKE_VECTORS_SAME_SIZE(dest.w[i],src.w[i]);
    }
}

template <typename U, typename T>
void make_wb_topology(std::vector<std::vector<node_shape_s<U>>>& u,const std::vector<std::vector<node_shape_s<T>>>& t) {
    make_topology(u,t);
    for (uint i = 0; i < u.size(); ++i) {
        for (uint j = 0; j < u[i].size(); ++j) {
            node_shape_allocate(u[i][j],t[i][j]);
        }
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
 * @param fdata Forward propagation data cache previously calculated using forwardpropagate
 * @param bdata Data cache for all outputs during this process.
 */
void backpropagate(const net_t& net, const net_forward_data_cache_t& fdata, net_back_data_cache_t& bdata);

#endif