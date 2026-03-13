#include "commands.h"
#include "graph.h"
#include <iostream>
#include <string>

const std::string HELP_TEXT = R"(
Available Commands:
  AddPerson <name>
  AddFriendship <name1> <name2>
  RemovePerson <name>
  RemoveFriendship <name1> <name2>
  UpdatePerson <oldname> <newname>
  ShowFriends <name>
  MutualFriends <name1> <name2>
  ShortestPath <name1> <name2>
  SaveNetwork <csv_file>
  LoadNetwork <csv_file>
  exit
)";

int main() {
    SocialGraph graph;
    std::string input;

    std::cout << "Social Network Analyzer\n";
    std::cout << "Type 'help' for available commands or 'exit' to quit.\n";

    while (true) {
        std::cout << "\n> ";
        if (!std::getline(std::cin, input)) {
            std::cout << "\nExiting.\n";
            break;
        }

        if (input == "exit") {
            std::cout << "Goodbye.\n";
            break;
        } else if (input == "help") {
            std::cout << HELP_TEXT;
        } else if (input.empty()) {
            continue;
        } else {
            std::cout << handleCommand(input, graph) << "\n";
        }
    }

    return 0;
}
