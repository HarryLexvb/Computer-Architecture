#include <iostream>
#include <bitset>
#include "IEE754.h"

using namespace std;

int main(){

    IEE754 op;
    // Convert 19.5 into IEEE 754 binary format..
    float number;
    cout << "enter a number: "; cin >> number;
    string str = op.GetBinary32( (float) number );
    cout << "Binary equivalent of " << number << ": " << endl;
    cout << str << endl;

    // .. and back again
    float f = op.GetFloat32( str );
    cout << "Decimal equivalent of " << str << ":" << endl;
    cout << f << endl;

}
