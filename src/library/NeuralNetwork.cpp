#include "NeuralNetwork.hpp"
#include "Math.hpp"
#include <iostream>

using namespace Configuration_n;

NeuralNetwork::NeuralNetwork() :
    m_input(NUMBER_FEATURES, NUMBER_DATA),
    m_output(1, NUMBER_DATA),
    m_expectedOutput(1, NUMBER_DATA),
    m_W1(NODES, 2),
    m_b1(NODES, BATCH_SIZE),
    m_W2(1, NODES),
    m_b2(1, BATCH_SIZE),
    m_cost(0.0F)
{

}

void NeuralNetwork::initialize()
{
    m_W1.fillRandom();
    m_b1.fillRandom();
    m_W2.fillRandom();
    m_b2.fillRandom();
}

void NeuralNetwork::load(Matrix2D& input, Matrix2D& label)
{
    m_input = input;
    m_expectedOutput = label;
}

void NeuralNetwork::run()
{
    trainNetwork();
    calculateCrossEntropy();
}

void NeuralNetwork::printResults()
{
    auto row = m_output.getRowSize();
    auto column = m_output.getColumnSize();
    for(auto i = 0; i < row; ++i)
    {
        for(auto j = 0; j < column; ++j)
        {
            std::cout << " Expected " << m_expectedOutput(i,j) << " Output " << m_output(i,j) << std::endl;
        }
    }
}

double NeuralNetwork::getCost() const
{
    return m_cost;
}

void NeuralNetwork::trainNetwork()
{
    // Layer 1
    auto Z1 = (m_W1 * m_input) + m_b1;
    auto A1 = Math_n::sigmoid(Z1);

    // Layer 2
    auto Z2 = (m_W2 * A1) + m_b2;
    auto A2 = Math_n::sigmoid(Z2);

    m_output = A2;

    // Back Prop
    //LAYER 2
    auto dZ2 = A2 - m_expectedOutput;
    auto dW2 = (dZ2 * A1.transpose()) / BATCH_SIZE;
    auto db2 = dZ2 / BATCH_SIZE;

    //LAYER 1
    auto dZ1 = (m_W2.transpose() * dZ2) - (-Math_n::power(A1, 2) + 1.0F);
    auto dW1 = (dZ1 * m_input.transpose()) / BATCH_SIZE;
    auto db1 = dZ1 / BATCH_SIZE;

    // G.D
    m_W1 = m_W1 - (dW1 * LEARNING_RATE);
    m_b1 = m_b1 - (db1 * LEARNING_RATE);

    m_W2 = m_W2 - (dW2 * LEARNING_RATE);
    m_b2 = m_b2 - (db2 * LEARNING_RATE);
}

void NeuralNetwork::calculateCrossEntropy()
{
    // Cost
    m_cost = Math_n::crossEntropy(BATCH_SIZE, m_output, m_expectedOutput);
}