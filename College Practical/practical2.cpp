#include <iostream>
#include <vector>
#include <list>

using namespace std;

// Structure for key-value pair
struct KeyValuePair {
    int key;
    string value;

    KeyValuePair(int k, const string& v) : key(k), value(v) {}
};

class Dictionary {
private:
    int size;
    vector<list<KeyValuePair>> table;

    // Hash function to map keys to indices
    int hashFunction(int key) {
        return key % size;
    }

public:
    // Constructor to initialize the dictionary
    Dictionary(int tableSize) : size(tableSize) {
        table.resize(size);
    }

    // Insert a key-value pair into the dictionary
    void insert(int key, const string& value) {
        int index = hashFunction(key);
        table[index].push_back(KeyValuePair(key, value));
    }

    // Find the value associated with a given key
    string find(int key) {
        int index = hashFunction(key);
        for (auto& pair : table[index]) {
            if (pair.key == key) {
                return pair.value;
            }
        }
        return "Key not found";
    }

    // Delete a key-value pair with the given key
    void remove(int key) {
        int index = hashFunction(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->key == key) {
                table[index].erase(it);
                return;
            }
        }
    }
};

int main() {
    Dictionary dict(10);

    dict.insert(1, "Value 1");
    dict.insert(11, "Value 11");
    dict.insert(21, "Value 21");

    cout << dict.find(1) << endl;  // Output: Value 1
    cout << dict.find(11) << endl; // Output: Value 11
    cout << dict.find(21) << endl; // Output: Value 21
    cout << dict.find(31) << endl; // Output: Key not found

    dict.remove(11);
    cout << dict.find(11) << endl; // Output: Key not found

    return 0;
}
