//
//  tree.h
//  hd
//
//  Created by Heberth Deza on 4/02/25.
//

#ifndef tree_h
#define tree_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct treeNode {
    struct treeNode * leftNodePtr;
    int data;
    struct treeNode * rightNodePtr;
} TreeNode;

void myBinaryTree(void);
void insertTreeNode(TreeNode ** headNodePtr, int num);
void printInOrder(TreeNode * headNodePtr);
void printInPreOrder(TreeNode * headNodePtr);
void printInPostOrder(TreeNode * headNodePtr);

#endif /* tree_h */
