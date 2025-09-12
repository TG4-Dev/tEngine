include(FetchContent)

# fmt - lighweight header only format lib
FetchContent_Declare(
  fmt
  GIT_REPOSITORY  https://github.com/fmtlib/fmt.git
  GIT_TAG         10.2.1 
)

FetchContent_MakeAvailable(fmt)

# spdlog - logging library
FetchContent_Declare(
  spdlog
  GIT_REPOSITORY  https://github.com/gabime/spdlog.git
  GIT_TAG         v1.14.1
)

FetchContent_MakeAvailable(spdlog)

#glm - math
FetchContent_Declare(
  glm
  GIT_REPOSITORY https://github.com/g-truc/glm.git
  GIT_TAG 1.0.1
)

FetchContent_MakeAvailable(glm)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

# Предотвращаем конфликты с другими сборками gtest
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)
