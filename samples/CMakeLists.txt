set(target sample)

file(GLOB SAMPLE_SOURCES "*.cpp")

foreach(SAMPLE ${SAMPLE_SOURCES})
    
    get_filename_component(NAME ${SAMPLE} NAME_WE)
    
    
    add_executable(${NAME} ${SAMPLE})
    
    
    target_link_libraries(${NAME} ${MP3_LIBRARY})
    
    add_dependencies(${NAME} generate_parser)
    
    
endforeach()