# CMakeLists.txt

cmake_minimum_required(VERSION 3.10)
project(SecureApp)

# Add the source files
set(SOURCE_FILES
    src/main.cpp
    src/utils/CryptoUtils.cpp
    src/gui/MainWindow.xaml
    src/gui/MainViewController.xaml
    src/Database.cpp
)

# Add the header files
set(HEADER_FILES
    include/utils/CryptoUtils.h
    include/gui/MainWindow.xaml.h
    include/gui/MainViewController.xaml.h
    include/Database.h
)

# Add the executable target
add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})

# Include directories
target_include_directories(${PROJECT_NAME}
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Link libraries
# Note: Adjust the library names according to the actual names on your system
target_link_libraries(${PROJECT_NAME}
    PRIVATE
    sqlite3
    # Add other necessary libraries here
)

# Set C++ standard
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
