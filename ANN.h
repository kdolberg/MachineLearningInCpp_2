/**
 * @file ANN.h
 * @brief Defines the ANN class
 * @author Kris Dolberg
 */

#ifndef ANN_H
#define ANN_H

#include "propagation.h"
#include "topology.h"

/**
 * @brief Class that provides the bevaviour of a neural network
 */
class ANN {
private:
	net_t net;
	net_forward_data_cache_t forward_data;
	net_back_data_cache_t back_data;
public:
	ANN(unsigned int inputs, std::vector<unsigned int> def);
	~ANN();
	/**
	 * Saves the xy_dataset in the net.
	 */
	void load_training_data(const xy_dataset_t& dataset);
	/**
	 * @brief Performs one iteration of forward and backpropagation on the current xy_dataset_t
	 */
	void learn();
private:
	/**
	 * @brief Allocates memory for the back and forward data caches.
	 */
	void initialize_data_caches();
};

#endif