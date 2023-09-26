#include <iostream>
#include <vector>

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
    void loadProgram(const std::vector<OpCode>& program) {
        this->program = program;
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

int main() {
    // Create a SimpleVM instance
    SimpleVM vm;

    // Load a simple program into the VM's memory
    std::vector<OpCode> program = {OpCode::ADD, OpCode::ADD, OpCode::SUB, OpCode::HALT};
    vm.loadProgram(program);

    // Execute the program
    vm.execute();

    return 0;
}
