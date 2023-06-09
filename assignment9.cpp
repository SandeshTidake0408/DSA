// A Dictionary stores keywords & its meanings. Provide facility for adding new keywords, deleting keywords, updating values of any entry. Provide facility to display whole data sorted in ascending/ Descending order. Also find how many maximum comparisons may require for finding any keyword. Use Height balance tree and find the complexity for finding a keyword

#include <iostream>
using namespace std;
class node
{
public:
    int key, height;
    node *left;
    node *right;
};

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int get_balance(node *N)
{
    if (N == NULL)
        return 0;
    return (height(N->left) - height(N->right));
}

node *RR(node *N) // right rotation for left skeew tree.
{
    node *temp1 = N->left;
    node *temp2 = temp1->right;

    temp1->right = N;
    N->left = temp2;

    // update height
    N->height = max(height(N->left), height(N->right)) + 1;
    temp1->height = max(height(temp1->left), height(temp1->right)) + 1;

    return temp1;
}

node *LL(node *N)
{
    node *temp1 = N->right;
    node *temp2 = temp1->left;

    temp1->left = N;
    N->right = temp2;

    N->height = max(height(N->left), height(N->right)) + 1;
    temp1->height = max(height(temp1->left), height(temp1->right)) + 1;

    return temp1;
}
node *new_node(int key)
{

    node *n = new node();
    n->key = key;
    n->left = NULL;
    n->right = NULL;
    n->height = 1;
    return n;
}

node *insert(node *root, int key)
{
    if (root == NULL)
    {
        return (new_node(key));
    }

    if (key < root->key)
    {
        root->left = insert(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = insert(root->right, key);
    }
    else
    {
        return root;
    }

    // update height of root node
    root->height = max(height(root->left), height(root->right)) + 1;

    int balance = get_balance(root);

    // four cases for unbalanced node
    if (balance > 1 && key < root->left->key)
    {
        return RR(root);
    }
    if (balance < -1 && key > root->right->key)
    {
        return LL(root);
    }
    if (balance > 1 && key > root->left->key)
    {
        root->left = LL(root->left);
        return RR(root);
    }
    if (balance < -1 && key < root->right->key)
    {
        root->right = RR(root->right);
        return LL(root);
    }

    return root;
}
// DFS

void inorder(node *N)
{
    if (N != NULL)
    {
        inorder(N->left);
        cout << N->key << " ";
        inorder(N->right);
    }
}
int Comparisons(node *root, int key)
{
    int comparisons = 0;
    node *current = root;

    while (current != NULL)
    {
        comparisons++;
        if (key == current->key)
        {
            return comparisons; // Key found
        }
        else if (key < current->key)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
    return comparisons;
}

int main()
{
    node *root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
    cout << root->key;
    cout << root->left->key;
    cout << root->right->key;
    cout << "\nAscending Order of Keys : ";
    inorder(root);
    int com = Comparisons(root, 30);
    cout << "\nNumber of Comparison required to find the key is : " << com;
    return 0;
}
