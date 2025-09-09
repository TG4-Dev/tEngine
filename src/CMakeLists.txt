add_library(tengine STATIC)

set(COMMON_FLAGS "-Wall -Werror -fno-expections")


if (MSVC)
  target_compile_options(tengine PRIVATE /W4 /WX)
elseif (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
        CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
      target_compile_options(tengine PRIVATE -Wall -Werror -fno-exceptions)
endif()


target_include_directories(tengine
      PUBLIC
          ${CMAKE_CURRENT_SOURCE_DIR}
)


target_sources(tengine
      PRIVATE
        core/Log.cpp
)
#find_package(fmt REQUIRED)
#find_package(spdlog REQUIRED)


target_link_libraries(tengine
      PUBLIC
            fmt::fmt
            spdlog::spdlog
            glm::glm
)

add_executable(sandbox app/sandbox_main.cpp)
target_link_libraries(sandbox PRIVATE tengine)
