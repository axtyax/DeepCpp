#ifndef DEEPCPP_SIGMOID_LAYER_H
#define DEEPCPP_SIGMOID_LAYER_H

#include "layer.h"

#include <vector>
#include <cstdlib>
#include <cmath>
#include <functional>
#include <iostream>

namespace dcpp {

//The bias layer allows for biases to be added to shift the activation functions of the previous layer horizontally
class SigmoidLayer : public Layer {


    private:
    
        int output_size;

        static double sigmoid_function(double input) {
            return 1.0/(1+exp(-input));
        }

    public:

        SigmoidLayer(int outsize) {
            output_size = outsize;
        }

        Signal& process(Signal& input) {
            last_input.set_values(input);
            last_output.set_values(input);
            last_output.apply_function(sigmoid_function);
            return last_output;
        }

        Signal& back_propagate(Signal& next_gradient) {
            gradient.set_values(next_gradient);
            for (int i = 0; i < gradient.get_size(); i++) {
                gradient[i] = sigmoid_function(last_input[i])*(1-sigmoid_function(last_input[i]))*gradient[i];
            }
            return gradient;
        }

};

}

#endif