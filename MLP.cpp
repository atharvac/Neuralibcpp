#include <iostream>
#include <vector>


class Neural {
private:
    int numI, numH, numO;
public:
    Neural (int inp, int hid, int outs){
        numI = inp;
        numH = hid;
        numO = outs;
    }
};
