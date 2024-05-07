#include "Controller.h"

namespace s21 {
void Controller::OpenObjFile(const std::string &file_name) {
  model->OpenObjFile(file_name);
}

void Controller::MoveFigure(const double &value, move type) {
  model->MoveFigureXYZ(value, type);
}

void Controller::RotateFigure(const double &angle, move type) {
  model->RotationByXYZ(angle, type);
}

size_t Controller::get_count_of_vertexes() const noexcept {
  return model->get_count_of_vertexes();
}
size_t Controller::get_count_of_facets() const noexcept {
  return model->get_count_of_facets();
}

double Controller::get_old_position_x() const noexcept {
  return model->get_old_position_x();
}
double Controller::get_old_position_y() const noexcept {
  return model->get_old_position_y();
}
double Controller::get_old_position_z() const noexcept {
  return model->get_old_position_z();
}
double Controller::get_scale() const noexcept { return model->get_scale(); }
void Controller::set_old_position_x(const double &d) {
  model->set_old_position_x(d);
}
void Controller::set_old_position_y(const double &d) {
  model->set_old_position_y(d);
}
void Controller::set_old_position_z(const double &d) {
  model->set_old_position_z(d);
}
void Controller::set_scale(const double &d) { model->set_scale(d); }
void Controller::IncreaseRedutionFigure(const double &d) {
  model->IncreaseRedutionFigureA(d);
}
std::vector<std::vector<double>> Controller::get_matrix_facetes() {
  return model->GetMatrixFacetes();
}

void Controller::ClearData() const noexcept { model->ClearData(); }

std::vector<std::vector<double>> Controller::GetMatrixVertexes() {
  return model->GetMatrixVertexes();
}

} // namespace s21
