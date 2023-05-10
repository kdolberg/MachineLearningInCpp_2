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

activation_function_t get_relu();

/**
 * @brief Performs the function f on all members of x
 */
scalar_data_t for_each(const function_t * f,scalar_data_t& x);

/**
 * @brief Calls for_each on every member of x for the function f.
 */
std::vector<scalar_data_t> for_each(const function_t * f, std::vector<scalar_data_t>& x);

#endif //ACTIVATION_FUNCTIONS_H