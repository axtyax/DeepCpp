#ifndef DEEPCPP_LAYER_H
#define DEEPCPP_LAYER_H

#include "signal.h"

namespace dcpp {

class Layer {

    protected:

        Signal weights;
        Signal partials;
        Signal output;

    public:

        Signal& get_output() {
            return output;
        }

        virtual Signal& process(Signal&) = 0;
        void process(Layer* previous_layer) {
            process(previous_layer->get_output());
        }

        //virtual compute_partials() = 0;

};

}

#endif