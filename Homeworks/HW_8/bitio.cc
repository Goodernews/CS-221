#include <iostream>
#include "bitio.hh"

// a BitIO object is meant to either read OR write, so one of ostream and istream in the constructor should be void

BitIO::BitIO(std::ostream* os, std::istream* is) {
// Is there really nothing needed here?
}

void BitIO::output_bit(bool bit) {  // output a singular bit to os
    os << bit;   // I definitely think I'm oversimplifying and something is missing here
}

bool BitIO::input_bit() {  // read a singular bit from is
    bool bit;
    is >> bit;  // Is there a loop or something needed to read just one bit at a time? Going to test this and see what kind of errors it gives to determine that
    return is;
}
