cmake_minimum_required( VERSION 3.2 )

project( akbi VERSION 0.1.0 LANGUAGES C )
set( CMAKE_C_STANDARD          11 )
set( CMAKE_C_STANDARD_REQUIRED ON )
set( CMAKE_C_EXTENSIONS        OFF )

if( WIN32 )
    set( CMAKE_C_VISIBILITY_PRESET hidden )
    set( CMAKE_VISIBILITY_INLINES_HIDDEN ON )
endif()

enable_testing()

set( LIB_NAME ${PROJECT_NAME} )

# where to look first for modules, before ${CMAKE_ROOT}/Modules/ is checked
set( ROOT ${CMAKE_CURRENT_SOURCE_DIR}/../.. )
set( APP_DIR ${ROOT}/app )

include( FetchContent )
include( ${CMAKE_CURRENT_SOURCE_DIR}/Custom.cmake )
include( ${CMAKE_CURRENT_SOURCE_DIR}/FileLists.cmake )

################################################################################
# fetch
################################################################################

fetchcontent_declare(
    clingo
    GIT_REPOSITORY "https://github.com/aiq/clingo"
    GIT_TAG "main"
    SOURCE_SUBDIR "mk/cmake"
)

fetchcontent_makeavailable( clingo )

fetchcontent_declare(
   raylib
   GIT_REPOSITORY https://github.com/raysan5/raylib.git
   GIT_TAG master
)
fetchcontent_makeavailable( raylib )

################################################################################
# build - make
################################################################################

set( APP_INC_DIRS ${INC_DIR} ${APP_DIR} )
if( WIN32 )
   set( APP_LINK_LIBS clingo raylib )
else()
   set( APP_LINK_LIBS m clingo raylib )
endif()
add_apps( "${APP_FILES}" "${APP_INC_DIRS}" "${APP_LINK_LIBS}" )
