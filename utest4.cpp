#include <iostream>
using namespace std;

#include "signal.h"
#include "feedforward_layer.h"
#include "network.h"
#include "mse_error.h"

int main() {

    //error function applied to the output of a multilayer network

    dcpp::Network network;
    network.add_layer(new dcpp::FeedForwardLayer(3,10,-1,1));
    network.add_layer(new dcpp::FeedForwardLayer(10,10,-1,1));
    network.add_layer(new dcpp::FeedForwardLayer(10,2,-1,1));
    network.set_error(new dcpp::MseError());

    cout << network.process((dcpp::Signal)std::vector<double>{1,2}) << endl;

    return 0;
}