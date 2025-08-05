#if !defined(ALPHAMETICS_H)
#define ALPHAMETICS_H
#include <iostream>
#include <vector>
#include <map>
#include <string>  // pour std::cin et std::getline
#include <set>
#include <sstream>
#include <optional>
#include <unordered_map>
#include <chrono>
#include <algorithm>
namespace alphametics {
std::optional<std::unordered_map<char, int>> solve(const std::string& puzzle);
// TODO: add your solution here

}  // namespace alphametics

#endif  // ALPHAMETICS_H