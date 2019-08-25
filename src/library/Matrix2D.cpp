#include <cstring>
#include <iostream>

#include "Matrix2D.hpp"
#include "RandomNumber.hpp"

Matrix2D::Matrix2D(std::size_t row, std::size_t column)
{
    m_pMatrix = new double[row*column];

    m_row = row;
    m_column = column;

    fillZero();
}

Matrix2D::~Matrix2D()
{
    clear();
}

Matrix2D::Matrix2D(const Matrix2D& matrix)
{
    // Create object
    auto size = matrix.m_row * matrix.m_column;
    m_pMatrix = new double[size];

    // Set row and column
    m_row = matrix.m_row;
    m_column = matrix.m_column;

    // Copy the matrix
    std::memcpy(m_pMatrix, matrix.m_pMatrix, size * sizeof(double));
}

Matrix2D::Matrix2D(Matrix2D&& matrix)
{
    // Move the object
    m_pMatrix = matrix.m_pMatrix;
    m_row = matrix.m_row;
    m_column = matrix.m_column;

    // Remove the object
    matrix.m_pMatrix = nullptr;
    matrix.m_row = 0;
    matrix.m_column = 0;
}

std::size_t Matrix2D::getRowSize() const
{
    return m_row;
}

std::size_t Matrix2D::getColumnSize() const
{
    return m_column;
}

// Operator overloading, for "standard" mathematical matrix operations
Matrix2D& Matrix2D::operator=(const Matrix2D& rhs)
{
    if((m_row != rhs.getRowSize()) || (m_column != rhs.getColumnSize()))
    {
        throw "Wrong assign operation!";
    }

    auto size = m_row * m_column;
    std::memcpy(m_pMatrix, rhs.m_pMatrix, size * sizeof(double));

    return *this;
}

// Matrix mathematical operations
Matrix2D Matrix2D::operator+(const Matrix2D& rhs)
{
    if((m_row != rhs.getRowSize()) || (m_column != rhs.getColumnSize()))
    {
        throw "Wrong summation!";
    }

    Matrix2D result(m_row, m_column);

    for(auto i = 0; i < m_row; ++i)
    {
        for(auto j = 0; j < m_column; ++j)
        {
            result(i, j) = (*this)(i,j) + rhs(i, j);
        }
    }

    return result;
}

Matrix2D& Matrix2D::operator+=(const Matrix2D& rhs)
{
    if((m_row != rhs.getRowSize()) || (m_column != rhs.getColumnSize()))
    {
        throw "Wrong summation!";
    }

    for(auto i = 0; i < m_row; ++i)
    {
        for(auto j = 0; j < m_column; ++j)
        {
            (*this)(i, j) += rhs(i, j);
        }
    }

    return *this;
}

Matrix2D Matrix2D::operator-(const Matrix2D& rhs)
{
    if((m_row != rhs.getRowSize()) || (m_column != rhs.getColumnSize()))
    {
        throw "Wrong substraction!";
    }

    Matrix2D result(m_row, m_column);

    for(auto i = 0; i < m_row; ++i)
    {
        for(auto j = 0; j < m_column; ++j)
        {
            result(i, j) = (*this)(i, j) - rhs(i, j);
        }
    }

    return result;
}

Matrix2D& Matrix2D::operator-=(const Matrix2D& rhs)
{
    if((m_row != rhs.getRowSize()) || (m_column != rhs.getColumnSize()))
    {
        throw "Wrong substraction!";
    }

    for(auto i = 0; i < m_row; ++i)
    {
        for(auto j = 0; j < m_column; ++j)
        {
            (*this)(i, j) -= rhs(i, j);
        }
    }

    return *this;
}

Matrix2D Matrix2D::operator*(const Matrix2D& rhs)
{
    if((m_column != rhs.getRowSize()))
    {
        throw "Wrong multipication!";
    }

    const auto row = m_row;
    const auto column = rhs.getColumnSize();
    Matrix2D result(row, column);

    for(auto i = 0; i < m_row; ++i)
    {
        for(auto j = 0; j < column; ++j)
        {
            for(auto k = 0; k < m_column; ++k)
            {
                result(i, j) += (*this)(i, k) * rhs(k, j);
            }
        }
    }

    return result;
}

Matrix2D& Matrix2D::operator*=(const Matrix2D& rhs)
{
    auto result = (*this) * rhs;
    (*this) = result;
    return *this;
}

Matrix2D Matrix2D::operator+(const double& rhs)
{
    Matrix2D result(m_row, m_column);

    for(auto i = 0; i < m_row; ++i)
    {
        for(auto j = 0; j < m_column; ++j)
        {
            result(i, j) = (*this)(i, j) + rhs;
        }
    }

    return result;
}

Matrix2D Matrix2D::operator-(const double& rhs)
{
    Matrix2D result(m_row, m_column);

    for(auto i = 0; i < m_row; ++i)
    {
        for(auto j = 0; j < m_column; ++j)
        {
            result(i, j) = (*this)(i, j) - rhs;
        }
    }

    return result;
}

Matrix2D Matrix2D::operator*(const double& rhs)
{
    Matrix2D result(m_row, m_column);

    for(auto i = 0; i < m_row; ++i)
    {
        for(auto j = 0; j < m_column; ++j)
        {
            result(i, j) = (*this)(i, j) * rhs;
        }
    }

    return result;
}

Matrix2D Matrix2D::operator/(const double& rhs)
{
    Matrix2D result(m_row, m_column);

    for(auto i = 0; i < m_row; ++i)
    {
        for(auto j = 0; j < m_column; ++j)
        {
            result(i, j) = (*this)(i, j) / rhs;
        }
    }

    return result;
}

Matrix2D& Matrix2D::operator-()
{
    for(auto i = 0; i < m_row; ++i)
    {
        for(auto j = 0; j < m_column; ++j)
        {
            (*this)(i, j) = -(*this)(i, j);
        }
    }

    return *this;
}

double& Matrix2D::operator()(const std::uint32_t& row, const std::uint32_t& column)
{
    return m_pMatrix[row*m_column+column];
}

const double& Matrix2D::operator()(const std::uint32_t& row, const std::uint32_t& column) const
{
    return m_pMatrix[row*m_column+column];
}

Matrix2D Matrix2D::transpose()
{
    Matrix2D result(m_column, m_row);

    for(auto i = 0; i < m_row; ++i)
    {
        for(auto j = 0; j < m_column; ++j)
        {
            result(j, i) = (*this)(i, j);
        }
    }

    return result;
}

void Matrix2D::fillRandom()
{
    static RandomNumber random(0);

    for(auto i = 0; i < m_row; ++i)
    {
        for(auto j = 0; j < m_column; ++j)
        {
            (*this)(i,j) = random.generateNumber();
        }
    }
}

void Matrix2D::fillZero()
{
    for(auto i = 0; i < m_row; ++i)
    {
        for(auto j = 0; j < m_column; ++j)
        {
            (*this)(i, j) = 0.0F;
        }
    }
}

void Matrix2D::clear()
{
    delete[] m_pMatrix;
}

Matrix2D operator-(double lhs, Matrix2D& rhs)
{
    return -rhs + lhs;
}

Matrix2D operator+(double lhs, Matrix2D& rhs)
{
    return rhs + lhs;
}