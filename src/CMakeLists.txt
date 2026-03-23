set(target ${MP3_LIBRARY})

file(GLOB hdrs "*.h*" "${MP3_INCLUDE}/*.h*")
file(GLOB srcs "*.cpp")

# Добавляем их в существующую библиотеку (НЕ создаём новую!)
if(srcs)
    target_sources(${target} PRIVATE ${srcs})
endif()


#add_library(${target} STATIC ${srcs} ${hdrs})
#target_link_libraries(${target} ${LIBRARY_DEPS})
#target_link_libraries(${target} antlr4_static)