/*
 * HTree: a class to represent a tree node with two values: a key
 * and a value.
 */

#include "htree.hh"
using namespace std;



// Return an optional list of directions from root to a node of a given key.
// If key not contained in this tree, returns nullptr


HTree::HTree(	HTree::key_t key,
		HTree::value_t value,
		HTree::tree_ptr_t left,
		HTree::tree_ptr_t right){
	key_ = key;
	value_ = value;
	left_ = left;
	right_ = right;
}

HTree::key_t HTree::get_key() const {
	return key_;
}
HTree::value_t HTree::get_value() const {
	return value_;
}


HTree::tree_ptr_t HTree::get_child(HTree::Direction dir) const {
	if (dir == HTree::Direction::LEFT){
		return left_;
	}
        if (dir == HTree::Direction::RIGHT){
		return right_;

	}
    return nullptr;	
}



HTree::possible_path_t HTree::path_to(key_t key) const 
{
 if (get_key()==key){
	 return possible_path_t(new path_t());
 }
 if (!get_child(Direction::LEFT)){
 	auto left_path = get_child(Direction::LEFT)->path_to(key);
 	if (left_path!=nullptr){ //Checks left
		left_path->push_front(HTree::Direction::LEFT); //recursively return_
 		return left_path;
 	}
 }
 if (!get_child(Direction::RIGHT)){
	auto right_path = get_child(HTree::Direction::RIGHT)->path_to(key);
 	if (right_path!=nullptr){ //Checks right
		right_path->push_front(HTree::Direction::RIGHT);
	 	return right_path;
 	}
 }

return nullptr;
}

