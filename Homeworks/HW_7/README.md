# Homework 7

**By**: :sparkles:Taylor :sparkles: Blair:sparkles: & :trollface: Cole :trollface: Nemec :neckbeard:


Homework 7 time!

# Part One

This section involves rewritting code from the previous assignment into a class with several methods. 

To compile, use the make file command `make test_htree`. The g++ version has not been defined, this is due to an inconsistency in g++ versions among collaborators. This version compiled with

## `htree.hh`

This file was intially made by Eitan Frachtenburg. Minor edits were made to add on to change the destructor to the default.  

## `htree.cc`

The methods that are used to compose the `HTree` class. It should be assumed that the defintions below are preceded by the `HTree::` 

 [x] Structure Outlined
 [x] Code written
 [x] Compiling succesfully
 [x] Passing some tests
 [ ] Passing all tests

### `Constructor`

Takes the definition from `htree.hh`. 

There are two required arguments:
 1. `key_` which takes an integer
 2. `value` which takes a 64 bit u integer

There are two optional values:
 1. `left` 
 2. `right`

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

**Edge Cases**

 + If there is no child or a bad direction has been passed, returns `nullptr`


### `~HTree` (Decstructor)

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
6. Happy little dance

# Part Two

## `hforest.hh`


## `hforest.cc`


## `test_h_forest.cc`

1. Tests vla vla vla


# Notes

Taylor created part one
Cole created part two
