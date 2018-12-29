#ifndef DEEPCPP_TRAINER_H
#define DEEPCPP_TRAINER_H

namespace dcpp {

#include "layer.h"
#include "signal.h"

//handler for training the network
class Trainer {

    private:

        double (*error_function)(Signal&, Signal&)
        std::vector<double> error_log;

    public:

        double compute_error() {

        }

};

double mean_squared_error(Signal& output, Signal& correct) {
    double err = 0;
    for (int i = 0; i < output.size(); i++) {
        err += 0.5 * (output[i] - correct[i])*(output[i] - correct[i]);
    }
}

}

#endif