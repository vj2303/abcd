class Set:
    def __init__(self):
        self.elements = []
    
    def add(self, element):
        if element not in self.elements:
            self.elements.append(element)
    
    def remove(self, element):
        if element in self.elements:
            self.elements.remove(element)

    def contains(self, element):
        return element in self.elements

    def size(self):
        return len(self.elements)

    def iterator(self):
        return iter(self.elements)
    
    def intersection(self, other_set):
        intersection_set = Set()
        for element in self.elements:
            if other_set.contains(element):
                intersection_set.add(element)
        return intersection_set
    
    def union(self, other_set):
        union_set = Set()
        for element in self.elements:
            union_set.add(element)
        for element in other_set.iterator():
            union_set.add(element)
        return union_set

    def difference(self, other_set):
        difference_set = Set()
        for element in self.elements:
            if not other_set.contains(element):
                difference_set.add(element)
        return difference_set
                                                 
    def is_subset(self, other_set):
        for element in self.elements:
            if not other_set.contains(element):
                return False
        return True

# Create sets
set1 = Set()
set2 = Set()

# Take user input for set1
num_elements_set1 = int(input("Enter the number of elements in set1: "))
print("Enter the elements for set1:")
for _ in range(num_elements_set1):
    element = int(input())
    set1.add(element)

# Take user input for set2
num_elements_set2 = int(input("Enter the number of elements in set2: "))
print("Enter the elements for set2:")
for _ in range(num_elements_set2):
    element = int(input())
    set2.add(element)

# Remove element from set1
element_to_remove = int(input("Enter an element to remove from set1: "))
set1.remove(element_to_remove)

# Check if an element is in the set
element_to_check = int(input("Enter an element to check in set1: "))
print(set1.contains(element_to_check))

# Get the size of the set
print(set1.size())

# Iterate over the set
for element in set1.iterator():
    print(element)

# Perform set operations
intersection = set1.intersection(set2)
union = set1.union(set2)
difference = set1.difference(set2)
is_subset = set1.is_subset(set2)

# Display the results
print("Intersection:", [element for element in intersection.iterator()])
print("Union:", [element for element in union.iterator()])
print("Difference:", [element for element in difference.iterator()])
print("Is Subset:", is_subset)
