#include "commands.h"
#include "storage.h"
#include <sstream>
#include <vector>

std::string handleCommand(const std::string& input, SocialGraph& graph) {
    std::istringstream ss(input);
    std::vector<std::string> parts;
    std::string token;
    while (ss >> token)
        parts.push_back(token);

    if (parts.empty()) return "";

    const std::string& cmd = parts[0];

    if (cmd == "AddPerson") {
        if (parts.size() != 2) return "Usage: AddPerson <name>";
        return graph.addPerson(parts[1]);
    }
    if (cmd == "AddFriendship") {
        if (parts.size() != 3) return "Usage: AddFriendship <name1> <name2>";
        return graph.addFriendship(parts[1], parts[2]);
    }
    if (cmd == "RemovePerson") {
        if (parts.size() != 2) return "Usage: RemovePerson <name>";
        return graph.removePerson(parts[1]);
    }
    if (cmd == "RemoveFriendship") {
        if (parts.size() != 3) return "Usage: RemoveFriendship <name1> <name2>";
        return graph.removeFriendship(parts[1], parts[2]);
    }
    if (cmd == "UpdatePerson") {
        if (parts.size() != 3) return "Usage: UpdatePerson <oldname> <newname>";
        return graph.updatePerson(parts[1], parts[2]);
    }
    if (cmd == "ShowFriends") {
        if (parts.size() != 2) return "Usage: ShowFriends <name>";
        return graph.showFriends(parts[1]);
    }
    if (cmd == "MutualFriends") {
        if (parts.size() != 3) return "Usage: MutualFriends <name1> <name2>";
        return graph.mutualFriends(parts[1], parts[2]);
    }
    if (cmd == "ShortestPath") {
        if (parts.size() != 3) return "Usage: ShortestPath <name1> <name2>";
        return graph.shortestPath(parts[1], parts[2]);
    }
    if (cmd == "SaveNetwork") {
        if (parts.size() != 2) return "Usage: SaveNetwork <csv_file>";
        return saveNetwork(graph, parts[1]);
    }
    if (cmd == "LoadNetwork") {
        if (parts.size() != 2) return "Usage: LoadNetwork <csv_file>";
        return loadNetwork(graph, parts[1]);
    }

    return "Unknown command: '" + cmd + "'. Type 'help' for available commands.";
}
