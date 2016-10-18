#include "lib.h"

int main()
{
    node *root;
    node *tmp;

    root = NULL;

    insert(&root, 9);
    insert(&root, 4);
    insert(&root, 15);
    insert(&root, 6);
    insert(&root, 12);
    insert(&root, 17);
    insert(&root, 2);
    insert(&root, 3);

    printf("Pre Order Display\n");
    print_preorder(root);

    printf("In Order Display\n");
    print_inorder(root);

    printf("Post Order Display\n");
    print_postorder(root);

    tmp = search(&root, 4);
    if (tmp) {
        printf("Searched node=%d\n", tmp->data);
    } else {
        printf("Data Not found in tree.\n");
    }
    printf("tree :\n");
    print_tree(root, 0);
    root = Delete(root,4);

    printf("Pre Order Display\n");
    print_preorder(root);
    printf("tree :\n");
    print_tree(root, 0);
    deltree(root);
}
