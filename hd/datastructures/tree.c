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
       Siblings: right and child nodes at the same level (same Parent).
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
    puts("");
}

void insertTreeNode(TreeNode ** headNodePtr, int num) {
    if (*headNodePtr == NULL) {
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
    
    // store the num of the parent
    int parentNum = (*headNodePtr)->data;
    if (num > parentNum) {// if num is grater than headNum, put it on the right node
        insertTreeNode(&((*headNodePtr)->rightNodePtr), num);
    } else if (num < parentNum) { // if num is less than headNum, put it on the left node
        insertTreeNode(&((*headNodePtr)->leftNodePtr), num);
    } else { // if equal, omit value
        puts("[duplicated]");
    }
}
