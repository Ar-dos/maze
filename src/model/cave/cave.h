#ifndef SRC_APPLICATION_CAVE_CAVE_H
#define SRC_APPLICATION_CAVE_CAVE_H

#include <fstream>
#include <iostream>
#include <vector>

#include "../parser.h"

class Cave {
 public:
  typedef std::vector<std::vector<bool>> CaveMatrix;

  Cave();

  const CaveMatrix GetMatrix();
  CaveMatrix CreateCaveFromFile(std::string filename);
  bool NextStep(int birth, int death);

 private:
  int rows_;
  int cols_;
  CaveMatrix matrix_;

  int GetNeigbours(int i, int j);
};
#endif  // SRC_APPLICATION_CAVE_CAVE_H
