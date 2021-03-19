# HW 6

Here is my homework 6 folder!


# `tree.cpp` 

This is the main file that contains the functions necessary for building a tree. 

## `create_tree`

`create_tree` is the function that creates nodes and child nodes based on the `struct Tree` which was predefined in `tree.hh`.

`create_tree` takes 2 required values:

1.  `key_` a user defined adress for a node that is unrelated to the adress that is assigned by the compiler. It takes an `int`.
2.  `value_`the value that a given node holds. It has a type of `uint64_t`

In addition `create_tree` has two optional values, `left_` and `right_` which have a default value of `nullptr` and take a node as a value. Both are type `Tree`.

It first creates a node, allocates space in the stack, and returns a pointer to the node.

- [ ] Succesfully compiling
- [x] Not succesfully compiling

## `destroy_tree`

`destroy_tree` takes a pointer to the root of a tree (although it can theoretically take any node) and recursivelly releases the memory, effictevely delting, the tree.

- [ ] Succesfully compiling
- [x] Not succesfully compiling

## `node_at`

`node_at` takes a pointer to a `Tree` root and a capitalized set of chars that leads to a given node, and returns the value of that node. 

 - [ ] Succesfully compiling
 - [x] Not succesfully compiling

## `path_to`

`path_to` takes a pointer to the root of a tree, and a value to search for. It recursively searches for the value and assumes that the tree is unordered. 

Edge cases: 
 * If there are multiple values it returns the leftmost value.
 * If the root is the value that is being searched for it returns an empty string `""`.
 * If there is no match the value returned is `"0"`. 

 - [ ] Succesfully compiling
 - [x] Not succesfully compiling

# `test_tree.cpp`

This is the testing file for my project. It tests the various functions through several common cases, and a handful of ege cases.


