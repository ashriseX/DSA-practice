#include <iostream> 
using namespace std; 
 
// Node structure 
class Node { 
public: 
    int data; 
    Node* left; 
    Node* right; 
 
 
    Node(int value) { 
        data = value; 
        left = right = NULL; 
    } 
}; 
 
// Insert into BST 
Node* insert(Node* root, int value) { 
    if (root == NULL) { 
        return new Node(value); 
    } 
 
    if (value < root->data) { 
        root->left = insert(root->left, value); 
    } else { 
        root->right = insert(root->right, value); 
    } 
 
    return root; 
} 
 
// Print Leaf Nodes 
void printLeafNodes(Node* root) { 
    if (root == NULL) return; 
 
    // If node is a leaf 

    if (root->left == NULL && root->right == NULL) { 
        cout << root->data << " "; 
        return; 
    } 
 
    printLeafNodes(root->left); 
    printLeafNodes(root->right); 
} 
 
// Count Leaf Nodes 
int countLeafNodes(Node* root) { 
    if (root == NULL) return 0; 
 
    // If node is a leaf 
    if (root->left == NULL && root->right == NULL) { 
        return 1; 
    } 
 
    return countLeafNodes(root->left) + countLeafNodes(root->right); 
} 
 
// Main function 
int main() { 
    Node* root = NULL; 
 
    // Insert elements 

 
    root = insert(root, 10); 
    root = insert(root, 5); 
    root = insert(root, 20); 
    root = insert(root, 3); 
    root = insert(root, 7); 
 
    cout << "Leaf Nodes: "; 
    printLeafNodes(root); 
 
    cout << "\nTotal Leaf Nodes: " << countLeafNodes(root); 
 
    return 0; 
} 