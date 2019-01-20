#ifndef DEEPCPP_FEEDFORWARD_LAYER_H
#define DEEPCPP_FEEDFORWARD_LAYER_H

#include "layer.h"

#include <vector>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iostream>

namespace dcpp {

//The feedforward layer implements basic backpropagation techniques used for feedforward networks
class FeedForwardLayer : public Layer {

    private:
    
        int input_size;
        int output_size;
        int num_weights;
 
        int weight_matrix_map(std::vector<int> i,int insize) {
            return i[1]*insize + i[0];
        }

    public:

        FeedForwardLayer(int insize, int outsize, double lwb, double lub) {
            std::function<int(std::vector<int>)> wmm = [s = insize,this](std::vector<int> i) {
                return weight_matrix_map(i,s);
            };
            weights.set_map(wmm);

            input_size = insize;
            output_size = outsize;
            num_weights = input_size*output_size;
            Signal nweights(num_weights);
            nweights.randomize(lwb,lub);
            weights.set_values(nweights);
        }

        FeedForwardLayer(int insize, int outsize) {
            FeedForwardLayer(insize,outsize,-1,1);
        }

        Signal& process(Signal& input) {
            last_input.set_values(input);
            Signal output_s(output_size);
            std::function<int(std::vector<int>)> trivial_map = [](std::vector<int> i) {
                return i[0];
            };
            output_s.set_map(trivial_map);
            for (int o = 0; o < output_s.get_size(); o++) {
                double osum = 0;
                for (int i = 0; i < input_size; i++) {
                    //std::cout << "w " << weights[{i,o}] << " i " << input[i] << endl;
                    osum += weights[{i,o}] * input[i];
                }
                output_s[o] = osum;
            }
            last_output = output_s;
            return last_output;
        }

        Signal& back_propagate(Signal& next_gradient) {
            //cout << "got grad " << next_gradient << "  " << next_gradient[0] << endl;
            //cout << "SIZES  " << input_size << " " << output_size << endl;
            partials = Signal(num_weights);
            partials.set_map(weights.get_map());
            gradient = Signal(input_size);
            for (int o = 0; o < next_gradient.get_size(); o++) {
                for (int w = 0; w < input_size; w++) {
                    partials[{w,o}] = next_gradient[o] * last_input[w];
                    //std::cout << "partial " << partials[{w,o}] << " from " << next_gradient[o] << " " << last_input[w] << std::endl;
                }
            }
            for (int i = 0; i < input_size; i++) {
                double grad_sum = 0;
                for (int o = 0; o < next_gradient.get_size(); o++) {
                    grad_sum += next_gradient[o] * weights[{i,o}];
                }
                gradient[i] = grad_sum;
            }
            return gradient;
        }

};

}

#endif