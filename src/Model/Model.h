#ifndef S21_CPP4_3DVIEWER_V2_SRC_MODEL_MODEL_H
#define S21_CPP4_3DVIEWER_V2_SRC_MODEL_MODEL_H

#include <cmath>
#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace s21 {
enum type {
  VERTEXES,
  FACETS,
};

enum move {
  X = 0,
  Y = 1,
  Z = 2,
};

typedef struct max_min {
  std::vector<double> x_max_min;
  std::vector<double> y_max_min;
  std::vector<double> z_max_min;
} max_min_t;

class ValidatorAbstract {
public:
  virtual void Validation(const std::string &) const = 0;
};

class ValidatorVexters : public ValidatorAbstract {
public:
  void Validation(const std::string &) const override;
};

class ValidatorFacets : public ValidatorAbstract {
public:
  void Validation(const std::string &) const override;
};

class FillerAbstract {
public:
  virtual std::vector<double> Fill(const std::string &str) const = 0;
};

class FillerVexters : FillerAbstract {
public:
  std::vector<double> Fill(const std::string &str) const override;
};

class FillerFacets : FillerAbstract {
public:
  std::vector<double> Fill(const std::string &str) const override;
};

class Model {
private:
  using Matrix = std::vector<std::vector<double>>;

  Model() {}
  Model(const Model &) = delete;
  Model &operator=(const Model &) = delete;

  Matrix matrix_;
  Matrix polygon_;
  max_min_t max_min_values;
  double old_position_x = 0;
  double old_position_y = 0;
  double old_position_z = 0;
  double old_scale = 0.5;

public:
  void OpenObjFile(std::string file_name);
  void ParsingObjFile(std::string str);
  static bool IsNumber(char c);
  static Model &GetInstanceModel() {
    static Model model_;
    return model_;
  }
  ValidatorVexters validtion_vexters;
  ValidatorFacets validtion_facets;
  FillerVexters filler_verters;
  FillerFacets filler_facets;

  double FindMaxVertexes(move) const;
  double FindMinVertexes(move) const;
  void FigureCentering();
  void MoveFigureXYZ(const double &, move);
  double SupportIncreaseReductionFigure(const double &);
  void IncreaseRedutionFigure(const double);
  void IncreaseRedutionFigureA(const double);
  void RotationByXYZ(const double &, move);
  void SetMinMaxData();
  void ClearData() {
    max_min_values.x_max_min.clear();
    max_min_values.y_max_min.clear();
    max_min_values.z_max_min.clear();

    for (size_t i = 0; i < matrix_.size(); ++i) {
      matrix_[i].clear();
    }
    for (size_t i = 0; i < polygon_.size(); ++i) {
      polygon_[i].clear();
    }

    matrix_.clear();
    polygon_.clear();
  }

  // getter
  Matrix GetMatrixVertexes() { return matrix_; }
  Matrix GetMatrixFacetes() { return polygon_; }
  size_t get_count_of_vertexes() const noexcept;
  size_t get_count_of_facets() const noexcept;
  double get_old_position_x() const noexcept;
  double get_old_position_y() const noexcept;
  double get_old_position_z() const noexcept;
  double get_scale() const noexcept;

  // setter
  void set_old_position_x(const double &);
  void set_old_position_y(const double &);
  void set_old_position_z(const double &);
  void set_scale(const double &);
};
} // namespace s21

#endif // S21_CPP4_3DVIEWER_V2_SRC_MODEL_MODEL_H
