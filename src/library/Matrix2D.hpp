#ifndef MATRIX2D_HPP
#define MATRIX2D_HPP

#include <cstdint>
#include <vector>

class Matrix2D
{
public:
    /**
     * @brief Construct a new Matrix 2 D object
     *
     * @param [in] row
     *  Number of rows
     * @param [out] column
     *  Number of columns
     */
    Matrix2D(std::size_t row, std::size_t column);

    /**
     * @brief Destroy the Matrix 2 D object
     */
    virtual ~Matrix2D();

    /**
     * @brief Copy constructor
     */
    Matrix2D(const Matrix2D& matrix);

    /**
     * @brief Get row size
     *
     * @return
     *  Returns row size
     */
    std::size_t getRowSize() const;

    /**
     * @brief Get column size
     *
     * @return
     *  Returns column size
     */
    std::size_t getColumnSize() const;

    /**
     * @brief Operator overloadings
     */
    Matrix2D& operator=(const Matrix2D& rhs);

    /**
     * @brief Matrix mathematical operations
     */
    Matrix2D operator+(const Matrix2D& rhs);
    Matrix2D& operator+=(const Matrix2D& rhs);
    Matrix2D operator-(const Matrix2D& rhs);
    Matrix2D& operator-=(const Matrix2D& rhs);
    Matrix2D operator*(const Matrix2D& rhs);
    Matrix2D& operator*=(const Matrix2D& rhs);
    Matrix2D transpose();

    /**
     * @brief Matrix scalar operations
     */
    Matrix2D operator+(const double& rhs);
    Matrix2D operator-(const double& rhs);
    Matrix2D operator*(const double& rhs);
    Matrix2D operator/(const double& rhs);

    /**
     * @brief Negative operands
     */
    Matrix2D& operator-();

    /**
     * @brief Matrix element access operands
     */
    double& operator()(const std::uint32_t& row, const std::uint32_t& column);
    const double& operator()(const std::uint32_t& row, const std::uint32_t& column) const;

    /**
     * @brief Fill randomly all the matrix elements between [0-1]
     */
    void fillRandom();
private:
    /**
     * @brief Clear the memory
     */
    void clear();

    double** m_pMatrix;
    std::size_t m_row;
    std::size_t m_column;
};

#endif // MATRIX2D_HPP