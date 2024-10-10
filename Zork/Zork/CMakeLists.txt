# CMakeList.txt : CMake project for Zork, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (Zork "Zork.cpp" "Zork.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Zork PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
