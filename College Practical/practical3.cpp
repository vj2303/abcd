#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

class SetADT {
private:
    unordered_set<int> elements;

public:
    void add(int new_element) {
        elements.insert(new_element);
    }

    void remove(int element) {
        elements.erase(element);
    }

    bool contains(int element) {
        return elements.find(element) != elements.end();
    }

    int size() {
        return elements.size();
    }

    void intersection(SetADT& other_set, SetADT& result_set) {
        for (const auto& element : elements) {
            if (other_set.contains(element)) {
                result_set.add(element);
            }
        }
    }

    void unionSet(SetADT& other_set, SetADT& result_set) {
        for (const auto& element : elements) {
            result_set.add(element);
        }
        for (const auto& element : other_set.elements) {
            result_set.add(element);
        }
    }

    void difference(SetADT& other_set, SetADT& result_set) {
        for (const auto& element : elements) {
            if (!other_set.contains(element)) {
                result_set.add(element);
            }
        }
    }

    bool subset(SetADT& other_set) {
        for (const auto& element : elements) {
            if (!other_set.contains(element)) {
                return false;
            }
        }
        return true;
    }

    class Iterator {
    private:
        SetADT& set;
        unordered_set<int>::iterator iter;

    public:
        Iterator(SetADT& set) : set(set), iter(set.elements.begin()) {}

        int next() {
            if (iter == set.elements.end()) {
                throw out_of_range("Iterator reached the end");
            }
            return *(iter++);
        }

        bool hasNext() {
            return iter != set.elements.end();
        }

        Iterator& operator=(const Iterator& other) {
            if (this != &other) {
                set = other.set;
                iter = other.iter;
            }
            return *this;
        }
    };

    Iterator iterator() {
        return Iterator(*this);
    }
};

int main() {
    SetADT mySet;
    mySet.add(1);
    mySet.add(2);
    mySet.add(3);
    mySet.add(4);

    cout << "Size of set: " << mySet.size() << endl;

    if (mySet.contains(2)) {
        cout << "Set contains 2" << endl;
    }

    mySet.remove(3);

    if (!mySet.contains(3)) {
        cout << "Set does not contain 3" << endl;
    }

    SetADT otherSet;
    otherSet.add(2);
    otherSet.add(4);
    otherSet.add(6);

    SetADT intersectionSet;
    mySet.intersection(otherSet, intersectionSet);

    cout << "Intersection set: ";
    SetADT::Iterator iter = intersectionSet.iterator();
    while (iter.hasNext()) {
        cout << iter.next() << " ";
    }
    cout << endl;

    SetADT unionSet;
    mySet.unionSet(otherSet, unionSet);

    cout << "Union set: ";
    iter = unionSet.iterator();
    while (iter.hasNext()) {
        cout << iter.next() << " ";
    }
    cout << endl;

    SetADT differenceSet;
    mySet.difference(otherSet, differenceSet);

    cout << "Difference set: ";
    iter = differenceSet.iterator();
    while (iter.hasNext()) {
        cout << iter.next() << " ";
    }
    cout << endl;

    if (mySet.subset(otherSet)) {
        cout << "mySet is a subset of otherSet" << endl;
    } else {
        cout << "mySet is not a subset of otherSet" << endl;
    }

    return 0;
}
