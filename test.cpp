#include <deepstate/DeepState.hpp>
#include "tree.h"

using namespace deepstate;

TEST(BinarySearchTree, InsertSearchRemove) {
    BinarySearchTree bst;

    // Insert random keys into the tree
    for (int i = 0; i < 100; ++i) {
        int key = DeepState_IntInRange(0, 1000);
        bst.insert(key);
    }

    // Search for random keys
    for (int i = 0; i < 100; ++i) {
        int key = DeepState_Int();
        bst.search(key);
    }

    // Remove random keys
    for (int i = 0; i < 100; ++i) {
        int key = DeepState_Int();
        bst.remove(key);
    }
}

TEST(BinarySearchTree, Traversal) {
    BinarySearchTree bst;

    // Insert random keys into the tree
    for (int i = 0; i < 100; ++i) {
        int key = DeepState_IntInRange(0, 1000);
        bst.insert(key);
    }

    // Perform traversal
    bst.inorderTraversal();
    bst.preorderTraversal();
    bst.postorderTraversal();
}

TEST(BinarySearchTree, EmptyTree) {
    BinarySearchTree bst;

    // Perform operations on an empty tree
    ASSERT_FALSE(bst.search(10));
    bst.remove(10);
}

TEST(BinarySearchTree, RemoveRoot) {
    BinarySearchTree bst;

    // Insert a key and remove it
    bst.insert(50);
    bst.remove(50);
    ASSERT_FALSE(bst.search(50));
}

TEST(BinarySearchTree, RemoveNonexistentKey) {
    BinarySearchTree bst;

    // Insert some keys
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);

    // Try removing a key that doesn't exist
    bst.remove(40);
    ASSERT_FALSE(bst.search(40));
}

