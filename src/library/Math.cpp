#include <cmath>
#include <iostream>

#include "Math.hpp"

namespace Math_n
{

Matrix2D& sigmoid(Matrix2D& matrix)
{
    auto row = matrix.getRowSize();
    auto column = matrix.getColumnSize();

    for(auto i = 0; i < row; ++i)
    {
        for(auto j = 0; j < column; ++j)
        {
            matrix(i,j) = (1.0 / (1 + std::exp(-matrix(i,j))));
        }
    }

    return matrix;
}

double crossEntropy(std::int32_t batchSize, Matrix2D& output, Matrix2D& expectedOutput)
{
    auto row = expectedOutput.getRowSize();
    auto column = expectedOutput.getColumnSize();
    auto row2 = output.getRowSize();
    auto column2 = output.getColumnSize();

    double sum = 0.0F;
    for(auto i = 0; i < row; ++i)
    {
        for(auto j = 0; j < column; ++j)
        {
            sum += (expectedOutput(i, j) * std::log(output(i, j))) +
                   ((1 - expectedOutput(i, j)) * std::log( (1 - output(i, j))));
        }
    }

    double result = ((-sum) / batchSize);

    return result;
}

Matrix2D& power(Matrix2D& matrix, std::uint32_t power)
{
    auto row = matrix.getRowSize();
    auto column = matrix.getColumnSize();

    for(auto i = 0; i < row; ++i)
    {
        for(auto j = 0; j < column; ++j)
        {
            matrix(i,j) = std::pow(matrix(i, j), power);
        }
    }

    return matrix;
}

} // namespace Math_n