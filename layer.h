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

        virtual Signal& process(Signal&) = 0;
        //virtual compute_partials() = 0;

};

}

#endif