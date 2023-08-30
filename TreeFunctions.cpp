#include "TreeFunctions.h"
#include <iostream>
using namespace std;

bool wrote = false;

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
