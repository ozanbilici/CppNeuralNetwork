[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](../master/LICENSE)

# CppNeuralNetwork (Neural Network Example in C++)

Example project demonstrates neural network implementation in C++. CppNeuralNetwork project was inspired by [this project](https://medium.com/coinmonks/implementing-an-artificial-neural-network-in-pure-java-no-external-dependencies-975749a38114). No additional library is needed.

Simple xor gate is implemented by using neural network in C++. After the training, the results should be as following:

| Expected | Output |
|:--------:|:------:|
| 0.0000   | 0.0431 |
| 1.0000   | 0.9573 |
| 1.0000   | 0.9587 |
| 0.0000   | 0.0409 |

## Code structure

- `CMakeLists.txt` CMake building script
- `src` contains source code
- `src/library` contains libraries

## Dependencies

- None

## Building

```
mkdir build
cd build
cmake ..
make
```

## Running

```
cd build/src
./CppNeuralNetwork
```

## Author

- Ozan Bilici - ozanbilici@gmail.com
