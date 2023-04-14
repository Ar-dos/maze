#ifndef SRC_APPLICATION_PAINTCAVEWIDGET_H
#define SRC_APPLICATION_PAINTCAVEWIDGET_H

#include <QPainter>
#include <QWidget>
#include <cmath>

#include "../controller/controller.h"

class PaintCaveWidget : public QWidget {
  Q_OBJECT
 public:
  PaintCaveWidget(QWidget *parent = nullptr);
  std::vector<std::vector<bool>> cave;
 private slots:
  void paintEvent(QPaintEvent *event) override;
};

#endif  // SRC_APPLICATION_PAINTCAVEWIDGET_H
