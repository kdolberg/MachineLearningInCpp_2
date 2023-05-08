/**
 * @file data.h
 * @brief Defines the various types of data that are used as inputs and outputs by nodes, layers, nets, etc.
 */

#ifndef DATA_H
#define DATA_H

/**
 * @brief The basic unit of information in this project.
 */
typedef double scalar_datum_t;

/**
 * @brief The basic IO vector for layers. Also the basic input vector for nodes.
 */
typedef std::vector<scalar_datum_t> vector_datum_t;

/**
 * @brief A whole bunch of scalars. Identical in structure to a vector_datum_t, but serves a different purpose. 
 */
typedef std::vector<scalar_datum_t> scalar_data_t;

/**
 * @brief Stores the input or output dataset for a single layer.
 * Used as input for a layer, input for a node, or output for a layer.
 * Note that this is NOT the output for a node.
 */
typedef std::vector<vector_datum_t> vector_data_t;

/**
 * @brief Template for anything with the topology of a node.
 */
template<typename T>
struct node_shape_s{
    T b;
    std::vector<T> w;
};

/**
 * @brief Partial derivatives for the weights and biases of a particular node
 */
typedef node_shape_s<std::vector<scalar_datum_t>> node_partial_derivatives_t;

/**
 * @brief Partial derivatives for the weights and biases of a layer
 */
typedef std::vector<node_partial_derivatives_t> layer_partial_derivatives_t;

/**
 * @brief Partial derivatives for the weights and biases of a net.
 */
typedef std::vector<layer_partial_derivatives_t> net_partial_derivatives_t;

/**
 * @brief A dataset formatted for a neural network to train on it.
 * Each vector_datum_t (elements of the two vectors in the struct) is one discrete datapoint. 
 */
typedef struct {
    /**
     * @brief Serves as input for the input layer at the start of training.
     */
    vector_data_t x_data;
    /**
     * @brief Compared to the output of the output layer for use in the error function.
     */
    vector_data_t y_data;
} xy_dataset_t;

/**
 * @brief Contains the INPUT data for each layer in a net.
 */
typedef std::vector<vector_data_t> net_layer_input_data_t;

#endif