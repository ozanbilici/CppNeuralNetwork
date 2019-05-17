#ifndef MATH_HPP
#define MATH_HPP

#include "Matrix2D.hpp"

/**
 * @brief Math namespace
 */
namespace Math_n
{

/**
 * @brief Calculate sigmoid
 *
 * @param [in,out] matrix
 *  Reference to input matrix that will be overwritten
 * @return matrix
 *  Reference to input matrix
 */
Matrix2D& sigmoid(Matrix2D& matrix);

/**
 * @brief Calculate cross entropy
 *
 * @param [in] batchSize
 *  Batch size
 * @param [in] expectedOutput
 *  Reference to the matrix that holds training labels
 * @param [in] output
 *  Reference to the matrix that holds labels from trained network
 * @return double
 *  Cross entropy results
 */
double crossEntropy(std::int32_t batchSize, Matrix2D& expectedOutput, Matrix2D& output);

/**
 * @brief Calculate power
 *
 * @param [in] matrix
 *  Reference to input matrix that will overwritten by power value
 * @param power
 *  Power value
 * @return Matrix
 *  Reference to input matrix
 */
Matrix2D& power(Matrix2D& matrix, std::uint32_t power);

} // namespace Math_n

#endif // MATH_HPP