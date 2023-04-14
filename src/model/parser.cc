#include "parser.h"

Parser::MazeMatrix Parser::ParseMazeMatrixFile(std::string filename, int &rows,
                                               int &cols) {
  std::ifstream file(filename, std::ifstream::in);
  file >> rows;
  file >> cols;
  MazeMatrix result = std::vector<std::vector<MazeCell> >(
      rows, std::vector<MazeCell>(cols, MazeCell()));

  if (file.is_open()) {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        int temp;
        file >> temp;
        result[i][j].SetRightWall(temp);
      }
    }

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        int temp;
        file >> temp;
        result[i][j].SetDownWall(temp);
      }
    }
    file.close();
  }
  return result;
}

Parser::CaveMatrix Parser::ParseCaveMatrixFile(std::string filename, int &rows,
                                               int &cols) {
  std::ifstream file(filename, std::ifstream::in);
  file >> rows;
  file >> cols;
  CaveMatrix result =
      std::vector<std::vector<bool> >(rows, std::vector<bool>(cols, false));
  if (file.is_open()) {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        bool temp;
        file >> temp;
        result[i][j] = temp;
      }
    }
    file.close();
  }
  return result;
}
