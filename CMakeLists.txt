cmake_minimum_required(VERSION 3.11..3.31)
project(stb-cmake-wrapper
  VERSION 0.2.0
  DESCRIPTION "CMake wrapper for stb libraries"
  LANGUAGES C
)

function(add_stb_library)
  set(oneValueArgs NAME EXT)
  set(multiValueArgs)

  cmake_parse_arguments(
    PARSE_ARGV 0 arg
    "${options}"
    "${oneValueArgs}"
    "${multiValueArgs}"
  )

  if (NOT DEFINED arg_NAME)
    message(FATAL_ERROR "NAME argument is required")
  endif()

  if (NOT DEFINED arg_EXT)
    set(arg_EXT "h")
  endif()

  set(target_name stb-${arg_NAME})
  string(TOUPPER ${arg_NAME} upper_NAME)

  add_library(
    ${target_name}
    main.c
  )
  target_include_directories(
    ${target_name}
    PUBLIC
      stb
  )
  target_compile_definitions(
    ${target_name}
    PRIVATE
      STB_${upper_NAME}_IMPLEMENTATION
      STB_CMAKE_WRAPPER_LIBRARY_INCLUDE="stb_${arg_NAME}.${arg_EXT}"
  )
  add_library(stb::${arg_NAME} ALIAS stb-${arg_NAME})

  if (MSVC)
    # Suppress known warnings for MSVC (W4 has too many to bother with)
    # This, as of April 2025, compiles with no warnings at all
    target_compile_options(${target_name} PRIVATE /W3 /WX /permissive- /wd4244)
    target_compile_definitions(${target_name} PRIVATE _CRT_SECURE_NO_WARNINGS)
  else()
    # There are a LOT of warnings with gcc/clang, so just disable them all...
    # We _trust_ stb, right?
    target_compile_options(${target_name} PRIVATE -w -Wno-incompatible-function-pointer-types)
  endif()

  target_compile_features(${target_name} PRIVATE c_std_11)
endfunction()

set(libraries

  hexwave
  image
  truetype
  image_write # The library is called image_writer but the header file is called image_write
  image_resize2
  rect_pack
  perlin
  ds
  sprintf
  # textedit # Too many definitions needed so leave it out for now
  # voxel_render # "Must defined STBVOX_CONFIG_MODE to select the mode"
  dxt
  easy_font
  # tilemap_editor # 'STBTE_DRAW_RECT' undefined;
  herringbone_wang_tile
  c_lexer
  divide
  # connected_components # "You must define STBCC_GRID_COUNT_X_LOG2 and STBCC_GRID_COUNT_Y_LOG2 to define the max grid supported."
  leakcheck
  include
)

foreach(library ${libraries})
  message(STATUS "Adding stb library: ${library}")
  add_stb_library(NAME ${library})
endforeach()
add_stb_library(NAME vorbis EXT "c")
