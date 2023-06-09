// Beginning with an empty binary search tree, Construct binary search tree by inserting the values in the order given. After constructing a binary tree -
// i. Insert new node
// ii. Find number of nodes in longest path from root
// iii. Minimum data value found in the tree
// iv. Change a tree so that the roles of the left and right pointers are swapped at every node
// v. Search a value

#include <iostream>
using namespace std;
#include <queue>

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};
class bst
{
public:
    void buildtree(node *&root)
    {
        node *temp;
        int data;
        cout << "Enter the data :";
        cin >> data;
        temp = new node(data);
        if (root == NULL)
        {
            root = temp;
        }
        else
        {
            insert(root, data);
        }
    }

    void insert(node *&root, int val)
    {
        node *temp = new node(val);
        if (root == NULL)
        {
            root = temp;
        }
        else if (val < root->data)
        {
            insert(root->left, val);
        }
        else
        {
            insert(root->right, val);
        }
    }

    void inorder(node *root)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void search(node *root, int key)
    {
        if (root == NULL)
        {
            cout << "TREE Not Found!" << endl;
            return;
        }
        else
        {
            if (key == root->data)
            {
                cout << "Key Found Successfully !!" << endl;
                return;
            }
            else if (key < root->data)
            {
                search(root->left, key);
            }
            else
            {
                search(root->right, key);
            }
        }
    }

    int height(node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        else
        {
            return max(height(root->left), height(root->right)) + 1;
        }
    }

    int longestPathLength(node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        else
        {
            int leftHeight = height(root->left);
            int rightHeight = height(root->right);
            return max(leftHeight, rightHeight) + 1;
        }
    }

    void minvalue(node *root)
    {
        if (root == NULL)
        {
            return;
        }
        else
        {
            while (root->left != NULL)
            {
                root = root->left;
            }
            cout << "Minimum Value in the Tree is : " << root->data << endl;
        }
    }

    void mirror_tree(node *root)
    {
        node *temp;
        if (root == NULL)
        {
            return;
        }
        temp = root->left;
        root->left = root->right;
        root->right = temp;
        mirror_tree(root->left);
        mirror_tree(root->right);
    }
};

int main()
{
    bst obj;
    node *root = NULL;
    char ch;
    do
    {
        obj.buildtree(root);
        cout << "Do you want to continue the build... [y/n]";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    cout << "Inorder Traversal :" << endl;
    obj.inorder(root);
    // obj.search(root, 36);
    // obj.search(root, 17);
    int path = obj.longestPathLength(root);
    cout << "Longest path is : " << path << endl;
    obj.minvalue(root);
    // // node *new_root;
    obj.mirror_tree(root);
    obj.inorder(root);

    return 0;
}

// void preorder(node *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }
//     cout << root->data << " ";
//     preorder(root->left);
//     preorder(root->right);
// }
// void postorder(node *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }
//     postorder(root->left);
//     postorder(root->right);
//     cout << root->data << " ";
// }