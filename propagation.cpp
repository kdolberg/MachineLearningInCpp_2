/**
 * @filename propagation.cpp
 * @author Kris Dolberg
 */

#include "propagation.h"
#include "topology.h"
#include "overloads.h"
#include "activation_functions.h"
#include "memory_allocation.h"

scalar_datum_t sum(const scalar_datum_t& x) {
    return x;
}

template <typename U>
U sum(const std::vector<U>& v) {
    U ret = v[0];
    for (uint i = 1; i < v.size(); ++i) {
        ret += v[i];
    }
    return ret;
}

void forpropagate(const net_t& net,net_for_data_cache_t& fdata) {
    assert(fdata.layer_io.size()==(net.wb.size()+1));
    fdata.layer_io[0] = net.training_dataset->x_data;//Add raw input data to the cache
    for (uint l_ind = 0; l_ind < net.wb.size(); ++l_ind) {//Iterate over each layer
        fdata.act[l_ind] = net.wb[l_ind]*fdata.layer_io[l_ind];//Calc. the activation values for this layer
        fdata.layer_io[l_ind+1] = for_each(net.af[l_ind].func,fdata.act[l_ind]);//Calc. outputs for this layer
        // fdata.derivs[l_ind] = for_each(net.af[l_ind].deriv_func,fdata.act[l_ind]);//Calc. derivatives of outputs for this layer
    }
}

vector_data_t error(const vector_data_t& s, const vector_data_t& y) {
    uint N = s.size();
    assert(N==y.size());
    return (s-y)*(s-y);
}

scalar_data_t derror(const vector_data_t& s, const vector_data_t& y) {
    uint N=s.size(), M=y[0].size();
    assert(N==y.size());
    vector_data_t tmp = (s-y)*2.0;
    scalar_data_t ret(N);
    for (uint data_ind = 0; data_ind < N; ++data_ind) {
        assert(M==y[data_ind].size());
        ret[data_ind] = 0;
        for (uint out_n_ind = 0; out_n_ind < M; ++out_n_ind) {
            ret[data_ind]+=tmp[data_ind][out_n_ind];
        }
    }
    return ret;
}

uint true_size(const vector_data_t& x) {
    uint ret = 0;
    for (uint i = 0; i < x.size(); ++i)
    {
        ret+=x[i].size();
    }
    return ret;
}

/**
 * TODO: Give this function a less dumb name
 */
void odd_multiply(
    const vector_data_t& curr_deriv,
    const vector_data_t& inherited_deriv)
{
    assert(curr_deriv.size()==inherited_deriv.size());
    vector_data_t ret(true_size(inherited_deriv));
    uint k = 0;
    for (uint i = 0; i < inherited_deriv.size(); ++i) {
        for (uint j = 0; j < inherited_deriv[i].size(); ++j) {
            // ret[k] = 
            // ++k;
        }
    }
}

// void calc_layer_real_partials(
//     const layer_wb_t& curr_layer,
//     const layer_wb_t& prev_layer,
//     const vector_data_t& curr_inputs,
//     const vector_data_t& curr_act,
//     const activation_function_t& act_func,
//     const vector_data_t& prev_deriv,
//     vector_data_t& inherited_deriv,
//     layer_partial_derivatives_t& curr_partials)
// {
//     vector_data_t curr_deriv = for_each(act_func.deriv_func,curr_act);
//     for (uint n_ind = 0; n_ind < curr_layer.size(); ++n_ind) {
        
//     }
// }

scalar_data_t dEdw(const scalar_data_t& dEdb,const vector_data_t& layer_inputs,uint w_ind) {
    scalar_data_t ret(dEdb.size());
    for (uint data_ind = 0; data_ind < dEdb.size(); ++data_ind) {
        
    }

    return ret;
}

void backpropagate(const net_t& net, const net_for_data_cache_t& fdata, net_back_data_cache_t& bdata) {
    // scalar_data_t *inherited_deriv;
    scalar_data_t inherited_deriv = derror(fdata.layer_io.back(),net.training_dataset->y_data);
    // inherited_deriv = &_derror;
    for (uint l_ind = net.wb.size()-1; l_ind < net.wb.size(); --l_ind) {
        for (uint n_ind = 0; n_ind < net.wb[l_ind].size(); ++n_ind) {
            bdata.real_partials[l_ind][n_ind].b = (inherited_deriv)*(for_each(net.af[l_ind].deriv_func,fdata.act[l_ind][n_ind]));
            for (uint w_ind = 0; w_ind < net.wb[l_ind][n_ind].w.size(); ++w_ind) {
                bdata.real_partials[l_ind][n_ind].w[w_ind] = bdata.real_partials[l_ind][n_ind].b*fdata.layer_io[l_ind];
            }//w
        }//n
    }//l
}