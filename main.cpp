#include <iostream>
using namespace std;

#include "feedforward_signal.h"
#include "feedforward_layer.h"

int main() {

    dcpp::FeedForwardSignal ffs;
    ffs.set_signal({1,2,3});

    dcpp::FeedForwardLayer ffl(3,2);
    ffl.forward_propagate(ffs);

    cout << (string)ffl.get_signal() << endl;

    return 0;
}