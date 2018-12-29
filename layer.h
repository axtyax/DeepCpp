#ifndef DEEPCPP_LAYER_H
#define DEEPCPP_LAYER_H

namespace dcpp {

//abstract class describing a generalized 'layer' object that carries a certain signal and handles b/fpropagation
template<class SignalType>
class Layer {

    protected:

        SignalType signal;

    public:

        SignalType& get_signal() {return signal;}
        
        void set_signal(SignalType s) {signal = s;}

        virtual void forward_propagate(SignalType&) = 0;
        void forward_propagate() {forward_propagate(signal);}
        virtual void backward_propagate(Layer&) = 0;

};

}

#endif