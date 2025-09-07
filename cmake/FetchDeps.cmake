include(FetchContent)

# fmt - lighweight header only format lib
FetchContent_Declare(
  fmt
  GIT_REPOSITORY  https://github.com/fmtlib/fmt.git
  GIT_TAG         master 
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
