# Homework 7

**By:** :sparkles:Taylor :sparkles: Blair:sparkles: & :trollface: Cole :trollface: Nemec :neckbeard:


Homework 7 time!

# Part One

This section involves rewritting code from the previous assignment into a class with several methods. 

To compile, use the make file command `make test_htree`. The g++ version has not been defined, this is due to an inconsistency in g++ versions among collaborators. This version compiled with on Taylors computer was 9.3.0.

## `htree.hh`

This file was intially made by Eitan Frachtenburg. Minor edits were made to add on to change the destructor to the default.  

There are 4 variables that have been added to the class, all of which are public:
 1. `key_` 
 2. `value_`
 3. `left_` 
 4. `right_`

## `htree.cc`

The methods that are used to compose the `HTree` class. It should be assumed that the defintions below are preceded by the `HTree::` 

- [x] Structure Outlined
- [x] Code written
- [x] Compiling succesfully
- [x] Passing all tests
- [x] No memory leaks

### `Constructor`

Takes the definition from `htree.hh`. 

There are two required arguments:
 1. `key_` which takes an integer
 2. `value_` which takes a 64 bit u integer

There are two optional values:
 1. `left_` 
 2. `right_`

Which both take a pointer to a new node and have a default value of `nullptr`

### `get_key`

A method that returns the key of a given node. 

**Returned type**: `int` 

### `get_value`

A method that returns the value of a given node.

**Returned type**: `uint64_t`

### `path_to`

Recursively searches for a given key value from a root node.

**Returned type**: `possible_path_t` which is a list that contains directions `LEFT` and `RIGHT` defined by `HTree::Direction`. 

**Edge Cases**

 + If there is more than one matching value this returns the leftmost key. 
 + If the key is at the root returns an empty list `{ }`.
 + If there is no value found, returns `nullptr`.

### `get_child`

Takes a node and a direction from the `Direction` enum defined in `htree.hh` and gets the appropriate child from the public variable.  

**Returned type**: A pointer to the child node in a given direction.

**Edge Case**
 + If there is no child, returns `nullptr`

### `~HTree` (Destructor)

This is set to the default destructor. 

## `test_tree.cc`

1. `create_test_tree()`
	1. Creates an example tree
2. `test_get_child()`
	1. Tests getting left child
	2. Tests getting right child 
3. `test_path_to()`
	1. Tests path to root
	2. Tests path to node with single depth
	3. Tests path to node that has a twin
	4. Tests path to a node that does not exist 
4. `test_get_key()`
	1. Tests getting root key
	2. Tests getting key of left child
5. `test_get_val()`
	1. Tests getting root value
	2. Tests getting value of right child
6. :musical_note: :notes: Happy little dance :notes: :musical_note:  

# Part Two: `HForest`

Part two involved making the `HForest` class. The `HForest` class stores multiple `HTrees` in the heap. 

Due to an update to the method `make_heap` the executables are made using a version of c++ greater than or equal to 20. 

## `hforest.hh`

Created from scratch. 

## `hforest.cc`

Created from scratch

- [x] Structure Outlined
- [x] Code written
- [x] Compiling succesfully
- [x] Passing all tests
- [x] No memory leaks

### Constuctor

There is no required arguments, if nothing is passed through at construction then a forest with size 0 is created.

Optionally, a forest can be intialled with a tree by passing through a pointer to a tree.

**Returned type:** `forest_ptr_t`

### `add_tree`

A method that adds a tree to a forest. Takes a pointer to a forest.

This is a void function and thus does not return anything.

### `size`

A method that gives the number of trees in a given forest. 

**Returned type:** `int`

### `pop_tree`

A method that removes the tree with the largest root value and returns a pointer to the tree.

**Returned type:** `tree_ptr_t`

**Edge cases**
 + If there are two trees that both contain the max value, then the one most recently added will be popped from the forest.
 + If there are no trees in a forest, then size is not decreased, and `nullptr` is returned.

### Destructor

Set to the default class destructor. 


## `test_hforest.cc`

1. `create_test_forest()`
	1. Creates a forest with a singular tree
2. `test_size()`
	1. Tests the size method on an empty tree
	2. Tests the size method on the tree from the first test
3. `test_add_tree()`
	1. creates a small tree
	2. Adds it to the forst
	3. Checks size to see if added succesfully
4. `test_pop()`
	1. Creates a large tree and adds it to the forest
	2. Runs `pop_tree` and check that the returned pointer is the same as the pointer that was created and that size is decreased.
	3. Adds three new trees (two with identical maximum values) to the forest.
	4. Checks that the most recently added tree with maximum value.
	5. Takes a nap and dreams of electric sheep. :zap: :sheep: :zap:

# Notes

Work was split fairly. 

Cole worked on:
 + `hforest.cc`
 + `hforest.hh`
 + `test_hforest.cc`
 + `makefile`

Taylor worked on:
 + `README.md`
 + `makefile`
 + `htree.hh`
 + `htree.cc`
 + `test_htree.cc`
 + `test_hforest.cc`

In addition, we would like to give a special thank you to the following individuals for coding and debugging assistance:
 + [Eitan Frachtenberg](https://github.com/eitanf)
	+ All files named
 + [David Ramirez](https://www.reed.edu/faculty-profiles/profiles/ramirez-david.html) 
 	+ `htree.cc`
 	+ `makefile`
 + [Lauren Connors](https://github.com/laurayco)
 	+ `hforest.cc`
	+ `makefile`
