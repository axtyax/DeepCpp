#ifndef DEEPCPP_SIGNAL_H
#define DEEPCPP_SIGNAL_H

#include <vector>
#include <type_traits>

namespace dcpp {

//abstract class describing a generalized 'signal' object that may pass through the network
template<class SignalContainer, class WeightType>
class Signal {

    protected:

        SignalContainer signal;
        SignalContainer delta;

    public:

        SignalContainer& get_signal() {return signal;}
        SignalContainer& get_delta() {return delta;}
        
        void set_signal(SignalContainer s) { signal = s;}
        void set_delta(SignalContainer d) {delta = d;}

        virtual void set_signal_linearly(std::vector<double>) = 0;
        virtual std::vector<double> get_signal_linearly() = 0;
        virtual void update_signal(SignalContainer&, WeightType&) = 0;
        virtual double get_linear_signal(int) = 0;
        virtual int size() = 0;

};

}

#endif