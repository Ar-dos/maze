#ifndef SRC_APPLICATION_PAINTMAZEWIDGET_H
#define SRC_APPLICATION_PAINTMAZEWIDGET_H
#include <QPainter>
#include <QWidget>
#include <cmath>

#include "../controller/controller.h"

class PaintMazeWidget : public QWidget {
  Q_OBJECT
 public:
  PaintMazeWidget(QWidget *parent = nullptr);
  std::vector<std::vector<MazeCell>> maze;
  std::vector<int> path;
 private slots:
  void paintEvent(QPaintEvent *event) override;
};

#endif  // PAINTMAZEWIDGET_H
