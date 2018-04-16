#include <stdio.h>
#include <stdlib.h>

typedef struct bstNode
{
    unsigned int data;
    struct bstNode *left;
    struct bstNode *right;
}bstNode_t;

class binarySearchTree
{
    bstNode_t *root;

public:
    binarySearchTree()
    {
        root = NULL;
    }

    ~binarySearchTree() {}

    bool insert(unsigned int data)
    {
        bstNode_t *tree;
        bstNode_t *entry;

        entry = (bstNode_t *)malloc(sizeof(bstNode_t));
        entry->data = data;
        entry->left = NULL;
        entry->right = NULL;

        if (!root)
        {
            root = entry;
            printf("root: data:%d\n", entry->data);
            return true;
        }

        tree = root;

        while (tree)
        {
            printf("data%d, node:%d\n", data, tree->data);
            if (data < tree->data) {
                if (tree->left) {
                    printf("data is less so travesring left\n");
                    tree = tree->left;
                } else {
                    printf("found end node... inserting\n");
                    tree->left = entry;
                    break;
                }
            } else if (data > tree->data) {
                if (tree->right) {
                    printf("data is greater so travesring right\n");
                    tree = tree->right;
                } else {
                    printf("found end node... inserting\n");
                    tree->right = entry;
                    break;
                }
            } else {
                printf("data is already present in the tree\n");
                break;
            }
        }

        return true;
    }

};

main()
{
    class binarySearchTree bst;

    bst.insert(5);
    bst.insert(2);
    bst.insert(3);
    bst.insert(7);
}
