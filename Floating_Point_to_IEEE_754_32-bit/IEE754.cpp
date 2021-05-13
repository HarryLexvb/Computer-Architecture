//
// Created by Usuario on 13/05/2021.
//

#include <limits.h>
#include <math.h>
#include <bitset>
#include "IEE754.h"

using namespace std;
IEE754::IEE754() {}
// Convert the 32-bit binary encoding into hexadecimal
int IEE754::Binary2Hex(string Binary) {
    bitset<32> set(Binary);
    int hex = set.to_ulong();
    return hex;
}
// Convert the 32-bit binary into the decimal
float IEE754::GetFloat32(string Binary){
    int HexNumber = Binary2Hex( Binary );
    bool negative  = !!(HexNumber & 0x80000000);
    int  exponent  =   (HexNumber & 0x7f800000) >> 23;
    int sign = negative ? -1 : 1;

    // Subtract 127 from the exponent
    exponent -= 127;

    // Convert the mantissa into decimal using the
    // last 23 bits
    int power = -1;
    float total = 0.0;
    for ( int i = 0; i < 23; i++ ){
        int c = Binary[ i + 9 ] - '0';
        total += (float) c * (float) pow( 2.0, power );
        power--;
    }
    total += 1.0;
    float value = sign * (float) pow( 2.0, exponent ) * total;
    return value;
}
// Get 32-bit IEEE 754 format of the decimal value
string IEE754::GetBinary32(float value) {
    union{
         float input;   // assumes sizeof(float) == sizeof(int)
         int   output;
    }data;

    data.input = value;
    bitset<sizeof(float) * CHAR_BIT> bits(data.output);
    string mystring = bits.to_string<char, char_traits<char>, allocator<char>>();
    return mystring;
}
IEE754::~IEE754() {}