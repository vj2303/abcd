#include <iostream>
#include <vector>
using namespace std;

struct Node {
    string label;
    vector<Node*> children;
};

class BookHierarchy {
public:
    Node* createTree() {
        Node* root = new Node;
        cout << "Enter name of book: ";
        cin >> root->label;
        int numChapters;
        cout << "Enter number of chapters in book: ";
        cin >> numChapters;
        for (int i = 0; i < numChapters; i++) {
            Node* chapter = new Node;
            cout << "Enter chapter name: ";
            cin >> chapter->label;
            int numSections;
            cout << "Enter number of sections in chapter '" << chapter->label << "': ";
            cin >> numSections;
            for (int j = 0; j < numSections; j++) {
                Node* section = new Node;
                cout << "Enter section name: ";
                cin >> section->label;
                int numSubsections;
                cout << "Enter number of subsections in section '" << section->label << "': ";
                cin >> numSubsections;
                for (int k = 0; k < numSubsections; k++) {
                    Node* subsection = new Node;
                    cout << "Enter subsection name: ";
                    cin >> subsection->label;
                    section->children.push_back(subsection);
                }
                chapter->children.push_back(section);
            }
            root->children.push_back(chapter);
        }
        return root;
    }

    void display(Node* root) {
        if (root != nullptr) {
            cout << "\n-----Book Hierarchy---";
            cout << "\n Book title: " << root->label << endl;
            for (const auto& chapter : root->children) {
                cout << "  Chapter: " << chapter->label << endl;
                cout << "  Sections:" << endl;
                for (const auto& section : chapter->children) {
                    cout << "    " << section->label << endl;
                    cout << "    Subsections:" << endl;
                    for (const auto& subsection : section->children) {
                        cout << "      " << subsection->label << endl;
                    }
                }
            }
        }
    }
};

int main() {
    BookHierarchy bh;
    Node* root = nullptr;
    int choice;
    while (true) {
        cout << "-----------------" << endl;
        cout << "Book Tree Creation" << endl;
        cout << "-----------------" << endl;
        cout << "1. Create" << endl;
        cout << "2. Display" << endl;
        cout << "3. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                root = bh.createTree();
                break;
            case 2:
                bh.display(root);
                break;
            case 3:
                exit(0);
            default:
                cout << "Wrong choice. Please try again." << endl;
        }
    }
    return 0;
}
