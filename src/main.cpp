#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstdlib>
#include <filesystem>

// Enum for valid commands
enum validCommands {
    echo,
    cd,
    exit0,
    type,
    invalid
};

// Function to validate command
validCommands isValid(std::string command) {
    command = command.substr(0, command.find(" "));

    if (command == "echo") return validCommands::echo;
    if (command == "cd") return validCommands::cd;
    if (command == "exit") return validCommands::exit0;
    if (command == "type") return validCommands::type;

    return invalid;
}

// Function to find the command in PATH directories
std::string get_path(std::string command) {
    std::string path_env = std::getenv("PATH");

    std::stringstream ss(path_env);
    std::string path;

    while (getline(ss, path, ':')) {
        std::string abs_path = path + '/' + command;

        if (std::filesystem::exists(abs_path) && std::filesystem::is_regular_file(abs_path)) {
            return abs_path;
        }
    }
    return "";
}

int main() {
    // Flush after every std::cout / std::cerr
    std::cout << std::unitbuf;
    std::cerr << std::unitbuf;

    // List of recognized commands
    std::vector<std::string> commands = {"echo", "exit", "type"};

    while (true) {
        // Print the shell prompt
        std::cout << "$ ";
        
        std::string input;
        std::getline(std::cin, input);

        if (input.empty()) {
            continue;
        }

        if (input == "exit 0") {
            break;
        }

        if (input.find("echo ") == 0) {
            std::string echo_input = input.substr(5);
            std::cout << echo_input << std::endl;
            continue;
        }

        if (input.find("type ") == 0) {
            std::string command = input.substr(5);
            // Check if the command is a built-in command
            auto it = std::find(commands.begin(), commands.end(), command);
            if (it != commands.end()) {
                std::cout << command << " is a shell builtin" << std::endl;
            } else {
                std::string found_path = get_path(command);
                if (!found_path.empty()) {
                    std::cout << command << " is " << found_path << std::endl;
                } else {
                    std::cout << command << ": not found" << std::endl;
                }
            }
            continue;
        }

        std::cout << input << ": command not found" << std::endl;
    }

    return 0;
}
