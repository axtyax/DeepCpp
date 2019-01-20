#ifndef DEEPCPP_MSE_ERROR_H
#define DEEPCPP_MSE_ERROR_H

#include "error.h"

#include <cmath>

namespace dcpp {

class MseError : public Error {

    public:

        double compute_error(Signal& output, Signal& correct) {
            double error = 0;
            for (int i = 0; i < output.get_size(); i++) {
                error += 1/2.0 * pow(output[i]-correct[i],2) * (1.0/output.get_size());
            }
            return error;
        }

        Signal compute_gradient(Signal& output, Signal& correct) {
            Signal gradient;
            for (int i = 0; i < output.get_size(); i++) {
                gradient.add_value((output[i]-correct[i])*(1.0/output.get_size()));
            }
            return gradient;
        }

};

}

#endif