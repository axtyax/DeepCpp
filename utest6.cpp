#include <iostream>
using namespace std;

#include "signal.h"
#include "feedforward_layer.h"
#include "bias_layer.h"
#include "sigmoid_layer.h"
#include "relu_layer.h"
#include "network.h"
#include "mse_error.h"

int main() {

    //Training the network to compute XOR (with sigmoid/relu activation)

    dcpp::Network network;
    network.add_layer(new dcpp::FeedForwardLayer(2,2,0,0.1));
    network.add_layer(new dcpp::BiasLayer(2,0,0.01));
    //network.add_layer(new dcpp::SigmoidLayer(2));
    network.add_layer(new dcpp::ReluLayer(2));
    network.add_layer(new dcpp::FeedForwardLayer(2,1,0,1));
    network.add_layer(new dcpp::ReluLayer(1));
    network.set_error(new dcpp::MseError());

    double err = network.compute_error(vector<double>{0,0},vector<double>{0}) +
                    network.compute_error(vector<double>{0,1},vector<double>{1}) +
                    network.compute_error(vector<double>{0,1},vector<double>{1}) +
                    network.compute_error(vector<double>{1,1},vector<double>{0});

    cout << "error: " << err << endl;

    for (int i = 0; i < 10000; i++) {
        
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

        err = network.compute_error(vector<double>{0,0},vector<double>{0}) +
                network.compute_error(vector<double>{0,1},vector<double>{1}) +
                network.compute_error(vector<double>{0,1},vector<double>{1}) +
                network.compute_error(vector<double>{1,1},vector<double>{0});

        cout << "error: " << err << endl;

        if (err < 0.0001) break;
        
    }

        cout << network.process(vector<double>{0,0}) << endl;
        cout << network.process(vector<double>{0,1}) << endl;
        cout << network.process(vector<double>{1,0}) << endl;
        cout << network.process(vector<double>{1,1}) << endl;

    return 0;
}