#include <iostream>
using namespace std;

#include "signal.h"
#include "feedforward_layer.h"
#include "bias_layer.h"
#include "network.h"
#include "mse_error.h"

int main() {

    //Training the network to compute XOR (no activation function)

    dcpp::Network network;
    network.add_layer(new dcpp::FeedForwardLayer(2,2,-1,1));
    network.add_layer(new dcpp::BiasLayer(2,-1,1));
    network.add_layer(new dcpp::FeedForwardLayer(2,1,-1,1));
    network.set_error(new dcpp::MseError());

    for (int i = 0; i < 1000; i++) {
        
        network.process(vector<double>{0,0});
        network.back_propagate(vector<double>{0});
        network.update();
        network.process(vector<double>{0,1});
        network.back_propagate(vector<double>{1});
        network.update();
        network.process(vector<double>{1,0});
        network.back_propagate(vector<double>{1});
        network.update();
        network.process(vector<double>{1,1});
        network.back_propagate(vector<double>{0});
        network.update();

        double err = network.compute_error(vector<double>{0,0},vector<double>{0}) +
                        network.compute_error(vector<double>{0,1},vector<double>{1}) +
                        network.compute_error(vector<double>{0,1},vector<double>{1}) +
                        network.compute_error(vector<double>{1,1},vector<double>{0});

        cout << "error: " << err << endl;
    }

        cout << network.process(vector<double>{0,0}) << endl;
        cout << network.process(vector<double>{0,1}) << endl;
        cout << network.process(vector<double>{1,0}) << endl;
        cout << network.process(vector<double>{1,1}) << endl;

    return 0;
}