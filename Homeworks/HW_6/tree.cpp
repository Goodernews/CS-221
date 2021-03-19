#include <iostream>
using namespace std;


using key_t = int;
using value_t = uint64_t;

struct Tree {
	key_t key_;
	value_t value;
	Tree* left_ = nullptr;
	Tree* right_ = nullptr;
};



void destroy_tree(Tree parent){
	if (parent.left_!=nullptr){
		destroy_node_and_children(parent->left_);
	}
	if (parent.right_!=nullptr){
		destroy_node_and_children(parent->right_);
	}
	delete *parent;
}

int path_to (Tree parent, value_t target){
	if(parent.value==target){
		return ("");
	}
	if (parent.left_!=nullptr){
		char child_search_left = path_to(parent->left_);
		if (child_search_left=="0"){
			goto check_right;
		}
		else if(child_search_left==""){
			return ("L");
		}
		else{
			return ("L" + child_search_left);
		}
	}
check_right:
	if (parent.right_!=nullptr){
		char child_search_right = path_to(parent->right_);
		if (child_search_right=="0"){
			goto none_found;
		}
		else if(child_search_right==""){
			return ("R");
		}
		else{
			return ("R" + child_search_right);
		}
	}
none_found:
	return("0");
}
