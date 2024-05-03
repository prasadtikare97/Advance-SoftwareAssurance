#ifndef TREE_H
#define TREE_H

struct Node {
    int key;
    Node* left;
    Node* right;
};

class BinarySearchTree {
public:
    BinarySearchTree();
    ~BinarySearchTree();

    void insert(int key);
    bool search(int key);
    void remove(int key);
    void inorderTraversal();
    void preorderTraversal();
    void postorderTraversal();

private:
    Node* root;

    Node* insertRecursive(Node* node, int key);
    bool searchRecursive(Node* node, int key);
    Node* removeRecursive(Node* node, int key);
    Node* findMin(Node* node);
    void inorderTraversalRecursive(Node* node);
    void preorderTraversalRecursive(Node* node);
    void postorderTraversalRecursive(Node* node);
    void deleteTree(Node* node);
};

#endif
