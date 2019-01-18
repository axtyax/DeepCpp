#include <iostream>
using namespace std;

#include "signal.h"

std::function<int(std::vector<int>)> test_map = [o = 1](std::vector<int> i) {
    return i[0]-o;
};

int main() {

    dcpp::Signal s({1,2,3});
    s.set_map(test_map);
    cout << s[{1}] << endl;

    return 0;
}