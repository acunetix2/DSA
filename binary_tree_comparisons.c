/*Group Members
Iddy Kibor Chesire SCT221-0119/2023
Jeremiah Ruwa Nzai SCT221-0092/2023
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* insert_node(int value)
{
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

int traverse_count(struct node* root)
{
    if (root == NULL) return 0;
    return 1 + traverse_count(root->left) + traverse_count(root->right);
}

void compareBinaryTree(struct node* A, struct node* B, struct node* C)
{
    int countA = traverse_count(A);
    int countB = traverse_count(B);
    int countC = traverse_count(C);

    printf("\nTree A has %d nodes.", countA);
    printf("\nTree B has %d nodes.", countB);
    printf("\nTree C has %d nodes.", countC);

    if (countA == countB && countA == countC)
    {
        printf("\nAll trees have the same number of nodes (%d).", countA);
    }
    else if (countA >= countB && countA >= countC)
    {
        printf("\nTree A has the most nodes (%d).", countA);
    }
    else if (countB >= countA && countB >= countC)
    {
        printf("\nTree B has the most nodes (%d).", countB);
    }
    else
    {

        printf("\nTree C has the most nodes (%d).", countC);
    }
}

void insert_to_tree(struct node* root, int value)
{
    if (root == NULL)
    {
        root = insert_node(value);
        return;
    }
    if ((root)->left == NULL)
    {
        (root)->left = insert_node(value);
    }
    else if ((root)->right == NULL)
    {
        (root)->right = insert_node(value);
    }
    else
    {
        insert_to_tree(&((root)->left), value);
    }
}

int main()
{
    struct node* A = NULL;
    struct node* B = NULL;
    struct node* C = NULL;

    int choice, value, tree;

    do {
        printf("\n------ USER MENU ------");
        printf("\n1. Insert node");
        printf("\n2. Compare trees");
        printf("\n3. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter tree to insert into (1 for A, 2 for B, 3 for C): ");
                scanf("%d", &tree);
                printf("Enter value to insert: ");
                scanf("%d", &value);

                if (tree == 1)
                {
                    insert_to_tree(&A, value);
                }
                else if (tree == 2)
                {
                    insert_to_tree(&B, value);
                }
                else if (tree == 3)
                {
                    insert_to_tree(&C, value);
                } else
                {
                    printf("Invalid tree number.\n");
                }
                break;
            case 2:
                compareBinaryTree(A, B, C);
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }

    } while(choice != 3);

    return 0;
}
