# This file is part of the SymCC runtime.
#
# The SymCC runtime is free software: you can redistribute it and/or modify it
# under the terms of the GNU Lesser General Public License as published by the
# Free Software Foundation, either version 3 of the License, or (at your option)
# any later version.
#
# The SymCC runtime is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
# FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License
# for more details.
#
# You should have received a copy of the GNU Lesser General Public License along
# with the SymCC runtime. If not, see <https://www.gnu.org/licenses/>.

cmake_minimum_required(VERSION 3.5)
project(SymRuntime)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 \
-Wredundant-decls -Wcast-align \
-Wmissing-include-dirs -Wswitch-default \
-Wextra -Wall -Winvalid-pch -Wredundant-decls -Wformat=2 \
-Wmissing-format-attribute -Wformat-nonliteral")

option(BACKEND "Which backend to use." "TRACING")
option(Z3_TRUST_SYSTEM_VERSION "Use the system-provided Z3 without a version check" OFF)

# Place the final product in the top-level output directory
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# There is list(TRANSFORM ... PREPEND ...), but it's not available before CMake 3.12.
set(SHARED_RUNTIME_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/Config.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/RuntimeCommon.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/LibcWrappers.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Shadow.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/GarbageCollection.cpp)

if (${BACKEND} STREQUAL "QSYM")
  message("Using QSYM backend.")
  add_subdirectory(qsym_backend)
elseif(${BACKEND} STREQUAL "SIMPLE")
  message("Using the simple Z3 backend.")
  add_subdirectory(simple_backend)
elseif(${BACKEND} STREQUAL "TRACING")
  message("Using the tracing backend.")
  add_subdirectory(tracing_backend)
else()
  message(FATAL_ERROR "The backend is set to '${BACKEND}', it must be one of QSYM, SIMPLE, or TRACING.")
endif()
