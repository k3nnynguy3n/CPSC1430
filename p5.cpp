// Kenny Nguyen
// This program interprets expressions in Reverse Polish Notation to perform logical and arithmetic operations

#include "queue.h"
#include "stack.h"
#include <iostream>

// OpId is an enum (short for enumeration). Enums assign names
// to integer values, allowing us to map things to a set of
// integer identifiers
enum OpId {
    BAD  = 0, // Does not correspond to any operation
    ADD  = 1,
    SUB  = 2,
    MUL  = 3,
    DIV  = 4,
    TOP  = 5,
    POP  = 6,
    DUP  = 7,
    COND = 8,
    ENQ  = 9,
    DEQ  = 10,
    SAVE = 11,
    LOAD = 12,
    END  = 1024
};

// To represent the mapping between operations and their string
// representation, we will make this helper struct to act as an
// entry in our list of mappings
struct Operation {
    std::string name;
    OpId        id;
};

// The mapping of operation string representations to their
// integer id
Operation const OPERATIONS[] = {
    {"add", ADD},
    {"sub", SUB},
    {"mul", MUL},
    {"div", DIV},
    {"top", TOP},
    {"pop", POP},
    {"dup", DUP},
    {"cond", COND},
    {"enq", ENQ},
    {"deq", DEQ},
    {"save", SAVE},
    {"load", LOAD},
    {"end", END},
};

// The number of entries in the operation id mapping, calculated
// by taking the quotient of the total size of the mapping by
// the size of each entry.
int const OPERATION_COUNT = sizeof(OPERATIONS) / sizeof(Operation);

// desc : Maps token strings to ther corresponding operation IDs, if
//        possible.
// pre  : None
// post : If the input token corresponds to a valid string representation
//        for an operation, the corresponding OpId value is returned. If
//        no such matching exists, OpId::BAD is returned instead
OpId token_to_operation_id(std::string token) {
    for (int i = 0; i < OPERATION_COUNT; i++) {
        // Linear search through entries until a match is found...
        if (OPERATIONS[i].name == token) {
            return OPERATIONS[i].id;
        }
    }
    // ... or until we run out of entries
    return OpId::BAD;
}

// desc : Returns true if and only if the input string represents a non-empty
//        string consisting only of roman numerals.
// pre  : None
// post : None, aside from description
bool is_numeric(std::string token) {
    int size = token.size();
    // In the odd case we get an empty string, we count it as *not* an integer
    if (size == 0) {
        return false;
    }
    // Iterate through token, double-checking that the character values are only
    // in the valid range for digits
    for (int i = 0; i < size; i++) {
        if (token[i] < '0' || token[i] > '9') {
            return false;
        }
    }
    return true;
}

// desc : please remember to document these functions, including their bodies
// pre  :
// post :
void evaluate(Stack &active_stack, Queue &active_queue, std::string token) {

    int   count = 0;
    Stack temp_stack;
    // Gets the count of the number of elements in the stack by pushing into a temp stack incrementing each time
    // that the loop iterates then pushes the elements back into the active stack from the temp stack
    while (!active_stack.is_empty()) {
        temp_stack.push(active_stack.pop());
        count++;
    }
    while (!temp_stack.is_empty()) {
        active_stack.push(temp_stack.pop());
    }

    if (is_numeric(token)) {
        // Convert the token to its integer value
        int value = stoi(token);
        // Push the value of the token onto the active stack
        active_stack.push(value);
    } else {
        // It is advised you use the provided OpId enumeration and id mapping
        // functions to switch between your function calls. Of course, not all
        // operations must be handled here, since the end/save/load operations
        // have special requirements that are easier to meet in the main function
        switch (token_to_operation_id(token)) {

        case OpId::ADD: {
            if (count >= 2) {
                int b = active_stack.pop();
                active_stack.pop();
                int a = active_stack.pop();
                active_stack.pop();
                active_stack.push(a + b);
            } else {
                std::cout << "Error: ADD operation requires at least two elements on the stack\n";
            }
            break;
        }

        case OpId::SUB: {
            if (count >= 2) {
                int b = active_stack.pop();
                active_stack.pop();
                int a = active_stack.pop();
                active_stack.pop();
                active_stack.push(a - b);
            } else {
                std::cout << "Error: SUBTRACT operation requires at least two elements on the stack\n";
            }
            break;
        }

        case OpId::MUL: {
            if (count >= 2) {
                int b = active_stack.pop();
                active_stack.pop();
                int a = active_stack.pop();
                active_stack.pop();
                active_stack.push(a * b);
            } else {
                std::cout << "Error: MUL operation requires at least two elements on the stack\n";
            }
            break;
        }

        case OpId::DIV: {
            if (count >= 2) {
                int b = active_stack.pop();
                active_stack.pop();
                int a = active_stack.pop();
                active_stack.pop();
                if (b == 0) {
                    std::cout << "Error: DIV operation attempted to divide by zero\n";
                    active_stack.push(a);
                } else {
                    active_stack.push(a / b);
                }
            } else {
                std::cout << "Error: DIV operation requires at least two elements on the stack\n";
            }
            break;
        }

        case OpId::TOP: {
            if (active_stack.is_empty()) {
                std::cout << "Error: TOP operation requires at least one element on the stack\n";
            } else {
                std::cout << active_stack.pop() << "\n";
            }
            break;
        }

        case OpId::POP: {
            if (active_stack.is_empty()) {
                std::cout << "Error: POP operation requires at least one element on the stack\n";
            } else {
                active_stack.pop();
            }
            break;
        }

        case OpId::DUP: {
            if (active_stack.is_empty()) {
                std::cout << "Error: DUP operation requires at least one element on the stack\n";
            } else {
                int a = active_stack.pop();
                active_stack.push(a);
            }
            break;
        }

        case OpId::COND: {
            if (count >= 3) {
                int c = active_stack.pop();
                active_stack.pop();
                int b = active_stack.pop();
                active_stack.pop();
                int a = active_stack.pop();
                active_stack.pop();
                active_stack.push(c != 0 ? a : b);
            } else {
                std::cout << "Error: COND operation requires at least three elements on the stack\n";
            }
            break;
        }

        case OpId::ENQ: {
            if (active_stack.is_empty()) {
                std::cout << "Error: ENQ operation requires at least one element on the stack\n";
            } else {
                active_queue.enqueue(active_stack.pop());
            }
        }

        case OpId::DEQ: {
            if (active_queue.is_empty()) {
                std::cout << "Error: DEQ operation requires at least one element on the queue\n";
            } else {
                active_stack.push(active_queue.dequeue());
            }
        }

        // The case below should happen if an invalid id (like OpId::BAD) is
        // yielded by the id mapping function
        default:
            std::cout << "Unrecognized token '" << token << "'\n";
        }
    }
}

// The main function initializes two stacks and two queues,
// reads input tokens from standard input and executes what the user would like
// Pre: None
// Post: The program has completed execution of the while loop, processed
//      all input tokens, and terminated normally by returning 0.
int main() {
    Stack       active_stack;
    Stack       save_stack;
    Queue       active_queue;
    Queue       save_queue;

    std::string token;
    while (std::cin >> token) {
        if (token == "end") {
            // To get the automatic memory cleanup from the Stack/Queue
            // destructors, we must terminate by returning normally from main
            return 0;
        } else if (token == "save") {
            active_stack = save_stack;
            active_queue = save_queue;
        } else if (token == "load") {
            save_stack = active_stack;
            save_queue = active_queue;
        } else {
            // to prevent main from becoming too large/complex, we delegate the
            // evaluation of "non-special" operations to a separate function
            evaluate(active_stack, active_queue, token);
        }
    }
}
