#include <deepstate/DeepState.hpp>
using namespace deepstate;

#include "search_lib.h" // Include the code file with the functions to be tested

// Test the addNode function
TEST(TreeTest, AddNodeTest) {
    Tree root = createTree();
    int index = 0;
    double data = 3.14;
    root = addNode(root, data, index);
    ASSERT_EQ(root->data, data);
    ASSERT_EQ(root->index, index);
    ASSERT_EQ(root->left, nullptr);
    ASSERT_EQ(root->right, nullptr);
}

// Test the getData function
TEST(TreeTest, GetDataTest) {
    const char* filename = "data.txt";
    std::ofstream file(filename);
    file << "3.14\n1.23\n2.71\n";
    file.close();
    Tree root = getData(filename);
    ASSERT_NE(root, nullptr);
    ASSERT_EQ(root->data, 3.14);
    ASSERT_EQ(root->index, 0);
    ASSERT_NE(root->left, nullptr);
    ASSERT_EQ(root->left->data, 1.23);
    ASSERT_EQ(root->left->index, 1);
    ASSERT_NE(root->right, nullptr);
    ASSERT_EQ(root->right->data, 2.71);
    ASSERT_EQ(root->right->index, 2);
}

// Test the getFirstOccurrence function
TEST(TreeTest, GetFirstOccurrenceTest) {
    Tree root = createTree();
    root = addNode(root, 3.14, 0);
    root = addNode(root, 1.23, 1);
    root = addNode(root, 2.71, 2);
    ASSERT_EQ(getFirstOccurrence(1.23, root), 1);
    ASSERT_EQ(getFirstOccurrence(42.0, root), -1);
}

// Test the getLastOccurrence function
TEST(TreeTest, GetLastOccurrenceTest) {
    Tree root = createTree();
    root = addNode(root, 3.14, 0);
    root = addNode(root, 1.23, 1);
    root = addNode(root, 2.71, 2);
    ASSERT_EQ(getLastOccurrence(1.23, root), 1);
    ASSERT_EQ(getLastOccurrence(42.0, root), -1);
}

// Test the getAllOccurrences function
TEST(TreeTest, GetAllOccurrencesTest) {
    Tree root = createTree();
    root = addNode(root, 3.14, 0);
    root = addNode(root, 1.23, 1);
    root = addNode(root, 2.71, 2);
    double occurrences[10];
    double numOccurrences;
    getAllOccurrences(3.14, root, occurrences, numOccurrences);
    ASSERT_EQ(numOccurrences, 1);
    ASSERT_EQ(occurrences[0], 0);
    getAllOccurrences(42.0, root, occurrences, numOccurrences);
    ASSERT_EQ(numOccurrences, 0);
}

// Test the push and pop functions
TEST(TreeTest, StackTest) {
    Stack* stack = nullptr;
    Treenode* node = new Treenode;
    node->data = 3.14;
    node->left = nullptr;
    node->right = nullptr;
    push(stack, node);
    Treenode* poppedNode = pop(stack);
    ASSERT_EQ(poppedNode->data, 3.14);
    ASSERT_EQ(poppedNode->left, nullptr);
    ASSERT_EQ(poppedNode->right, nullptr);
    delete poppedNode;
}

// Test the validateTree function
TEST(TreeTest, ValidateTreeTest) {
    Tree validTree = createTree();
    validTree = addNode(validTree, 1.23, 0);
    validTree = addNode(validTree, 0.42, 1);
    validTree = addNode(validTree, 2.0, 2);
    ASSERT_TRUE(validateTree(validTree));

    Tree invalidTree = createTree();
    invalidTree = addNode(invalidTree, 3.14, 0);
    invalidTree = addNode(invalidTree, 4.0, 1);
    invalidTree = addNode(invalidTree, 2.0, 2);
    ASSERT_FALSE(validateTree(invalidTree));
}

// Entry point for running the tests
int main(int argc, char** argv) {
    DeepState_InitOptions(argc, argv);
    DeepState_Run();
    return 0;
}