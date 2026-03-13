#pragma once
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class SocialGraph {
public:
    std::unordered_map<std::string, std::unordered_set<std::string>> adjacency;

    std::string addPerson(const std::string& name);
    std::string removePerson(const std::string& name);
    std::string addFriendship(const std::string& name1, const std::string& name2);
    std::string removeFriendship(const std::string& name1, const std::string& name2);
    std::string updatePerson(const std::string& oldName, const std::string& newName);
    std::string showFriends(const std::string& name);
    std::string mutualFriends(const std::string& name1, const std::string& name2);
    std::string shortestPath(const std::string& name1, const std::string& name2);
};
