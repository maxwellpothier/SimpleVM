#include <iostream>
#include <vector>
#include <fstream>

// Define some opcodes (instructions)
enum class OpCode {
    ADD,
    SUB,
    HALT
};

// Define a simple VM class
class SimpleVM {
public:
    SimpleVM() : running(true), accumulator(0) {}

// Load program into VM memory
void loadProgram(const std::string& filePath) {
    std::cout << "Loading program from " << filePath << std::endl;
    std::ifstream file(filePath, std::ios::binary);
    if (!file) {
        std::cerr << "Unable to open file: " << filePath << std::endl;
        throw std::runtime_error("Failed to open file.");
    }

    // Read the header/marker (assuming it's a fixed size of 2 bytes)
    char header[2];
    if (!file.read(header, sizeof(header))) {
        std::cerr << "Error reading header." << std::endl;
        throw std::runtime_error("Error reading header.");
    }

    // Verify the header/marker if needed

    // Read opcodes
    OpCode opcode;
    while (file.read(reinterpret_cast<char*>(&opcode), sizeof(OpCode))) {
        // Interpret opcode here
        program.push_back(opcode);
    }

    pc = 0;
}



    // Execute the loaded program
    void execute() {
        while (running) {
            if (pc >= program.size()) {
                std::cout << "Program finished execution.\n";
                break;
            }

            OpCode currentOp = program[pc];

            switch (currentOp) {
                case OpCode::ADD:
                    accumulator += 1;
                    break;
                case OpCode::SUB:
                    accumulator -= 1;
                    break;
                case OpCode::HALT:
                    running = false;
                    std::cout << "Halted.\n";
                    break;
                default:
                    std::cerr << "Unknown opcode.\n";
                    running = false;
                    break;
            }

            pc++;
        }
    }

private:
    std::vector<OpCode> program;
    bool running;
    int accumulator;
    std::vector<OpCode>::size_type pc;
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Please provide a binary file to execute.\n";
        return 1;
    }

    // Create a SimpleVM instance
    SimpleVM vm;

    // Load a simple program into the VM's memory
    vm.loadProgram(argv[1]);

    // Execute the program
    vm.execute();

    return 0;
}
