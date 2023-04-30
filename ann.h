#ifndef ANN_H
#define ANN_H

#include "node.h"

class ANN {
private:
	std::list<layer_t> layers;
	xy_dataset_t training_dataset;
public:
	ANN();
	~ANN();

	/**
	 * Adds a single layer to the net.
	 */
	void add_layer(layer_t l);

	/**
	 * Load a dataset into the input nodes
	 * Erases previusly-loaded training data
	 */
	void load_dataset(const xy_dataset_t& new_training_dataset);

	/**
	 * Train the neural net on the currently-loaded dataset.
	 */
	void train(uint32_t epochs, scalar_t learning_rate);

	/**
	 * Obtain output data that has already been calculated
	 */
	//Get the whole output vector-vector.
	layer_io_data_t output();
	//Get the output datum at a particular index
	layer_io_datum_t output(uint32_t index);
};

#endif