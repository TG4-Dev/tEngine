add_library(tengine STATIC)

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
