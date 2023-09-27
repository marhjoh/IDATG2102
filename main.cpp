#include <iostream>
#include "Node.h"
#include "TreeFunctions.h"

/**
 * Main function to demonstrate the insertion of values into a binary search tree.
 */
int main() {
    // Create an instance of the TreeFunctions class to manage the binary search tree.

    // Insert values into the binary search tree.
    TreeFunctions::insert(17);
    TreeFunctions::insert(22);
    TreeFunctions::insert(19);
    TreeFunctions::insert(12);
    TreeFunctions::insert(4);
    TreeFunctions::insert(24);
    TreeFunctions::insert(8);
    TreeFunctions::insert(6);
    TreeFunctions::insert(10);
    TreeFunctions::insert(15);
    TreeFunctions::insert(13);
    TreeFunctions::insert(20);

    /*
     * The binary search tree will look like this:
     *
     *                17
     *               /  \
     *             12   22
     *            /  \     \
     *           4    15     24
     *            \   / \     /
     *            8  13  19  20
     *             \
     *             10
     *
     * In-order traversal of this tree will give a sorted sequence of values.
     *
     */
}


