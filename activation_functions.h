/**
 * @file activation_functions.h
 * @brief Activation functions available in this library
 */

#ifndef ACTIVATION_FUNCTIONS_H
#define ACTIVATION_FUNCTIONS_H

/**
 * @brief Leaky ReLU function
 */
scalar_datum_t ReLU(scalar_datum_t x);

/**
 * @brief Derivative of leaky ReLU function
 */
scalar_datum_t ddxReLU(scalar_datum_t x);

#endif //ACTIVATION_FUNCTIONS_H