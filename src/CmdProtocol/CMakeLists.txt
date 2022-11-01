
set(library_name "CmdProtocol")
file(GLOB file_srcs "*.cpp")
add_library(${library_name} STATIC ${file_srcs})
target_link_libraries(${library_name} pugixml::pugixml gflags )
