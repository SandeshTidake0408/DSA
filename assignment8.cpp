#include <iostream>
using namespace std;

int sum(int freq[], int low, int high)
{ // sum of frequency from low to high range
    int sum = 0;
    for (int k = low; k <= high; k++)
        sum += freq[k];
    return sum;
}

int minCostBST(int keys[], int freq[], int n)
{
    int cost[n][n];

    for (int i = 0; i < n; i++) // when only one key, move along diagonal elements
        cost[i][i] = freq[i];

    for (int length = 2; length <= n; length++)
    {
        for (int i = 0; i <= n - length + 1; i++)
        { // from 0th row to n-length+1 row as i
            int j = i + length - 1;
            cost[i][j] = INT_MAX; // initially store to infinity

            for (int r = i; r <= j; r++)
            {
                // find cost when r is root of subtree
                int c = ((r > i) ? cost[i][r - 1] : 0) + ((r < j) ? cost[r + 1][j] : 0) + sum(freq, i, j);
                if (c < cost[i][j])
                    cost[i][j] = c;
            }
        }
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << cost[i][j] << " ";
        }
        cout << endl;
    }
    return cost[0][n - 1];
}

int main()
{
    int keys[] = {10, 12, 20};
    int freq[] = {34, 8, 50};
    int n = 3;
    cout << minCostBST(keys, freq, n);
    cout << "Cost of Optimal BST is: " << minCostBST(keys, freq, n);
}