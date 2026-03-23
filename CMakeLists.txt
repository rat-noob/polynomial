cmake_minimum_required(VERSION 3.14)
cmake_policy(VERSION 3.5)

set(Project_name Polynomial)
project(${Project_name})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Для Visual Studio добавляем флаги
if(MSVC)
    add_compile_options(/std:c++17)
    add_compile_options(/EHsc)
    add_compile_options(/permissive-)
    add_compile_options(/Zc:__cplusplus)  # Важно для правильного определения __cplusplus
endif()

set(MP3_LIBRARY "${Project_name}")
set(MP3_TESTS   "test_${Project_name}")
set(MP3_INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/include")

# ============================================
# ANTLR
# ============================================
include(FetchContent)

FetchContent_Declare(
    antlr4
    GIT_REPOSITORY https://github.com/antlr/antlr4.git
    GIT_TAG        4.13.2
    SOURCE_SUBDIR  runtime/Cpp
)

# Собираем статическую библиотеку
set(ANTLR4_BUILD_SHARED OFF CACHE BOOL "" FORCE)
set(ANTLR4_CXX_STANDARD 17 CACHE STRING "" FORCE)
set(ANTLR4_WITH_STATIC_CRT ON CACHE BOOL "" FORCE)  # Для Windows

FetchContent_MakeAvailable(antlr4)

# ============================================
# КРИТИЧЕСКИ ВАЖНО: Отключаем проблемный модуль профилирования
# ============================================
if(MSVC)
    target_compile_definitions(antlr4_static PRIVATE ANTLR4_CPP_NO_PROFILING)
endif()

# ============================================
# Генерация парсера ANTLR
# ============================================

# Создаём папку для сгенерированных файлов
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/generated)

# Путь к JAR-файлу ANTLR
set(ANTLR4_JAR "D:/UNN/antlr/antlr-4.13.2-complete.jar")

if(NOT EXISTS ${ANTLR4_JAR})
    set(ANTLR4_JAR ${antlr4_SOURCE_DIR}/antlr4-4.13.2-complete.jar)
endif()
# Если всё ещё не найден, скачиваем
if(NOT EXISTS ${ANTLR4_JAR})
    message(STATUS "Downloading ANTLR JAR...")
    file(DOWNLOAD 
        https://www.antlr.org/download/antlr-4.13.2-complete.jar
        ${CMAKE_CURRENT_BINARY_DIR}/antlr-4.13.2-complete.jar
        SHOW_PROGRESS
    )
    set(ANTLR4_JAR ${CMAKE_CURRENT_BINARY_DIR}/antlr-4.13.2-complete.jar)
endif()

message(STATUS "Using ANTLR JAR: ${ANTLR4_JAR}")

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

add_custom_command(
    OUTPUT ${GENERATED_SOURCES} ${GENERATED_HEADERS}
    COMMAND java -jar ${ANTLR4_JAR}
        -Dlanguage=Cpp
        -visitor
        -no-listener
        -o ${CMAKE_CURRENT_SOURCE_DIR}/generated
        ${CMAKE_CURRENT_SOURCE_DIR}/grammar/Polynomial.g4
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/grammar/Polynomial.g4
    COMMENT "Generating ANTLR parser for Polynomial"
)

add_custom_target(generate_parser
    DEPENDS ${GENERATED_SOURCES} ${GENERATED_HEADERS}
)

# ============================================
# Создание библиотеки
# ============================================
add_library(${MP3_LIBRARY} STATIC)

# Добавляем сгенерированные ANTLR файлы в библиотеку
target_sources(${MP3_LIBRARY} PRIVATE
    ${GENERATED_SOURCES}
)

# Добавляем заголовочные файлы (для удобства в IDE)
target_sources(${MP3_LIBRARY} PRIVATE
    ${GENERATED_HEADERS}
)

# Подключаем заголовочные директории
target_include_directories(${MP3_LIBRARY} PUBLIC
    ${MP3_INCLUDE}
    ${CMAKE_CURRENT_SOURCE_DIR}/generated
    ${CMAKE_CURRENT_SOURCE_DIR}/parser
)

# Добавляем зависимости
add_dependencies(${MP3_LIBRARY} generate_parser)

# Линкуем ANTLR
target_link_libraries(${MP3_LIBRARY} antlr4_static)

# ============================================
# Добавление поддиректорий
# ============================================
add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(samples)