set(APP_NAME "ScpiServer")
file(GLOB cpp_files "*.cpp")
add_executable(${APP_NAME} ${cpp_files}  )
target_link_libraries(${APP_NAME} PUBLIC  Poco::Net Poco::Util Poco::JSON gflags RTTR::Core CommonUtility DomainModel)
