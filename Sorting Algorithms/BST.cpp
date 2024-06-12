#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Create a Node
struct node *createNode(int key){
    struct node *newNode = new node; // Allocate memory for the new node
    newNode->key = key; // Assign the key value
    newNode->left = newNode->right = NULL; // Initialize left and right nodes to null
    return newNode; // Return the new node
}

// Inorder traversal
void traverseInOrder(struct node *root) {
    if (root == nullptr) // If the BST is empty, return
        return;
    traverseInOrder(root->left); // Recursively traverse the left subtree
    cout << root->key << " "; // Print the key value of the node
    traverseInOrder(root->right); // Recursively traverse the right subtree
}

// Insert a node
struct node *insertNode(struct node *node, int key) {
    if (node == nullptr) // If the tree is empty, create a new node
        return createNode(key); 
    
    if (key < node->key) // If the key to be inserted is less than the node's key
        node->left = insertNode(node->left, key); // Insert in the left subtree
    else if (key > node->key) // Else
        node->right = insertNode(node->right, key); // Insert in the right subtree

    return node; // Return the node pointer
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
    if (root == nullptr)  // If the BST is empty, return
        return root;

    if (key < root->key) // If the key to be deleted is less than the root's key,
        root->left = deleteNode(root->left, key); // Delete from left subtree
    else if (key > root->key) // If the key to be deleted is greater than the root's key,
        root->right = deleteNode(root->right, key); // Delete from right subtree
    else { 
        // If the key is same as root's key, then this is the node to be deleted
        // Node with only one child or no child
        if (root->left == nullptr) {
            struct node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            struct node* temp = root->left;
            delete root;
            return temp;
        }
    // Node with two children: Get the inorder successor (smallest in the right subtree)
    struct node* temp = root->right;
        while (temp->left != nullptr)
            temp = temp->left;
        // Copy the inorder successor's content to this node
        root->key = temp->key;
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root; // Return the root pointer
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}