#include "tree.h"
#include <iostream>

BinarySearchTree::BinarySearchTree() {
    root = nullptr;
}

BinarySearchTree::~BinarySearchTree() {
    deleteTree(root);
}

void BinarySearchTree::insert(int key) {
    root = insertRecursive(root, key);
}

Node* BinarySearchTree::insertRecursive(Node* node, int key) {
    if (node == nullptr) {
        Node* newNode = new Node();
        newNode->key = key;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    if (key < node->key) {
        node->left = insertRecursive(node->left, key);
    } else if (key > node->key) {
        node->right = insertRecursive(node->right, key);
    }

    return node;
}

bool BinarySearchTree::search(int key) {
    return searchRecursive(root, key);
}

bool BinarySearchTree::searchRecursive(Node* node, int key) {
    if (node == nullptr) {
        return false;
    }

    if (key == node->key) {
        return true;
    } else if (key < node->key) {
        return searchRecursive(node->left, key);
    } else {
        return searchRecursive(node->right, key);
    }
}

void BinarySearchTree::remove(int key) {
    root = removeRecursive(root, key);
}

Node* BinarySearchTree::removeRecursive(Node* node, int key) {
    if (node == nullptr) {
        return nullptr;
    }

    if (key < node->key) {
        node->left = removeRecursive(node->left, key);
    } else if (key > node->key) {
        node->right = removeRecursive(node->right, key);
    } else {
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            return nullptr;
        } else if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        } else {
            Node* temp = findMin(node->right);
            node->key = temp->key;
            node->right = removeRecursive(node->right, temp->key);
        }
    }

    return node;
}

Node* BinarySearchTree::findMin(Node* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

void BinarySearchTree::inorderTraversal() {
    inorderTraversalRecursive(root);
    std::cout << std::endl;
}

void BinarySearchTree::inorderTraversalRecursive(Node* node) {
    if (node != nullptr) {
        inorderTraversalRecursive(node->left);
        std::cout << node->key << " ";
        inorderTraversalRecursive(node->right);
    }
}

void BinarySearchTree::preorderTraversal() {
    preorderTraversalRecursive(root);
    std::cout << std::endl;
}

void BinarySearchTree::preorderTraversalRecursive(Node* node) {
    if (node != nullptr) {
        std::cout << node->key << " ";
        preorderTraversalRecursive(node->left);
        preorderTraversalRecursive(node->right);
    }
}

void BinarySearchTree::postorderTraversal() {
    postorderTraversalRecursive(root);
    std::cout << std::endl;
}

void BinarySearchTree::postorderTraversalRecursive(Node* node) {
    if (node != nullptr) {
        postorderTraversalRecursive(node->left);
        postorderTraversalRecursive(node->right);
        std::cout << node->key << " ";
    }
}

void BinarySearchTree::deleteTree(Node* node) {
    if (node != nullptr) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}
