cmake_minimum_required(VERSION 3.6)
#cmake_policy(VERSION 3.5)

set(Project_name Polynomial)
project(${Project_name})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(MP3_LIBRARY "${Project_name}")
set(MP3_TESTS   "test_${Project_name}")
set(MP3_INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(GENERATED_DIR "${CMAKE_CURRENT_SOURCE_DIR}/generated")

set(ANTLR_DIR "D:/UNN/ANTLR/antlr-4.13.2")
set(ANTLR_INCLUDE "D:/UNN/ANTLR/antlr-4.13.2/include/antlr4-runtime")
set(ANTLR_LIB "D:/UNN/ANTLR/antlr-4.13.2/lib")


set(GENERATED_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/generated/PolynomialLexer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/generated/PolynomialParser.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/generated/PolynomialBaseVisitor.cpp
)

set(GENERATED_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/generated/PolynomialLexer.h
    ${CMAKE_CURRENT_SOURCE_DIR}/generated/PolynomialParser.h
    ${CMAKE_CURRENT_SOURCE_DIR}/generated/PolynomialVisitor.h
    ${CMAKE_CURRENT_SOURCE_DIR}/generated/PolynomialBaseVisitor.h
)





add_library(${MP3_LIBRARY} STATIC)

# Добавляем сгенерированные ANTLR файлы в библиотеку
target_sources(${MP3_LIBRARY} PRIVATE
    ${GENERATED_SOURCES}
    ${CMAKE_CURRENT_SOURCE_DIR}/parser/PolyBuilderVisitor.cpp
)


target_sources(${MP3_LIBRARY} PRIVATE
    ${GENERATED_HEADERS}
)


target_include_directories(${MP3_LIBRARY} PUBLIC
    ${MP3_INCLUDE}
    ${GENERATED_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/parser
    ${ANTLR_INCLUDE}
)

# Добавляем зависимости
#add_dependencies(${MP3_LIBRARY} generate_parser)

# Линкуем ANTLR
target_link_libraries(${MP3_LIBRARY} ${ANTLR_LIB}/antlr4-runtime.lib)

# ============================================
# Добавление поддиректорий
# ============================================
add_subdirectory(src)
#add_subdirectory(test)
add_subdirectory(samples)