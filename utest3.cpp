#include <iostream>
using namespace std;

#include "signal.h"
#include "layer.h"
#include "feedforward_layer.h"
#include "network.h"

int main() {

    //signal passing through multiple layers
    dcpp::Layer* ffl1 = new dcpp::FeedForwardLayer(2,10,-1,1);
    dcpp::Layer* ffl2 = new dcpp::FeedForwardLayer(10,10,-1,1);
    dcpp::Layer* ffl3 = new dcpp::FeedForwardLayer(10,3,-1,1);

    dcpp::Signal input({1,2});
    ffl1->process(input);
    ffl2->process(ffl1);
    ffl3->process(ffl2);
    dcpp::Signal manual_output = ffl3->get_output();

    cout << manual_output[0] << " " << manual_output[1] << endl;

    dcpp::Network net;
    net.add_layer(ffl1);
    net.add_layer(ffl2);
    net.add_layer(ffl3);
    dcpp::Signal network_output = net.process((dcpp::Signal)std::vector<double>{1,2});

    cout << network_output[0] << " " << network_output[1] << endl;

    return 0;
}