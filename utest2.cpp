#include <iostream>
using namespace std;

#include "signal.h"
#include "feedforward_layer.h"

int main() {

    dcpp::FeedForwardLayer ffl(2,2,0,1);
    dcpp::Signal input({1,2});
    dcpp::Signal out = ffl.process(input);

    cout << out[0] << endl;
    cout << out[1] << endl;

    return 0;
}