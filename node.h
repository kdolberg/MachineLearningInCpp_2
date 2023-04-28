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

/**
 * Used as input for a layer, input for a node, or output for a layer.
 * Note that this is NOT the output for a node.
 * 
 * This is a struct in part so that we can easily add any other bits of information that turn out to be needed.
 */
typedef struct{
	layer_io_datum_t data;
	/*Add other bits of data (activation values, partial derivatives), when you know what they'll look like*/
}layer_data_cache_t;

typedef struct {
	/**
	 * This struct will be present in all nodes. There will be a pointer to the corresponding elements in the 
	 * layer_data_cache_t
	 */
} node_output_cache_t;

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
 * Glues together the other elements of a node that were defined earlier.
 */
typedef struct node_t{
	/**
	 * Topology pointers
	 */
	node_t * input_nodes;// The nodes whose output is the input for this node. Null if this is an input layer.
	node_t * output_nodes;// The nodes whose input is the output from this node. Null if this is an output layer.

	/**
	 * Mathy structs
	 */
	const layer_data_cache_t * input;
	node_output_cache_t output;
	const node_activation_function_t * activation_function;
	node_wb_t wb;
} node_t;

#endif