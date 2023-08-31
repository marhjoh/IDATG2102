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
