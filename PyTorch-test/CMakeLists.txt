cmake_minimum_required(VERSION 3.16)
project(pytorch-test)

set(CMAKE_CXX_STANDARD 20)

# Find and add PyTorch path
execute_process(COMMAND python -c "import torch;print(torch.utils.cmake_prefix_path, end='')"
                RESULT_VARIABLE pytorch_cmake_prefix_result
                OUTPUT_VARIABLE pytorch_cmake_prefix_output)
set(CMAKE_PREFIX_PATH "${pytorch_cmake_prefix_output}/Torch;${CMAKE_PREFIX_PATH}")
message(STATUS "PyTorch cmake prefix path: ${CMAKE_PREFIX_PATH}")

find_package(Torch REQUIRED)
message("PyTorch Include Dirs: ${TORCH_INCLUDE_DIRS} | PyTorch Libraries: ${TORCH_LIBRARIES} | PyTorch Flags: ${TORCH_CXX_FLAGS}")

file(GLOB CXX_EXEC "*.cpp")

add_executable(pytorch-test ${CXX_EXEC})
target_link_libraries(pytorch-test PRIVATE ${TORCH_LIBRARIES})
