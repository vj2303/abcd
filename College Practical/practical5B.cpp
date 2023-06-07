#include <iostream>
#include <algorithm>

using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

node* create_node(int value) {
    node* new_node = new node;
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

node* insert(node* root, int value) {
    if (root == NULL) {
        root = create_node(value);
    }
    else if (value <= root->data) {
        root->left = insert(root->left, value);
    }
    else {
        root->right = insert(root->right, value);
    }
    return root;
}

void swapPointers(node* root) {
    if (root == NULL) {
        return;
    }
    swap(root->left, root->right);
    swapPointers(root->left);
    swapPointers(root->right);
}

bool search(node* root, int value) {
    if (root == NULL) {
        return false;
    }
    else if (root->data == value) {
        return true;
    }
    else if (value < root->data) {
        return search(root->left, value);
    }
    else {
        return search(root->right, value);
    }
}

int main() {
    node* root = NULL;

    // Insert values in the order given
    int values[] = {10, 5, 15, 3, 7, 12, 20};
    int numValues = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < numValues; i++) {
        root = insert(root, values[i]);
    }

    // Insert a new node
    int newValue;
    cout << "Enter a value to insert: ";
    cin >> newValue;
    root = insert(root, newValue);

    // Swap left and right pointers
    swapPointers(root);
    cout << "Tree after swapping left and right pointers at every node." << endl;

    // Search for a value
    int searchValue;
    cout << "Enter a value to search for: ";
    cin >> searchValue;
    if (search(root, searchValue)) {
        cout << "Value " << searchValue << " found in the tree" << endl;
    }
    else {
        cout << "Value " << searchValue << " not found in the tree" << endl;
    }

    return 0;
}
