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

file(GLOB_RECURSE mangos_worldd_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp *.h)

include_directories(
  ${CMAKE_SOURCE_DIR}/src/shared
  ${CMAKE_SOURCE_DIR}/dep/include/gsoap
  ${CMAKE_SOURCE_DIR}/src/framework
  ${CMAKE_SOURCE_DIR}/src/game
  ${CMAKE_BINARY_DIR}
  ${CMAKE_BINARY_DIR}/src/shared
  ${ACE_INCLUDE_DIR}
  ${MYSQL_INCLUDE_DIR}
  ${OPENSSL_INCLUDE_DIR}
)

add_executable(mangos_worldd
  ${mangos_worldd_SRCS}
)

add_dependencies(mangos_worldd revision.h)
if(NOT ACE_USE_EXTERNAL)
  add_dependencies(mangos_worldd ACE_Project)
# add_dependencies(mangos_worldd ace)
endif()

target_link_libraries(mangos_worldd
  game
  shared
  framework
  g3dlite
  gsoap
  ${ACE_LIBRARIES}
)

if(WIN32)
  target_link_libraries(mangos_worldd
    zlib
    optimized ${MYSQL_LIBRARY}
    optimized ${OPENSSL_LIBRARIES}
    debug ${MYSQL_DEBUG_LIBRARY}
    debug ${OPENSSL_DEBUG_LIBRARIES}
  )
  if(PLATFORM MATCHES X86)
    target_link_libraries(mangos_worldd
      debug ${WIN_DEBUGLIBS}
    )    
  endif()
endif()

if(UNIX)
  target_link_libraries(mangos_worldd
    ${MYSQL_LIBRARY}
    ${OPENSSL_LIBRARIES}
    ${ZLIB_LIBRARIES}
  )
endif()

if(APPLE)
  target_link_libraries(mangos_worldd
    ${OSX_LIBS}
  )
endif()

set(mangos_worldd_LINK_FLAGS "")

if(UNIX)
  set(mangos_worldd_LINK_FLAGS "-pthread ${mangos_worldd_LINK_FLAGS}")
endif()

if(APPLE)
  set(mangos_worldd_LINK_FLAGS "-framework Carbon ${mangos_worldd_LINK_FLAGS}")
endif()

set_target_properties(mangos_worldd PROPERTIES LINK_FLAGS
  "${mangos_worldd_LINK_FLAGS}"
)

install(TARGETS mangos_worldd DESTINATION ${BIN_DIR})
install(FILES run-mangosd DESTINATION ${BIN_DIR})
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/mangosd.conf.dist.in ${CMAKE_CURRENT_BINARY_DIR}/mangosd.conf.dist)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/mangosd.conf.dist DESTINATION ${CONF_DIR})
