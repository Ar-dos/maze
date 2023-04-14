#include "paintmazewidget.h"

PaintMazeWidget::PaintMazeWidget(QWidget *parent) : QWidget(parent) {}

void PaintMazeWidget::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  QPen pen;
  pen.setWidth(2);
  pen.setColor("black");
  painter.setPen(pen);
  if (!maze.empty()) {
    int rows = maze.size();
    int cols = maze[0].size();
    int cell_width = round((500 - (cols + 1) * 2) / (double)cols);
    int cell_height = round((500 - (rows + 1) * 2) / (double)rows);
    for (int row = 0; row < rows; row++) {
      for (int col = 0; col < cols; col++) {
        if (row == 0) {
          painter.drawLine(col * (cell_width + 2), 0,
                           (col + 1) * (cell_width + 2), 0);
        }
        if (col == 0) {
          painter.drawLine(0, row * (cell_height + 2), 0,
                           (row + 1) * (cell_height + 2));
        }

        if (maze[row][col].GetDownWall()) {
          painter.drawLine(
              col * (cell_width + 2), (row + 1) * (cell_height + 2),
              (col + 1) * (cell_width + 2), (row + 1) * (cell_height + 2));
        }
        if (maze[row][col].GetRightWall()) {
          painter.drawLine(
              (col + 1) * (cell_width + 2), row * (cell_height + 2),
              (col + 1) * (cell_width + 2), (row + 1) * (cell_height + 2));
        }
      }
    }

    if (!path.empty()) {
      pen.setColor("red");
      painter.setPen(pen);
      for (int var = 0; var < path.size() - 2; var = var + 2)
        painter.drawLine(path[var] * (cell_width + 2) + cell_width / 2,
                         path[var + 1] * (cell_height + 2) + cell_height / 2,
                         path[var + 2] * (cell_width + 2) + cell_width / 2,
                         path[var + 3] * (cell_height + 2) + cell_height / 2);
    }
  }
}
