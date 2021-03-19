#include <iostream>
#include <string>

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
		destroy_node_and_children(*parent.left_);
	}
	if (parent.right_!=nullptr){
		destroy_node_and_children(*parent.right_);
	}
	delete parent;
}

int path_to (Tree parent, value_t target){
	if(parent.value==target){
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
		else if(child_search_right==""){
			return ("R");
		}
		else{
			return ("R" + child_search_right);
		}
	}
	
	return("0");
}

value_t node_at(Tree parent, char path){
	if (path==""){
		return parent.value;
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
