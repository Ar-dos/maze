#include "maze_cell.h"

MazeCell::MazeCell() : right_wall_(false), down_wall_(false) {}

bool MazeCell::GetRightWall() { return right_wall_; }

void MazeCell::SetRightWall(bool available) { right_wall_ = available; }

bool MazeCell::GetDownWall() { return down_wall_; }

void MazeCell::SetDownWall(bool available) { down_wall_ = available; }
