#ifndef DEEPCPP_ERROR_H
#define DEEPCPP_ERROR_H

#include "signal.h"

#include <vector>

namespace dcpp {

class Error {

    private:
    
        std::vector<double> error_history;
        int historoy_length;

    public:

        virtual double compute_error(Signal&,Signal&);
        virtual Signal compute_gradient(Signal&,Signal&);

};

}

#endif