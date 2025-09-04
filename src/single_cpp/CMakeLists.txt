
# 获取src目录下所有的cpp文件
file(GLOB SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/single_cpp)
# 为每个cpp文件创建单独的可执行文件
foreach(source_file ${SOURCE_FILES})
    # 获取不带路径的文件名
    get_filename_component(executable_name ${source_file} NAME_WE)
    
    # 为每个源文件创建可执行文件
    add_executable(${executable_name} ${source_file})
    
    # 如果需要，可以在这里添加额外的链接库
    # target_link_libraries(${executable_name} some_library)
endforeach()