#include "tests.h"

namespace s21 {
TEST(test_centerig_figure, test_one) {
  Model &a = Model::GetInstanceModel();
  Controller b(&a);
  std::vector<std::vector<double>> answer = {
      {-0.5, -0.5, -0.5}, {-0.5, -0.5, 0.5}, {-0.5, 0.5, -0.5},
      {-0.5, 0.5, 0.5},   {0.5, -0.5, -0.5}, {0.5, -0.5, 0.5},
      {0.5, 0.5, -0.5},   {0.5, 0.5, 0.5}};
  b.OpenObjFile("cube.obj");
  std::vector<std::vector<double>> res = b.GetMatrixVertexes();

  EXPECT_EQ(answer.size(), res.size());
  for (size_t i = 0; i < answer.size(); ++i) {
    EXPECT_EQ(answer[i].size(), res[i].size());
  }

  // std::vector<std::vector<double>>::iterator it_a = answer.begin();
  // std::vector<std::vector<double>>::iterator it_r = res.begin();
  for (size_t i = 0; i < answer.size(); ++i) {
    EXPECT_EQ(answer[i].size(), res[i].size());

    for (size_t j = 0; j < answer[i].size(); ++j) {
      EXPECT_NEAR(answer[i][j], res[i][j], 1e-6);
    }
  }
}

TEST(test_rotate_figure, test_rotate_one_x) {
  Model &a = Model::GetInstanceModel();
  Controller b(&a);
  std::vector<std::vector<double>> answer = {
      {-0.5, -0.447585, -0.547419}, {-0.5, -0.547419, 0.447585},
      {-0.5, 0.547419, -0.447585},  {-0.5, 0.447585, 0.547419},
      {0.5, -0.447585, -0.547419},  {0.5, -0.547419, 0.447585},
      {0.5, 0.547419, -0.447585},   {0.5, 0.447585, 0.547419}};
  b.OpenObjFile("cube.obj");
  b.RotateFigure(0.1, s21::move::X);
  std::vector<std::vector<double>> res = b.GetMatrixVertexes();

  EXPECT_EQ(answer.size(), res.size());
  for (size_t i = 0; i < answer.size(); ++i) {
    EXPECT_EQ(answer[i].size(), res[i].size());
  }

  // std::vector<std::vector<double>>::iterator it_a = answer.begin();
  // std::vector<std::vector<double>>::iterator it_r = res.begin();

  for (size_t i = 0; i < answer.size(); ++i) {
    EXPECT_EQ(answer[i].size(), res[i].size());

    for (size_t j = 0; j < answer[i].size(); ++j) {
      EXPECT_NEAR(answer[i][j], res[i][j], 1e-6);
    }
  }
}

TEST(test_rotate_figure, test_rotate_two_y) {
  Model &a = Model::GetInstanceModel();
  Controller b(&a);
  std::vector<std::vector<double>> answer = {
      {-0.547419, -0.5, -0.447585}, {-0.447585, -0.5, 0.547419},
      {-0.547419, 0.5, -0.447585},  {-0.447585, 0.5, 0.547419},
      {0.447585, -0.5, -0.547419},  {0.547419, -0.5, 0.447585},
      {0.447585, 0.5, -0.547419},   {0.547419, 0.5, 0.447585},
  };
  b.OpenObjFile("cube.obj");
  b.RotateFigure(0.1, s21::move::Y);
  std::vector<std::vector<double>> res = b.GetMatrixVertexes();

  EXPECT_EQ(answer.size(), res.size());
  for (size_t i = 0; i < answer.size(); ++i) {
    EXPECT_EQ(answer[i].size(), res[i].size());
  }

  // std::vector<std::vector<double>>::iterator it_a = answer.begin();
  // std::vector<std::vector<double>>::iterator it_r = res.begin();
  for (size_t i = 0; i < answer.size(); ++i) {
    EXPECT_EQ(answer[i].size(), res[i].size());

    for (size_t j = 0; j < answer[i].size(); ++j) {
      EXPECT_NEAR(answer[i][j], res[i][j], 1e-6);
    }
  }
}

TEST(test_rotate_figure, test_rotate_three_z) {
  Model &a = Model::GetInstanceModel();
  Controller b(&a);
  std::vector<std::vector<double>> answer = {
      {-0.447585, -0.547419, -0.5}, {-0.447585, -0.547419, 0.5},
      {-0.547419, 0.447585, -0.5},  {-0.547419, 0.447585, 0.5},
      {0.547419, -0.447585, -0.5},  {0.547419, -0.447585, 0.5},
      {0.447585, 0.547419, -0.5},   {0.447585, 0.547419, 0.5},
  };
  b.OpenObjFile("cube.obj");
  b.RotateFigure(0.1, s21::move::Z);
  std::vector<std::vector<double>> res = b.GetMatrixVertexes();

  EXPECT_EQ(answer.size(), res.size());
  for (size_t i = 0; i < answer.size(); ++i) {
    EXPECT_EQ(answer[i].size(), res[i].size());
  }

  // std::vector<std::vector<double>>::iterator it_a = answer.begin();
  // std::vector<std::vector<double>>::iterator it_r = res.begin();
  for (size_t i = 0; i < answer.size(); ++i) {
    EXPECT_EQ(answer[i].size(), res[i].size());

    for (size_t j = 0; j < answer[i].size(); ++j) {
      EXPECT_NEAR(answer[i][j], res[i][j], 1e-6);
    }
  }
}

TEST(test_move_figure, test_move_one_x) {
  Model &a = Model::GetInstanceModel();
  Controller b(&a);
  std::vector<std::vector<double>> answer = {
      {-0.4, -0.5, -0.5}, {-0.4, -0.5, 0.5}, {-0.4, 0.5, -0.5},
      {-0.4, 0.5, 0.5},   {0.6, -0.5, -0.5}, {0.6, -0.5, 0.5},
      {0.6, 0.5, -0.5},   {0.6, 0.5, 0.5}};
  b.OpenObjFile("cube.obj");
  b.MoveFigure(0.1, s21::move::X);
  std::vector<std::vector<double>> res = b.GetMatrixVertexes();

  EXPECT_EQ(answer.size(), res.size());
  for (size_t i = 0; i < answer.size(); ++i) {
    EXPECT_EQ(answer[i].size(), res[i].size());
  }

  // std::vector<std::vector<double>>::iterator it_a = answer.begin();
  //  std::vector<std::vector<double>>::iterator it_r = res.begin();
  for (size_t i = 0; i < answer.size(); ++i) {
    EXPECT_EQ(answer[i].size(), res[i].size());

    for (size_t j = 0; j < answer[i].size(); ++j) {
      EXPECT_NEAR(answer[i][j], res[i][j], 1e-6);
    }
  }
}

TEST(test_move_figure, test_move_one_y) {
  Model &a = Model::GetInstanceModel();
  Controller b(&a);
  std::vector<std::vector<double>> answer = {
      {-0.5, -0.4, -0.5}, {-0.5, -0.4, 0.5}, {-0.5, 0.6, -0.5},
      {-0.5, 0.6, 0.5},   {0.5, -0.4, -0.5}, {0.5, -0.4, 0.5},
      {0.5, 0.6, -0.5},   {0.5, 0.6, 0.5}};
  b.OpenObjFile("cube.obj");
  b.MoveFigure(0.1, s21::move::Y);
  std::vector<std::vector<double>> res = b.GetMatrixVertexes();

  EXPECT_EQ(answer.size(), res.size());
  for (size_t i = 0; i < answer.size(); ++i) {
    EXPECT_EQ(answer[i].size(), res[i].size());
  }

  // std::vector<std::vector<double>>::iterator it_a = answer.begin();
  // std::vector<std::vector<double>>::iterator it_r = res.begin();
  for (size_t i = 0; i < answer.size(); ++i) {
    EXPECT_EQ(answer[i].size(), res[i].size());

    for (size_t j = 0; j < answer[i].size(); ++j) {
      EXPECT_NEAR(answer[i][j], res[i][j], 1e-6);
    }
  }
}

TEST(test_move_figure, test_move_one_z) {
  Model &a = Model::GetInstanceModel();
  Controller b(&a);
  std::vector<std::vector<double>> answer = {
      {-0.5, -0.5, -0.4}, {-0.5, -0.5, 0.6}, {-0.5, 0.5, -0.4},
      {-0.5, 0.5, 0.6},   {0.5, -0.5, -0.4}, {0.5, -0.5, 0.6},
      {0.5, 0.5, -0.4},   {0.5, 0.5, 0.6}};
  b.OpenObjFile("cube.obj");
  b.MoveFigure(0.1, s21::move::Z);
  std::vector<std::vector<double>> res = b.GetMatrixVertexes();

  EXPECT_EQ(answer.size(), res.size());
  for (size_t i = 0; i < answer.size(); ++i) {
    EXPECT_EQ(answer[i].size(), res[i].size());
  }

  // std::vector<std::vector<double>>::iterator it_a = answer.begin();
  // std::vector<std::vector<double>>::iterator it_r = res.begin();
  for (size_t i = 0; i < answer.size(); ++i) {
    EXPECT_EQ(answer[i].size(), res[i].size());

    for (size_t j = 0; j < answer[i].size(); ++j) {
      EXPECT_NEAR(answer[i][j], res[i][j], 1e-6);
    }
  }
}
} // namespace s21

int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}
