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

file(GLOB_RECURSE mangosscript_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp *.h)

include_directories(
  ${CMAKE_SOURCE_DIR}/src/shared
  ${CMAKE_SOURCE_DIR}/src/framework
  ${ACE_INCLUDE_DIR}
  ${MYSQL_INCLUDE_DIR}
)

add_library(mangosscript SHARED
  ${mangosscript_SRCS}
)

add_dependencies(mangosscript revision.h)
if(NOT ACE_USE_EXTERNAL)
  add_dependencies(mangosscript ACE_Project)
# add_dependencies(mangosscript ace)
endif()

target_link_libraries(mangosscript
  ${ZLIB_LIBRARIES}
  ${ACE_LIBRARIES}
)

if(WIN32)
  target_link_libraries(mangosscript
    mangosd # FIXME: could this be done for unix? because unix won't generate exe.libs
  )
  if(WIN32 AND PLATFORM MATCHES X86)
    target_link_libraries(mangosscript
      debug ${WIN_DEBUGLIBS}
    )
  endif()
endif()

if(APPLE)
  target_link_libraries(mangosscript
    ${OSX_LIBS}
  )
endif()

set(mangosscript_LINK_FLAGS "")
if(UNIX)
  set(mangosscript_LINK_FLAGS "-pthread ${mangosscript_LINK_FLAGS}")
endif()
if(APPLE)
  set(mangosscript_LINK_FLAGS "-framework Carbon ${mangosscript_LINK_FLAGS}")
  # Needed for the linking because of the missing symbols
  set(mangosscript_LINK_FLAGS "-Wl,-undefined -Wl,dynamic_lookup ${mangosscript_LINK_FLAGS}")
endif()

set_target_properties(mangosscript PROPERTIES LINK_FLAGS
  "${mangosscript_LINK_FLAGS}"
)

# LIBRARY = dyld / so, RUNTIME = dll
install(TARGETS mangosscript
  LIBRARY DESTINATION ${LIBS_DIR}
  RUNTIME DESTINATION ${LIBS_DIR}
)

