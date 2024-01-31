#include <iostream>
#include <string>
#include <iomanip>

// Function to estimate memory usage of a std::string
size_t getStringMemoryUsage(const std::string& str) {
    // Calculate size of the string object itself
    size_t sizeOfStringObject = sizeof(str);

    // Calculate size of string's content (characters) and additional bookkeeping
    size_t sizeOfStringContent = str.capacity() * sizeof(std::string::value_type);

    // Return total estimated memory usage
    return sizeOfStringObject + sizeOfStringContent;
}

int main() {
    std::string myString = "Hello, World!";
    
    // Get an estimate of the memory used by the string
    size_t memoryUsage = getStringMemoryUsage(myString);

    std::string str = "Hello, World!"; 
    // Display the result
    std::cout << "Size of the string object itself: " << sizeof(str) << " bytes";
    std::cout << "\nEstimated memory usage of the string: " << memoryUsage << " bytes" << std::endl;

    return 0;
}
