#ifndef TREEFUNCTIONS_H
#define TREEFUNCTIONS_H

#include "Node.h"

class TreeFunctions {
public:
    static void writeEveryOtherLeafNode(Node* node);
    static int countBigger(Node* node, int value);
    static bool greaterThanChildren(Node* node);
    static void isCompleteTree(Node* node);
    static int countLeafNodes(Node* node);
    static void mirrorTree(Node* node);
    static Node* convertListToBBT(int len);
    static Node* transformBTToList(Node* node);
    static void rightmostPathTraversal();
    static void printPathToRoot(Node* node);
    static void printPathsToRootFromLeaves(Node* node);
    static bool isHeapOrdered(Node* node);
    };

#endif // TREEFUNCTIONS_H
