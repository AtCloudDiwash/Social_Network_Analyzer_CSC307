#include "graph.h"
#include <algorithm>
#include <queue>
#include <sstream>
#include <vector>

std::string SocialGraph::addPerson(const std::string& name) {
    if (adjacency.count(name))
        return "'" + name + "' already exists in the network.";
    adjacency[name] = {};
    return "'" + name + "' added to the network.";
}

std::string SocialGraph::removePerson(const std::string& name) {
    if (!adjacency.count(name))
        return "'" + name + "' not found in the network.";
    for (auto& neighbor : adjacency[name])
        adjacency[neighbor].erase(name);
    adjacency.erase(name);
    return "'" + name + "' removed from the network.";
}

std::string SocialGraph::addFriendship(const std::string& name1, const std::string& name2) {
    if (!adjacency.count(name1))
        return "'" + name1 + "' not found in the network.";
    if (!adjacency.count(name2))
        return "'" + name2 + "' not found in the network.";
    if (adjacency[name1].count(name2))
        return "'" + name1 + "' and '" + name2 + "' are already friends.";
    adjacency[name1].insert(name2);
    adjacency[name2].insert(name1);
    return "Friendship added between '" + name1 + "' and '" + name2 + "'.";
}

std::string SocialGraph::removeFriendship(const std::string& name1, const std::string& name2) {
    if (!adjacency.count(name1))
        return "'" + name1 + "' not found in the network.";
    if (!adjacency.count(name2))
        return "'" + name2 + "' not found in the network.";
    if (!adjacency[name1].count(name2))
        return "'" + name1 + "' and '" + name2 + "' are not friends.";
    adjacency[name1].erase(name2);
    adjacency[name2].erase(name1);
    return "Friendship removed between '" + name1 + "' and '" + name2 + "'.";
}

std::string SocialGraph::updatePerson(const std::string& oldName, const std::string& newName) {
    if (!adjacency.count(oldName))
        return "'" + oldName + "' not found in the network.";
    if (adjacency.count(newName))
        return "'" + newName + "' already exists in the network.";
    adjacency[newName] = std::move(adjacency[oldName]);
    adjacency.erase(oldName);
    for (auto& neighbor : adjacency[newName]) {
        adjacency[neighbor].erase(oldName);
        adjacency[neighbor].insert(newName);
    }
    return "'" + oldName + "' renamed to '" + newName + "'.";
}

std::string SocialGraph::showFriends(const std::string& name) {
    if (!adjacency.count(name))
        return "'" + name + "' not found in the network.";
    if (adjacency[name].empty())
        return "'" + name + "' has no friends yet.";
    std::vector<std::string> friends(adjacency[name].begin(), adjacency[name].end());
    std::sort(friends.begin(), friends.end());
    std::string result = "Friends of '" + name + "': ";
    for (size_t i = 0; i < friends.size(); i++) {
        if (i > 0) result += ", ";
        result += friends[i];
    }
    return result;
}

std::string SocialGraph::mutualFriends(const std::string& name1, const std::string& name2) {
    if (!adjacency.count(name1))
        return "'" + name1 + "' not found in the network.";
    if (!adjacency.count(name2))
        return "'" + name2 + "' not found in the network.";
    std::vector<std::string> mutual;
    for (const auto& f : adjacency[name1])
        if (adjacency[name2].count(f))
            mutual.push_back(f);
    if (mutual.empty())
        return "No mutual friends between '" + name1 + "' and '" + name2 + "'.";
    std::sort(mutual.begin(), mutual.end());
    std::string result = "Mutual friends of '" + name1 + "' and '" + name2 + "': ";
    for (size_t i = 0; i < mutual.size(); i++) {
        if (i > 0) result += ", ";
        result += mutual[i];
    }
    return result;
}

std::string SocialGraph::shortestPath(const std::string& name1, const std::string& name2) {
    if (!adjacency.count(name1))
        return "'" + name1 + "' not found in the network.";
    if (!adjacency.count(name2))
        return "'" + name2 + "' not found in the network.";
    if (name1 == name2)
        return "'" + name1 + "' and '" + name2 + "' are the same person.";

    std::unordered_set<std::string> visited;
    std::queue<std::vector<std::string>> q;
    q.push({name1});
    visited.insert(name1);

    while (!q.empty()) {
        auto path = q.front();
        q.pop();
        const std::string& current = path.back();
        for (const auto& neighbor : adjacency.at(current)) {
            if (neighbor == name2) {
                std::string result;
                for (size_t i = 0; i < path.size(); i++) {
                    if (i > 0) result += " -> ";
                    result += path[i];
                }
                result += " -> " + neighbor;
                return result;
            }
            if (!visited.count(neighbor)) {
                visited.insert(neighbor);
                auto newPath = path;
                newPath.push_back(neighbor);
                q.push(newPath);
            }
        }
    }
    return "No connection found between '" + name1 + "' and '" + name2 + "'.";
}
