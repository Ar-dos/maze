#include "gtest/gtest.h"
#include "model/cave/cave.h"
#include "model/maze/maze.h"
#include "model/maze/maze_cell.h"

TEST(generate_maze_test, s21_maze) {
  Maze maze;
  maze.GenerateMaze(5, 5);
  ASSERT_EQ(maze.GetRows(), 5);
  ASSERT_EQ(maze.GetCols(), 5);
}

TEST(generate_maze_error_size_test, s21_maze) {
  Maze maze;
  maze.GenerateMaze(-5, 5);
  ASSERT_TRUE(maze.GetMazeMatrix().empty());
}

TEST(open_maze_test, s21_mase) {
  Maze open;
  open.CreateMazeFromFile("../datasets/maze.txt");
  open.CreateFileFromMaze("../datasets/maze_res.txt");
  Maze maze;
  maze.CreateMazeFromFile("../datasets/maze_res.txt");
  ASSERT_EQ(maze.GetRows(), 4);
  ASSERT_EQ(maze.GetCols(), 4);

  ASSERT_EQ(maze.GetMazeMatrix()[0][0].GetRightWall(), 0);
  ASSERT_EQ(maze.GetMazeMatrix()[0][1].GetRightWall(), 0);
  ASSERT_EQ(maze.GetMazeMatrix()[0][2].GetRightWall(), 0);
  ASSERT_EQ(maze.GetMazeMatrix()[0][3].GetRightWall(), 1);
  ASSERT_EQ(maze.GetMazeMatrix()[1][0].GetRightWall(), 1);
  ASSERT_EQ(maze.GetMazeMatrix()[1][1].GetRightWall(), 0);
  ASSERT_EQ(maze.GetMazeMatrix()[1][2].GetRightWall(), 1);
  ASSERT_EQ(maze.GetMazeMatrix()[1][3].GetRightWall(), 1);
  ASSERT_EQ(maze.GetMazeMatrix()[2][0].GetRightWall(), 0);
  ASSERT_EQ(maze.GetMazeMatrix()[2][1].GetRightWall(), 1);
  ASSERT_EQ(maze.GetMazeMatrix()[2][2].GetRightWall(), 0);
  ASSERT_EQ(maze.GetMazeMatrix()[2][3].GetRightWall(), 1);
  ASSERT_EQ(maze.GetMazeMatrix()[3][0].GetRightWall(), 0);
  ASSERT_EQ(maze.GetMazeMatrix()[3][1].GetRightWall(), 0);
  ASSERT_EQ(maze.GetMazeMatrix()[3][2].GetRightWall(), 0);
  ASSERT_EQ(maze.GetMazeMatrix()[3][3].GetRightWall(), 1);

  ASSERT_EQ(maze.GetMazeMatrix()[0][0].GetDownWall(), 1);
  ASSERT_EQ(maze.GetMazeMatrix()[0][1].GetDownWall(), 0);
  ASSERT_EQ(maze.GetMazeMatrix()[0][2].GetDownWall(), 1);
  ASSERT_EQ(maze.GetMazeMatrix()[0][3].GetDownWall(), 0);
  ASSERT_EQ(maze.GetMazeMatrix()[1][0].GetDownWall(), 0);
  ASSERT_EQ(maze.GetMazeMatrix()[1][1].GetDownWall(), 0);
  ASSERT_EQ(maze.GetMazeMatrix()[1][2].GetDownWall(), 1);
  ASSERT_EQ(maze.GetMazeMatrix()[1][3].GetDownWall(), 0);
  ASSERT_EQ(maze.GetMazeMatrix()[2][0].GetDownWall(), 1);
  ASSERT_EQ(maze.GetMazeMatrix()[2][1].GetDownWall(), 1);
  ASSERT_EQ(maze.GetMazeMatrix()[2][2].GetDownWall(), 0);
  ASSERT_EQ(maze.GetMazeMatrix()[2][3].GetDownWall(), 1);
  ASSERT_EQ(maze.GetMazeMatrix()[3][0].GetDownWall(), 1);
  ASSERT_EQ(maze.GetMazeMatrix()[3][1].GetDownWall(), 1);
  ASSERT_EQ(maze.GetMazeMatrix()[3][2].GetDownWall(), 1);
  ASSERT_EQ(maze.GetMazeMatrix()[3][3].GetDownWall(), 1);
}

TEST(open_maze_error_test, s21_mase) {
  Maze open;
  open.CreateMazeFromFile("fsdfsdf/maze.txt");
  ASSERT_TRUE(open.GetMazeMatrix().empty());
}

TEST(path_maze_test, s21_mase) {
  Maze maze;
  maze.CreateMazeFromFile("../datasets/maze.txt");
  maze.FindPath(0, 0, 0, 1);
  ASSERT_EQ(maze.GetPath()[0], 0);
  ASSERT_EQ(maze.GetPath()[1], 0);

  ASSERT_EQ(maze.GetPath()[2], 1);
  ASSERT_EQ(maze.GetPath()[3], 0);

  ASSERT_EQ(maze.GetPath()[4], 1);
  ASSERT_EQ(maze.GetPath()[5], 1);

  ASSERT_EQ(maze.GetPath()[6], 1);
  ASSERT_EQ(maze.GetPath()[7], 2);

  ASSERT_EQ(maze.GetPath()[8], 0);
  ASSERT_EQ(maze.GetPath()[9], 2);

  ASSERT_EQ(maze.GetPath()[10], 0);
  ASSERT_EQ(maze.GetPath()[11], 1);
}

TEST(cave_test, s21_maze) {
  Cave cave;
  cave.CreateCaveFromFile("../datasets/cave.txt");
  cave.NextStep(4, 3);
  ASSERT_EQ(cave.GetMatrix()[0][0], 1);
  ASSERT_EQ(cave.GetMatrix()[0][1], 1);
  ASSERT_EQ(cave.GetMatrix()[0][2], 1);
  ASSERT_EQ(cave.GetMatrix()[0][3], 1);
  ASSERT_EQ(cave.GetMatrix()[1][0], 1);
  ASSERT_EQ(cave.GetMatrix()[1][1], 0);
  ASSERT_EQ(cave.GetMatrix()[1][2], 0);
  ASSERT_EQ(cave.GetMatrix()[1][3], 1);
  ASSERT_EQ(cave.GetMatrix()[2][0], 1);
  ASSERT_EQ(cave.GetMatrix()[2][1], 0);
  ASSERT_EQ(cave.GetMatrix()[2][2], 0);
  ASSERT_EQ(cave.GetMatrix()[2][3], 1);
  ASSERT_EQ(cave.GetMatrix()[3][0], 1);
  ASSERT_EQ(cave.GetMatrix()[3][1], 1);
  ASSERT_EQ(cave.GetMatrix()[3][2], 1);
  ASSERT_EQ(cave.GetMatrix()[3][3], 1);
}

int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}
