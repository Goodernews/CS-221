#include "bitio.hh"
#include "huffman.hh"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

// this is not debugged, just a draft of what "should" work

int main(int argc, char* argv[]) {
  while (i=1; i<argc; i++) {  // start at one to skip the first argument (run file name), and loop for every file
    ifstream ifile(&filename);  // file stream to read binary encoded text from
    ofstream ofile(&filename + ".plaintext");  // file stream to write decoded text to

    if (ifile.is_open()) {  // is a valid readable file
      BitIO::BitIO bitio(nullptr, &ifile);
      Huffman::Huffman huff;
      char byte;

      while (byte != Huffman::HEO) {
        byte = char(huff.decode(bitio.input_bit()));  // huffman tree does its huffmagic, gives decoded byte
        ofile.put(byte);
      }
    }
  }
}
