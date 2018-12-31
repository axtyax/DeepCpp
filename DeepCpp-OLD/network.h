#ifndef DEEPCPP_NETWORK_H
#define DEEPCPP_NETWORK_H

#include <vector>
#include <tuple>

#include "layer.h"
#include "signal.h"

namespace dcpp {

template< class OutputType, class ... LayerTypes>
class Network {

    private:

        std::tuple<LayerTypes...> layers;
        constexpr int num_layers = sizeof...(LayerTypes);

    public:

        void define_layers(std::tuple<LayerTypes...> l) {
            layers = l;
        }

        OutputType process(std::vector<double> input) {
            layers[0]->forward_propagate(input);
            for (int l = 1; l < num_layers; l++) {
                std::get<l>(layers)->forward_propagate(std::get<l-1>(layers)->get_signal());
            }
            return std::get<num_layers>(layers)->get_signal();
        }

};

}

#endif