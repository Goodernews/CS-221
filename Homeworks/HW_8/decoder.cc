#include "bitio.hh"
#include "huffman.hh"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

// this is not fully debugged, just a draft of what "should" work

int main(int argc, char* argv[]) {
  for (int i=1; i<argc; i++) {
    char* filename = argv[i];  // start at one to skip the first argument (run file name), and loop for every file
    std::ifstream ifile(filename);  // file stream to read binary encoded text from
    std::ofstream ofile(strcat(filename, ".plaintext"));  // file stream to write decoded text to

    if (ifile.is_open()) {  // is a valid readable file
      BitIO bitio(nullptr, &ifile);
      Huffman huff;
      char byte;

      while (byte != Huffman::HEOF) {
        byte = char(huff.decode(bitio.input_bit()));  // huffman tree does its huffmagic, gives decoded byte
      }
    }
  }
}
