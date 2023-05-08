#ifndef PROPAGATION_H
#define PROPAGATION_H

#include "net.h"

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