// Consider a scenario for Hospital to cater services to different kinds of patients as Serious (top priority), b) non-serious (medium priority), c) General Checkup (Least priority). Implement the priority queue to cater services to the patients.
#include <iostream>
using namespace std;

class node
{
public:
    char name[10];
    int prio;
};

void push(node *a[], int index)
{
    int curr = index;
    int parent;
    while (curr > 0)
    {
        parent = (curr - 1) / 2;
        if (a[parent]->prio < a[curr]->prio)
        {
            node *temp = a[parent];
            a[parent] = a[curr];
            a[curr] = temp;
            curr = parent;
        }
        else
        {
            return;
        }
    }
}

node *pop(node *arr[], int &n)
{
    int lc, rc;
    node *maxElemet = arr[0];
    arr[0] = arr[n];
    n--;
    int curr = 0;
    while (true)
    {
        int maxchild = -1;
        lc = (2 * curr) + 1;
        rc = (2 * curr) + 2;
        if (lc <= n)
        {
            maxchild = lc;
            if (rc <= n && arr[lc]->prio < arr[rc]->prio)
            {
                maxchild = rc;
            }
        }
        if (maxchild == -1 || arr[curr]->prio >= arr[maxchild]->prio)
        {
            break;
        }
        node *temp = arr[curr];
        arr[curr] = arr[maxchild];
        arr[maxchild] = temp;
        curr = maxchild;
    }
    return maxElemet;
}

int main()
{
    int val;
    cout << "Enter the No of patients : ";
    cin >> val;
    node *arr[val];
    for (int i = 0; i < val; i++)
    {
        node *temp = new node();
        cout << "Enter the name and priority of patient : ";
        cin >> temp->name >> temp->prio;
        arr[i] = temp;
        push(arr, i);
    }
    cout << pop(arr, val)->prio;
    cout << pop(arr, val)->prio;
    return 0;
}