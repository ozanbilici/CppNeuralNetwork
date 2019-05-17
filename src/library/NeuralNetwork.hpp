#ifndef NEURAL_NETWORK_HPP
#define NEURAL_NETWORK_HPP

#include "Matrix2D.hpp"
#include "Configuration.hpp"

class NeuralNetwork
{
public:
    /**
     * @brief Construct a new Neural Network object
     *
     */
    NeuralNetwork();

    /**
     * @brief Initialize the network
     */
    void initialize();

    /**
     * @brief Load the data
     *
     * @param [in] input
     *  Reference to input data
     * @param label
     *  Reference to label
     */
    void load(Matrix2D& input, Matrix2D& label);

    /**
     * @brief Run the network for one step
     */
    void run();

    /**
     * @brief Print results
     */
    void printResults();

    /**
     * @brief Get cross entropy result
     *
     * @return
     *  Returns cross entropy result
     */
    double getCost() const;

private:
    /**
     * @brief train network for one step
     */
    void trainNetwork();

    /**
     * @brief Calculate cross entropy result
     */
    void calculateCrossEntropy();

    Matrix2D m_input;
    Matrix2D m_output;
    Matrix2D m_expectedOutput;

    Matrix2D m_W1;
    Matrix2D m_b1;

    Matrix2D m_W2;
    Matrix2D m_b2;

    double m_cost;
};

#endif // NEURAL_NETWORK_HPP