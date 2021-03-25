#include "hforest.hh"


// Implemented this functionality in the applicable functions (add_tree(), pop_tree()) in hforest.hh
//void makeHForestHeap(HForest::forest_ptr_t forest){
//
//    int vecBegin = *forest.entries.begin();
//    int vecEnd   = *forest.entries.end();
//
//    std::make_heap(vecBegin, vecEnd, compare_trees());  // Make the entries vector a heap
//}

size_t HForest::size(HForest::forest_ptr_t forest){  // Return how many trees are in the forest

    if(forest == nullptr){  // If forest is a nullptr, we don't wanna do anything else with this function, so we return 0
        return 0;
    }

    HForest deRefForest = *forest;  // Dereference forest so that we can access it and its data
    return deRefForest.entries.size();  // Return the size() of the "entries" vector of the HForest
}

// add_tree() is implemented in hforest.hh
//void HForest::add_tree(HTree::tree_ptr_t tree){ //  Take a pointer to an HTree (of type HTree::tree_ptr_t) and add it to the forest
//
//}

//Plan:
    // create reference of some sort to HForest.entries[0]
    // use a vector method to remove the entry from entries
    // return the reference we created

HTree::tree_ptr_t HForest::pop_tree(HForest::forest_ptr_t forest){    //  Return a pointer to the HTree with the highest value in the root node, and remove it from the forest.
    if(forest == nullptr){  // If forest is a nullptr, we won't do anything else with this function, so we immediately return nullptr
        return nullptr;
    }
    HForest deRefForest = *forest;
    // The forest will, presumably, already have its entries in heap order, since add_tree() runs make_heap() after adding a new tree to entries. Thus, the tree with the highest-value root node will be the first entry
    HTree()
}



