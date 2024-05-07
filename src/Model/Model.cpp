#include "Model.h"

namespace s21 {
void Model::OpenObjFile(std::string file_name) {
  std::ifstream inputFile(file_name);
  std::string line;
  std::istringstream input;

  if (inputFile.is_open()) {
    ClearData();
    while (std::getline(inputFile, line)) {
      ParsingObjFile(line);
    }
    FigureCentering();
    IncreaseRedutionFigure(0.5);
  } else
    throw std::runtime_error("Not open file!");
}

void Model::ParsingObjFile(std::string str) {
  switch (str[0]) {
  case 'v':
    validtion_vexters.Validation(str);
    matrix_.push_back(filler_verters.Fill(str));
    break;

  case 'f':
    validtion_facets.Validation(str);
    polygon_.push_back(filler_facets.Fill(str));
    break;
  case '\0':
    break;
  default:
    throw std::runtime_error("Wrong data!");
    break;
  }
}

bool Model::IsNumber(char c) { return c >= '0' && c <= '9'; }

size_t Model::get_count_of_vertexes() const noexcept {
  size_t count = 0;
  for (size_t i = 0; i < matrix_.size(); ++i) {
    count += matrix_[i].size();
  }
  return count;
}

size_t Model::get_count_of_facets() const noexcept { return polygon_.size(); }

double Model::get_old_position_x() const noexcept { return old_position_x; }

double Model::get_old_position_y() const noexcept { return old_position_y; }

double Model::get_old_position_z() const noexcept { return old_position_z; }

double Model::get_scale() const noexcept { return old_scale; }

void Model::set_old_position_x(const double &d) { old_position_x = d; }
void Model::set_old_position_y(const double &d) { old_position_y = d; }
void Model::set_old_position_z(const double &d) { old_position_z = d; }

void Model::set_scale(const double &d) { old_scale = d; }
void ValidatorVexters::Validation(const std::string &str) const {
  auto i = 1;
  while (str[i] != '\0' && str[i] != '\n') {
    if (str[i] == '.' || str[i] == '-' || Model::IsNumber(str[i]) ||
        (str[i] == ' '))
      ++i;
    else
      throw std::runtime_error("Wrong data! Vertex");
  }
}

void ValidatorFacets::Validation(const std::string &str) const {
  auto i = 1;
  while (str[i] != '\0' && str[i] != '\n') {
    if (Model::IsNumber(str[i]) || (str[i] == ' ') || (str[i] == '/'))
      ++i;
    else
      throw std::runtime_error("Wrong data! Facets");
  }
}

std::vector<double> FillerVexters::Fill(const std::string &str) const {
  auto counter = 0;
  auto i = 1;
  std::string number;
  std::vector<double> values;
  while (str[i] != '\0' && str[i] != '\n') {
    if (str[i] == '.' || str[i] == '-' || Model::IsNumber(str[i])) {
      number.push_back(str[i]);
      ++i;
    } else {
      if (!number.empty()) {
        values.push_back(std::stod(number));
        ++counter;
      }
      number.clear();
      while (str[i] == ' ')
        i++;
    }
  }
  if (!number.empty()) {
    number.push_back(str[i]);
    values.push_back(std::stod(number));
    ++counter;
  }
  if (counter != 3)
    throw std::runtime_error("Wrong data!");
  return values;
}

std::vector<double> FillerFacets::Fill(const std::string &str) const {
  auto i = 1;
  std::string number;
  std::vector<double> values;
  while (str[i] != '\0' && str[i] != '\n') {
    if (Model::IsNumber(str[i]) || (str[i] == ' ')) {
      number.push_back(str[i]);
      ++i;
    } else if (str[i] == '/') {
      while (str[i] != ' ' && Model::IsNumber(str[i + 1]))
        ++i;
      ++i;
      if (!number.empty()) {
        values.push_back(std::stod(number));
      }
      number.clear();
    }
  }
  return values;
}

double Model::FindMaxVertexes(move type) const {
  double maxType = matrix_.at(0)[type];

  for (const auto &row : matrix_) {
    if (row.at(type) > maxType) {
      maxType = row.at(type);
    }
  }
  return maxType;
}

double Model::FindMinVertexes(move type) const {
  double minType = matrix_.at(0)[type];

  for (const auto &row : matrix_) {
    if (row.at(type) < minType) {
      minType = row.at(type);
    }
  }
  return minType;
}

void Model::SetMinMaxData() {
  max_min_values.x_max_min.push_back(FindMaxVertexes(X));
  max_min_values.x_max_min.push_back(FindMinVertexes(X));
  max_min_values.y_max_min.push_back(FindMaxVertexes(Y));
  max_min_values.y_max_min.push_back(FindMinVertexes(Y));
  max_min_values.z_max_min.push_back(FindMaxVertexes(Z));
  max_min_values.z_max_min.push_back(FindMinVertexes(Z));
}

void Model::FigureCentering() {
  SetMinMaxData();

  double center_x =
      max_min_values.x_max_min[1] +
      (max_min_values.x_max_min[0] - max_min_values.x_max_min[1]) / 2;
  double center_y =
      max_min_values.y_max_min[1] +
      (max_min_values.y_max_min[0] - max_min_values.y_max_min[1]) / 2;
  double center_z =
      max_min_values.z_max_min[1] +
      (max_min_values.z_max_min[0] - max_min_values.z_max_min[1]) / 2;

  for (size_t i = 0; i < matrix_.size(); ++i) {
    for (size_t j = 0; j < matrix_[i].size(); ++j) {
      if (j == X)
        matrix_[i][j] -= center_x;
      if (j == Y)
        matrix_[i][j] -= center_y;
      if (j == Z)
        matrix_[i][j] -= center_z;
    }
  }
}

void Model::MoveFigureXYZ(const double &value, move type) {
  for (size_t i = 0; i < matrix_.size(); ++i) {
    for (size_t j = 0; j < matrix_[i].size(); ++j) {
      if (type == X && j == 0)
        matrix_[i][j] += value;
      if (type == Y && j == 1)
        matrix_[i][j] += value;
      if (type == Z && j == 2)
        matrix_[i][j] += value;
    }
  }
}

double Model::SupportIncreaseReductionFigure(const double &val) {
  double diff_x = max_min_values.x_max_min[0] - max_min_values.x_max_min[1];
  double diff_y = max_min_values.y_max_min[0] - max_min_values.y_max_min[1];
  double diff_z = max_min_values.z_max_min[0] - max_min_values.z_max_min[1];
  double max_diff = std::max(std::max(diff_x, diff_y), diff_z);
  return (val - (val * (-1))) / max_diff;
}

void Model::IncreaseRedutionFigure(const double val) {
  for (size_t i = 0; i < matrix_.size(); ++i) {
    for (size_t j = 0; j < matrix_[i].size(); ++j) {
      if (j == X)
        matrix_[i][j] *= SupportIncreaseReductionFigure(val);
      if (j == Y)
        matrix_[i][j] *= SupportIncreaseReductionFigure(val);
      if (j == Z)
        matrix_[i][j] *= SupportIncreaseReductionFigure(val);
    }
  }
}

void Model::IncreaseRedutionFigureA(const double val) {
  for (size_t i = 0; i < matrix_.size(); ++i) {
    for (size_t j = 0; j < matrix_[i].size(); ++j) {
      if (j == X)
        matrix_[i][j] *= val;
      if (j == Y)
        matrix_[i][j] *= val;
      if (j == Z)
        matrix_[i][j] *= val;
    }
  }
}

void Model::RotationByXYZ(const double &angle, move type) {
  for (size_t i = 0; i < matrix_.size(); ++i) {
    double temp_x = matrix_[i][0];
    double temp_y = matrix_[i][1];
    double temp_z = matrix_[i][2];
    if (type == X) {
      matrix_[i][1] = std::cos(angle) * temp_y - std::sin(angle) * temp_z;
      matrix_[i][2] = std::sin(angle) * temp_y + std::cos(angle) * temp_z;
    } else if (type == Y) {
      matrix_[i][0] = std::cos(angle) * temp_x + std::sin(angle) * temp_z;
      matrix_[i][2] = -std::sin(angle) * temp_x + std::cos(angle) * temp_z;
    } else if (type == Z) {
      matrix_[i][0] = std::cos(angle) * temp_x - std::sin(angle) * temp_y;
      matrix_[i][1] = std::sin(angle) * temp_x + std::cos(angle) * temp_y;
    }
  }
}

} // namespace s21
