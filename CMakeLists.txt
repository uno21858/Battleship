cmake_minimum_required(VERSION 3.14)
project(Battleship1C__)

# raylib
find_package(raylib QUIET)
if (NOT raylib_FOUND)
    include(FetchContent)
    FetchContent_Declare(
            raylib
            GIT_REPOSITORY https://github.com/raysan5/raylib.git
            GIT_TAG 4.5.0
            GIT_SHALLOW 1
    )
    FetchContent_MakeAvailable(raylib)
endif()

# raylib-cpp
find_package(raylib_cpp QUIET)
if (NOT raylib_cpp_FOUND)
    if (NOT DEFINED RAYLIB_CPP_VERSION)
        set(RAYLIB_CPP_VERSION next)
    endif()
    include(FetchContent)
    FetchContent_Declare(
            raylib_cpp
            GIT_REPOSITORY https://github.com/RobLoach/raylib-cpp.git
            GIT_TAG ${RAYLIB_CPP_VERSION}
    )
    FetchContent_MakeAvailable(raylib_cpp)
endif()



# Cambiar el nombre al que se va a ejecutar

# Definimos el ejecutable
add_executable(Battleship1C__ main.cpp
        Button.cpp
        naves.cpp
        StartMenu.cpp
        tablero.cpp
        main.cpp)




# Configuración de propiedades del target
set_target_properties(Battleship1C__ PROPERTIES CXX_STANDARD 11)

# Vinculación de bibliotecas necesarias
target_link_libraries(Battleship1C__ PUBLIC raylib raylib_cpp)

# Configuraciones específicas para Web
if (${PLATFORM} STREQUAL "Web")
    # Generar un archivo .html para Emscripten
    set_target_properties(Battleship1C__ PROPERTIES SUFFIX ".html")

    # Flags de Emscripten necesarias para usar Raylib
    target_link_options(Battleship1C__ PRIVATE
            -sEXPORTED_FUNCTIONS=['_main','_malloc']
            -sEXPORTED_RUNTIME_METHODS=ccall
            -sUSE_GLFW=3)
endif()

