add_library(tengine STATIC)


target_compile_definitions(tengine 
  PRIVATE
    SPDLOG_NO_EXCEPTIONS
    SPDLOG_FMT_EXTERNAL
)

if (MSVC)
  target_compile_options(tengine PRIVATE /W4 /WX /EHs-c-)
elseif (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	target_compile_options(tengine PRIVATE 
		$<$<CONFIG:Release>:-Wall -Werror -fno-exceptions>
		$<$<CONFIG:Debug>:-Wall -Werror -fsanitize=address,undefined>
	)
	target_link_options(tengine PUBLIC
		$<$<CONFIG:Debug>:-Wall -Werror -fsanitize=address,undefined>
	)
endif()

target_include_directories(tengine
      PUBLIC
          ${CMAKE_CURRENT_SOURCE_DIR}
)


target_sources(tengine
      PRIVATE
        core/Log.cpp
 "core/time/Clock.cpp")
#find_package(fmt REQUIRED)
#find_package(spdlog REQUIRED)


target_link_libraries(tengine
      PUBLIC
            fmt::fmt
            spdlog::spdlog
            glm::glm
			GTest::gtest_main
)

add_executable(sandbox app/sandbox_main.cpp "core/time/Clock.cpp")
target_link_libraries(sandbox PRIVATE tengine)
