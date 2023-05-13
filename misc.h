
#ifndef MISC_H
#define MISC_H
#include <vector>
#include "datatypes.h"
#ifndef uint
typedef unsigned int uint;
#endif //uint
/**
 * @brief
 */
scalar_datum_t __xor__(uint a, uint b);
/**
 * @brief
 */
xy_dataset_t make_xor_dataset();
/**
 * @brief
 */
uint char2int(const char * arg);
/**
 * @brief
 */
std::vector<uint> interpret_args(int _argc, char const *_argv[]);

#endif