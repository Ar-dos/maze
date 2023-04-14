#ifndef SRC_APPLICATION_MODEL_H
#define SRC_APPLICATION_MODEL_H

#include "cave/cave.h"
#include "maze/maze.h"

class Model {
 public:
  Model();

  Maze* GetMaze();
  Cave* GetCave();

 private:
  Maze maze_;
  Cave cave_;
};

#endif  // SRC_APPLICATION_MODEL_H
