set(COURSE_WORK_SRC matrix.h matrix.cpp)

add_library(core ${COURSE_WORK_SRC})
add_executable(course-work main.cpp)

target_link_libraries(course-work core)