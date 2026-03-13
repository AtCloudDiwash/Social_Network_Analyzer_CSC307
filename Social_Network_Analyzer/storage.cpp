#include "storage.h"
#include <algorithm>
#include <fstream>
#include <set>
#include <vector>

std::string saveNetwork(SocialGraph& graph, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open())
        return "Error: Could not open file '" + filename + "' for writing.";

    file << "person,friend\n";
    std::set<std::pair<std::string, std::string>> written;

    for (const auto& [person, friends] : graph.adjacency) {
        if (friends.empty()) {
            file << person << ",\n";
        } else {
            std::vector<std::string> sortedFriends(friends.begin(), friends.end());
            std::sort(sortedFriends.begin(), sortedFriends.end());
            for (const auto& f : sortedFriends) {
                auto pair = std::make_pair(
                    std::min(person, f),
                    std::max(person, f)
                );
                if (!written.count(pair)) {
                    file << person << "," << f << "\n";
                    written.insert(pair);
                }
            }
        }
    }
    return "Network saved to '" + filename + "'.";
}

std::string loadNetwork(SocialGraph& graph, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open())
        return "File '" + filename + "' not found.";

    graph.adjacency.clear();
    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        if (line.empty()) continue;
        size_t comma = line.find(',');
        if (comma == std::string::npos) continue;
        std::string person = line.substr(0, comma);
        std::string friendName = line.substr(comma + 1);

        if (!person.empty() && !graph.adjacency.count(person))
            graph.adjacency[person] = {};
        if (!friendName.empty()) {
            if (!graph.adjacency.count(friendName))
                graph.adjacency[friendName] = {};
            graph.adjacency[person].insert(friendName);
            graph.adjacency[friendName].insert(person);
        }
    }
    return "Network loaded from '" + filename + "'.";
}
