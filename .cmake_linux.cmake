##
## EPITECH PROJECT, 2021
## Tek2
## File description:
## CMakeLists.txt
##

## PROJECT VAR
## <=====================================>
project( sfml
        VERSION
        1.0
        DESCRIPTION
        "Sfml Module for Shipwreck Engine"
        LANGUAGES
        CXX
        )
set( EXEC sfml )
set( EXT cpp )

## SOURCE FOLDERS
set( SRC_FOLDERS
        ${CMAKE_SOURCE_DIR}/Project/sources/
        )
## INCLUDE FOLDERS
set( INC_FOLDERS
        ${CMAKE_SOURCE_DIR}/Project/includes/
        ${CMAKE_SOURCE_DIR}/Engine/
        ${CMAKE_SOURCE_DIR}/Engine/sfml/
        ${CMAKE_SOURCE_DIR}/Engine/core/
        )
## IMPORTED SHARED LIBRARY NAME
set( SHARED_LIB_NAME
        Jsnp
        SWEngine-Core
        SWEngine-SfmlModule
        )
## IMPORTED SHARED LIBRARY LOCATION
set( SHARED_LIB_LOCATION
        ${CMAKE_SOURCE_DIR}/Engine/libJsnp.so
        ${CMAKE_SOURCE_DIR}/Engine/libSWEngine-Core.so
        ${CMAKE_SOURCE_DIR}/Engine/libSWEngine-SfmlModule.so
        )
## <=====================================>


## GET SOURCES
## <=====================================>
foreach(filePath ${SRC_FOLDERS})
    string(APPEND TMP "${filePath}*.${EXT};")
endforeach()
file(GLOB SRC ${TMP})
## <=====================================>


## OUTPUT
## <=====================================>
## EXECUTABLE
add_executable(${EXEC} ${SRC})

## or SHARED LIB
# add_library(${EXEC} SHARED ${SRC})

## or STATIC LIB
# add_library(${EXEC} STATIC ${SRC})
## <=====================================>


## ADD INCLUDES
## <=====================================>
target_include_directories(${EXEC} PRIVATE ${INC_FOLDERS})
## <=====================================>

## ADD PARAMETER
## <=====================================>
if (UNIX)
    target_compile_options(${EXEC} PRIVATE -g3)
endif (UNIX)
## <=====================================>


## SHARED LIBRARY LINKING
## <=====================================>
list(LENGTH SHARED_LIB_NAME  list_len)
math(EXPR LIST_LEN "${list_len} - 1")

foreach(ctr RANGE ${LIST_LEN})
    list(GET SHARED_LIB_NAME ${ctr} lib)
    list(GET SHARED_LIB_LOCATION ${ctr} loc)
    add_library(${lib} SHARED IMPORTED)
    set_target_properties(${lib} PROPERTIES
            IMPORTED_LOCATION ${loc}
            )
endforeach()
target_link_libraries(${EXEC}
        PUBLIC
                ${SHARED_LIB_NAME}
                -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
        )
## <=====================================>