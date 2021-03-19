# HW_6 Overview

Here is my homework 6 folder! It contains all the code necessary for the assignment along with a sassy `README.md`.

# `tree.cpp` 

This is the main file that contains the functions necessary for building a tree. 


- [x] Functions completed
- [x] No errors compiling

## `create_tree`

`create_tree` is the function that creates nodes and child nodes based on the `struct Tree` which was predefined in `tree.hh`.

`create_tree` takes 2 required values:

1.  `key_` a user defined adress for a node that is unrelated to the adress that is assigned by the compiler. It takes an `int`.
2.  `value_`the value that a given node holds. It has a type of `uint64_t`

In addition `create_tree` has two optional values, `left_` and `right_` which have a default value of `nullptr` and take a node as a value. Both are type `Tree`.

It first creates a node, allocates space in the stack, and returns a pointer to the node.

- [x] No errors compiling
- [ ] Errors compiling

## `destroy_tree`

`destroy_tree` takes a pointer to the root of a tree (although it can theoretically take any node) and recursively releases the memory, effictevely delting, the tree.

- [x] No errors compiling
- [ ] Errors compiling

## `node_at`

`node_at` takes a pointer to a `Tree` root and a capitalized set of chars that leads to a given node, and returns the value of that node. 

`node_at` works recursively. If the path is valid, it returns a pointer to a node. Otherwise it returns `nullptr` if the path does not lead to a node. 

- [x] No errors compiling
- [ ] Errors compiling

## `path_to`

`path_to` takes a pointer to the root of a tree, and a value to search for. 

It recursively searches for the key value and assumes that the tree is unordered. Returns the path to the node in the form of a string. 

Edge cases: 
 * If there are multiple values it returns the leftmost value.
 * If the root is the value that is being searched for it returns an empty string `""`.
 * If there is no match the value returned is `"-"`. 

- [x] No errors compiling
- [ ] Errors compiling

# `test_tree.cpp`

This is the testing file for my project. It tests the various functions through several common cases, and a handful of edge cases.

 1. `create_tree`
	1. Test if possible to make a root node.
	2. Prints the value in the root node.
	3. Create two children on the root with an additional two grandchildren.
	4. Prints two children node values

2. `path_to`
	1. Tests two cases with a valid path
	2. Tests case with a key that is not in the root.
3. `node_at`
	1. Tests three cases where the node is within the tree and prints the value
	2. Tests an invalid path using assert to ensure that it returns `nullptr`
4. `destroy_tree`
	1. Destroys the example tree.
5. **Does a little happy dance**
