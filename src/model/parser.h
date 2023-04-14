#include <fstream>
#include <vector>

#include "maze/maze_cell.h"

#pragma once

class Parser {
 public:
  typedef std::vector<std::vector<MazeCell> > MazeMatrix;
  typedef std::vector<std::vector<bool> > CaveMatrix;

  MazeMatrix ParseMazeMatrixFile(std::string filename, int &rows, int &cols);
  CaveMatrix ParseCaveMatrixFile(std::string filename, int &rows, int &cols);
};
