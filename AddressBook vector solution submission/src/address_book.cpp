

#include "include/address_book.h"

#include <stdexcept>

// This operation will just add the person, which is the entry object, to the enry container
void AddressBook::add(AddressBook::Entry& person)
{
    entries.push_back(person);
}

// Iterator finds the person that needs to be deleted and deletes using entries.erase()
// More over, lambda expression is used for the predicate
void AddressBook::remove(AddressBook::Entry& person)
{

    auto it = std::find_if(entries.begin(), entries.end(),
                          [&](const AddressBook::Entry& entry) { return entry.first_name == person.first_name && entry.phone_number == person.phone_number && entry.last_name == person.last_name; });
    if (it != entries.end()) {
      entries.erase(it);
    }
}

std::vector<AddressBook::Entry> AddressBook::sortedByFirstName()
{
    // Iterator iterates over vector and uses sort algortihm to sort by first name
    std::vector<Entry> sorted_entries = entries;
    std::sort(sorted_entries.begin(), sorted_entries.end(),
              [](const Entry& a, const Entry& b) {
                return a.first_name < b.first_name;
              });
    return sorted_entries;
}

std::vector<AddressBook::Entry> AddressBook::sortedByLastName()
{
    // Iterator iterates over vector and uses sort algortihm to sort by last name
    std::vector<Entry> sorted_entries = entries;
    std::sort(sorted_entries.begin(), sorted_entries.end(),
              [](const Entry& a, const Entry& b) {
                return a.last_name < b.last_name;
              });
    return sorted_entries;
}

// To determine if the given string could match a name in the address book, I converted both strings to lowercase using the transform algorithm, and then compared if they match. Both the first and last name could have search results.
std::vector<AddressBook::Entry> AddressBook::find(const std::string& name)
{


    std::vector<Entry> matching_entries;
        std::string lowercase_search_string = name;
    
        std::transform(lowercase_search_string.begin(), lowercase_search_string.end(), lowercase_search_string.begin(), ::tolower);
    
        for (const auto& entry : entries) {
          std::string lowercase_name = entry.first_name;
            
          std::transform(lowercase_name.begin(), lowercase_name.end(), lowercase_name.begin(), ::tolower);
            
          if (lowercase_name.find(lowercase_search_string) == 0) {
            matching_entries.push_back(entry);
          }
          
          else {
            lowercase_name = entry.last_name;
            std::transform(lowercase_name.begin(), lowercase_name.end(), lowercase_name.begin(), ::tolower);
              
            if (lowercase_name.find(lowercase_search_string) == 0) {
              matching_entries.push_back(entry);
            }
          }
}
    return matching_entries;
}


// I designed an address book program that uses a vector for storing and managing entries.
// While this design works well for basic operations, it has a time complexity of O(n) for removing, and searching entries. 
// To improve the performance of these operations, I attempted to implement a balanced binary search tree, which would have a time complexity of O(log n) for the mentioned operations. 
// However, I encountered many errors and issues while implementing this solution and was unable to successfully run the program. 
// The binary search tree attempt will also be included in the submission. The classes are complete and the .cpp implementation is complete as well.
// However I was not able to test the program due to an error that I encountered regarding pointers.
// Despite spending around 3 hours on the vector-based solution and another 4-5 hours on the binary search tree solution, I was unable to complete the latter. 
// It took more time than I initially expected due to the errors and issues encountered.
//.




