cmake_minimum_required(VERSION 3.7)
project(CMakeBuildTemplate)

# set cpp版本
set(CMAKE_CXX_STANDARD 11)

# set source files
set(SOURCE_FILES
        main.cpp)

# build DEBUG or RELEASE
set(CMAKE_BUILD_TYPE RELEASE) # DEBUG RELEASE

message("构建类型是${CMAKE_BUILD_TYPE}")


# 启动测试
enable_testing()

# 定义一个宏，用来简化测试工作
macro(do_test arg1 arg2 result)
    add_test(test_${arg1}_${arg2} CMakeBuildTemplate ${arg1} ${arg2})
    set_tests_properties(test_${arg1}_${arg2}
            PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endmacro(do_test)

# 测试帮助信息是否可以正常提示
add_test(test_usage CMakeBuildTemplate)
set_tests_properties(test_usage
        PROPERTIES PASS_REGULAR_EXPRESSION "Usage: .* num_a num_b")

do_test(5 2 "7")
do_test(10 20 "30")

configure_file(
        ${PROJECT_SOURCE_DIR}/config/config.h.in
        ${PROJECT_SOURCE_DIR}/config/config.h
)

option(USE_MYMATH
        "Use provided math implementation" ON)

if (USE_MYMATH)
    # 添加 include目录
    include_directories(${PROJECT_SOURCE_DIR}/math)
    # 添加 子目录
    add_subdirectory(math)
    set(EXTRA_LIBS ${EXTRA_LIBS} math_functions)
endif (USE_MYMATH)

# 指定生成目标
add_executable(CMakeBuildTemplate ${SOURCE_FILES})

# 添加链接库
target_link_libraries(CMakeBuildTemplate ${EXTRA_LIBS})

# 指定安装路径
install(TARGETS CMakeBuildTemplate DESTINATION bin)
install(FILES ${PROJECT_SOURCE_DIR}/config/config.h
        DESTINATION include)