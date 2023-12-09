# CMakeList.txt: CMake-Projekt für "AdventOfCode_2023". Schließen Sie die Quelle ein, und definieren Sie
# projektspezifische Logik hier.
#

# Fügen Sie der ausführbaren Datei dieses Projekts eine Quelle hinzu.
add_executable (AdventOfCode_2023 "AdventOfCode_2023.cpp" "AdventOfCode_2023.h" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET AdventOfCode_2023 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Fügen Sie bei Bedarf Tests hinzu, und installieren Sie Ziele.
