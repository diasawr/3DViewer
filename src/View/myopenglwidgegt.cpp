#include "myopenglwidgegt.h"
#include "mainwindow.h"

MyOpenGLWidgegt::MyOpenGLWidgegt(QWidget *parent) : QOpenGLWidget{parent} {
  x_pos = y_pos = angle_x = angle_y = 0;
}

void MyOpenGLWidgegt::paintGL() {
  if (status_paint) {
    initializeOpenGL();
    setProjectionType();
    setLineStipple();
    try {
      drawLines();
      typePoints();
      update();
    } catch (...) {
      controller->ClearData();
      update();
    }
  }
}

void MyOpenGLWidgegt::initializeOpenGL() {
  initializeOpenGLFunctions();
  glEnable(GL_DEPTH_TEST);
  glMatrixMode(GL_PROJECTION);
  glRotatef(angle_x, 1, 0, 0);
  glRotatef(angle_y, 0, 1, 0);
  glClearColor(red_background, green_background, blue_background,
               alpha_background);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void MyOpenGLWidgegt::setProjectionType() {
  if (currentProjectionType == 2) {
    glLoadIdentity();
    glFrustum(-1, 1, -1.0, 1.0, 1.0, 5000.0);
    glTranslatef(0, 0, -2);
  } else if (currentProjectionType == 1) {
    glLoadIdentity();
    glOrtho(-1, 1, -1.0, 1.0, 1.0, 5000.0);
    glTranslatef(0, 0, -2);
  }
}

void MyOpenGLWidgegt::setLineStipple() {
  if (useDashedLine) {
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x00FF);
  } else {
    glDisable(GL_LINE_STIPPLE);
  }
}

void MyOpenGLWidgegt::drawLines() {
  glLineWidth(edgeThickness);
  glColor3f(red, green, blue);
  auto s1 = controller->get_matrix_facetes().size();
  auto matrix_ = controller->GetMatrixVertexes();
  auto matrix_f = controller->get_matrix_facetes();
  for (size_t i = 0; i < s1; i++) {
    glBegin(GL_LINE_STRIP);
    for (size_t j = 0; j < matrix_f[i].size(); ++j) {
      glVertex3d(matrix_.at(matrix_f[i][j] - 1)[0],
                 matrix_.at(matrix_f[i][j] - 1)[1],
                 matrix_.at(matrix_f[i][j] - 1)[2]);
    }
    glEnd();
  }
}

void MyOpenGLWidgegt::drawPoints() {
  if (type_point != 3) {
    glPointSize(size_point);
    glColor3f(red_point, green_point, blue_point);
    auto s1 = controller->get_matrix_facetes().size();
    auto matrix_ = controller->GetMatrixVertexes();
    auto matrix_f = controller->get_matrix_facetes();
    for (size_t i = 0; i < s1; i++) {
      glBegin(GL_POINTS);
      for (size_t j = 0; j != matrix_f[i].size(); ++j) {
        glVertex3d(matrix_.at(matrix_f[i][j] - 1)[0],
                   matrix_.at(matrix_f[i][j] - 1)[1],
                   matrix_.at(matrix_f[i][j] - 1)[2]);
      }
      glEnd();
    }
  }
}

void MyOpenGLWidgegt::typePoints() {
  if (type_point != 3) {
    glPointSize(size_point);
    glColor3f(red_point, green_point, blue_point);
    if (type_point == 1) {
      glEnable(GL_POINT_SMOOTH);
      glEnable(GL_BLEND);
      glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
      drawPoints();
      glDisable(GL_POINT_SMOOTH);
      glDisable(GL_BLEND);
    } else if (type_point == 2) {
      glEnable(GL_DEPTH_TEST);
      glPointSize(size_point);
      glColor3f(red_point, green_point, blue_point);
      drawPoints();
    }
  }
}

void MyOpenGLWidgegt::mouseMoveEvent(QMouseEvent *e) {
  float speed = 0.5;

  angle_x = speed * M_PI_2 * (GLfloat(e->y()) - y_pos) / width();
  angle_y = speed * M_PI_2 * (GLfloat(e->x()) - x_pos) / height();

  update();
}

void MyOpenGLWidgegt::mousePressEvent(QMouseEvent *e) {
  if (e->button() == Qt::LeftButton) {
    x_pos = e->x();
    y_pos = e->y();
  }
}

void MyOpenGLWidgegt::setEdgeThickness(int thickness) {
  edgeThickness = thickness;
  update();
}

void MyOpenGLWidgegt::setTypePoint(int type) {
  type_point = type;
  update();
}

void MyOpenGLWidgegt::setDashedLine(bool dashed) {
  useDashedLine = dashed;
  update();
}
void MyOpenGLWidgegt::setsizepoint(int size) {
  size_point = size;
  update();
}

void MyOpenGLWidgegt::setProjectionType(int type) {
  currentProjectionType = type;
  update();
}

void MyOpenGLWidgegt::setFigureColor(float chosen_red, float chosen_green,
                                     float chosen_blue) {
  red = chosen_red;
  green = chosen_green;
  blue = chosen_blue;
  update();
}
void MyOpenGLWidgegt::setPointColor(float chosen_red_point,
                                    float chosen_green_point,
                                    float chosen_blue_point) {
  red_point = chosen_red_point;
  green_point = chosen_green_point;
  blue_point = chosen_blue_point;
  update();
}
void MyOpenGLWidgegt::setBackgroundColor(float chosen_red_background,
                                         float chosen_green_background,
                                         float chosen_blue_background,
                                         float chosen_alpha_background) {
  red_background = chosen_red_background;
  green_background = chosen_green_background;
  blue_background = chosen_blue_background;
  alpha_background = chosen_alpha_background;
  update();
}
