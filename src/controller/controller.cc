#include "controller.h"

Controller::Controller(Model* model) : model_(model) {}

std::vector<std::vector<MazeCell>> Controller::GenerateMaze(int rows,
                                                            int cols) {
  return model_->GetMaze()->GenerateMaze(rows, cols);
}

std::vector<std::vector<MazeCell>> Controller::GetMazeMatrix() {
  return model_->GetMaze()->GetMazeMatrix();
}

std::vector<std::vector<MazeCell>> Controller::CreateMazeFromFile(
    std::string filename) {
  return model_->GetMaze()->CreateMazeFromFile(filename);
}

void Controller::CreateFileFromMaze(std::string filename) {
  return model_->GetMaze()->CreateFileFromMaze(filename);
}

std::vector<int> Controller::GetPath() { return model_->GetMaze()->GetPath(); }

bool Controller::FindPath(int x, int y, int fx, int fy) {
  return model_->GetMaze()->FindPath(x, y, fx, fy);
}

std::vector<std::vector<bool>> Controller::GetCaveMatrix() {
  return model_->GetCave()->GetMatrix();
}
std::vector<std::vector<bool>> Controller::CreateCaveFromFile(
    std::string filename) {
  return model_->GetCave()->CreateCaveFromFile(filename);
}

bool Controller::CaveNextStep(int b, int d) {
  return model_->GetCave()->NextStep(b, d);
}
