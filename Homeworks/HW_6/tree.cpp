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


std::string path_to(tree_ptr_t tree, key_t key) {
	if(tree->key_ == key){
		return ("");
	}
	if (tree->left_ != nullptr){
		std::string child_search_left = path_to(tree->left_, key);
		if(child_search_left == ""){
			return ("L");
		}
		else if (child_search_left!="-"){
			return ("L" + child_search_left);
		}
	}
	if (tree->right_ != nullptr){
		std::string child_search_right = path_to(tree->right_, key);
		if (child_search_right == ""){
			return ("R");
		}
		else if (child_search_right != "-") {
			return ("R" + child_search_right);
		}
	}
	
	return("-");
	/*If no items found in tree the returned value is "-"*/
}

tree_ptr_t node_at(tree_ptr_t tree, std::string path) {
	if (path==""){
		return tree;
	}
	if (tree==nullptr){
		return nullptr;
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
