set(APP_NAME "UnitTest")
file(GLOB cpp_files "*.cpp")
add_executable(${APP_NAME} ${cpp_files} )
target_link_libraries(${APP_NAME}   Catch2::Catch2 Catch2::Catch2WithMain CommonUtility DomainModel)
