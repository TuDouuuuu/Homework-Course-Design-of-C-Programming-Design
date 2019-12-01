#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
 
struct binary_tree_node
{
        int value;
        struct binary_tree_node *left, *right;
};
 
int binary_tree_get_deepth(struct binary_tree_node *tree)
{
        int left, right;
         
        if (tree != NULL) {
                left = 0;
                if (tree->left != NULL) {
                        left += binary_tree_get_deepth(tree->left);
                }
                right = 0;
                if (tree->right != NULL) {
                        right += binary_tree_get_deepth(tree->right);
                }
                return (left < right ? right : left) + 1;
        }else {
                return 0;
        }
}
 
int binary_tree_delete(struct binary_tree_node **tree)
{
        if (*tree != NULL) {
                if ((*tree)->left != NULL) {
                        binary_tree_delete(&(*tree)->left);
                }
                if ((*tree)->right != NULL) {
                        binary_tree_delete(&(*tree)->right);
                }
                free(*tree);
                *tree = NULL;
        }
        return 0;
}
 
int binary_tree_insert(struct binary_tree_node **tree, int value)
{
        struct binary_tree_node *node;
 
        if (*tree == NULL) {
                node = (struct binary_tree_node *)malloc(sizeof(struct binary_tree_node));
                if (node != NULL) {
                        memset(node, 0, sizeof(struct binary_tree_node));
                        node->value = value;
                        *tree = node;
                        return 0;
                }else {
                        return -1;
                }
        }else {
                if (value < (*tree)->value) {
                        return binary_tree_insert(&(*tree)->left, value);
                }else {
                        return binary_tree_insert(&(*tree)->right, value);
                }
        }
}
 
int binary_tree_print(struct binary_tree_node *tree, int level, char disp_tab[128])
{
        int i;
 
        if (level < 127) {
                for (i = 1; i < level; ++i) {
                        printf(disp_tab[i] ? "| " : "  ");
                }
                if (level) {
                        printf("+-");
                }
                if (tree == NULL) {
                        printf("\n");
                }else {
                        printf("%d\n", tree->value);
                        if (tree->left != NULL || tree->right != NULL) {
                                disp_tab[level + 1] = 1;
                                binary_tree_print(tree->right, level + 1, disp_tab);
                                disp_tab[level + 1] = 0;
                                binary_tree_print(tree->left, level + 1, disp_tab);
                        }
                }
        }
        return 0;
}
 
int main(void)
{
        char disp_tab[128];
        struct binary_tree_node *tree = NULL;
        int i;
 
        srand(time(NULL));
        for (i = 0; i < 20; ++i) {
                binary_tree_insert(&tree, rand() % 100 + 1);
        }
        printf("deepth: %d\n", binary_tree_get_deepth(tree));
        binary_tree_print(tree, 0, disp_tab);
        binary_tree_delete(&tree);
        return 0;
}