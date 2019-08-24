# compile main executable
include_directories(
    ./
    library
)

add_executable(${CMAKE_PROJECT_NAME}
    main.cpp

    library/RandomNumber.cpp
    library/Matrix2D.cpp
    library/NeuralNetwork.cpp
    library/Math.cpp
)