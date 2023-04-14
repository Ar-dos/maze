#ifndef SRC_APPLICATION_MAZE_SRC_MAZE_CELL_H_
#define SRC_APPLICATION_MAZE_SRC_MAZE_CELL_H_

class MazeCell {
 public:
  MazeCell();

  bool GetRightWall();
  void SetRightWall(bool available);

  bool GetDownWall();
  void SetDownWall(bool available);

 private:
  bool right_wall_;
  bool down_wall_;
};

#endif  // SRC_APPLICATION_MAZE_SRC_MAZE_CELL_H_
