#include "TreeFunctions.h"
#include <iostream>
using namespace std;

// Parameters
bool wrote = false;          // A flag indicating whether a node has been printed or not.
int gLevel = -1;             // The current level of the node or nullptr being processed.
bool gCompleteTree = true;   // A flag indicating whether the tree is considered complete or not.
int gDepth = 0;              // The maximum depth to which nodes are being checked.
bool gLevelUp = false;       // A flag indicating if the traversal has gone up a level at least once.

/**
 * Traverses a binary tree and writes the ID of every other leaf node in a top-down manner.
 * A leaf node is a node with no left or right child. The writing starts from the rightmost leaf node
 * and alternates between writing and not writing on consecutive leaf nodes.
 *
 * @param node A pointer to the root of the binary tree to traverse.
 */
void TreeFunctions::writeEveryOtherLeafNode(Node* node){
    if(node){
        writeEveryOtherLeafNode(node->right);    //Goes to the right leaf node first

        if(wrote && !node->left && !node->right)    {   // Checks if something is printed
            cout << node->ID << '\n';
            wrote = false;                              // Set wrote to false
        }   else if (!node->left && !node->right)   {   // Checks if leaf node
            wrote = true;
        }
        writeEveryOtherLeafNode(node->left);       // Check nodes at the left
    }
}

/**
 * Counts the number of nodes in a binary tree that have values greater than a specified value.
 *
 * @param node A pointer to the root of the binary tree or subtree to be counted.
 * @param value The threshold value against which node values are compared.
 * @return The count of nodes with values greater than 'value' in the binary tree or subtree.
 */
int TreeFunctions::countBigger(Node* node, int value){
    if(node){                                               // If there is a node there, the code is executed
        if(value < node->ID && value != node->ID){          // If a node is larger than the value should be
            return countBigger(node->left, value) +   // +1 is returned
            countBigger(node->right, value) + 1;
        } else{
            return 0;                                       // Returns 0 if there are no nodes larger
        }
    }
}

/**
 * Checks whether the value of a node is greater than its children's values in a binary tree.
 * This function recursively traverses the binary tree and ensures that a parent node's value is greater
 * than or equal to its children's values.
 *
 * @param node A pointer to the node being examined in the binary tree or subtree.
 * @return 'true' if the value of the current node is greater than or equal to its children's values,
 *         'false' otherwise.
 */
bool TreeFunctions::greaterThanChildren(Node* node){
    if(node){               //Checks if the node is a nullptr
        if((node->left && node->ID < node->left->ID) ||
           (node->right && node->ID < node->right->ID)) {
            return false;   // Returns false if the node to the left or right is larger than the current node
        }
        else {
            return greaterThanChildren(node->left) && //Recursively checks the tree preorder
                   greaterThanChildren(node->right);
        }
    } else
    return true;            // Returns true if you have gone through the whole thing without errors
}


/**
 * Checks if a binary tree is a complete tree, considering the levels and depths of its nodes.
 * This function traverses the binary tree in a postorder manner while comparing levels and depths of nodes
 * to determine if the tree meets the criteria of a complete tree. A complete tree is defined as a tree where
 * all levels are fully filled except possibly for the last level, which is filled left to right.
 *
 * @param node A pointer to the node being examined in the binary tree or subtree.
 */
void TreeFunctions::isCompleteTree(Node* node) {
    if(node && gCompleteTree) {
        gLevel++; // Increment the level as we are traversing down the tree initially
        if(gDepth < gLevel) { // If depth is less than the current level, increase depth by 1
            gDepth += 1; // Set the depth if the current leaf node is the lowest
            if(!(node->left && node->right) && !gLevelUp) // At the first leaf node, start
                gLevelUp = true; // traversing back up the tree
        }
        isCompleteTree(node->right); // Traverse right, then left in a postorder manner recursively
        isCompleteTree(node->left);

        if((!node->left && node->right) // If there's a node to the right but not left at any point,
           // it's not a complete tree since it must be filled from the left
           || ((!node->left || !node->right) && (gLevel < gDepth-1)) // If the node lacks children and is one level above
           // the depth, it's not a complete tree
           || (gLevelUp && !node->right && node->left)) {
            gCompleteTree = false; // Set gCompleteTree to false since the tree is not complete
            return;
        }
        gLevel--; // Decrement the level as we move back up the tree
    }
}

/**
 * Counts the number of leaf nodes in a binary tree.
 *
 * @param node A pointer to the node being examined in the binary tree or subtree.
 * @return The count of leaf nodes in the binary tree or subtree.
 */
int TreeFunctions::countLeafNodes(Node* node) {
    if(node == nullptr)
        return 0;
    if(node->left == nullptr && node->right == nullptr)
        return 1;
    return countLeafNodes(node->left) + countLeafNodes(node->right);
}

/**
 * Mirrors a binary tree by swapping the left and right subtrees of each node.
 * This function recursively traverses the binary tree and swaps the left and right subtrees of each node,
 * effectively creating a mirror image of the original tree.
 *
 * @param node A pointer to the node being processed in the binary tree or subtree.
 */
void TreeFunctions::mirrorTree(Node* node) {
    if (node != nullptr) {
        Node* tmp = node->left;    // Store a temporary copy of the left subtree
        node->left = node->right;  // Swap the left and right subtrees
        node->right = tmp;         // Set the right subtree to the temporary left subtree
        mirrorTree(node->left);        // Recursively mirror the left subtree
        mirrorTree(node->right);       // Recursively mirror the right subtree
    }
}

/**
 * Converts a sorted linked list into a Balanced Binary Tree (BBT).
 *
 * @param len The length of the linked list segment to be converted.
 * @return A pointer to the root of the Balanced Binary Tree.
 */
Node* TreeFunctions::convertListToBBT(int len) {
    if (len == 0) {
        return nullptr;
    }

    // Recursively convert the left half of the linked list
    Node* left = convertListToBBT(len / 2);

    Node* head = root;   // Store the current root
    head->prev_left = left;
    root = root->next_right; // Move root to the next node

    // Recursively convert the right half of the linked list
    Node* right = convertListToBBT(len - (len / 2) - 1);
    head->next_right = right;

    return head;
}

/**
 * Transforms a binary tree to a doubly linked list while maintaining the order of nodes.
 *
 * @param node A pointer to the root of the binary tree or subtree to be transformed.
 * @return A pointer to the head of the transformed doubly linked list.
 */
Node* TreeFunctions::transformBTToList(Node* node) {
    if (node->prev_left != nullptr) {
        // Recursively transform the left subtree and find the last node
        Node* prev = transformBTToList(node->prev_left);
        while (prev->next_right != nullptr)
            prev = prev->next_right;

        // Adjust pointers to connect the previous node's next to the current node
        prev->next_right = node;
        node->prev_left = prev;
    }
    if (node->next_right != nullptr) {
        // Recursively transform the right subtree and find the first node
        Node* next = transformBTToList(node->next_right);
        while (next->prev_left != nullptr)
            next = next->prev_left;

        // Adjust pointers to connect the next node's previous to the current node
        next->prev_left = node;
        node->next_right = next;
    }
    return node;
}

/**
 * Traverses and prints the IDs of the nodes along the rightmost path of the binary tree.
 */
void TreeFunctions::rightmostPathTraversal() {
    Node* node = root; // Start traversal from the root node
    while (node != z) { // Traverse until the sentinel node 'z' is encountered
        cout << node->ID << ' '; // Print the ID of the current node
        node = (node->right != z) ? node->right : node->left; // Move to the right child if it's not 'z',
                                                                // otherwise move to the left child
    }
}

/**
 * Prints the path from a specified node's value to the root of the binary tree.
 *
 * @param node A pointer to the node from which the path to the root is to be printed.
 */
void TreeFunctions::printPathToRoot(Node* node) {
    int id = node->ID;
    node = root;
    while (node != z) {
        cout << node->ID << ' '; // Print the value of the current node in the path
        node = (id < node->ID) ? node->left : node->right; // Move up the tree based on comparison
    }
}

/**
 * Recursively prints the paths from each leaf node's value to the root of the binary tree.
 *
 * @param p A pointer to the node from which the paths to the root are to be printed.
 */
void TreeFunctions::printPathsToRootFromLeaves(Node* node) {
    if (node != z) {
        if (node->left == z && node->right == z) {
            printPathToRoot(node); // If the node is a leaf, print the path to the root
            cout << '\n';
        }
        printPathsToRootFromLeaves(node->left);  // Recursively print paths from the left subtree
        printPathsToRootFromLeaves(node->right); // Recursively print paths from the right subtree
    }
}

/**
 * Checks if a binary tree is heap-ordered.
 * A binary tree is considered heap-ordered if for every node 'node', the value of 'node' is greater than
 * or equal to the values of its children.
 *
 * @param node A pointer to the node being checked in the binary tree or subtree.
 * @return True if the tree is heap-ordered, otherwise false.
 */
bool TreeFunctions::isHeapOrdered(Node* node) {
    if (node != z) { // If the node is not null
        // Check if the left child exists and has a greater value than the current node
        if (node->left != nullptr && node->left->ID > node->ID)
            return false;

        // Check if the right child exists and has a greater value than the current node
        if (node->right != nullptr && node->right->ID > node->ID)
            return false;

        // Recursively check the left and right subtrees
        return (isHeapOrdered(node->left) && isHeapOrdered(node->right));
    } else {
        // If the node is null, it's considered heap-ordered
        return true;
    }
}


