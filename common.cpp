#include "common.h"
#include <string>

using namespace std;

string get_remainder(string dividend, string divisor) {
    /*
        Performs "long division" by XORing and shifting

        Returns the remainder as a string

        Example test cases:
        (the underscore "_" just indicates the zeroes added
        to the original message before performing long division)

        (1) 11010011101100_000 mod 1011 = 100
        (2) 01010111_00000000 mod 100000111 = 10100010
    */
    int num_shifts = dividend.length() - divisor.length() + 1;
    for (int i=0; i<num_shifts; ++i) {
        //if dividend starts with zero, we would XOR the dividend
        //with zeroes which has no effect, so we just shift
        if (dividend[i] == '0') {
            continue;
        }
        //XOR each bit in the divisor with its corresponding bit
        //in the dividened
        for (int j=0; j<divisor.length(); ++j) {
            //XOR of same bits -> '0'
            //XOR of different bits -> '1'
            dividend[i+j] = (dividend[i+j] == divisor[j]) ? '0' : '1';
        }
    }
    //trim all leading zeroes
    while (dividend[0] == '0') {
        dividend.erase(0, 1);
    }
    return dividend;
}