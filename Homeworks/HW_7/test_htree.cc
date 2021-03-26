/*
 * test_tree: A simple unit test for the Tree data structure.
 */

#include "htree.hh"
#include <cassert>

using namespace std;

// Create an elaborate example test tree:
HTree::tree_ptr_t create_test_tree()
{
  return make_shared<HTree>(126, 1);
}

void test_htree(const HTree::tree_ptr_t root)
{
  assert(*(root->path_to(126)) == HTree::path_t({ }));
}

void test_get_k_v(const HTree::tree_ptr_t root){
  assert(root->get_key()==126);
}


int main()
{
  auto root = create_test_tree();
  test_htree(root);

  return 0;
}

