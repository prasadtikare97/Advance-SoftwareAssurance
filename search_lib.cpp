#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include "search_lib.h" // Include the code file with the functions to be tested

const int NOT_FOUND = -1;
const char SPECIFIER[] = "%.2f";

typedef double dtype;
typedef Treenode* Node;
typedef Treenode* Tree;

Tree createTree() {
    Tree root = nullptr;
    return root;
}

void printTree(Tree root) {
    if (root == nullptr) {
        return;
    }
    std::cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}

Tree addNode(Tree root, dtype data, int index) {
    if (root == nullptr) {
        Treenode* newNode = new Treenode;
        newNode->data = data;
        newNode->index = index;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }
    if (data < root->data) {
        root->left = addNode(root->left, data, index);
    } else {
        root->right = addNode(root->right, data, index);
    }
    return root;
}

Tree getData(const char* filename) {
    Tree root = nullptr;
    int index = 0;
    double file_data;
    std::ifstream file1(filename);
    if (!file1) {
        std::cout << "No such file or directory" << std::endl;
        return root;
    }
    while (file1 >> file_data) {
        root = addNode(root, file_data, index);
        index++;
    }
    file1.close();
    return root;
}

int getFirstOccurrence(dtype element, Tree root) {
    if (root == nullptr) {
        return NOT_FOUND;
    }
    while (root != nullptr) {
        if (element == root->data) {
            return root->index;
        } else if (element < root->data) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return NOT_FOUND;
}

int getLastOccurrence(dtype element, Tree root) {
    if (root == nullptr) {
        std::cout << "\nTree is Empty." << std::endl;
        return NOT_FOUND;
    }
    int lastIndex = -1;
    Treenode* current = root;
    while (current != nullptr) {
        if (element < current->data) {
            current = current->left;
        } else if (element > current->data) {
            current = current->right;
        } else {
            Treenode* leftSubtree = current->left;
            while (leftSubtree != nullptr) {
                if (leftSubtree->data == element) {
                    lastIndex = leftSubtree->index;
                    leftSubtree = leftSubtree->left;
                } else {
                    leftSubtree = nullptr;
                }
            }
            lastIndex = current->index;
            current = current->right;
        }
    }
    return lastIndex;
}

void getAll(dtype element, Tree root, dtype occurrences[], dtype& numOccurrences) {
    if (root != nullptr) {
        if (element == root->data) {
            occurrences[numOccurrences] = root->index;
            numOccurrences++;
        }
        getAll(element, root->left, occurrences, numOccurrences);
        getAll(element, root->right, occurrences, numOccurrences);
    }
}

void getAllOccurrences(dtype element, Tree root, dtype occurrences[], dtype& numOccurrences) {
    numOccurrences = 0;
    getAll(element, root, occurrences, numOccurrences);
}

void push(Stack*& stack, Treenode* node) {
    Node newNode = new Treenode;
    newNode->data = node->data;
    newNode->left = nullptr;
    newNode->right = nullptr;

    Stack* newStackNode = new Stack;
    newStackNode->data = newNode;
    newStackNode->next = stack;
    stack = newStackNode;
}

Treenode* pop(Stack*& stack) {
    if (stack == nullptr) {
        return nullptr;
    }
    Stack* tempNode = stack;
    stack = stack->next;

    Treenode* poppedNode = new Treenode;
    poppedNode->data = tempNode->data->data;
    poppedNode->left = nullptr;
    poppedNode->right = nullptr;

    delete tempNode->data;
    delete tempNode;
    return poppedNode;
}


bool validateTree(Tree root) {
    if (root == nullptr) {
        return true; // An empty tree is a valid BST
    }

    Stack* stack = nullptr;
    Treenode* current = root;
    Treenode* previous = nullptr;

    while (current != nullptr || stack != nullptr) {
        // Traverse the left subtree
        while (current != nullptr) {
            // Push the node to stack
            stack = new Stack{current, stack};
            current = current->left;
        }

        // Pop the top node
        current = stack->data;
        stack = stack->next;
        previous = current->right;

        // Check if the current node's data is smaller than or equal to the previous node's data
        if (previous != nullptr && current->data <= previous->data) {
            return false; // Tree is not a BST
        }

        // Move current
        current = current->right;
    }

    return true;
}

char getChoiceYN()
{
    char choice;
    char lowerChoice;

    while (true) {
        std::cin >> choice;
        lowerChoice = std::tolower(choice);

        if (lowerChoice == 'y' || lowerChoice == 'n') {
            return lowerChoice;
        } else {
            std::cout << "Invalid option. Please type 'y' to restart or 'n' to exit:" << std::endl;
        }
    }
}

void saveData(const char* filename, Treenode* root)
{
    std::ofstream file2(filename, std::ios_base::app);
    if (!file2) {
        std::cout << "Error opening file." << std::endl;
        return;
    }

    if (root != nullptr) {
        // Write data to the file in preorder
        file2 << root->data << std::endl;

        // Recursive call to left and right
        saveData(filename, root->left);
        saveData(filename, root->right);
    }

    file2.close();
}