/**
 * @file net.h
 * @brief
 */

#ifndef NODE_H
#define NODE_H

#include<stdint.h>
#include<stdbool.h>
#include<vector>
#include<list>
#include "topology.h"
#include "data.h"

/**
 * @brief The weights and bias of a particular node.
 */
typedef node_shape_s<scalar_t> node_wb_t;

/**
 * @brief Activation function for a node.
 */
typedef scalar_t scalar_function_t(scalar_t);

/**
 * @brief Activation function for a node.
 */
typedef struct {
	scalar_function_t func;
	scalar_function_t deriv_func;
} node_activation_function_t;

/**
 * @brief All activation functions used in a particular net.
 */
typedef std::vector<std::vector node_activation_function_t> net_activation_functions_t;
/**
 * @brief Weights and biases used in a particular net.
 */
typedef std::vector<std::vector<node_wb_t>> net_wb_t;

typedef struct {
	net_wb_t wb;
	net_activation_functions_t af;
} net_t;

#endif