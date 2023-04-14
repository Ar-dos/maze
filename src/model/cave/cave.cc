#include "cave.h"

Cave::Cave() : rows_(0), cols_(0), matrix_(0) {}

const Cave::CaveMatrix Cave::GetMatrix() { return matrix_; }

Cave::CaveMatrix Cave::CreateCaveFromFile(std::string filename) {
  Parser p = Parser();
  matrix_ = p.ParseCaveMatrixFile(filename, rows_, cols_);
  return matrix_;
}

int Cave::GetNeigbours(int i, int j) {
  int res = 0;
  for (int ki = -1; ki <= 1; ki++) {
    for (int kj = -1; kj <= 1; kj++) {
      if (i + ki < 0 || i + ki >= rows_ || j + kj < 0 || j + kj >= cols_) {
        res++;
      } else if (matrix_[i + ki][j + kj] && !(ki == 0 && kj == 0)) {
        res++;
      }
    }
  }
  return res;
}

bool Cave::NextStep(int birth, int death) {
  bool res = 0;
  CaveMatrix temp = matrix_;
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      if (matrix_[i][j] == 1) {
        if (GetNeigbours(i, j) < death) temp[i][j] = 0;
      } else {
        if (GetNeigbours(i, j) > birth) temp[i][j] = 1;
      }
    }
  }
  if (matrix_ != temp)
    matrix_ = temp;
  else
    res = 1;
  return res;
}
