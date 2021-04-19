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
    std::ifstream ifile(filename);  // file stream to read plain text for encoding from
    std::ofstream ofile(strcat(filename, ".comp"));  // file stream to write encoded version to

    if (ifile.is_open()) {  // is a valid readable file
      BitIO bitio(&ofile, nullptr);
      Huffman huff;
      char byte;

      while (ifile.get(byte)) {
        std::vector<bool> enbyte = huff.encode(byte);  // huffman tree does its huffmagic, gives encoded byte
        for (i=0; i<8; i++) {  // for each bit in the encoded byte
          bool bit = enbyte[i];
          bitio.output_bit(bit);
        }
      }
    }
  }
}
