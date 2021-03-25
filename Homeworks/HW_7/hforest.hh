//Store trees in list, organize list with make_heap

#pragma once

#include <list>
#include <memory>
//#include <vector>

#include "htree.hh"

//Can/should I just put this right in the header file??
bool compare_trees(HTree::tree_ptr_t t1, HTree::tree_ptr_t t2) {  // Eitan's compare_trees() function
    return t1->get_value() < t2->get_value();
}

class HForest{

public:
	using size_t = int;
	using forest_ptr_t = std::shared_ptr<const HForest>;

    size_t size;
    list<HTree::tree_ptr_t> entries;

	//Initialization:
	HForest(HTree firstForestTree): entries{firstForestTree} {};   // Create a new HForest, with firstForestTree as the first entry in it
	HForest();  // Default forest: no entries
	~HForest();

	size_t size(forest_ptr_t forest);  // Return how many tree_ptr_t are in the forest
    // add_tree() is defined here, inline, since we need to access HForest.entries without passing some sort of reference to HForest when we call the function
	void add_tree(HTree::tree_ptr_t tree) { entries.push_back(tree); std::make_heap(entries.begin(), entries.end(), compare_trees()) };  // Take a pointer to an HTree (of type HTree::tree_ptr_t) and add it to the forest

    HTree::tree_ptr_t pop_tree(forest_ptr_t forest); //  Return a pointer to the HTree with the highest value in the root node, and remove it from the forest.

};



