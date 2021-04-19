#include "bitio.hh"
#include "cassert"

BitIO::BitIO(std::ostream* os, std::istream* is) {  // constructor
  os_ = os;
  is_ = is;
  pos_ = 0;
}

void BitIO::output_bit(bool bit) {
  assert (os_);  // make sure ostream is not void

  buffer_[pos_] = bit;
//  std::cout << "output bit " << pos_ << ": " << bit << std::endl;
  pos_++;
  if (pos_ == 8) {  // buffer is full, send char to stream
    BitIO::send_char();
  }
}

bool BitIO::input_bit() {
  assert (is_);  // make sure istream is not void

  if (pos_ == 0) {  // read new buffer
    unsigned char c_byte = is_ -> get();  // read a char byte from istream
    unsigned int i_byte = static_cast<ulong>(c_byte);  // convert from char to ulong int
    buffer_ = i_byte;  // save bits in buffer

//    std::cout << "CHAR RECIEVED: " << buffer_ << " / " << i_byte << std::endl;
  }
  bool bit = buffer_.test(pos_);
//  std::cout << "input bit " << pos_ << ": " << bit << std::endl;
  pos_++;
  if (pos_ == 8) {  // if at the end of the buffer, reset to 0
    pos_ = 0;
    buffer_.reset();
  }
  return bit;
}

void BitIO::send_char() {  // send buffer to stream, and reset buffer and pos
  unsigned int i_byte = buffer_.to_ulong();  // convert buffer bitset to ulong to char to be a byte
  unsigned char c_byte = char(i_byte);
  os_ -> put(c_byte);  // send byte to ostream

//  std::cout << "CHAR SENT: " << buffer_ << " / " << i_byte << " POS: " << pos_ << std::endl;

  pos_ = 0;
  buffer_.reset();
}

BitIO::~BitIO() {
  if (os_) {
    if (pos_ != 0) {  // if pos == 0 (empty buffer), don't send
      BitIO::send_char();
    }
    buffer_.reset();
  }
}
