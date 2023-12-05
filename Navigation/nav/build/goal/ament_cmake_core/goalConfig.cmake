# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_goal_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED goal_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(goal_FOUND FALSE)
  elseif(NOT goal_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(goal_FOUND FALSE)
  endif()
  return()
endif()
set(_goal_CONFIG_INCLUDED TRUE)

# output package information
if(NOT goal_FIND_QUIETLY)
  message(STATUS "Found goal: 0.0.1 (${goal_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'goal' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${goal_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(goal_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${goal_DIR}/${_extra}")
endforeach()
