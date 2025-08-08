#include "robot_simulator.h"

namespace robot_simulator {

Bearing Robot::get_bearing() const {
    return current_bearing;
}

std::pair<int, int> Robot::get_position() const {
    return current_position;
}

void Robot::turn_right() {
    switch (current_bearing) {
        case Bearing::NORTH: current_bearing = Bearing::EAST; break;
        case Bearing::EAST:  current_bearing = Bearing::SOUTH; break;
        case Bearing::SOUTH: current_bearing = Bearing::WEST; break;
        case Bearing::WEST:  current_bearing = Bearing::NORTH; break;
    }
}

void Robot::turn_left() {
    switch (current_bearing) {
        case Bearing::NORTH: current_bearing = Bearing::WEST; break;
        case Bearing::WEST:  current_bearing = Bearing::SOUTH; break;
        case Bearing::SOUTH: current_bearing = Bearing::EAST; break;
        case Bearing::EAST:  current_bearing = Bearing::NORTH; break;
    }
}

void Robot::advance() {
    switch (current_bearing) {
        case Bearing::NORTH: current_position.second += 1; break;
        case Bearing::EAST:  current_position.first  += 1; break;
        case Bearing::SOUTH: current_position.second -= 1; break;
        case Bearing::WEST:  current_position.first  -= 1; break;
    }
}

void Robot::execute_sequence(const std::string& seq) {
    for (char c : seq) {
        if (c == 'R') {
            turn_right();
        } else if (c == 'L') {
            turn_left();
        } else if (c == 'A') {
            advance();
        }
    }
}

}  // namespace robot_simulator
