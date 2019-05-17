#include <cstdlib>
#include <ctime>

#include "Matrix2D.hpp"

Matrix2D::Matrix2D(std::size_t row, std::size_t column)
{
    m_pMatrix = new double*[row];
    for(int i = 0; i < row; ++i)
    {
        m_pMatrix[i] = new double[column];
    }

    m_row = row;
    m_column = column;
}

Matrix2D::~Matrix2D()
{
    clear();
}

Matrix2D::Matrix2D(const Matrix2D& matrix)
{
    m_pMatrix = new double*[matrix.m_row];
    for(int i = 0; i < matrix.m_row; ++i)
    {
        m_pMatrix[i] = new double[matrix.m_column];
    }

    m_row = matrix.m_row;
    m_column = matrix.m_column;

    *this = matrix;
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

    for(auto i = 0; i < m_row; ++i)
    {
        for(auto j = 0; j < m_column; ++j)
        {
            (*this)(i, j) = rhs(i, j);
        }
    }

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
    return m_pMatrix[row][column];
}

const double& Matrix2D::operator()(const std::uint32_t& row, const std::uint32_t& column) const
{
    return m_pMatrix[row][column];
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
    /* initialize random seed: */
    srand(time(nullptr));

    for(auto i = 0; i < m_row; ++i)
    {
        for(auto j = 0; j < m_column; ++j)
        {
            (*this)(i,j) = ((double) rand() / (RAND_MAX)) + 1;
        }
    }
}

void Matrix2D::clear()
{
    for(int i = 0; i < m_row; ++i)
    {
        delete[] m_pMatrix[i];
    }
    delete[] m_pMatrix;
}