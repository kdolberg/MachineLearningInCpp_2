#ifndef NODE_H
#define NODE_H

#include<stdint.h>
#include<stdbool.h>
#include<vector>
#include<list>

#define BIAS_INDEX 0
#define FIRST_WEIGHT_INDEX 1

typedef double scalar_t;

/**
 * A single input or output for a layer.
 * Note that the output for an individual node would be a scalar
 */
typedef std::vector<scalar_t> data_vec_t;
typedef std::vector<data_vec_t> dataset_t;

/**
 * The weights and bias of a particular node.
 */
typedef struct{
	uint32_t num_weights;
	scalar_t b;
	scalar_t w[];
}node_wb_t;

typedef scalar_t scalar_function_t(scalar_t);

typedef struct {
	scalar_function_t * func;
	scalar_function_t * deriv_func;
}node_activation_function_t;

/**
 * All signal data that is stored in the node.
 * * Examples:	Input
 * 				Output
 * 				Activation values
 * 				Parial derivatives
 */
typedef struct {
	 activation;
} node_data_cache_t;

/**
 * Glues together the other elements of a node that were defined earlier.
 */
typedef struct node_t{
	/**
	 * Topology pointers
	 */
	node_t * input_nodes;// The nodes whose output is the input for this node. Null if this is an input layer.
	node_t * output_nodes;// The nodes whose input is the output from this node. Null if this is an output layer.

	/**
	 * The mathy structs
	 */
	node_data_cache_t * p_data_cache;
	const node_activation_function_t * activation_function;
	node_wb_t wb;
} node_t;

#endif