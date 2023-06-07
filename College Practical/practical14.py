class KeyValuePair:
    def __init__(self, key, value):
        self.key = key
        self.value = value

class HashTable:
    def __init__(self, size):
        self.size = size
        self.table = [[] for _ in range(size)]

    def _hash_function(self, key):
        return hash(key) % self.size

    def insert(self, key, value):
        index = self._hash_function(key)
        chain = self.table[index]
        
        # Check if the key already exists
        for pair in chain:
            if pair.key == key:
                # Replace the value if the key already exists
                pair.value = value
                return
        
        # If the key does not exist, append a new key-value pair
        chain.append(KeyValuePair(key, value))

    def find(self, key):
        index = self._hash_function(key)
        chain = self.table[index]

        # Iterate through the chain to find the key
        for pair in chain:
            if pair.key == key:
                return pair.value
        
        # Key not found
        return None

    def delete(self, key):
        index = self._hash_function(key)
        chain = self.table[index]

        # Find the key in the chain and remove it
        for i, pair in enumerate(chain):
            if pair.key == key:
                del chain[i]
                return

        # Key not found

    def print_table(self):
        for i, chain in enumerate(self.table):
            print(f'Index {i}:', end=' ')
            for pair in chain:
                print(f'({pair.key}, {pair.value})', end=' ')
            print()

# Example usage:
hash_table = HashTable(10)

while True:
    choice = input("Enter choice (1. Insert, 2. Find, 3. Delete, 4. Print, 5. Exit): ")
    
    if choice == "1":
        key = input("Enter key: ")
        value = input("Enter value: ")
        hash_table.insert(key, value)
    elif choice == "2":
        key = input("Enter key to find: ")
        result = hash_table.find(key)
        if result is None:
            print("Key not found.")
        else:
            print(f"Value: {result}")
    elif choice == "3":
        key = input("Enter key to delete: ")
        hash_table.delete(key)
    elif choice == "4":
        hash_table.print_table()
    elif choice == "5":
        break
    else:
        print("Invalid choice. Please try again.")

