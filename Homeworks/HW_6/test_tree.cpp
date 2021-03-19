#include <iostream>
#include "tree.cpp"

using namespace std;

int main(){
	cout << "Building Root of tree" <<endl;
	tree_ptr_t test_tree = create_tree(1,1);
	cout << "Root value is: " << test_tree->value_ <<endl;
		
	cout << "\nAdding two children and grand children" <<endl;
	test_tree->left_ = create_tree(12,5, create_tree(85,9), create_tree(85, 2)); 
	test_tree->right_ = create_tree(100, 9, create_tree(101, 3), create_tree(4, 500));
	cout << "Left node value: " << test_tree->left_->value_ << endl;
	cout << "Right node value: " << test_tree->right_->value_ << endl;

	cout << "\nPath to first 5 value: " << path_to(test_tree, 5) << endl;
	cout << "Path to node with value 2: " << path_to(test_tree, 2) << endl;

	cout << "\nNode at LR: " << node_at(test_tree, "LR")->value_ << endl;
	cout << "Node at RR: " << node_at(test_tree, "RR")->value_ << endl;
	cout << "Node at R: " << node_at(test_tree, "R")->value_ << endl;

	cout << "\nDeleting tree" <<endl;
	destroy_tree(test_tree);

	cout << "\nTasks completed Succesfully!" <<endl;
	return 0;
}
