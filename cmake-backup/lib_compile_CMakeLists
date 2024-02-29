cmake_minimum_required(VERSION 3.25)
project(library_book_manager)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "-static")

# set a macro indicating where main.cpp is
set(MAIN_PRG ${PROJECT_SOURCE_DIR}/src/main.cpp)

# find where lib is
find_library(FUNC_LIB myfunc ${PROJECT_SOURCE_DIR}/lib)


add_executable(library_book_manager  # this is the name of executive file generated
        ${MAIN_PRG}
)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# link lib into exe
target_link_libraries(library_book_manager
        ${FUNC_LIB}
)