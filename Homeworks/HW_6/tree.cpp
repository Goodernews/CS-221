#include <iostream>
#include <string>
#include "tree.hh"

using namespace std;


tree_ptr_t create_tree(	const key_t& key,
			const value_t& value,
			tree_ptr_t left = nullptr,
			tree_ptr_t right = nullptr){
	tree_ptr_t temp = Tree(key_=key, value_=value, left_=left, right_=right);
	free(temp);
	return temp;
}


void destroy_tree(tree_ptr_t parent){
	if (parent.left_!=nullptr){
		destroy_tree(*parent.left_);
	}
	if (parent.right_!=nullptr){
		destroy_tree(*parent.right_);
	}
	delete (parent);
}


const char*  path_to (Tree parent, value_t target){
	if(parent.value_==target){
		return ("");
	}
	if (parent.left_!=nullptr){
		char child_search_left = path_to(*parent.left_, target);
		if(child_search_left==""){
			return ("L");
		}
		else if (child_search_left!="0"){
			return ("L" + child_search_left);
		}
	}
	if (parent.right_!=nullptr){
		char child_search_right = path_to(*parent.right_, target);
		else if (child_search_right==""){
			return ("R");
		}
		else {
			return ("R" + child_search_right);
		}
	}
	
	return("0");

}       

value_t	node_at(Tree parent, char path){
	if (path==""){
		return parent.value_;
	}
	char next_direction = path.front();
	char remaining_path = path.erase(0,1);
	else if (next_direction = "L"){
		return node_at(*parent.left_, remaining_path);
	}
	else if (next_direction = "R"){
		return node_at(*parent.right_, remaining_path);
	}

}
