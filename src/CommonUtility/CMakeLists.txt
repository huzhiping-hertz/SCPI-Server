set(utility_library_name "CommonUtility")
file(GLOB UTILITY_SRCS "*.cpp")
add_library(${utility_library_name} SHARED ${UTILITY_SRCS})
target_link_libraries(${utility_library_name}  Poco::Util Poco::JSON)