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
    if (value < root->data){ 
        root->left = insert(root->left, value); 
        }
    else {
        root->right = insert(root->right, value); 
    }
    return root; 
} 
 
// Find minimum value node (used for inorder successor) 
Node* findMin(Node* root) { 
    while (root && root->left != NULL) { 
        root = root->left; 
    } 
    return root; 
} 
 
// Delete Node from BST 
Node* deleteNode(Node* root, int key) { 
    if (root == NULL) return NULL; 
 
    // Search the node 
    if (key < root->data) { 
        root->left = deleteNode(root->left, key); 
    } 
    else if (key > root->data) { 
        root->right = deleteNode(root->right, key); 
    } 
    else { 

        
        //    CASE 1: No child 
        if (root->left == NULL && root->right == NULL) { 
            delete root; 
            return NULL; 
        } 
 
        //    CASE 2: One child 
        else if (root->left == NULL) { 
            Node* temp = root->right; 
            delete root; 
            return temp; 
        } 
        else if (root->right == NULL) { 
            Node* temp = root->left; 
            delete root; 
            return temp; 
        } 
 
        //    CASE 3: Two children 
        Node* temp = findMin(root->right); // inorder successor 
        root->data = temp->data; 
        root->right = deleteNode(root->right, temp->data); 
    } 
 
    return root; 
} 
 

// Inorder traversal (for checking) 
void inorder(Node* root) { 
    if (root == NULL) return; 
 
    inorder(root->left); 
    cout << root->data << " "; 
    inorder(root->right); 
} 
 
// Main 
int main() { 
    Node* root = NULL; 
 
    // Insert elements 
    root = insert(root, 10); 
    root = insert(root, 5); 
    root = insert(root, 20); 
    root = insert(root, 3); 
    root = insert(root, 7); 
 
    cout << "Inorder before deletion: "; 
    inorder(root); 
 
    // Delete a node 
    root = deleteNode(root, 5); 
 

    cout << "\nInorder after deletion: "; 
    inorder(root); 
 
    return 0; 
} 