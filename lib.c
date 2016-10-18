#include "lib.h"

void print_tree(node *tree, int l)
{
  int i;
  if(!tree) {
    return;
  }
  print_tree(tree->right, l+1);
  for(i = 0; i < l; ++i) {
    printf(" ");
  }
  printf("%d\n", tree->data);
  print_tree(tree->left, l+1);
}


void insert(node **tree, int val) {
    node *temp = NULL;
    if(!(*tree)) {
        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }
    if(val < (*tree)->data) {
        insert(&(*tree)->left, val);
    } else if(val > (*tree)->data) {
        insert(&(*tree)->right, val);
    }
}

node *search(node **tree, int val) {
    if(!(*tree)) {
        return NULL;
    }
    if(val == (*tree)->data) {
        return *tree;
    } else if(val < (*tree)->data) {
        search(&((*tree)->left), val);
    } else if(val > (*tree)->data){
        search(&((*tree)->right), val);
    }
}

void deltree(node *tree) {
    if (tree) {
        deltree(tree->left);
        deltree(tree->right);
        free(tree);
    }
}

void print_preorder(node * tree) {
    if (tree) {
        printf("%d\n",tree->data);
        print_preorder(tree->left);
        print_preorder(tree->right);
    }
}

void print_inorder(node *tree) {
    if (tree) {
        print_inorder(tree->left);
        printf("%d\n",tree->data);
        print_inorder(tree->right);
    }
}
void print_postorder(node *tree) {
    if (tree) {
        print_postorder(tree->left);
        print_postorder(tree->right);
        printf("%d\n",tree->data);
    }
}

node *FindMin(node *tree) {
	while(tree->left != NULL) {
        tree = tree->left;
	}
	return tree;
}

node* Delete(node *tree, int val) {
	if(tree == NULL) {
        return tree;
	} else if(val < tree->data) {
	    tree->left = Delete(tree->left,val);
	} else if (val > tree->data) {
	    tree->right = Delete(tree->right,val);
	// The value to be deleted was found
	} else {
		// Case 1:  No child
		if(tree->left == NULL && tree->right == NULL) {
			free(tree);
			tree = NULL;
		}
		//Case 2: One child
		else if(tree->left == NULL) {
			node *temp = tree;
			tree = tree->right;
			free(temp);
		} else if(tree->right == NULL) {
			node *temp = tree;
			tree = tree->left;
			free(temp);
		}
		// case 3: 2 children
		else {
			node *temp = FindMin(tree->right);
			tree->data = temp->data;
			tree->right = Delete(tree->right,temp->data);
		}
	}
	return tree;
}
