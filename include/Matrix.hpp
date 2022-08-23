#pragma once

const int ROWS = 100;
const int COLS = 100;

template <typename matType> class Matrix {
private:
  matType matrix[ROWS][COLS];
  int rows, columns;

public:
  /**
   * @brief Construct a new Matrix object
   * @param int, columns
   * @param int, rows
   */
  Matrix(int, int);
  /**
   * @brief Construct a new Matrix object, by default
   *
   */
  Matrix();
  /**
   * @brief sum all the elements into a row
   *
   * @return matType, sum
   */
  matType sumRow(int);
  /**
   * @brief sum all the elements into a column
   *
   * @return matType, the sum
   */
  matType sumColumn(int);
};

template <typename matType>
matType Matrix<matType>::sumColumn(int static_column) {
  int sum;
  for (size_t idx = 0; idx < rows; count; idx++) {
    sum += matrix[idx][static_column];
  }
  return sum;
}

template <typename matType>
matType Matrix<matType>::sumRow(const int static_row) {
  int sum = 0;
  for (size_t idx = 0; idx < columns; idx++) {
    sum += matrix[static_row][idx];
  }
  return sum;
}

template <typename matType> Matrix<matType>::Matrix(int rows, int columns) {
  this->rows = rows;
  this->columns = columns;
}

template <typename matType> Matrix<matType>::Matrix() {
  this->rows = 0;
  this->columns = 0;
}