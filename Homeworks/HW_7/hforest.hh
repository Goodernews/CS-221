//Store trees in list, organize list with make_heap

#pragma once

#include <vector>
#include <memory>

#include "htree.hh"

#pragma once

class HForest{

 public:
    using size_t = int;
	using forest_ptr_t = std::shared_ptr<HForest>;

    size_t size_ {0};
    std::vector<HTree::tree_ptr_t> entries;

	//Initialization:
	HForest(HTree::tree_ptr_t firstForestTree); // Create a new HForest, with firstForestTree as the first entry in it
	//HForest();  // Default forest: no entries
	~HForest() = default;

	//size_t size(forest_ptr_t forest);  // Return how many tree_ptr_t are in the forest
    size_t size() const;  // Return how many tree_ptr_t are in the forest
    // add_tree() is defined here, inline, since we need to access HForest.entries without passing some sort of reference to HForest when we call the function
	void add_tree(HTree::tree_ptr_t tree) ;  // Take a pointer to an HTree (of type HTree::tree_ptr_t) and add it to the forest

    HTree::tree_ptr_t pop_tree(); //  Return a pointer to the HTree with the highest value in the root node, and remove it from the forest.

};



