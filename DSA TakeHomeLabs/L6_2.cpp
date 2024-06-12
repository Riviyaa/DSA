#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    Node *insert(Node *root, int data)
    {
        if (root == NULL)
        {
            return new Node(data);
        }
        else
        {
            Node *cur;
            if (data <= root->data)
            {
                cur = insert(root->left, data);
                root->left = cur;
            }
            else
            {
                cur = insert(root->right, data);
                root->right = cur;
            }

            return root;
        }
    }

    vector<int> findAncestors(Node *root, int data)
    {
        if (root == NULL)
        {
            return {};
        }

        // Create a vector to store the ancestors
        vector<int> ancestors;

        // Start from the root and go down the tree
        while (root != NULL)
        {
            // If data is less than the root's data, go left
            if (data < root->data)
            {
                ancestors.push_back(root->data);
                root = root->left;
            }
            // If data is more than the root's data, go right
            else if (data > root->data)
            {
                ancestors.push_back(root->data);
                root = root->right;
            }
            // If data is equal to the root's data, we have found the node
            else
            {
                break;
            }
        }
        return ancestors;
    }

    Node *lca(Node *root, int v1, int v2)
    {
        if (root == NULL)
        {
            return NULL;
        }

        // If both v1 and v2 are smaller than root, then LCA lies in left
        if (root->data > v1 && root->data > v2)
        {
            return lca(root->left, v1, v2);
        }

        // If both v1 and v2 are greater than root, then LCA lies in right
        if (root->data < v1 && root->data < v2)
        {
            return lca(root->right, v1, v2);
        }

        return root;
    }
};

int main()
{
    Solution myTree;
    Node *root = NULL;

    int t;
    int data;

    std::cin >> t;

    while (t-- > 0)
    {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    int v1, v2;
    std::cin >> v1 >> v2;

    Node *ans = myTree.lca(root, v1, v2);

    if (ans != NULL)
    {
        std::cout << ans->data;
    }
    else
    {
        std::cout << "No common ancestor found";
    }

    return 0;
}
