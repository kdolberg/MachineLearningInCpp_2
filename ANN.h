/**
 * @file ANN.h
 * @brief Defines the ANN class
 * @author Kris Dolberg
 */

#ifndef ANN_H
#define ANN_H

#include "propagation.h"

/**
 * @brief Produces a random scalar_datum_t between -0.5 and 0.5
 */
scalar_datum_t random_scalar();

/**
 * @brief Initializes a net_t object
 * @param n The net to be formatted
 * @param def The definition of the net
 */
void make_net(net_t& n, const std::vector<uint>& def);

/**
 * @brief Class that provides the bevaviour of a neural network
 */
class ANN {
private:
	/**
	 * @brief Struct containing all net-related data that can remain const during forpropagation and backpropagation.
	 */
	net_t net;
	/**
	 * @brief Cache for data produced during forward propagation.
	 * Remains const during backpropagation.
	 */
	net_for_data_cache_t fdata;
	/**
	 * @brief Cache for data produced during backpropagation.
	 * Remains const during forpropagation.
	 */
	net_back_data_cache_t bdata;
public:
	ANN(unsigned int inputs, std::vector<unsigned int> def);
	~ANN();
	/**
	 * @brief Saves the xy_dataset in the net.
	 * @param dataset Dataset to be loaded
	 */
	void load_training_data(const xy_dataset_t& dataset);
	/**
	 * @brief Performs one iteration of forward and backpropagation on the current xy_dataset_t
	 */
	void learn();

	/**
	 * @brief Sets the learning rate.
	 * @param rate The new learning rate.
	 */
	void set_learning_rate(scalar_datum_t rate);
};

#endif