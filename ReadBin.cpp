#include <iostream>
#include <fstream>

int main() {
    const std::string filePath = "we.bin";  // Replace with the path to your binary file

    std::ifstream file(filePath, std::ios::binary);
    if (!file) {
        std::cerr << "Unable to open file: " << filePath << std::endl;
        return 1;
    }

    char byte;
    while (file.get(byte)) {
        std::cout << "Read byte: " << static_cast<int>(byte) << std::endl;
        // You can choose what to do with each byte here
    }

    return 0;
}
