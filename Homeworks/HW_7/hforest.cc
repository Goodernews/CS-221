#include "hforest.hh"


//Can/should I just put this right in the header file??
bool compare_trees(HTree::tree_ptr_t t1, HTree::tree_ptr_t t2) {  // Eitan's compare_trees() function
    return t1->get_value() < t2->get_value();
}


HForest::HForest(HTree::tree_ptr_t firstForestTree) {
    entries.push_back(firstForestTree);
}


// Implemented this functionality in the applicable functions (add_tree(), pop_tree()) in hforest.hh
//void makeHForestHeap(HForest::forest_ptr_t forest){}

//HForest::size_t HForest::size(HForest::forest_ptr_t forest){  // Return how many trees are in the forest
//
//    if(forest == nullptr){  // If forest is a nullptr, we don't wanna do anything else with this function, so we return 0
//        return 0;
//    }
//
//    HForest deRefForest = *forest;  // Dereference forest so that we can access it and its data
//    return deRefForest.entries.size();  // Return the size() of the "entries" list of the HForest
//}

HForest::size_t HForest::size() const{  // Return how many trees are in the forest
    return size_;
}

// add_tree() is implemented in hforest.hh
//void HForest::add_tree(HTree::tree_ptr_t tree){} //  Take a pointer to an HTree (of type HTree::tree_ptr_t) and add it to the forest

//pop_tree Plan:
    // create reference of some sort to HForest.entries[0]
        //HForest.entries is a list of *pointers*, not of the trees themselves. Thus, deleting an entry from entries won't delete the tree, but will delete the pointer from the tree.
    // use list methods to remove the entry from entries
    // return the reference we created

HTree::tree_ptr_t HForest::pop_tree(){    //  Return a pointer to the HTree with the highest value in the root node, and remove it from the forest.



    //THIS IS WHERE BEHAVIOR MAY BREAK
    // The forest will, presumably, already have its entries in heap order, since add_tree() runs make_heap() after adding a new tree to entries. Thus, the tree with the highest-value root node will be the first entry
        // THE FOLLOWING 2 LINES IN PARTICULAR ARE SUS
    //HTree maxRootNode                   = *(deRefForest.entries.front());   // dereference the desired root node
    HTree::tree_ptr_t maxRootNode       = entries.front();   // dereference the desired root node
    //HTree::tree_ptr_t maxRootNodePtr    = &maxRootNode;    //  This makes a new tree_ptr_t to the desired root node

        //*HOPEFULLY* this won't actually delete the thing we wanna return a reference to...
    //deRefForest.entries.pop_front();    // Remove the desired node from the list
    //deRefForest.entries.erase(deRefForest.entries.begin());

    return maxRootNode;
}

void HForest::add_tree(HTree::tree_ptr_t tree) {
    entries.push_back(tree);
    std::make_heap(entries.begin(), entries.end(), compare_trees);
    size_ = size_ + 1;
}




