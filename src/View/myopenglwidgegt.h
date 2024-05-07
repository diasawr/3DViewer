#ifndef MYOPENGLWIDGEGT_H
#define MYOPENGLWIDGEGT_H
#define GL_SILENCE_DEPRECATION

#include "mainwindow.h"
#include <QMouseEvent>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QPainter>
enum ProjectionType { Central, Parallel };
class MyOpenGLWidgegt : public QOpenGLWidget,
                        public QOpenGLFunctions

{
  Q_OBJECT
public:
  MyOpenGLWidgegt(QWidget *parent = nullptr);

  bool status_paint;
  GLfloat y_pos, x_pos;
  GLfloat angle_x, angle_y;
  float xRot, yRot, mLastRotY, mLastRotX;
  QPointF mPos;
  GLfloat red;
  GLfloat green;
  GLfloat blue;
  GLfloat red_background;
  GLfloat green_background;
  GLfloat blue_background;
  GLfloat alpha_background;
  int size_point;
  int type_point;
  int edgeThickness;
  bool useDashedLine = false;
  int currentProjectionType;
  GLfloat red_point;
  GLfloat green_point;
  GLfloat blue_point;
  void setEdgeThickness(int thickness);
  void setDashedLine(bool dashed);
  void setsizepoint(int thickness);
  void setProjectionType(int type);
  void setFigureColor(float chosen_red, float chosen_green, float chosen_blue);
  void setPointColor(float chosen_red_point, float chosen_green_point,
                     float chosen_blue_point);
  void setBackgroundColor(float chosen_red_background,
                          float chosen_green_background,
                          float chosen_blue_background,
                          float chosen_alpha_background);
  void setTypePoint(int type);
  void drawSphere(double radius, int stacks, int slices);
  void initializeOpenGL();
  void setProjectionType();
  void setLineStipple();
  void drawLines();
  void drawPoints();
  void typePoints();
  s21::Controller *controller;

protected:
  void paintGL() override;

private:
  void mouseMoveEvent(QMouseEvent *e) override;
  void mousePressEvent(QMouseEvent *e) override;
};
#endif // MYOPENGLWIDGEGT_H
