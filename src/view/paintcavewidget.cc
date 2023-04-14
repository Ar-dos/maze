#include "paintcavewidget.h"

PaintCaveWidget::PaintCaveWidget(QWidget *parent) : QWidget(parent) {}

void PaintCaveWidget::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  if (!cave.empty()) {
    int rows = cave.size();
    int cols = cave[0].size();
    int cell_width = round(500 / (double)cols);
    int cell_height = round(500 / (double)rows);
    for (int row = 0; row < rows; row++) {
      for (int col = 0; col < cols; col++) {
        if (cave[row][col])
          painter.fillRect(col * (cell_width), row * (cell_height), cell_width,
                           cell_height, "black");
        else
          painter.fillRect(col * (cell_width), row * (cell_height), cell_width,
                           cell_height, "white");
      }
    }
  }
}
