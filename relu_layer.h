#ifndef DEEPCPP_RELU_LAYER_H
#define DEEPCPP_RELU_LAYER_H

#include "layer.h"

#include <vector>
#include <cstdlib>
#include <cmath>
#include <functional>
#include <iostream>

namespace dcpp {

//The bias layer allows for biases to be added to shift the activation functions of the previous layer horizontally
class ReluLayer : public Layer {


    private:
    
        int output_size;

        static double relu_function(double input) {
            if (input < 0) return 0;
            return input;
        }

    public:

        ReluLayer(int outsize) {
            output_size = outsize;
        }

        Signal& process(Signal& input) {
            last_input.set_values(input);
            last_output.set_values(input);
            last_output.apply_function(relu_function);
            return last_output;
        }

        Signal& back_propagate(Signal& next_gradient) {
            gradient.set_values(next_gradient);
            for (int i = 0; i < gradient.get_size(); i++) {
                if (last_input[i] < 0) gradient[i] = 0;
                else gradient[i] = next_gradient[i];
            }
            return gradient;
        }

};

}

#endif