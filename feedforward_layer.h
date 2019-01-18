#ifndef DEEPCPP_FEEDFORWARD_LAYER_H
#define DEEPCPP_FEEDFORWARD_LAYER_H

#include "layer.h"

#include <vector>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iostream>

namespace dcpp {

//The feedforward layer implements basic backpropagation techniques used for feedforward networks
class FeedForwardLayer : public Layer {

    private:
    
        int input_size;
        int output_size;
 
        int weight_matrix_map(std::vector<int> i,int insize) {
            return i[1]*insize + i[0];
        }

    public:

        FeedForwardLayer(int insize, int outsize, double lwb, double lub) {
            std::function<int(std::vector<int>)> wmm = [s = insize,this](std::vector<int> i) {
                return weight_matrix_map(i,s);
            };
            weights.set_map(wmm);

            input_size = insize;
            output_size = outsize;
            Signal nweights(insize*outsize);
            nweights.randomize(lwb,lub);
            weights.set_values(nweights);
        }

        FeedForwardLayer(int insize, int outsize) {
            FeedForwardLayer(insize,outsize,-1,1);
        }

        Signal& process(Signal& input) {
            Signal output_s(output_size);
            std::function<int(std::vector<int>)> trivial_map = [](std::vector<int> i) {
                return i[0];
            };
            output_s.set_map(trivial_map);
            for (int o = 0; o < output_s.get_size(); o++) {
                double osum = 0;
                for (int i = 0; i < input_size; i++) {
                    //std::cout << "w " << weights[{i,o}] << " i " << input[i] << endl;
                    osum += weights[{i,o}] * input[i];
                }
                output_s[o] = osum;
            }
            output = output_s;
            return output;
        }

};

}

#endif