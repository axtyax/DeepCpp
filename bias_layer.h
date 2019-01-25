#ifndef DEEPCPP_BIAS_LAYER_H
#define DEEPCPP_BIAS_LAYER_H

#include "layer.h"

#include <vector>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iostream>

namespace dcpp {

//The bias layer allows for biases to be added to shift the activation functions of the previous layer horizontally
class BiasLayer : public Layer {

    private:
    
        int output_size;

    public:

        BiasLayer(int outsize, double lwb, double lub) {
            output_size = outsize;
            weights = Signal(output_size);
            weights.randomize(lwb,lub);
        }

        Signal& process(Signal& input) {
            last_input.set_values(input);
            Signal output_s(output_size);
            for (int o = 0; o < output_s.get_size(); o++) {
                output_s[o] = input[o] + weights[o];
            }
            last_output.set_values(output_s);
            return last_output;
        }

        Signal& back_propagate(Signal& next_gradient) {
            partials = Signal(output_size);
            gradient.set_values(next_gradient);
            for (int i = 0; i < gradient.get_size(); i++) {
                partials[i] = gradient[i];
            }
            return gradient;
        }

};

}

#endif