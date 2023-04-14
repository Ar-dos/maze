#include "maze.h"

Maze::Maze() : rows_(0), cols_(0), matrix_(0), current_row_(0) {}

Maze::MazeMatrix Maze::GetMazeMatrix() { return matrix_; }
int Maze::GetRows() { return rows_; }
int Maze::GetCols() { return cols_; }

/**
 * Creates a maze based on data from a file.
 * @param filename - filename for template reading.
 * @return maze as matrix.
 * @note returns an empty matrix if there were errors with the file.
 */
Maze::MazeMatrix Maze::CreateMazeFromFile(std::string filename) {
  Parser p = Parser();
  matrix_ = p.ParseMazeMatrixFile(filename, rows_, cols_);
  return matrix_;
}

/**
 * Generates a maze of the given size.
 * @param rows - count of rows in maze matrix.
 * @param cols - count of cols in maze matrix.
 * @return maze as matrix.
 */
Maze::MazeMatrix Maze::GenerateMaze(int rows, int cols) {
  try {
    rows_ = rows;
    cols_ = cols;
    matrix_ = std::vector<std::vector<MazeCell>>(
        rows_, std::vector<MazeCell>(cols_, MazeCell()));
    srand(time(NULL));
    std::set<int> sets;

    current_row_.clear();
    for (int i = 0; i < cols_; i++) {
      current_row_.push_back(0);
    }

    for (int row = 0; row < rows_ - 1; row++) {
      GenerateRow(row, sets);
    }
    GenerateLastRow(sets);
  } catch (std::exception const&) {
    rows_ = 0;
    cols_ = 0;
    matrix_.clear();
  }
  return matrix_;
}

void Maze::GenerateRow(int row, std::set<int>& sets) {
  UpdateSets(sets);
  SetRightWalls(row, sets);
  SetDownWalls(row);
  RemoveSets(row);
}

void Maze::GenerateLastRow(std::set<int>& sets) {
  UpdateSets(sets);
  SetRightWalls(rows_ - 1, sets);

  for (int i = 0; i < cols_ - 1; i++) {
    if (current_row_[i] != current_row_[i + 1]) {
      matrix_[rows_ - 1][i].SetRightWall(false);
      int set_for_remove = current_row_[i + 1];
      MergeSets(set_for_remove, current_row_[i]);
    }
    matrix_[rows_ - 1][i].SetDownWall(true);
  }
  matrix_[rows_ - 1][cols_ - 1].SetDownWall(true);
}

void Maze::UpdateSets(std::set<int>& set) {
  int id = 1;
  for (int i = 0; i < cols_; i++) {
    if (current_row_[i] == 0) {
      while (!set.insert(id).second) {
        id++;
      }
      current_row_[i] = id;
    }
  }
}

void Maze::SetRightWalls(int row, std::set<int>& set) {
  for (int i = 0; i < cols_ - 1; i++) {
    if (current_row_[i] == current_row_[i + 1] || SetWall()) {
      matrix_[row][i].SetRightWall(true);
    } else {
      int set_for_remove = current_row_[i + 1];
      MergeSets(set_for_remove, current_row_[i]);
      set.erase(set_for_remove);
    }
  }
  matrix_[row][cols_ - 1].SetRightWall(true);
}

void Maze::MergeSets(int set_for_remove, int set_for_add) {
  for (int j = 0; j < cols_; j++) {
    if (current_row_[j] == set_for_remove) {
      current_row_[j] = set_for_add;
    }
  }
}

void Maze::SetDownWalls(int row) {
  for (int i = 0; i < cols_; i++) {
    if (SetWall()) {
      matrix_[row][i].SetDownWall(true);
    }
  }

  for (int i = 0; i < cols_; i++) {
    if (!ThereIsWayDown(row, current_row_[i])) {
      matrix_[row][i].SetDownWall(false);
    }
  }
}

bool Maze::ThereIsWayDown(int row, int set) {
  bool is_open_down_way = false;
  for (int i = 0; i < cols_ && !is_open_down_way; i++) {
    if (current_row_[i] == set && matrix_[row][i].GetDownWall() == false) {
      is_open_down_way = true;
    }
  }
  return is_open_down_way;
}

void Maze::RemoveSets(int row) {
  for (int i = 0; i < cols_; i++) {
    if (matrix_[row][i].GetDownWall()) {
      current_row_[i] = 0;
    }
  }
}

bool Maze::SetWall() {
  int result = rand() % 101 + 1;
  return (result % 2 == 0) ? true : false;
}

void Maze::CreateFileFromMaze(std::string filename) {
  std::ofstream file(filename, std::ofstream::out);
  if (file.is_open()) {
    file << rows_ << " " << cols_ << std::endl;
    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < cols_; ++j)
        file << matrix_[i][j].GetRightWall() << " ";
      file << std::endl;
    }
    file << std::endl;
    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < cols_; ++j)
        file << matrix_[i][j].GetDownWall() << " ";
      file << std::endl;
    }
  }
}

std::vector<int> Maze::GetPath() { return PointOrder; }

bool Maze::FindPath(int sx, int sy, int fx, int fy) {
  bool res = 0;
  if (!matrix_.empty() && sx > -1 && sy > -1 && fx > -1 && fy > -1 &&
      sx < cols_ && sy < rows_ && fx < cols_ && fy < rows_) {
    int x = sx, y = sy;
    path_.clear();
    PointOrder.clear();
    for (int i = 0; i < rows_; i++) {
      path_.push_back(std::vector<int>());
      for (int j = 0; j < cols_; j++) {
        path_[i].push_back(0);
      }
    }
    int count = 0;
    while ((x != fx || y != fy) && count < 10000) {
      Move(&x, &y);
      count++;
    }
    if (count != 10000) {
      path_[y][x] = 1, x = sx, y = sy, count = 0;
      while ((x != fx || y != fy) && count < 10000) {
        PointOrder.push_back(x);
        PointOrder.push_back(y);
        path_[y][x] = 3;
        Check(&x, &y, 1);
        count++;
      }
      PointOrder.push_back(x);
      PointOrder.push_back(y);
      res = 1;
    }
  }
  return res;
}

bool Maze::GetLeftWay(int x, int y, int v) {
  bool res = 0;
  if (x != 0) {
    if (!matrix_[y][x - 1].GetRightWall() && path_[y][x - 1] == v) res = 1;
  }
  return res;
}
bool Maze::GetUpWay(int x, int y, int v) {
  bool res = 0;
  if (y != 0) {
    if (!matrix_[y - 1][x].GetDownWall() && path_[y - 1][x] == v) res = 1;
  }
  return res;
}
bool Maze::GetRightWay(int x, int y, int v) {
  bool res = 0;
  if (x != cols_ - 1) {
    if (!matrix_[y][x].GetRightWall() && path_[y][x + 1] == v) res = 1;
  }
  return res;
}
bool Maze::GetDownWay(int x, int y, int v) {
  bool res = 0;
  if (y != rows_ - 1) {
    if (!matrix_[y][x].GetDownWall() && path_[y + 1][x] == v) res = 1;
  }
  return res;
}

void Maze::Move(int* x, int* y) {
  int v = 0;
  path_[*y][*x] = 1;
  if (Check(x, y, v)) {
    v++;
    path_[*y][*x] = 2;
    Check(x, y, v);
  }
}

bool Maze::Check(int* x, int* y, int v) {
  bool res = 1;
  if (GetRightWay(*x, *y, v)) {
    (*x)++;
    res = 0;
  } else if (GetDownWay(*x, *y, v)) {
    (*y)++;
    res = 0;
  } else if (GetLeftWay(*x, *y, v)) {
    (*x)--;
    res = 0;
  } else if (GetUpWay(*x, *y, v)) {
    (*y)--;
    res = 0;
  }
  return res;
}
