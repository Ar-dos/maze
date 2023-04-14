#ifndef SRC_APPLICATION_CONTROLLER_H
#define SRC_APPLICATION_CONTROLLER_H

#include "../model/model.h"

class Controller {
 public:
  explicit Controller(Model *model);

  std::vector<std::vector<MazeCell>> GenerateMaze(int rows, int cols);
  std::vector<std::vector<MazeCell>> GetMazeMatrix();
  std::vector<std::vector<MazeCell>> CreateMazeFromFile(std::string filename);
  void CreateFileFromMaze(std::string filename);

  bool FindPath(int x, int y, int fx, int fy);
  std::vector<int> GetPath();

  std::vector<std::vector<bool>> GetCaveMatrix();
  std::vector<std::vector<bool>> CreateCaveFromFile(std::string filename);
  bool CaveNextStep(int b, int d);

 private:
  Model *model_;
};

#endif  // SRC_APPLICATION_CONTROLLER_H
