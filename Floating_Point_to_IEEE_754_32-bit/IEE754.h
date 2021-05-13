//
// Created by Usuario on 13/05/2021.
//

#ifndef FLOATING_POINT_TO_IEEE_754_32_BIT_IEE754_H
#define FLOATING_POINT_TO_IEEE_754_32_BIT_IEE754_H

#include <iostream>
using namespace std;
class IEE754{
public:
    IEE754();
    int Binary2Hex(string Binary);
    float GetFloat32(string Binary);
    string GetBinary32( float value );
    ~IEE754();
};

#endif //FLOATING_POINT_TO_IEEE_754_32_BIT_IEE754_H
