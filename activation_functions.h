/**
 * @file activation_functions.h
 * @brief Activation functions available in this library
 */

#ifndef ACTIVATION_FUNCTIONS_H
#define ACTIVATION_FUNCTIONS_H

#include "datatypes.h"

/**
 * @brief Leaky ReLU function
 */
scalar_data_t ReLU(scalar_data_t x);

/**
 * @brief Derivative of leaky ReLU function
 */
scalar_data_t ddxReLU(scalar_data_t x);

node_activation_function_t get_relu();

#endif //ACTIVATION_FUNCTIONS_H