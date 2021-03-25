/*
 * HTree: a class to represent a tree node with two values: a key
 * and a value.
 */

#include "htree.hh"
using namespace std;



// Return an optional list of directions from root to a node of a given key.
// If key not contained in this tree, returns nullptr


HTree::key_t HTree::get_key() const {
	return key;
}

HTree::value_t HTree::get_value() const {
	return value;
}


HTree::tree_ptr_t HTree::get_child(HTree::Direction dir){
	if (dir == HTree::Direction::LEFT){
	return left;
	}
       if (dir == HTree::Direction::RIGHT){
	return right;
	}	       
}

HTree::possible_path_t HTree::path_to(key_t key) const
{
  return nullptr;
}


/*
void HTree::destroy_tree(){
	if (left_!=nullptr){
		destroy_tree(left_);
	}
	if (right_!=nullptr){
		destroy_tree(right_);
	}
	delete parent;
}

*/
