#ifndef MEMORY_ALLOCATION_H
#define MEMORY_ALLOCATION_H

#include "propagation.h"
#include "topology.h"
#include "../Utilities/vector_overloads.h"

/**
 * @brief Allocates memory for a dataset that can be used as training data
 */
xy_dataset_t make_xy_dataset(uint num_inputs,uint num_outputs,uint dataset_size);

/**
 * @brief Returns the number of nodes in the final layer of the given net
 * @param net Neural net
 */
uint net_num_outputs(const net_t& net);

/**
 * @brief Returns the number of nodes in the final layer of the given net
 * @param wb Neural net weights and biases
 */
uint net_num_outputs(const net_wb_t& wb);

/**
 * @brief Returns the number of weights in the nodes (must be the same) of the first layer of the given net
 */
uint net_num_inputs(const net_t& net);

/**
 * @brief Returns the number of weights in the nodes (must be the same) of the first layer of the given net_wb_t
 * @param net_wb_t whose number of inputs is sought
 * @return Number of inputs
 */
uint net_num_inputs(const net_wb_t& wb);

/**
 * @brief Returns the number of nodes in the given layer
 * @param net Net in question
 * @param layer_ind Index of the layer in question
 */
uint layer_num_outputs(const net_t& net, uint layer_ind);

/**
 * @brief Adds the given dataset to the net. Returns a datacache struct with the appropriate memory allocation.
 */
net_all_data_cache_t add_training_dataset(net_t& net,const xy_dataset_t& data);

#endif //MEMORY_ALLOCATION_H