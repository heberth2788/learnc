//
//  tree.c
//  hd
//
//  Created by Heberth Deza on 4/02/25.
//

#include "tree.h"

/**
    Trees
 
       Non-linear data structure (two dimensional data structure)
       Binary tree, a 'Parent node' contains two links(self-referential right and left childs)
       Root node: is the first node in the tree.
       Siblings: child nodes at the same level (same Parent).
       Leaft node: a node without children.
 */

// Binary tree that contain the left child less than its parent node
// and the right child greater than its parent node.
void myBinaryTree(void) {
    TreeNode * headNodePtr = NULL;
    srand(time(NULL));
    
    puts("\tBINARY-TREE data structure\n");
    printf("%s", "Elements to add to the binary tree:\n");
    
    int item = 0;
    for (int i=0; i < 10; i++) {
        item = rand() % 15; // random values from 0 to 14
        printf("%3d ", item);
        insertTreeNode(&headNodePtr, item);
    }
    
    puts("\nPrinting tree in order");
    printInOrder(headNodePtr);
    
    puts("\n\nPrinting tree in pre-order");
    printInPreOrder(headNodePtr);
    
    puts("\n\nPrinting tree in post-order");
    printInPostOrder(headNodePtr);
    
    puts("\n");
}

// recursive algorithm to insert a node into a tree
void insertTreeNode(TreeNode ** headNodePtr, int num) {
    // check if NULL
    if (headNodePtr == NULL || *headNodePtr == NULL) {
        // create the tree-node
        TreeNode * newNode = malloc(sizeof(TreeNode));
        if (newNode == NULL) {
            printf("\t[%d] could not be inserted, no memory available\n", num);
            return;
        }
        newNode->leftNodePtr = NULL;
        newNode->data = num;
        newNode->rightNodePtr = NULL;
        
        *headNodePtr = newNode;
        puts("[inserted]");
        return;
    }
    
    
    int parentNum = (*headNodePtr)->data; // store the parent's num
    if (num > parentNum) {// if num is grater than headNum, put it on the right child
        insertTreeNode(&((*headNodePtr)->rightNodePtr), num);
    } else if (num < parentNum) { // if num is less than headNum, put it on the left child
        insertTreeNode(&((*headNodePtr)->leftNodePtr), num);
    } else { // if equal, omit value
        puts("[duplicated]");
    }
}

// recursive algorithm to print the tree in order
void printInOrder(TreeNode * headNodePtr) {
    if(headNodePtr != NULL) {
        printInOrder(headNodePtr->leftNodePtr);
        printf("[%d] ", headNodePtr->data);
        printInOrder(headNodePtr->rightNodePtr);
    }
}

// recursive algorithm to print the tree in pre-order
void printInPreOrder(TreeNode * headNodePtr) {
    if(headNodePtr != NULL) {
        printf("[%d] ", headNodePtr->data);
        printInOrder(headNodePtr->rightNodePtr);
        printInOrder(headNodePtr->leftNodePtr);
    }
}


// recursive algorithm to print the tree in post-order
void printInPostOrder(TreeNode * headNodePtr) {
    if(headNodePtr != NULL) {
        printInOrder(headNodePtr->leftNodePtr);
        printInOrder(headNodePtr->rightNodePtr);
        printf("[%d] ", headNodePtr->data);
    }
}
