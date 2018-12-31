#ifndef DEEPCPP_FEEDFORWARD_SIGNAL_H
#define DEEPCPP_FEEDFORWARD_SIGNAL_H

#include "signal.h"
#include <vector>
#include <string>

#include <iostream>

namespace dcpp {

//The feedforward signal is just a vector of values
class FeedForwardSignal : public Signal<std::vector<double>, std::vector<std::vector<double>> > {

    private:

        

    public:

        FeedForwardSignal(){}

        FeedForwardSignal(int size) {
            signal = std::vector<double>(size,0.0);
        }

        void set_signal_linearly(std::vector<double> vals) {
            signal = vals;    
        }

        std::vector<double> get_signal_linearly() {
            return signal;
        }

        void update_signal(std::vector<double>& values, std::vector< std::vector<double> >& weights) {
            for (int o = 0; o < weights.size(); o++) {
                double weighted_sum = 0;
                for(int w = 0; w < weights[o].size(); w++) {
                    weighted_sum += values[w] * weights[o][w];
                }
                signal[o] = weighted_sum;
            }
        }

        double get_linear_signal(int i) {
            return signal[i];
        }

        int size() {
            return signal.size();
        }

        operator std::string() const{
            std::string str = "";
            for (int i = 0; i < signal.size(); i++) {
                str += std::to_string(signal[i]) + ", ";
            }
            return str;
        }

};

}

#endif