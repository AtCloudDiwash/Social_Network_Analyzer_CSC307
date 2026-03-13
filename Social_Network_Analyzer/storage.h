#pragma once
#include "graph.h"
#include <string>

std::string saveNetwork(SocialGraph& graph, const std::string& filename);
std::string loadNetwork(SocialGraph& graph, const std::string& filename);
