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

        virtual Signal& process(Signal&) = 0;get_signalget_signalget_signalget_signalgeget_signalget_signalget_signalget_signalget_signalt_signal
        void process(Layer* previous_layer) {
            process(previous_layer->get_output());
        }

        //virtual compute_partials() = 0;

};

}

#endif