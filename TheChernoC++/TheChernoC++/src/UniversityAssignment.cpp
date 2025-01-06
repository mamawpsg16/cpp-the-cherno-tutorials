#include <iostream>
#include <sstream>
#include <string>

// HashTable class definition
class HashTable {
public:
    // Entry struct to hold data and status of each slot
    struct Entry {
        std::string data;                 // Data stored in the entry
        std::string status = "never used"; // Default status (empty slot)
    };

    static const int Size = 26;  // Hash table size (fixed to 26)

public:
    // Default constructor
    HashTable() = default;

    // Add an entry to the hash table
    void addEntry(const std::string& entry) {
        bool exists = find(entry);  // Check if the entry already exists
        if (!exists) {              // If not, proceed to add it
            int insertIndex = getInsertedEntryIndex(entry);  // Get an index to insert
            m_entries[insertIndex].data = entry;             // Store the data
            m_entries[insertIndex].status = "occupied";      // Mark the slot as occupied
        }
    }

    // Delete an entry from the hash table
    void deleteEntry(const std::string& entry) {
        int index;
        bool exists = find(entry, &index);  // Check if the entry exists
        if (exists) {
            std::cout << "Deleting: " << m_entries[index].data << " at index " << index << '\n';
            m_entries[index].status = "tombstone";  // Mark the slot as deleted
        }
    }

    // Print all entries in the hash table
    void printEntries() {
        for (size_t i = 0; i < Size; i++) {
            std::cout << m_entries[i].data << "(" << m_entries[i].status << ")" << '\n';
        }
    }

private:
    // Hash function: Generates an index based on the last character of the string
    int getIndex(const std::string& entry) {
        return entry.back() - 'a';  // 'a' is subtracted to map 'a' to 0, 'b' to 1, etc.
    }

    // Search for an entry, with an optional index to mark for deletion
    bool find(const std::string& entry, int* deleteIndex = nullptr) {
        int index = getIndex(entry);  // Get the starting index
        while (true) {
            if (m_entries[index].data == entry && m_entries[index].status == "occupied") {  // If found
                if (deleteIndex) {
                    *deleteIndex = index;  // Store index for deletion
                }
                return true;
            }
            if (m_entries[index].status == "never used") {  // Stop if slot is empty
                return false;
            }
            index = (index + 1) % Size;  // Linear probing (move to next slot)
        }
        return false;
    }

    // Find an available index for insertion (linear probing)
    int getInsertedEntryIndex(const std::string& entry) {
        int index = getIndex(entry);  // Get the starting index
        while (true) {
            if (m_entries[index].status == "never used" || m_entries[index].status == "tombstone") {
                return index;  // Return if slot is empty or previously deleted
            }
            index = (index + 1) % Size;  // Linear probing
        }
        return -1;  // Should never reach here
    }

private:
    Entry m_entries[Size];  // Array of entries (fixed size)
};

// Main function to handle user input and process hash table operations
//int main() {
//    std::string input;
//
//    std::cout << "Enter input (e.g., Aapple Dapple Aorange): ";
//    std::getline(std::cin, input);  // Read entire line of input
//
//    HashTable hashTable;
//    std::stringstream ss(input);  // String stream to split input
//
//    while (ss.good()) {
//        std::string token;
//        ss >> token;  // Read each token
//
//        // Extract the operation (A or D) and the entry
//        std::string entry = token.substr(1);  // Extract string after first character
//        if (token[0] == 'A') {                // Add entry if 'A' is the prefix
//            hashTable.addEntry(entry);
//        }
//        else if (token[0] == 'D') {         // Delete entry if 'D' is the prefix
//            hashTable.deleteEntry(entry);
//        }
//    }
//
//    hashTable.printEntries();  // Print final state of the hash table
//
//    return 0;
//}
