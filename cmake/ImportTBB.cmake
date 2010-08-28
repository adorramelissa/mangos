#
# Copyright (C) 2005-2010 MaNGOS <http://getmangos.com/>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
#

# Specify tbb lib that was build externally
# add_library(tbb SHARED IMPORTED)
# add_library(tbbmalloc SHARED IMPORTED)
if(WIN32)
  set(LIB_SUFFIX dll)
  if(PLATFORM MATCHES X86)
    set(LIBDIR ia32)
  else()
    set(LIBDIR intel64)
  endif()
#   set_target_properties(tbb PROPERTIES
#     IMPORTED_LOCATION_RELEASE ${CMAKE_SOURCE_DIR}/dep/tbb/build/vsproject/${LIBDIR}/Release/tbb.dll
#     IMPORTED_LOCATION_DEBUG ${CMAKE_SOURCE_DIR}/dep/tbb/build/vsproject/${LIBDIR}/Debug/tbb_debug.dll
#     IMPORTED_IMPLIB_RELEASE ${CMAKE_SOURCE_DIR}/dep/tbb/build/vsproject/${LIBDIR}/Release/tbb.lib
#     IMPORTED_IMPLIB_DEBUG ${CMAKE_SOURCE_DIR}/dep/tbb/build/vsproject/${LIBDIR}/Debug/tbb_debug.lib
#   )
#   set_target_properties(tbbmalloc PROPERTIES
#     IMPORTED_LOCATION_RELEASE ${CMAKE_SOURCE_DIR}/dep/tbb/build/vsproject/${LIBDIR}/Release/tbbmalloc.dll
#     IMPORTED_LOCATION_DEBUG ${CMAKE_SOURCE_DIR}/dep/tbb/build/vsproject/${LIBDIR}/Debug/tbbmalloc_debug.dll
#     IMPORTED_IMPLIB_RELEASE ${CMAKE_SOURCE_DIR}/dep/tbb/build/vsproject/${LIBDIR}/Release/tbbmalloc.lib
#     IMPORTED_IMPLIB_DEBUG ${CMAKE_SOURCE_DIR}/dep/tbb/build/vsproject/${LIBDIR}/Debug/tbbmalloc_debug.lib
#   )
  set(TBB_LIBRARIES_DIR
    ${CMAKE_SOURCE_DIR}/dep/tbb/build/vsproject/${LIBDIR}/Release
    ${CMAKE_SOURCE_DIR}/dep/tbb/build/vsproject/${LIBDIR}/Debug
  )
else()
  if(APPLE)
    set(LIB_SUFFIX dylib)
  else()
    set(LIB_SUFFIX so)
  endif()
#   set_target_properties(tbb PROPERTIES
#     IMPORTED_LOCATION_RELEASE ${CMAKE_SOURCE_DIR}/dep/tbb/build/libs_release/libtbb.${LIB_SUFFIX}
#     IMPORTED_LOCATION_DEBUG ${CMAKE_SOURCE_DIR}/dep/tbb/build/libs_debug/libtbb_debug.${LIB_SUFFIX}
#   )
#   set_target_properties(tbbmalloc PROPERTIES
#     IMPORTED_LOCATION_RELEASE ${CMAKE_SOURCE_DIR}/dep/tbb/build/libs_release/libtbbmalloc.${LIB_SUFFIX}
#     IMPORTED_LOCATION_DEBUG ${CMAKE_SOURCE_DIR}/dep/tbb/build/libs_debug/libtbbmalloc_debug.${LIB_SUFFIX}
#   )
  set(TBB_LIBRARIES_DIR
    ${CMAKE_SOURCE_DIR}/dep/tbb/build/libs_release
    ${CMAKE_SOURCE_DIR}/dep/tbb/build/libs_debug
  )
endif()
# Sadly doesn't work in current version
# add_dependencies(tbb TBB_Project)
# add_dependencies(tbbmalloc TBB_Project)
# set_target_properties(tbb PROPERTIES DEPENDS TBB_Project)
# set_target_properties(tbbmalloc PROPERTIES DEPENDS TBB_Project)

set(TBB_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/dep/tbb/include)
set(TBB_LIBRARIES tbb tbbmalloc)

# Little Hack to remove the link warnings because of not found directories
if(XCODE)
  foreach(DIR ${TBB_LIBRARIES_DIR})
    foreach(CONF ${CMAKE_CONFIGURATION_TYPES})
      file(MAKE_DIRECTORY ${DIR}/${CONF})
    endforeach(CONF)
  endforeach(DIR)
  foreach(CONF ${CMAKE_CONFIGURATION_TYPES})
    set(CONFSTR ${CONFSTR} PATTERN "${CONF}" EXCLUDE)
  endforeach(CONF)
endif()

link_directories(
  ${TBB_LIBRARIES_DIR}
)

foreach(DIR ${TBB_LIBRARIES_DIR})
  install(
    DIRECTORY ${DIR}/ DESTINATION ${LIBS_DIR}
    FILES_MATCHING PATTERN "*.${LIB_SUFFIX}*"
    ${CONFSTR}
  )
endforeach(DIR)
