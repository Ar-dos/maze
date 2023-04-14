#include <QApplication>

#include "../controller/controller.h"
#include "main_window.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  Model Model;
  Controller Controller(&Model);
  MainWindow w(nullptr, &Controller);
  w.show();
  return a.exec();
}
