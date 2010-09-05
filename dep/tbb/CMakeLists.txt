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

include(ExternalProject)

if(WIN32 AND MSVC)
  ExternalProject_Add(TBB_Project
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}
    BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
  )
  ExternalProject_Add_Step(TBB_Project TBB_Upgrade
    COMMAND ${CMAKE_BUILD_TOOL} <SOURCE_DIR>\\build\\vsproject\\makefile.sln /upgrade
  )
  ExternalProject_Add_Step(TBB_Project TBB_Build
    DEPENDEES TBB_Upgrade
    COMMAND ${CMAKE_BUILD_TOOL} <SOURCE_DIR>\\build\\vsproject\\makefile.sln /build Debug
    COMMAND ${CMAKE_BUILD_TOOL} <SOURCE_DIR>\\build\\vsproject\\makefile.sln /build Release
  )
elseif(UNIX)
  ExternalProject_Add(TBB_Project
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}
    BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}
    CONFIGURE_COMMAND ""
    BUILD_COMMAND make -j2 -C <SOURCE_DIR> # export arch="ia32" && 
    INSTALL_COMMAND ""
  )
else()
  message(FATAL_ERROR
    "This script doesn't support your system configuration to compile/install TBB."
  )
endif()
