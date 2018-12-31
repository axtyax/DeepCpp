#ifndef DEEPCPP_TRAINER_H
#define DEEPCPP_TRAINER_H

namespace dcpp {

#include "layer.h"
#include "signal.h"
#include "network.h"

struct Example {

    std::vector<int> input;
    std::vector<int> output;

    Example<std::vector<int> i, std::vector<int> o) : input(i), output(o) {
    }

};

//handler for training the network
class Trainer {

    private:

        double (*error_function)(Signal&, Signal&);
        std::vector<double> error_log;

        std::vector<Example> training_set;
        std::vector<Example> testing_set;

        Network* network;

    public:

        Trainer() {
        }

        Trainer(Network *n) {
            attach_network(n);
        }

        void attach_network(Network* n) {
            network = n;
        }

        double compute_error(Example e) {
            return 1.0;
        }

        double compute_error(int num_examples) {
            return 1.0;
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