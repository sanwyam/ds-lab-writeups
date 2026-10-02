#include <stdio.h>
#include <malloc.h>
struct node
{
    struct node *left;
    int data;
    struct node *right;
};
struct node *insert(struct node *root, int val);
void inorder(struct node *root);
struct node *delete_key(struct node *root, int val);
struct node *find_min(struct node *root);
struct node *search(struct node *root, int data);
int main(void)
{
    struct node *root = NULL, *temp = NULL;
    int n, val, ch, i;
    do
    {
        printf("\n***BST OPERATIONS*****");
        printf("\n1.Create");
        printf("\n2.Inorder");
        printf("\n3.Delete");

        printf("\n4.Search");
        printf("\n5.Exit");
        printf("\nEnter ur choice = ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter no of nodes = ");
            scanf("%d", &n);
            printf("\nEnter tree values");
            for (i = 0; i < n; i++)
            {
                scanf("%d", &val);
                root = insert(root, val);
            }
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            printf("Enter key to be deleted ");
            scanf("%d", &val);
            root = delete_key(root, val);
            break;
        case 4:
            printf("Enter key to be searched ");
            scanf("%d", &val);
            temp = search(root, val);
            if (temp != NULL)
                printf("\n Key found = %d", temp->data);
            else
                printf("\nKey not found");
            break;
        case 5:
            printf("\nExit");
            break;
        default:
            printf("Invalid choice");
        }
    } while (ch != 5);
    return 0;
}
struct node *insert(struct node *root, int data)
{
    if (root == NULL)
    {
        root = (struct node *)malloc(sizeof(struct node));
        root->data = data;
        root->left = root->right = NULL;
    }

    else
    {
        if (data > (root->data))
            root->right = insert(root->right, data);
        else
            root->left = insert(root->left, data);
    }
    return root;
}
struct node *search(struct node *root, int val)
{
    if (root == NULL)
    {
        return root;
    }
    else
    {
        while (root != NULL || root->data != val)
        {
            if (val < root->data)
                root = root->left;
            else
                root = root->right;
        }
    }
    return root;
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("\t%d", root->data);
        inorder(root->right);
    }
}
struct node *minValueNode(struct node *node)
{
    struct node *current = node;

    while (current->left != NULL)
        current = current->left;
    return current;
}
struct node *delete_key(struct node *root, int key)
{
    if (root == NULL)
        return root;
    if (key < root->data)
        root->left = delete_key(root->left, key);

    else if (key > root->data)
        root->right = delete_key(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = delete_key(root->right, temp->data);
    }
    return root;
}
