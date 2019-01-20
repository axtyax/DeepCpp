#ifndef DEEPCPP_LAYER_H
#define DEEPCPP_LAYER_H

#include "signal.h"

namespace dcpp {

class Layer {

    protected:

        Signal weights;
        Signal partials;
        Signal gradient;
        Signal last_input;
        Signal last_output;

    public:

        Signal& get_output() {
            return last_output;
        }

        virtual Signal& process(Signal&) = 0;
        void process(Layer* previous_layer) {
            process(previous_layer->get_output());
        }

        virtual Signal& back_propagate(Signal&) = 0;

        void update() {
            for (int i = 0; i < weights.get_size(); i++) {
                weights[i] -= partials[i] * 0.001;
            }
        }

};

}

#endif