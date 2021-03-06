#include <stdio.h>
#include <iostream>

#include "hforest.hh"
#include "htree.hh"
#include "huffman.hh"

Huffman::Huffman(){ //because this will start out the same every time, it can be made in advance
	

	HForest forest; //create forest
	
	for(int i=0; i<ALPHABET_SIZE; i++){
	forest.add_tree(std::make_shared<HTree>(i, 0, nullptr, nullptr));
	} //makes a blank huffman forest

	auto encoder_ = build_tree(forest); //turns forest into an encoding tree

}

Huffman::Huffman(HForest forest){
	auto encoder_ = build_tree(forest);
}

HForest  Huffman::break_tree(){
       	// splits alphabet trees into forest
	HForest forest;
	for(int i=0; i<ALPHABET_SIZE; i++){ //assumes there is a value for each node
		auto curr_val = encoder_->search_key(i)->get_value();//find a leaf node val
		forest.add_tree(std::make_shared<HTree>(i, curr_val, nullptr, nullptr)); //add to forest
	}
	
	return forest;
}


HTree::tree_ptr_t Huffman::build_tree(HForest forest){
       	//makes forest into huffman tree
	while(forest.size()>1){ //Pop two trees
		auto smallest_tree = forest.pop_tree();
		if(forest.size()==0){
			return smallest_tree;
		}
		auto small_tree = forest.pop_tree(); //gets smallest trees
		HTree::value_t num_nodes = smallest_tree->get_value() + small_tree->get_value(); //Num children
		auto merged_tree = std::make_shared<HTree>(Huffman::dummy_key_, //to signify it is not a leaf node
				num_nodes, //root value temporarily holds number of leaves in tree
				small_tree, //adds nodes to merging node
				smallest_tree);
		forest.add_tree(merged_tree); //adds merged tree back to the forest
	}

	return forest.pop_tree();//clear forest add base tree to encoder_
}




Huffman::bits_t Huffman::encode(int symbol){
	auto node_pointer = encoder_->search_key(symbol); //find pointer to node with a key
	node_pointer->add_one_val(); ///add one to value of target node frequency
	auto broken_tree_ = break_tree(); //break apart tree into forest
	encoder_ = build_tree(broken_tree_);


	auto enum_path = encoder_->path_to(symbol); //gets path to in form of enum left and rights
	bits_t encode_path;
	for(auto i: *enum_path){
		if (i==HTree::Direction::LEFT){
			encode_path.push_back(true);
		}
		else{
			encode_path.push_back(false);
		}
	}
	return encode_path;
}



int Huffman::decode(bool bits){
	auto node = encoder_;
	
	for(auto i: bits){
		if(node==nullptr){
			return -1;
		}
		if (*i==true){
			node = node->get_child(HTree::Direction::LEFT);
		}
		else{
			node = node->get_child(HTree::Direction::RIGHT);
		}
	}
	
	if (node==nullptr){
		return -1; //if error
	}

	node->sub_one_val();

	return node->get_key(); //symbol to change

}


