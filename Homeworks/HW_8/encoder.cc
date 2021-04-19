#include "bitio.hh"
#include "huffman.hh"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

// this is not debugged, just a draft of what "should" work

int main(int argc, char* argv[]) {
  while (i=1; i<argc; i++) {  // start at one to skip the first argument (run file name), and loop for every file
    ifstream ifile(&filename);  // file stream to read plain text for encoding from
    ofstream ofile(&filename + ".comp");  // file stream to write encoded version to

    if (ifile.is_open()) {  // is a valid readable file
      BitIO::BitIO bitio(&ofile, nullptr);
      Huffman::Huffman huff;

      while (ifile.get(byte)) {
        enbyte = huff.encode(byte)  // huffman tree does its huffmagic, gives encoded byte
        while (i=0; i<8; i++) {  // for each bit in the encoded byte
          bool bit = enbyte[i];
          bitio.output_bit(bit);
        }
      }
    }
  }
}
