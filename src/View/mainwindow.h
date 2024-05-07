#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../Controller/Controller.h"
#include "gif/qgifimage_p.h"
#include <QColorDialog>
#include <QDebug>
#include <QElapsedTimer>
#include <QFileDialog>
#include <QImageWriter>
#include <QLCDNumber>
#include <QMainWindow>
#include <QMessageBox>
#include <QMovie>
#include <QOpenGLWidget>
#include <QSettings>
#include <QSlider>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(s21::Controller *controller_, QWidget *parent = nullptr);
  ~MainWindow();
  bool file_open = false;
  QString save_settings;

private slots:
  void on_radioButtonNON_clicked();

private slots:
  void on_radioButtonCentral_clicked();

private slots:
  void on_radioButtonParal_clicked();

private slots:
  void on_slider_edgeThickness_valueChanged(int value);

private slots:
  void on_checkBox_dashedLine_stateChanged(int arg1);

private slots:
  void on_screen_clicked();

private slots:
  void on_pushButton_chooseFile_clicked();

  void on_horizontalSlider_x_value_valueChanged(int value);

  void on_horizontalSlider_y_value_valueChanged(int value);

  void on_horizontalSlider_z_value_valueChanged(int value);

  void on_horizontalSlider_scale_valueChanged(int value);

  void on_horizontalSlider_x_translate_valueChanged(int value);

  void on_horizontalSlider_y_translate_valueChanged(int value);

  void on_horizontalSlider_z_translate_valueChanged(int value);

  void on_ParallelProjectionSelected();
  void on_CentralProjectionSelected();
  void on_size_point_valueChanged(int value);
  void on_background_color_clicked();
  void on_gif_clicked();
  void on_color_clicked();
  void on_without_clicked();
  void on_circle_clicked();
  void on_square_clicked();
  void on_peaks_color_clicked();
  void load_Settings();
  void save_Settings();
  void save_Settings_base();

private:
  Ui::MainWindow *ui;
  s21::Controller *controller;
};
#endif // MAINWINDOW_H
