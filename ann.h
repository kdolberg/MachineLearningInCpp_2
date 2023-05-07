#ifndef ANN_H
#define ANN_H

#include "node.h"

/** @brief The default rate at which the neural network learns
 */
#define DEFAULT_LEARNING_RATE 0.01

/** Class that defines the behaviour of an artificial neural network.
 */
class ANN {
private:
	/**
	 * @brief The layers of the neural net.
	 */
	std::list<layer_t> layers;
	/**
	 * @brief The training dataset.
	 */
	xy_dataset_t training_dataset;
	/**
	 * @brief the learning rate.
	 */
	scalar_t learning_rate = DEFAULT_LEARNING_RATE;
public:
	ANN();
	~ANN();

	/**
	 * @brief Loads a new training dataset.
	 * 
	 * Erases previusly-loaded training data.
	 */
	void load_dataset(const xy_dataset_t& new_training_dataset);

	/**
	 * @brief Set the learning rate.
	 */
	void set_learning_rate(scalar_t new_learning_rate);

	/**
	 * @brief Train the neural net on the currently-loaded dataset for one epoch.
	 */
	void train();

	/**
	 * @brief Obtain all of the calculated output data.
	 */
	layer_io_data_t output();

	/**
	 * @brief Get the output datum at a particular index
	 */
	layer_io_datum_t output(uint32_t index);
};

#endif