## CMAKE VAR

## <================JSON=================>
file(READ ${CMAKE_CURRENT_SOURCE_DIR}/Engine/config/compilation.json MY_JSON_STRING)

string(JSON NAME GET ${MY_JSON_STRING} Setting project_name)
string(JSON EXEC_NAME GET ${MY_JSON_STRING} Setting exec_name)
string(JSON COMPILE_TYPE GET ${MY_JSON_STRING} Setting compile_type)
string(JSON MODULE GET ${MY_JSON_STRING} Setting module)
string(JSON BUILD_PATH GET ${MY_JSON_STRING} Setting build_path)
string(JSON ASSET_PATH GET ${MY_JSON_STRING} Setting asset_path)
string(JSON MODULE_NAME GET ${MY_JSON_STRING} ${MODULE} name)
string(JSON MODULE_PATH GET ${MY_JSON_STRING} ${MODULE} path)
string(JSON MODULE_INCLUDE GET ${MY_JSON_STRING} ${MODULE} include)
string(JSON MODULE_DEPENDENCE GET ${MY_JSON_STRING} ${MODULE} dependence)

string(JSON MODULE_DEPENDENCE_LEN LENGTH ${MODULE_DEPENDENCE} name)
string(JSON MODULE_DEPENDENCE_LIB_LEN LENGTH ${MODULE_DEPENDENCE} library)

math(EXPR MODULE_DEPENDENCE_LEN "${MODULE_DEPENDENCE_LEN} - 1")
math(EXPR MODULE_DEPENDENCE_LIB_LEN "${MODULE_DEPENDENCE_LIB_LEN} - 1")

foreach(IDX RANGE ${MODULE_DEPENDENCE_LEN})
    string(JSON TMP_DEP_NAME GET ${MODULE_DEPENDENCE} name ${IDX})
    list(APPEND MODULE_DEPENDENCE_NAME ${TMP_DEP_NAME})
endforeach()

foreach(IDX RANGE ${MODULE_DEPENDENCE_LIB_LEN})
    string(JSON TMP_DEP_LIB GET ${MODULE_DEPENDENCE} library ${IDX})
    unset(FINAL)
    string(APPEND FINAL "${CMAKE_SOURCE_DIR}/${TMP_DEP_LIB}")
    list(APPEND MODULE_DEPENDENCE_LIBRARY ${FINAL})
endforeach()

file(COPY ${CMAKE_SOURCE_DIR}/${ASSET_PATH}/ DESTINATION ${CMAKE_SOURCE_DIR}/${BUILD_PATH}/out/assets)
file(COPY ./Engine/config/ DESTINATION ${CMAKE_SOURCE_DIR}/${BUILD_PATH}/out/Engine/config)

message("Project name: " ${NAME})
message("Executable name: " ${EXEC_NAME})
message("Compilation type: " ${COMPILE_TYPE})
message("Build path: " ${BUILD_PATH})
message("Asset path: " ${ASSET_PATH})
message("Module name: " ${MODULE_NAME})
message("Module path: " ${MODULE_PATH})
foreach(IDX RANGE ${MODULE_DEPENDENCE_LEN})
    list(GET MODULE_DEPENDENCE_NAME ${IDX} OUT)
    message("Module dependence name[ ${IDX} ] : " ${OUT})
endforeach()
message("\n")
foreach(IDX RANGE ${MODULE_DEPENDENCE_LEN})
    list(GET MODULE_DEPENDENCE_LIBRARY ${IDX} OUT)
    message("Module dependence path[ ${IDX} ] : " ${OUT})
endforeach()
message("\n")

## <=====================================>

## <=====================================>
cmake_minimum_required( VERSION 3.20 )
set( CMAKE_BUILD_TYPE ${COMPILE_TYPE} ) # Release / RelWithDebInfo / Debug
set( CMAKE_CXX_STANDARD 20 )
set( CMAKE_CXX_STANDARD_REQUIRED True )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/${BUILD_PATH}/out )
set( CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")
## <=====================================>


## PROJECT VAR
## <=====================================>
project( ${NAME}
        VERSION
        1.0
        LANGUAGES
        CXX
        )
set( EXEC ${EXEC_NAME} )
set( EXT cpp )

## SOURCE FOLDERS
set( SRC_FOLDERS
        ${CMAKE_SOURCE_DIR}/Project/sources/
        )
## INCLUDE FOLDERS
set( INC_FOLDERS
        ${CMAKE_SOURCE_DIR}/Project/includes/
        ${CMAKE_SOURCE_DIR}/Engine/
        ${CMAKE_SOURCE_DIR}/Engine/core/
        ${CMAKE_SOURCE_DIR}/${MODULE_INCLUDE}
        )

## IMPORTED SHARED LIBRARY NAME
set( SHARED_LIB_NAME
        Jsnp
        SWEngine-Core
        yaml-cpp
        ${MODULE_NAME}
        ${MODULE_DEPENDENCE_NAME}
        )
## IMPORTED SHARED LIBRARY LOCATION
set( SHARED_LIB_LOCATION
        ${CMAKE_SOURCE_DIR}/Engine/libJsnp.so
        ${CMAKE_SOURCE_DIR}/Engine/libSWEngine-Core.so
        ${CMAKE_SOURCE_DIR}/Engine/libyaml-cpp.so
        ${CMAKE_SOURCE_DIR}/${MODULE_PATH}
        ${MODULE_DEPENDENCE_LIBRARY}
        )
## <=====================================>


## GET SOURCES
## <=====================================>
foreach(filePath ${SRC_FOLDERS})
    string(APPEND TMP "${filePath}*.${EXT};")
endforeach()
file(GLOB_RECURSE SRC ${TMP})
## <=====================================>


## OUTPUT
## <=====================================>
## EXECUTABLE
add_executable(${EXEC} ${SRC})
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
        )
## <=====================================>