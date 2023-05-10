/**
 * @filename propagation.cpp
 * @author Kris Dolberg
 */

#include "propagation.h"
#include "topology.h"
#include "overloads.h"

void forwardpropagate(const net_t& net,net_forward_data_cache_t& fdata) {
    for (uint i = 0; i < net.wb.size(); ++i) {//Iterate through each layer

    }
}

void backpropagate(const net_t& net, const net_forward_data_cache_t& fdata, net_back_data_cache_t& bdata) {

}