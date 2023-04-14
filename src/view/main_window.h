#ifndef SRC_APPLICATION_MAINWINDOW_H
#define SRC_APPLICATION_MAINWINDOW_H

#include <QFileDialog>
#include <QMainWindow>
#include <QPainter>
#include <QTimer>
#include <QTimerEvent>

#include "../controller/controller.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr, Controller *controller = nullptr);
  ~MainWindow();

 private slots:

  void on_buttonGenerateMaze_clicked();
  void on_buttonLoadMaze_clicked();

  void on_buttonSaveToFile_clicked();

  void on_buttonFindPath_clicked();

  void on_buttonLoadCave_clicked();

  void on_buttonNextStep_clicked();

  void auto_step();

  void on_buttonAutoStep_clicked();

 private:
  Ui::MainWindow *ui;
  Controller *controller_;
  QTimer *time;
};
#endif  // SRC_APPLICATION_MAINWINDOW_H
