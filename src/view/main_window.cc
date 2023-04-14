#include "main_window.h"

#include "paintmazewidget.h"
#include "ui_main_window.h"

MainWindow::MainWindow(QWidget *parent, Controller *controller)
    : QMainWindow(parent), ui(new Ui::MainWindow), controller_(controller) {
  ui->setupUi(this);
  ui->widget->setEnabled(false);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_buttonLoadMaze_clicked() {
  QString filter = "Maze file (*.txt)";
  std::string filename =
      QFileDialog::getOpenFileName(this, "Open a file", "/", filter)
          .toStdString();
  controller_->CreateMazeFromFile(filename);
  ui->widget->maze = controller_->GetMazeMatrix();
  ui->widget->path.clear();
  ui->widget->repaint();
}

void MainWindow::on_buttonGenerateMaze_clicked() {
  controller_->GenerateMaze(ui->lineEditRows->text().toInt(),
                            ui->lineEditCols->text().toInt());
  ui->widget->maze = controller_->GetMazeMatrix();
  ui->widget->path.clear();
  ui->widget->repaint();
}

void MainWindow::on_buttonSaveToFile_clicked() {
  std::string filename = QFileDialog::getSaveFileName(
                             this, "Save as...", "name", "Maze file (*.txt)")
                             .toStdString();
  controller_->CreateFileFromMaze(filename);
}

void MainWindow::on_buttonFindPath_clicked() {
  if (controller_->FindPath(
          ui->lineEdit->text().toInt(), ui->lineEdit_2->text().toInt(),
          ui->lineEdit_3->text().toInt(), ui->lineEdit_4->text().toInt())) {
    ui->widget->path = controller_->GetPath();
    ui->widget->repaint();
  } else {
    ui->widget->path.clear();
    ui->widget->repaint();
  }
}

void MainWindow::on_buttonLoadCave_clicked() {
  QString filter = "Cave file (*.txt)";
  std::string filename =
      QFileDialog::getOpenFileName(this, "Open a file", "/", filter)
          .toStdString();
  controller_->CreateCaveFromFile(filename);
  ui->widget_2->cave = controller_->GetCaveMatrix();
  ui->widget_2->repaint();
}

void MainWindow::on_buttonNextStep_clicked() {
  if (!controller_->GetCaveMatrix().empty()) {
    controller_->CaveNextStep(ui->spinBox->value(), ui->spinBox_2->value());
    ui->widget_2->cave = controller_->GetCaveMatrix();
    ui->widget_2->repaint();
  }
}

void MainWindow::auto_step() {
  if (controller_->CaveNextStep(ui->spinBox->value(), ui->spinBox_2->value())) {
    time->stop();
    ui->spinBox->setEnabled(1);
    ui->spinBox_2->setEnabled(1);
  } else {
    ui->widget_2->cave = controller_->GetCaveMatrix();
    ui->widget_2->repaint();
  }
}

void MainWindow::on_buttonAutoStep_clicked() {
  if (!controller_->GetCaveMatrix().empty()) {
    time = new QTimer(this);
    connect(time, SIGNAL(timeout()), this, SLOT(auto_step()));
    time->start(ui->spinBox_3->value());
    ui->spinBox->setEnabled(0);
    ui->spinBox_2->setEnabled(0);
  }
}
