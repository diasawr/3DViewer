#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
  s21::Model &Model = s21::Model::GetInstanceModel();
  s21::Controller Controller(&Model);
  QApplication a(argc, argv);
  MainWindow w(&Controller);
  w.show();
  return a.exec();
}
