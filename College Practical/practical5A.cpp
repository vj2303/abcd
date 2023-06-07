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

int height(node* root) {
    if (root == NULL) {
        return 0;
    }
    else {
        int left_height = height(root->left);
        int right_height = height(root->right);
        return 1 + max(left_height, right_height);
    }
}

int min_value(node* root) {
    if (root == NULL) {
        return -1;
    }
    else if (root->left == NULL) {
        return root->data;
    }
    else {
        return min_value(root->left);
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

    // Find number of nodes in the longest path from root
    int longestPath = height(root);
    cout << "Number of nodes in the longest path from root: " << longestPath << endl;

    // Find the minimum data value in the tree
    int minValue = min_value(root);
    cout << "Minimum data value found in the tree: " << minValue << endl;

    return 0;
}
