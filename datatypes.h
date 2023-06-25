/**
 * @file datatypes.h
 * @brief Defines the basic structs and typedefs for layers, nodes, nets, etc. as well as their respective IO data.
 */

#ifndef DATATYPES_H
#define DATATYPES_H

//Includes
#include<stdint.h>
#include<stdbool.h>
#include<vector>
#include<list>
#include "linear_algebra.h"

namespace MachineLearning {

/************************************************************************************************************************
                                                        IO data types
 ************************************************************************************************************************/

    /**
     * @brief The basic unit of information in this project.
     */
    typedef double scalar_datum_t;

    /**
     * @brief Row in a matrix
     */
    typedef LinearAlgebra::HorizontalVector<scalar_datum_t> row_t;

    /**
     * @brief Column in a matrix
     */
    typedef LinearAlgebra::VecrticalVector<scalar_datum_t> col_t;

    /**
     * @brief Matrix
     */
    typedef LinearAlgebra::Matrix<scalar_datum_t> matrix_t;

    /**
     * @brief Weights and biases for a particular layer.
     */
    typedef struct layer_wb_t{
        matrix_t weights;
        col_t biases;
    } layer_wb_t;

    /**
     * @brief Column vector representing input data for a layer.
     * Interchangeable with layer_out_datum_t.
     */
    typedef col_t layer_in_datum_t;

    /**
     * @brief Column vector representing output data for a lyaer.
     * Interchangeable with layer_in_datum_t.
     */
    typedef col_t layer_out_datum_t;

    typedef std::vector<col_t> col_data_t;

    typedef col_data_t layer_out_data_t;

    typedef col_data_t layer_in_data_t;

    /**
     * @brief Activation function for a node.
     */
    typedef scalar_datum_t function_t(scalar_datum_t);

    /**
     * @brief Activation function for a node.
     * @param func Activation function
     * @param deriv_func Activation function derivative
     */
    typedef struct {
        function_t * func;
        function_t * deriv_func;
        activation_function_t operator++() {
            return {this->deriv_func,this->func};
        }
    } activation_function_t;

    /**
     * @brief A dataset formatted for a neural network to train on it.
     * Each vector_datum_t (elements of the two vectors in the struct) is one discrete datapoint. 
     * @param y_data Compared to the output of the output layer for use in the error function.
     */
    typedef struct {
        /**
         * @brief Serves as input for the input layer at the start of training.
         */
        vector_data_t x_data;
        /**
         * @brief 
         */
        vector_data_t y_data;
    } xy_dataset_t;
}

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
 * @brief Partial derivatives for the weights and biases of a particular node
 */
typedef node_shape_s<scalar_data_t> node_partial_derivatives_t;

/**
 * @brief Partial derivatives for the weights and biases of a layer
 */
typedef std::vector<node_partial_derivatives_t> layer_partial_derivatives_t;

/**
 * @brief Partial derivatives for the weights and biases of a net.
 */
typedef std::vector<layer_partial_derivatives_t> net_partial_derivatives_t;

/**
 * @brief Contains the INPUT data for each layer in a net.
 */
typedef std::vector<vector_data_t> net_layer_io_data_t;

/**
 * @brief Neural net data that cannot remain const during forpropagation.
 */
typedef struct {
    /**
     * @brief Partial derivatives of base values calculated during forward propagation (?).
     */
    net_layer_io_data_t derivs;
    /**
     * @brief Intermediate inputs between each layer calculated during forward propagation.
     */
    net_layer_io_data_t layer_io;

    /**
     * @brief Activation data used to calculate IO data and derivatives.
     */
    net_layer_io_data_t act;
} net_for_data_cache_t;

/**
 * @brief Neural net data that cannot remain const during backpropagation.
 */
typedef struct {
    net_partial_derivatives_t prelim_partials;
    /**
     * @brief Real partial derivatives calculated during backpropagation
     */
    net_partial_derivatives_t real_partials;
} net_back_data_cache_t;

typedef struct {
    net_for_data_cache_t f;
    net_back_data_cache_t b;
} net_all_data_cache_t;

/************************************************************************************************************************
                                            Structural Neural Net Datatypes
 ************************************************************************************************************************/



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
	 * @brief The learning rate
	 */
	scalar_datum_t learning_rate;
	/**
	 * @brief Weights and biases in each node
	 */
	net_wb_t wb;
	/**
	 * @brief Activation functions for each node.
	 */
	std::vector<activation_function_t> af;
	/**
	 * @brief Pointer to training dataset
	 */
	const xy_dataset_t * training_dataset;

    /**
     * @brief Vector originally used to define the net
     */
    std::vector<uint> def;
} net_t;

typedef net_wb_t gradient_t;

#endif