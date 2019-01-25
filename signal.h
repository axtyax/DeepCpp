#ifndef DEEPCPP_SIGNAL_H
#define DEEPCPP_SIGNAL_H

#include <vector>
#include <functional>
#include <stdlib.h>
#include <time.h>
#include <string>

#include <iostream>

namespace dcpp {

class Signal {

    private:

        std::vector<double> values;
        std::function<int(std::vector<int>)> linear_map;
        std::vector<int> max_dimensions;

        std::function<int(std::vector<int>)> trivial_map = [](std::vector<int> i) {
            return i[0];
        };

    public:

        Signal() {
            srand (time(NULL));
            set_map(trivial_map);
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
                double randval;
                if (lbound == ubound)
                    randval = lbound;
                else
                    randval = (rand() % ((int)((ubound - lbound)*1000)) + (int)((lbound)*1000)) / 1000.0;
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

        void add_value(double v) {
            values.push_back(v);
        }

        void set_map(std::function<int(std::vector<int>)> m) {
            linear_map = m;
        }

        std::function<int(std::vector<int>)> get_map() {
            return linear_map;
        }

        void set_size(std::vector<int> max_dimensions) {
            this->max_dimensions = max_dimensions;
            int size = 1;
            for (std::vector<int>::iterator it = max_dimensions.begin(); it != max_dimensions.end(); ++it)
                size *= *it;
            values.reserve(size);
        }

        int get_size() {
            return values.size();
        }
        
        int get_size(int dim) {
            return max_dimensions[dim];
        }

        double& get_value(int i) {
            return values[i];
        }

        double& get_value(std::vector<int> index) {
            return values[linear_map(index)];
        }

        double& operator[] (std::vector<int> index) {
            return get_value(index);
        }

        double& operator[] (int index) {
            return values[index];
        }

        void apply_function(double (*f)(double)) {
            for (int i = 0; i < get_size(); i++)
                values[i] = f(values[i]);
        }

        typedef typename std::vector<double>::iterator iterator;
        iterator begin() { return values.begin(); }
        iterator end() { return values.end(); }

};

}

std::ostream& operator<< (std::ostream &out, dcpp::Signal data) {
    for (int i = 0; i < data.get_size(); i++) {
        out << std::to_string(data[i]) + ", ";
    }
    return out;
}

#endif