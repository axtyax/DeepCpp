#ifndef DEEPCPP_NETWORK_H
#define DEEPCPP_NETWORK_H

#include "layer.h"
#include "signal.h"
#include "error.h"

#include <vector>

namespace dcpp {

class Network {

    private:

        std::vector<Layer*> layers;     
        Signal last_output;

        Error* error_function;

    public:

        void add_layer(Layer* layer) {
            layers.push_back(layer);
        }

        Signal process(Signal input) {
            layers[0]->process(input);
            for (std::vector<Layer*>::iterator it = layers.begin()+1; it != layers.end(); ++it) {
                (*it)->process(*(it-1));
            }
            last_output = layers[layers.size()-1]->get_output();
            return last_output;
        }

        void set_error(Error* ef) {
            error_function = ef;
        }

        double compute_error(Signal input, Signal correct) {
            process(input);
            return error_function->compute_error(layers[layers.size()-1]->get_output(),correct);
        }

        double compute_error(Signal correct) {
            return error_function->compute_error(last_output,correct);
        }

};

}

#endif