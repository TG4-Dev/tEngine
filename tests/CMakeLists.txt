add_executable(run_tests
	TestTests.cpp   
)

# Линкуем с gtest и вашей библиотекой
target_link_libraries(run_tests
	tengine
    GTest::gtest_main  # автоматически вызывает RUN_ALL_TESTS()
)

# Регистрируем тест в CTest
add_test(NAME run_tests COMMAND run_tests)
