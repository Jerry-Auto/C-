
# 自动处理所有子目录
file(GLOB subdirs LIST_DIRECTORIES true RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*")

foreach(subdir ${subdirs})
    # 拼接绝对路径
    set(full_subdir_path "${CMAKE_CURRENT_SOURCE_DIR}/${subdir}")
    if(IS_DIRECTORY ${full_subdir_path})
        message(STATUS "Processing subdirectory: ${subdir}")
        
        # 使用绝对路径查找.cpp文件
        file(GLOB SOURCES 
        "${full_subdir_path}/*.cpp"
        "${full_subdir_path}/*.c"
        )
        # 获取头文件所在目录
        get_filename_component(header_dir "${full_subdir_path}" ABSOLUTE)
        if(SOURCES)
            # 提取目录名（去掉路径前缀）
            get_filename_component(EXEC_NAME ${subdir} NAME)
            # 创建可执行文件
            add_executable(${EXEC_NAME} ${SOURCES})
            target_include_directories(${EXEC_NAME} PRIVATE ${header_dir})
            # 设置可执行文件输出路径（可选，如果上面的全局设置不够）
            set_target_properties(${EXEC_NAME} PROPERTIES
                RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/${EXEC_NAME}"
            )
            message(STATUS "Added executable: ${EXEC_NAME} (from ${SOURCES})")
        else()
            message(WARNING "No .cpp files found in ${subdir}, skipping...")
        endif()
    endif()
endforeach()