/*
    Notes:
    for message with m-bits,
    generator with g-bits,

    - the degree of the generator polynomial is (g-1)
    - number of bits of CRC = degree of generator polynomial = (g-1)
    - total length of codeword/trasmitted message (message + CRC) = m + g-1
*/

#include <iostream>
#include <string>
#include "common.h"

using namespace std;

int main() {
    //read two lines from stdin:
    //first line is message,
    //second line is generator polynomial
    string message, generator;
    getline(cin, message);
    getline(cin, generator);

    //add zero bits to the LSB side of message,
    //number of zero bits to add = number of generator bits - 1
    string message_padded = message;
    int num_crc_bits = generator.length() - 1;
    for (int i=0; i<num_crc_bits; ++i) {
        message_padded += "0";
    }

    //get remainder and pad it with zeroes (if required) before
    //concatinating with message
    string remainder = get_remainder(message_padded, generator);
    while (remainder.length() < num_crc_bits) {
        remainder = "0" + remainder;
    }
    
    //output two lines to stdout:
    //first is the codeword (transmitted message),
    //second is the generator polynomial (to be read by other programs)
    cout << message + remainder << endl;
    cout << generator << endl;

    return 0;
}