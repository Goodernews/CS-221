# HW 8: Huffman

**By:** Taylor Blair & Alan Jessup

# Part One: `Huffman encoding`

Implementing Huffman encoding.

- [x] Structure Outlined
- [x] Code written
- [ ] Compiling successfully
- [ ] Passing all tests
- [ ] No memory leaks

## `HTree.cc` & `Hforest.cc`

A few new methods were added for simplicity sake:

### `HTree::add_one_val`

This is a method that takes a current node and adds one to the current value.

### `HTree::search_key`

This is a method that takes a key, and recursivelly searches for a node containg said key. It then returns a pointer to the node containing the given key.

### `HForest::compare_tree`

This method previously inserted the largest element in the stack in the first position, so when popped the largest value was returned. Now the function returns the smallest node (by node value).

## `huffman.hh`

Header file for the huffman code.

### `dummy_key_`

This is a dummy key variable that denotes a non leaf node. Default value is `-1`

## `huffman.cc`

This is the main file

### `constructor`

Makes a blank huffman tree

### `encode`

Finds the target node, adds one to the value, breaks tree, rebuilds tree to account for the potentially updated structure, returns vector of `true`'s and `false`'s to represent a path.

### `decode`

Returns key of node...

**NOT IMPLEMENTED**

### `build_tree`

Takes a forest of nodes that have no children, and builds it into a huffman encoder that is the form of a tree.

### `break_tree`

Takes a huffman tree, returns a forest of single node leaves that have no children nodes. Used for copying the alpha and EOF keys.


## `test_huffman.cc`

**Testing time!**

This was already provided by Eitan Frachtenberg. No modifications were made.  

# Part Two: `bitio`

Creating a bitio class that reads and writes bits.

- [x] Structure Outlined
- [x] Code written
- [x] Compiling successfully
- [x] Passing all tests
- [ ] No memory leaks


## `bitio.hh`

Header file

## `bitio.cc`

What are the functions


## `test_bitio.cc`

1. test patience
2. Take the elevator out of the bit mine

# Part Three: Encoding and Decoding

Lets encode and decode!

- [x] Structure Outlined
- [x] Code written
- [x] Compiling successfully
- [ ] Passing all tests
- [ ] No memory leaks


## `encoder.cc`

Takes a file, and compresses. Outputs a `.comp` file

## `decoder.cc`

Takes a `.comp` outputs a `.comp.plaintext`


# Part Four: Testing Compression

Middle out test

| File |  Original File Size | Compressed Size | Same size post decompression? |
| ---- | ------------------- | --------------- | ----------------------------- |
| [`da_ba_dee.txt`](https://www.musixmatch.com/lyrics/PelleK/Blue-Da-Ba-Dee)| 2.0K | Not Tested | N/A              |
| [` gospel_flying_spaghetti.txt`](https://archive.org/stream/TheGospelOfTheFlyingSpaghettiMonster/The+Gospel+Of+The+Flying+Spaghetti+Monster_djvu.txt) | 263 K | Not Tested | N/A |


# Notes

This is not fully completed. Taylor made the adaptive Huffman encoding, Alan made BitIO and Encoder/Decoder. 

## Special Thanks

Special thanks to the following people for debugging assitance:

 + [Eitan Frachtenberg](https://github.com/eitanf)
	+ All files listed
 + [David Ramirez](https://www.reed.edu/faculty-profiles/profiles/ramirez-david.html)
	+ Emotional support
 + [Edward Coleman Nemec](https://github.com/deeptronos)
	+ Debugging
	+ Intial huffman structure
 + Evan Reid Siden
 	+ Bitio
 + [Willow Winter](https://github.com/RaineWillow)
	+ Performance improvments
	+ Intial huffman structure
