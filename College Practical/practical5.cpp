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

void swap(node* root) {
    if (root == NULL) {
        return;
    }
    swap(root->left, root->right);
    swap(root->left);
    swap(root->right);
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
    int choice;
    int value;

    do {
        cout << "Operations on BST" << endl;
        cout << "1. Insert Element" << endl;
        cout << "2. Height of the tree" << endl;
        cout << "3. Smallest value in the tree" << endl;
        cout << "4. Mirror image of the tree" << endl;
        cout << "5. Search an element" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a value to insert: ";
                cin >> value;
                root = insert(root, value);
                break;
            case 2:
                cout << "Height of the tree: " << height(root) << endl;
                break;
            case 3:
                cout << "Smallest value in the tree: " << min_value(root) << endl;
                break;
            case 4:
                swap(root);
                cout << "Mirror image of the tree created." << endl;
                break;
            case 5:
                cout << "Enter a value to search for: ";
                cin >> value;
                if (search(root, value)) {
                    cout << "Value " << value << " found in the tree" << endl;
                }
                else {
                    cout << "Value " << value << " not found in the tree" << endl;
                }
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
