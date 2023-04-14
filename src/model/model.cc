#include "model.h"

Model::Model() : maze_(), cave_() {}

Maze* Model::GetMaze() { return &maze_; }

Cave* Model::GetCave() { return &cave_; }
