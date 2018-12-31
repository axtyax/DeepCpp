#ifndef DEEPCPP_FEEDFORWARD_LAYER_H
#define DEEPCPP_FEEDFORWARD_LAYER_H

#include "layer.h"
#include "feedforward_signal.h"

#include <vector>
#include <cstdlib>
#include <ctime>

namespace dcpp {

//The feedforward layer implements basic backpropagation techniques used for feedforward networks
class FeedForwardLayer : public Layer<FeedForwardSignal> {

    private:

        using WeightMatrix = std::vector< std::vector<double> >;
        WeightMatrix weights;

    public:

        FeedForwardLayer(int input_size, int output_size) {

            srand(time(0));

            signal = FeedForwardSignal(output_size);

            for (int o = 0; o < output_size; o++) {
                std::vector<double> neuron_weights;
                for (int i = 0; i < input_size; i++) {
                    double random_weight = ((rand() % 200) - 100.0) / (input_size*100);
                    //std::cout << "  " << random_weight << std::endl;
                    neuron_weights.push_back(random_weight);
                }
                weights.push_back(neuron_weights);
            }
        
        }

        void forward_propagate(FeedForwardSignal& s) {
            signal.update_signal(s.get_signal(),weights);
        }

        void backward_propagate(Layer&) {

        }

};

}

#endif