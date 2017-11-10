set(SOURCE_FILES
        MathFunctions.cpp
        )

add_library(math_functions ${SOURCE_FILES})

# 指定 math_functions 库的安装路径
install(TARGETS math_functions DESTINATION bin)
install(FILES MathFunctions.h DESTINATION include)