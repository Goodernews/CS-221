# Homework 7

**By**: :sparkles:Taylor :sparkles: Blair:sparkles: & :trollface: Cole :trollface: Nemec :neckbeard:


Homework 7 time!

# Part One

This section involves rewritting code from the previous assignment into a class with several methods. 

To compile, use the make file command `make test_htree`. The g++ version has not been defined, this is due to an inconsistency in g++ versions among collaborators. This version compiled with

## `htree.hh`

This file was intially made by Eitan Frachtenburg. Minor edits were made to add on 

## `htree.cc`

The methods that are used to compose the `HTree` class. It should be assumed that the defintions below are preceded by the `HTree::` [WRITE MORE HERE TAY TAY] 

 [x] Structure Outlined
 [x] Errors
 [ ] Compiling succesfully

### `Constructor`

Takes the definition from `htree.hh`. 

### `get_key`

Returns the key of a given node. 

### `get_value`

Returns the value of a given node.

### `path_to`

Recursively searches for a given key value from a root node.

**Edge Cases**

 + If there is more than one matching value this returns the leftmost key. 
 + If the key is at the root returns an empty list `{ }`.
 + If there is no value found, returns `nullptr`.

### `get_child`

Takes a node and a direction (from the `Direction` enum defined in `htree.hh`) and returns a pointer to the child node in a given direction.

**Edge Cases**

 + If there is no child or a bad direction has been passed, returns `nullptr`
 


### `~HTree` (Decstructor)

This is set to the default destructor. 


## `test_tree.cc`

1. Creating a Tree
2. Tests `path_to`
3. Deconstructs tree


# Part Two

## `hforest.hh`


## `hforest.cc`


## `test_h_forest.cc`

1. Tests vla vla vla


# Notes


