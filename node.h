#ifndef NODE_H
#define NODE_H

#include<stdint.h>
#include<stdbool.h>
#include<vector>
#include<list>

#define BIAS_INDEX 0
#define FIRST_WEIGHT_INDEX 1

typedef double scalar_t;
typedef std::vector<scalar_t> layer_io_datum_t;
typedef std::vector<layer_io_datum_t> layer_io_data_t;

/**
 * Used as input for a layer, input for a node, or output for a layer.
 * Note that this is NOT the output for a node.
 * 
 * This is a struct in part so that we can easily add any other bits of information that turn out to be needed.
 */
typedef struct {
	layer_io_data_t data;
	/*Add other bits of data (activation values, partial derivatives), when you know what they'll look like*/
} layer_data_cache_t;

typedef scalar_t bias_t;
typedef std::vector<scalar_t> weights_t;
/**
 * The weights and bias of a particular node.
 */
typedef struct {
	bias_t b;
	weights_t w;
} node_wb_t;

typedef std::vector<scalar_t*> node_output_t;

/**
 * Partial derivatives of the weights and bias of a particular node.
 */
typedef struct {
	node_output_t b;
	std::vector<node_output_t> w;
} node_partial_derivatives_t;

/**
 * Contains pointers to all io data that nodes need to do their node things
 */
typedef struct {
	//Raw inputs for the node, the output from the previous layer
	layer_io_data_t * my_input;
	//Input from the next layer, the partial derivatives used to calculate this node's partial derivatives (will use the b partials only)
	node_partial_derivatives_t * next_layer_partial_derivatives;

	//Outputs for this node
	node_output_t my_output;
	node_partial_derivatives_t my_partial_derivatives;
} node_data_cache_t;

typedef scalar_t scalar_function_t(scalar_t);

/**
 * Activation function for a node.
 */
typedef struct {
	scalar_function_t func;
	scalar_function_t deriv_func;
} node_activation_function_t;

/**
 * Glues together the other elements of a node that were defined earlier.
 */
typedef struct node_t {
	/**
	 * Mathy structs
	 */
	node_data_cache_t * data_cache;
	const node_activation_function_t * activation_function;
	node_wb_t wb;
} node_t;

typedef struct {
	std::vector<node_t> nodes;
	layer_data_cache_t data_cache;
} layer_t;

/**
 * A dataset formatted for a neural network to train on it.
 */
typedef struct {
	layer_io_data_t x_data;
	layer_io_data_t y_data;
} xy_dataset_t;

#endif