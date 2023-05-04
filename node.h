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

template<typename T>
struct node_shape_s{
	T b;
	std::vector<T> w;
};

/**
 * The weights and bias of a particular node.
 */
typedef node_shape_s<scalar_t> node_wb_t;

/**
 * Partial derivatives for the weights and biases of a particular node (for one input datum)
 */
typedef node_shape_s<scalar_t*> node_naive_partial_derivative_pointers_t;

typedef struct {
	scalar_t * node_output;
	node_naive_partial_derivative_pointers_t naive_partials;
} node_forwardpropagation_output_t;

typedef scalar_t scalar_function_t(scalar_t);

/**
 * Activation function for a node.
 */
typedef struct {
	scalar_function_t func;
	scalar_function_t deriv_func;
} node_activation_function_t;

/**
 * Glues together the elements of a node
 */
typedef struct node_t {
	node_activation_function_t * activation_function;
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