#ifndef SRC_APPLICATION_MAZE_SRC_MAZE_H_
#define SRC_APPLICATION_MAZE_SRC_MAZE_H_

#include <ctime>
#include <iostream>
#include <memory>
#include <set>
#include <vector>

#include "../parser.h"
#include "maze_cell.h"

class Maze {
 public:
  typedef std::vector<std::vector<MazeCell>> MazeMatrix;

  Maze();

  MazeMatrix GetMazeMatrix();
  int GetRows();
  int GetCols();

  MazeMatrix GenerateMaze(int rows, int cols);
  MazeMatrix CreateMazeFromFile(std::string filename);
  void CreateFileFromMaze(std::string filename);

  typedef std::vector<std::vector<int>> PathMatrix;
  std::vector<int> GetPath();
  bool FindPath(int sx, int sy, int fx, int fy);

 private:
  int rows_;
  int cols_;
  MazeMatrix matrix_;
  std::vector<int> current_row_;

  void GenerateRow(int row, std::set<int>& sets);
  void GenerateLastRow(std::set<int>& sets);

  void UpdateSets(std::set<int>& set);
  void SetRightWalls(int row, std::set<int>& set);
  void MergeSets(int set_for_remove, int set_for_add);
  void SetDownWalls(int row);
  bool ThereIsWayDown(int row, int set);
  void RemoveSets(int row);
  bool SetWall();

  PathMatrix path_;
  bool GetLeftWay(int x, int y, int v);
  bool GetUpWay(int x, int y, int v);
  bool GetRightWay(int x, int y, int v);
  bool GetDownWay(int x, int y, int v);

  bool Check(int* x, int* y, int v);
  void Move(int* x, int* y);

  std::vector<int> PointOrder;
};

#endif  // SRC_APPLICATION_MAZE_SRC_MAZE_H_
