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
 
// Preorder Traversal (NRL) 
void preorderNRL(Node* root) { 
    if (root == NULL) return; 
 
    cout << root->data << " ";     // Node 
    preorderNRL(root->right);      // Right 
    preorderNRL(root->left);       // Left 
} 
 
// Inorder Traversal (RNL) 
void inorderRNL(Node* root) { 
    if (root == NULL) return; 
 
    inorderRNL(root->right);       // Right 
    cout << root->data << " ";     // Node 
    inorderRNL(root->left);        // Left 
 
 
} 
 
// Postorder Traversal (RLN) 
void postorderRLN(Node* root) { 
    if (root == NULL) return; 
 
    postorderRLN(root->right);     // Right 
    postorderRLN(root->left);      // Left 
    cout << root->data << " ";     // Node 
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
 
    cout << "Preorder (NRL): "; 
    preorderNRL(root); 
 
    cout << "\nInorder (RNL): "; 
 
 
    inorderRNL(root); 
 
    cout << "\nPostorder (RLN): "; 
    postorderRLN(root); 
 
    return 0; 
} 
