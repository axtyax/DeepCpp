#include <iostream>
using namespace std;

#include "signal.h"
#include "layer.h"
#include "feedforward_layer.h"

int main() {

    //signal passing through multiple layers
    dcpp::Layer* ffl1 = new dcpp::FeedForwardLayer(2,10,-1,1);
    dcpp::Layer* ffl2 = new dcpp::FeedForwardLayer(10,10,-1,1);
    dcpp::Layer* ffl3 = new dcpp::FeedForwardLayer(10,3,-1,1);

    dcpp::Signal input({1,2});
    ffl1->process(input);
    ffl2->process(ffl1);
    ffl3->process(ffl2);
    dcpp::Signal output = ffl3->get_output();

    cout << output[0] << " " << output[1] << endl;

    return 0;
}