#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* insertNode(Node* root, int value) {
    if (root == nullptr) {
        root = createNode(value);
    }
    else if (value <= root->data) {
        root->left = insertNode(root->left, value);
    }
    else {
        root->right = insertNode(root->right, value);
    }
    return root;
}

int findHeight(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    else {
        int leftHeight = findHeight(root->left);
        int rightHeight = findHeight(root->right);
        return max(leftHeight, rightHeight) + 1;
    }
}

int findMinValue(Node* root) {
    if (root == nullptr) {
        cout << "Tree is empty." << endl;
        return -1;
    }
    else if (root->left == nullptr) {
        return root->data;
    }
    else {
        return findMinValue(root->left);
    }
}

void mirrorImage(Node* root) {
    if (root == nullptr) {
        return;
    }
    else {
        swap(root->left, root->right);
        mirrorImage(root->left);
        mirrorImage(root->right);
    }
}

bool searchValue(Node* root, int value) {
    if (root == nullptr) {
        return false;
    }
    else if (root->data == value) {
        return true;
    }
    else if (value < root->data) {
        return searchValue(root->left, value);
    }
    else {
        return searchValue(root->right, value);
    }
}

void printMenu() {
    cout << "Operations on BST" << endl;
    cout << "1. Insert Element" << endl;
    cout << "2. Height of the tree" << endl;
    cout << "3. Smallest value in the tree" << endl;
    cout << "4. Mirror image of the tree" << endl;
    cout << "5. Search an element" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    Node* root = nullptr;
    int choice, value;

    do {
        printMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter the value to be inserted: ";
                cin >> value;
                root = insertNode(root, value);
                cout << "Value " << value << " inserted into the tree." << endl;
                break;
            }
            case 2: {
                int treeHeight = findHeight(root);
                cout << "Height of the tree: " << treeHeight << endl;
                break;
            }
            case 3: {
                int minValue = findMinValue(root);
                if (minValue != -1) {
                    cout << "Smallest value in the tree: " << minValue << endl;
                }
                break;
            }
            case 4: {
                mirrorImage(root);
                cout << "Mirror image of the tree created." << endl;
                break;
            }
            case 5: {
                cout << "Enter the value to be searched: ";
                cin >> value;
                bool found = searchValue(root, value);
                if (found) {
                    cout << "Value " << value << " found in the tree." << endl;
                }
                else {
                    cout << "Value " << value << " not found in the tree." << endl;
                }
                break;
            }
            case 6: {
                cout << "Exiting the program." << endl;
                break;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    } while (choice != 6);

    return 0;
}
