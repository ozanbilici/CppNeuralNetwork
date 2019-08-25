#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP

/**
 * @brief Configuration namespace
 */
namespace Configuration_n
{

/**
 * @brief Number of features
 */
static constexpr auto NUMBER_FEATURES = 2;

/**
 * @brief Number of data
 */
static constexpr auto NUMBER_DATA = 4;

/**
 * @brief Number of nodes
 */
static constexpr auto NODES = 30;

/**
 * @brief Batch size
 */
static constexpr auto BATCH_SIZE = 4;

/**
 * @brief Learning rate
 */
static const double LEARNING_RATE = 0.01F;

/**
 * @brief Number of epoch
 */
constexpr auto NUMBER_EPOCH = 10000;

}

#endif // CONFIGURATION_HPP