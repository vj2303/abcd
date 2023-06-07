class HashTable:
    def __init__(self):
        self.table = {}

    def insert(self, key, value):
        self.table[key] = value

    def find(self, key):
        return self.table.get(key)

    def delete(self, key):
        if key in self.table:
            del self.table[key]

    def print_table(self):
        for key, value in self.table.items():
            print(f'({key}, {value})')

# Example usage:
hash_table = HashTable()

while True:
    choice = input("Enter choice (1. Insert, 2. Find, 3. Delete, 4. Print, 5. Exit): ")
    
    if choice == "1":
        key = input("Enter key: ")
        value = input("Enter value: ")
        hash_table.insert(key, value)
    elif choice == "2":
        key = input("Enter key to find: ")
        result = hash_table.find(key)
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

