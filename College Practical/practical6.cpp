#include <iostream>
#include <stack>
#include <cctype>
#include <algorithm>

using namespace std;

class Node {
public:
    char data;
    Node* left;
    Node* right;
    Node(char value) : data(value), left(nullptr), right(nullptr) {}
};

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

Node* constructExpressionTree(const string& expression) {
    stack<Node*> stack;
    for (int i = expression.length() - 1; i >= 0; i--) {
        char currentChar = expression[i];
        if (isOperator(currentChar)) {
            Node* newNode = new Node(currentChar);
            newNode->left = stack.top();
            stack.pop();
            newNode->right = stack.top();
            stack.pop();
            stack.push(newNode);
        } else {
            Node* newNode = new Node(currentChar);
            stack.push(newNode);
        }
    }
    return stack.top();
}

void postOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    stack<Node*> stack;
    stack.push(root);
    string result;
    while (!stack.empty()) {
        Node* current = stack.top();
        stack.pop();
        result += current->data;
        if (current->right) {
            stack.push(current->right);
        }
        if (current->left) {
            stack.push(current->left);
        }
    }
    // Reverse the result to get the post-order traversal
    reverse(result.begin(), result.end());
    cout << "Post-order traversal: " << result << endl;
}

void deleteTree(Node* root) {
    if (root == nullptr) {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    int choice;
    string prefixExpression;
    Node* root = nullptr;

    do {
        cout << "Menu:" << endl;
        cout << "1. Enter the prefix expression" << endl;
        cout << "2. Perform post-order traversal" << endl;
        cout << "3. Delete the entire tree" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the prefix expression: ";
                cin >> prefixExpression;
                root = constructExpressionTree(prefixExpression);
                break;
            case 2:
                if (root == nullptr) {
                    cout << "Expression tree is not constructed yet. Please enter the prefix expression first." << endl;
                } else {
                    postOrderTraversal(root);
                    cout << "Traversal is done." << endl;
                }
                break;
            case 3:
                if (root == nullptr) {
                    cout << "Expression tree is not constructed yet. Please enter the prefix expression first." << endl;
                } else {
                    deleteTree(root);
                    root = nullptr;
                    cout << "Tree is deleted." << endl;
                }
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

        cout << endl;
    } while (choice != 4);

    return 0;
}
