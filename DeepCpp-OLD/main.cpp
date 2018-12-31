#include <iostream>
using namespace std;

#include "feedforward_signal.h"
#include "feedforward_layer.h"
#include "network.h"

int main() {

    dcpp::FeedForwardSignal ffs;
    ffs.set_signal({1,2,3});

    dcpp::FeedForwardLayer ffl(3,2);
    ffl.forward_propagate(ffs);

    cout << (string)ffl.get_signal() << endl;

    dcpp::Network<dcpp::FeedForwardLayer,dcpp::FeedForwardLayer*> net;
    std::tuple<dcpp::FeedForwardLayer*> netlayers(new dcpp::FeedForwardLayer(3,1));
    net.define_layers(netlayers);
    net.process({1,2,3});

    return 0;
}