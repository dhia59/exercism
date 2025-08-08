#pragma once
#include <utility>   // for std::pair
#include <string>    // for std::string

namespace robot_simulator {

enum class Bearing {
    NORTH,
    EAST,
    SOUTH,
    WEST
};

class Robot {
    std::pair<int, int> current_position{0, 0};
    Bearing current_bearing{Bearing::NORTH};

public:
    
    // Default constructor
    Robot() = default;
    // Constructor
    Robot(std::pair<int, int> pos, Bearing b)
        : current_position(pos), current_bearing(b) {}

    Bearing get_bearing() const ;
    std::pair<int, int> get_position() const ;
    void turn_right();
    void turn_left();
    void advance();
    void execute_sequence(const std::string& seq);
};

} // namespace robot_simulator
