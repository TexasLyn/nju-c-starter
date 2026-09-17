cmake_minimum_required(VERSION 3.20)
project(zhic C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# 让每个 .c 文件都成为一个独立的可运行目标，方便在 CLion 里单独运行。
# 新增文件后点 CLion 顶部的 "Reload CMake Project" 即可刷新。

add_compile_options(-Wall -Wextra -g)

# 判断源码是不是"改错题"骨架：这类文件里故意埋了错误，
# 编译不过才是正常的，所以不加入构建目标（否则整个工程构建失败）。
function(is_error_fix_task src out_var)
    file(READ "${src}" head LIMIT 700)
    if(head MATCHES "@NOCOMPILE")
        set(${out_var} TRUE PARENT_SCOPE)
    else()
        set(${out_var} FALSE PARENT_SCOPE)
    endif()
endfunction()

# ---- practice/：动手写的练习骨架 ----
file(GLOB PRACTICE_SOURCES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/practice/*.c")
foreach(src ${PRACTICE_SOURCES})
    get_filename_component(name ${src} NAME_WE)
    is_error_fix_task(${src} is_ef)
    if(is_ef)
        message(STATUS "跳过改错题骨架（故意含错）：${name}")
    else()
        add_executable(${name} ${src})
        # 关掉未使用变量/参数的警告：骨架里预留的变量本来就是给你填的
        target_compile_options(${name} PRIVATE
            -Wno-unused-variable
            -Wno-unused-parameter
            -Wno-unused-but-set-variable)
    endif()
endforeach()

# ---- answers/：参考答案，目标名加 ans_ 前缀避免和练习重名 ----
file(GLOB ANSWER_SOURCES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/answers/*.c")
foreach(src ${ANSWER_SOURCES})
    get_filename_component(name ${src} NAME_WE)
    add_executable(ans_${name} ${src})
endforeach()
