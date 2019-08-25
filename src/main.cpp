#include <iostream>
#include <iomanip>

#include "NeuralNetwork.hpp"
#include "Configuration.hpp"
#include "Timer.hpp"

using namespace Configuration_n;

/**
 * @brief 2D data to matrix converter
 *
 * @param [in] data
 *  Pointer to input data to be converted
 * @return Matrix2D
 *  Returns 2D Matrix
 */
Matrix2D data2MatrixConverter(double data[][Configuration_n::NUMBER_FEATURES])
{
    Matrix2D input(NUMBER_FEATURES, NUMBER_DATA);

    for(auto i = 0; i < NUMBER_DATA; i++)
    {
        input(0, i) = data[i][0];
        input(1, i) = data[i][1];
    }

    return input;
}

/**
 * @brief Label data to 2D Matrix converter
 *
 * @param [in] data
 *  Pointer to label data to be converted
 * @return Matrix2D
 *  Returns 2D Matrix
 */
Matrix2D label2MatrixConverter(double label[])
{
    Matrix2D labelMatrix(1, NUMBER_DATA);

    for(auto i = 0; i < NUMBER_DATA; i++)
    {
        labelMatrix(0, i) = label[i];
    }

    return labelMatrix;
}

/**
 * @brief Main function
 */
int main(int argv, char** argc)
{
    // Set float precision to 4 for cout
    std::cout << std::setprecision(4) << std::fixed;

    // data
    double data[4][2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    double labels[4] = {0, 1, 1, 0};

    // neural network
    NeuralNetwork neuralNetwork;

    // initalize neural network
    std::cout << "Initialize weights..." << std::endl;
    neuralNetwork.initialize();

    // loading the data
    std::cout << "Loading the training data..." << std::endl;
    Matrix2D inputMatrix = std::move(data2MatrixConverter(data));
    Matrix2D labelMatrix = std::move(label2MatrixConverter(labels));
    neuralNetwork.load(inputMatrix, labelMatrix);

    // starting the training
    std::cout << "Training starting..." << std::endl;
    for(auto epoch = 0; epoch < NUMBER_EPOCH; ++epoch)
    {
        std::cout << "Epoch " << epoch << " Cost: " << (float) neuralNetwork.getCost() << " ";

        {
            Timer timer;
            neuralNetwork.run();
        }
    }

    neuralNetwork.printResults();
}
