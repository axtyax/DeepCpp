#ifndef DEEPCPP_SIGNAL_H
#define DEEPCPP_SIGNAL_H

#include <vector>
#include <functional>
#include <stdlib.h>
#include <time.h>  

#include <iostream>

namespace dcpp {

class Signal {

    private:

        std::vector<double> values;
        std::function<int(std::vector<int>)> linear_map;

    public:

        Signal() {
            srand (time(NULL));
        }

        Signal (std::vector<double> v) {
            Signal();
            values = v;
        }

        Signal(int size) {
            Signal();
            for (int i = 0; i < size; i++) 
                values.push_back(0);
        }

        void randomize(double lbound, double ubound) {
            for (std::vector<double>::iterator it = values.begin(); it != values.end(); ++it) {
                double randval = (rand() % ((int)(ubound - lbound)*1000) + (int)(lbound)*1000) / 1000.0;
                //std::cout << randval << std::endl;
                *it = randval;
            }
        }

        void set_values(Signal& other_signal) {
            values.clear();
            for (int i = 0; i < other_signal.get_size(); i++) {
                values.push_back(other_signal[i]);
            }
        }

        void set_map(std::function<int(std::vector<int>)> m) {
            linear_map = m;
        }

        int get_size() {
            return values.size();
        }

        double get_value(int i) {
            return values[i];
        }

        double get_value(std::vector<int> index) {
            return values[linear_map(index)];
        }

        double operator[] (std::vector<int> index) {
            return get_value(index);
        }

        double& operator[] (int index) {
            return values[index];
        }

};

}

#endif