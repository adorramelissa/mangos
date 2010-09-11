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

file(GLOB_RECURSE realmd_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp *.h)

include_directories(
  ${CMAKE_SOURCE_DIR}/src/shared
  ${CMAKE_SOURCE_DIR}/src/framework
  ${CMAKE_BINARY_DIR}
  ${CMAKE_BINARY_DIR}/src/shared
  ${MYSQL_INCLUDE_DIR}
  ${ACE_INCLUDE_DIR}
)

add_executable(realmd
  ${realmd_SRCS}
)

add_dependencies(realmd revision.h)
if(NOT ACE_USE_EXTERNAL)
  add_dependencies(realmd ACE_Project)
# add_dependencies(realmd ace)
endif()

target_link_libraries(realmd
  shared
  framework
  ${ACE_LIBRARIES}
)

if(WIN32)
  target_link_libraries(realmd
    optimized ${MYSQL_LIBRARY}
    optimized ${OPENSSL_LIBRARIES}
    debug ${MYSQL_DEBUG_LIBRARY}
    debug ${OPENSSL_DEBUG_LIBRARIES}
  )
  if(PLATFORM MATCHES X86)
    target_link_libraries(realmd
      debug ${WIN_DEBUGLIBS}
    )
  endif()
endif()

if(UNIX)
  target_link_libraries(realmd
    ${MYSQL_LIBRARY}
    ${OPENSSL_LIBRARIES}
  )
endif()

if(APPLE)
  target_link_libraries(realmd
    ${OSX_LIBS}
  )
endif()

set(realmd_LINK_FLAGS "")

if(UNIX)
  set(realmd_LINK_FLAGS "-pthread ${realmd_LINK_FLAGS}")
endif()

if(APPLE)
  set(realmd_LINK_FLAGS "-framework Carbon ${realmd_LINK_FLAGS}")
endif()

set_target_properties(realmd PROPERTIES LINK_FLAGS
  "${realmd_LINK_FLAGS}"
)

install(TARGETS realmd DESTINATION ${BIN_DIR})
install(FILES realmd.conf.dist.in DESTINATION ${CONF_DIR} RENAME realmd.conf.dist)
