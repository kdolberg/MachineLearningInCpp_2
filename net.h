/**
 * @file net.h
 * @brief Defines the basic structs and typedefs for layers, nodes, nets, etc.
 */

#ifndef NODE_H
#define NODE_H

//Includes
#include<stdint.h>
#include<stdbool.h>
#include<vector>
#include<list>

//Homebrewed includes
#include "topology.h"
#include "data.h"

/**
 * @brief The weights and bias of a particular node.
 */
typedef node_shape_s<scalar_datum_t> node_wb_t;

/**
 * @brief Activation function for a node.
 */
typedef scalar_datum_t scalar_function_t(scalar_datum_t);

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
typedef std::vector<std::vector<node_activation_function_t>> net_activation_functions_t;

/**
 * @brief Weights and biases for a particular layer.
 */
typedef std::vector<node_wb_t> layer_wb_t;
/**
 * @brief Weights and biases used in a particular net. Can also be used as a gradient.
 */
typedef std::vector<layer_wb_t> net_wb_t;

/**
 * @brief Weights, biases, and activation functions of a net.
 * This struct is intended to include all information in a neural net that can remain const during back and forward propagation.
 */
typedef struct {
	/**
	 * @brief Weights and biases in each node
	 */
	net_wb_t wb;
	/**
	 * @brief Activation functions for each node.
	 */
	net_activation_functions_t af;
	/**
	 * @brief Pointer to training dataset
	 */
	const xy_dataset_t * training_dataset;
} net_t;

/**
 * @brief Neural net data that cannot remain const during back and forward propagation.
 */
typedef struct {
	/**
	 * @brief Naive partial derivatives calculated during forward propagation (?).
	 */
	net_partial_derivatives_t naive_partials;
	/**
	 * Real partial derivatives calculated during backpropagation
	 */
	net_partial_derivatives_t real_partials;
	/**
	 * Intermediate inputs between each layer calculated during forward propagation.
	 */
	net_layer_input_data_t layer_inputs;
} net_data_cache_t;

#endif