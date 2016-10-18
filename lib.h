#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct bin_tree {
    int data;
    struct bin_tree * right, * left;
} node;

void insert(node **tree, int val);
node *search(node **tree, int val);
void deltree(node *tree);
void print_preorder(node *tree);
void print_inorder(node *tree);
void print_postorder(node *tree);
node *FindMin(node *tree);
node* Delete(node *tree, int val);
void print_tree(node *tree, int l);

#endif // LIB_H_INCLUDED
