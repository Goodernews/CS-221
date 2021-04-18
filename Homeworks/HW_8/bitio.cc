#include "bitio.hh"

BitIO::BitIO(std::ostream* os, std::istream* is) {  // constructor
  os_ = os;
  is_ = is;
  pos_ = 0;
}

void BitIO::output_bit(bool bit) {
  if (os_) {  // make sure ostream is not void
    buffer_[pos_] = bit;
    std::cout << "output bit " << pos_ << ": " << bit << std::endl;
    if (pos_ == 8) {  // buffer is full, send char to stream
      BitIO::send_char();
    }
    else {  // otherwise, incriment position in buffer for next bit to be added
      pos_++;
    }
  }
}

bool BitIO::input_bit() {
  if (is_) {  // make sure istream is not void
    if (pos_ == 0) {
      char byte;
      byte = is_ -> get();  // read a char byte from istream
      std::cout << "CHAR RECIEVED: " << byte << std::endl;
      buffer_ = int(byte);  // convert from char to int to bitset and save in buffer
    }
    bool bit = buffer_.test(pos_);
    pos_++;
    std::cout << "input bit " << pos_ << ": " << bit << std::endl;
    return bit;
    if (pos_ == 8) {  // if at the end of the buffer, reset to 0
      pos_ = 0;
      buffer_.reset();
    }
  }
  else {
    return false;  // not really, idk, what do you even do if istream is void here?
  }
}

void BitIO::send_char() {  // send buffer to stream, and reset buffer and pos
  char byte = char(buffer_.to_ulong());  // convert buffer bitset to ulong to char to be a byte
  std::cout << "CHAR SENT: " << byte << std::endl;
  os_ -> put(byte);  // send byte to ostream
  buffer_.reset();
  pos_ = 0;
}

BitIO::~BitIO() {
  if (os_) {
    BitIO::send_char();
  }
}
