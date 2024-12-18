# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "D:/Projects/New/C++/CMAKE/MyEngine/cmake-build-release/_deps/glm-src")
  file(MAKE_DIRECTORY "D:/Projects/New/C++/CMAKE/MyEngine/cmake-build-release/_deps/glm-src")
endif()
file(MAKE_DIRECTORY
  "D:/Projects/New/C++/CMAKE/MyEngine/cmake-build-release/_deps/glm-build"
  "D:/Projects/New/C++/CMAKE/MyEngine/cmake-build-release/_deps/glm-subbuild/glm-populate-prefix"
  "D:/Projects/New/C++/CMAKE/MyEngine/cmake-build-release/_deps/glm-subbuild/glm-populate-prefix/tmp"
  "D:/Projects/New/C++/CMAKE/MyEngine/cmake-build-release/_deps/glm-subbuild/glm-populate-prefix/src/glm-populate-stamp"
  "D:/Projects/New/C++/CMAKE/MyEngine/cmake-build-release/_deps/glm-subbuild/glm-populate-prefix/src"
  "D:/Projects/New/C++/CMAKE/MyEngine/cmake-build-release/_deps/glm-subbuild/glm-populate-prefix/src/glm-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/Projects/New/C++/CMAKE/MyEngine/cmake-build-release/_deps/glm-subbuild/glm-populate-prefix/src/glm-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "D:/Projects/New/C++/CMAKE/MyEngine/cmake-build-release/_deps/glm-subbuild/glm-populate-prefix/src/glm-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
