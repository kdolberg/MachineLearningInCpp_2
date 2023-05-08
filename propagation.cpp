/**
 * @filename propagation.cpp
 * @author Kris Dolberg
 */

#include "propagation.h"
#include "topology.h"

/************************************************************************************************************************
                                                    Static Functions
 ************************************************************************************************************************/
/**
 * @brief Allocates memory for a forward data cache struct based on net
 * @param net The neural network that will be using this data cache
 * @param fdata The forward data cache struct whose memory will be allocated 
 */
static void allocate_cache_memory(const net_t& net, net_forward_data_cache_t& fdata, net_back_data_cache_t& bdata) {
    uint dataset_size = net.training_dataset->x_data.size();
    assert(dataset_size==net.training_dataset->y_data.size());
    copy_topology(fdata.naive_partials,net.wb,dataset_size);
    copy_topology(fdata.layer_io,net.wb,dataset_size);
}

/************************************************************************************************************************
                                                    Shared Functions
 ************************************************************************************************************************/
void forwardpropagate(const net_t& net,net_forward_data_cache_t& fdata) {

    /*Some additional memory allocation needed for naive partials*/
    for (uint i = 0; i < net.wb.size(); ++i) {
        // net.wb[i]*fdata.layer_io[i];
    }
}

void backpropagate(const net_t& net, const net_forward_data_cache_t& fdata, net_back_data_cache_t& bdata) {
}