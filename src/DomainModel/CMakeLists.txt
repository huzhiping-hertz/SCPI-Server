set(library_name "DomainModel")
file(GLOB file_srcs "*.cpp")
add_library(${library_name} STATIC ${file_srcs})
target_link_libraries(${library_name} Poco::Util Poco::JSON RTTR::Core CommonUtility)