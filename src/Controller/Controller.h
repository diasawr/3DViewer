#ifndef S21_CPP4_3DVIEWER_V2_SRC_CONTROLLER_CONTROLLER_H
#define S21_CPP4_3DVIEWER_V2_SRC_CONTROLLER_CONTROLLER_H

#include "../Model/Model.h"
namespace s21 {
class Controller {
private:
  Model *model;

public:
  Controller(Model *m) : model(m){};
  ~Controller(){};
  void OpenObjFile(const std::string &);
  size_t get_count_of_vertexes() const noexcept;
  size_t get_count_of_facets() const noexcept;
  double get_old_position_x() const noexcept;
  double get_old_position_y() const noexcept;
  double get_old_position_z() const noexcept;
  double get_scale() const noexcept;
  void set_old_position_x(const double &);
  void set_old_position_y(const double &);
  void set_old_position_z(const double &);
  void set_scale(const double &);
  void MoveFigure(const double &, move);
  void RotateFigure(const double &, move);
  void IncreaseRedutionFigure(const double &);
  std::vector<std::vector<double>> GetMatrixVertexes();
  std::vector<std::vector<double>> get_matrix_facetes();
  void ClearData() const noexcept;
};
} // namespace s21

#endif // S21_CPP4_3DVIEWER_V2_SRC_CONTROLLER_CONTROLLER_H
