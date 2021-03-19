#include <iostream>
#include <string>
#include "tree.hh"

using namespace std;


tree_ptr_t create_tree(	const key_t& key,
			const value_t& value,
			tree_ptr_t left ,
			tree_ptr_t right){
	tree_ptr_t temp = new Tree{key, value, left, right};
	return temp;
}


void destroy_tree(tree_ptr_t parent){
	if (parent->left_!=nullptr){
		destroy_tree(parent->left_);
	}
	if (parent->right_!=nullptr){
		destroy_tree(parent->right_);
	}
	delete parent;
}


std::string path_to (Tree parent, value_t target){
	if(parent.value_==target){
		return ("");
	}
	if (parent.left_!=nullptr){
		std::string child_search_left = path_to(parent.left_, target);
		if(child_search_left==""){
			return ("L");
		}
		else if (child_search_left!="0"){
			return ("L" + child_search_left);
		}
	}
	if (parent.right_!=nullptr){
		std::string child_search_right = path_to(parent.right_, target);
		if (child_search_right==""){
			return ("R");
		}
		else if (child_search_right!="0") {
			return ("R" + child_search_right);
		}
	}
	
	return("0");
	/*If no items found in tree the returned value is "0"*/
}

tree_ptr_t node_at(tree_ptr_t tree, std::string path) {
	if (path==""){
		return tree;
	}
	char next_direction = path.front();
	std::string remaining_path = path.substr(1);
	if (next_direction == 'L'){
		return node_at(tree->left_, remaining_path);
	}
	else if (next_direction == 'R'){
		return node_at(tree->right_, remaining_path);
	}
	return nullptr;

}
