# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/archiejames/Desktop/cardgame

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/archiejames/Desktop/cardgame/build

# Include any dependencies generated for this target.
include CMakeFiles/Card_Game.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Card_Game.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Card_Game.dir/flags.make

CMakeFiles/Card_Game.dir/src/animations/animation_manager.cpp.o: CMakeFiles/Card_Game.dir/flags.make
CMakeFiles/Card_Game.dir/src/animations/animation_manager.cpp.o: ../src/animations/animation_manager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/archiejames/Desktop/cardgame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Card_Game.dir/src/animations/animation_manager.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Card_Game.dir/src/animations/animation_manager.cpp.o -c /Users/archiejames/Desktop/cardgame/src/animations/animation_manager.cpp

CMakeFiles/Card_Game.dir/src/animations/animation_manager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Card_Game.dir/src/animations/animation_manager.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/archiejames/Desktop/cardgame/src/animations/animation_manager.cpp > CMakeFiles/Card_Game.dir/src/animations/animation_manager.cpp.i

CMakeFiles/Card_Game.dir/src/animations/animation_manager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Card_Game.dir/src/animations/animation_manager.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/archiejames/Desktop/cardgame/src/animations/animation_manager.cpp -o CMakeFiles/Card_Game.dir/src/animations/animation_manager.cpp.s

CMakeFiles/Card_Game.dir/src/main.cpp.o: CMakeFiles/Card_Game.dir/flags.make
CMakeFiles/Card_Game.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/archiejames/Desktop/cardgame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Card_Game.dir/src/main.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Card_Game.dir/src/main.cpp.o -c /Users/archiejames/Desktop/cardgame/src/main.cpp

CMakeFiles/Card_Game.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Card_Game.dir/src/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/archiejames/Desktop/cardgame/src/main.cpp > CMakeFiles/Card_Game.dir/src/main.cpp.i

CMakeFiles/Card_Game.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Card_Game.dir/src/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/archiejames/Desktop/cardgame/src/main.cpp -o CMakeFiles/Card_Game.dir/src/main.cpp.s

CMakeFiles/Card_Game.dir/src/sound.cpp.o: CMakeFiles/Card_Game.dir/flags.make
CMakeFiles/Card_Game.dir/src/sound.cpp.o: ../src/sound.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/archiejames/Desktop/cardgame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Card_Game.dir/src/sound.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Card_Game.dir/src/sound.cpp.o -c /Users/archiejames/Desktop/cardgame/src/sound.cpp

CMakeFiles/Card_Game.dir/src/sound.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Card_Game.dir/src/sound.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/archiejames/Desktop/cardgame/src/sound.cpp > CMakeFiles/Card_Game.dir/src/sound.cpp.i

CMakeFiles/Card_Game.dir/src/sound.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Card_Game.dir/src/sound.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/archiejames/Desktop/cardgame/src/sound.cpp -o CMakeFiles/Card_Game.dir/src/sound.cpp.s

CMakeFiles/Card_Game.dir/src/sprite.cpp.o: CMakeFiles/Card_Game.dir/flags.make
CMakeFiles/Card_Game.dir/src/sprite.cpp.o: ../src/sprite.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/archiejames/Desktop/cardgame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Card_Game.dir/src/sprite.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Card_Game.dir/src/sprite.cpp.o -c /Users/archiejames/Desktop/cardgame/src/sprite.cpp

CMakeFiles/Card_Game.dir/src/sprite.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Card_Game.dir/src/sprite.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/archiejames/Desktop/cardgame/src/sprite.cpp > CMakeFiles/Card_Game.dir/src/sprite.cpp.i

CMakeFiles/Card_Game.dir/src/sprite.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Card_Game.dir/src/sprite.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/archiejames/Desktop/cardgame/src/sprite.cpp -o CMakeFiles/Card_Game.dir/src/sprite.cpp.s

CMakeFiles/Card_Game.dir/src/structures.cpp.o: CMakeFiles/Card_Game.dir/flags.make
CMakeFiles/Card_Game.dir/src/structures.cpp.o: ../src/structures.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/archiejames/Desktop/cardgame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Card_Game.dir/src/structures.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Card_Game.dir/src/structures.cpp.o -c /Users/archiejames/Desktop/cardgame/src/structures.cpp

CMakeFiles/Card_Game.dir/src/structures.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Card_Game.dir/src/structures.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/archiejames/Desktop/cardgame/src/structures.cpp > CMakeFiles/Card_Game.dir/src/structures.cpp.i

CMakeFiles/Card_Game.dir/src/structures.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Card_Game.dir/src/structures.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/archiejames/Desktop/cardgame/src/structures.cpp -o CMakeFiles/Card_Game.dir/src/structures.cpp.s

CMakeFiles/Card_Game.dir/src/texture_loader.cpp.o: CMakeFiles/Card_Game.dir/flags.make
CMakeFiles/Card_Game.dir/src/texture_loader.cpp.o: ../src/texture_loader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/archiejames/Desktop/cardgame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Card_Game.dir/src/texture_loader.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Card_Game.dir/src/texture_loader.cpp.o -c /Users/archiejames/Desktop/cardgame/src/texture_loader.cpp

CMakeFiles/Card_Game.dir/src/texture_loader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Card_Game.dir/src/texture_loader.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/archiejames/Desktop/cardgame/src/texture_loader.cpp > CMakeFiles/Card_Game.dir/src/texture_loader.cpp.i

CMakeFiles/Card_Game.dir/src/texture_loader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Card_Game.dir/src/texture_loader.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/archiejames/Desktop/cardgame/src/texture_loader.cpp -o CMakeFiles/Card_Game.dir/src/texture_loader.cpp.s

CMakeFiles/Card_Game.dir/src/third_parties/glad.c.o: CMakeFiles/Card_Game.dir/flags.make
CMakeFiles/Card_Game.dir/src/third_parties/glad.c.o: ../src/third_parties/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/archiejames/Desktop/cardgame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/Card_Game.dir/src/third_parties/glad.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Card_Game.dir/src/third_parties/glad.c.o -c /Users/archiejames/Desktop/cardgame/src/third_parties/glad.c

CMakeFiles/Card_Game.dir/src/third_parties/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Card_Game.dir/src/third_parties/glad.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/archiejames/Desktop/cardgame/src/third_parties/glad.c > CMakeFiles/Card_Game.dir/src/third_parties/glad.c.i

CMakeFiles/Card_Game.dir/src/third_parties/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Card_Game.dir/src/third_parties/glad.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/archiejames/Desktop/cardgame/src/third_parties/glad.c -o CMakeFiles/Card_Game.dir/src/third_parties/glad.c.s

# Object files for target Card_Game
Card_Game_OBJECTS = \
"CMakeFiles/Card_Game.dir/src/animations/animation_manager.cpp.o" \
"CMakeFiles/Card_Game.dir/src/main.cpp.o" \
"CMakeFiles/Card_Game.dir/src/sound.cpp.o" \
"CMakeFiles/Card_Game.dir/src/sprite.cpp.o" \
"CMakeFiles/Card_Game.dir/src/structures.cpp.o" \
"CMakeFiles/Card_Game.dir/src/texture_loader.cpp.o" \
"CMakeFiles/Card_Game.dir/src/third_parties/glad.c.o"

# External object files for target Card_Game
Card_Game_EXTERNAL_OBJECTS =

Card_Game: CMakeFiles/Card_Game.dir/src/animations/animation_manager.cpp.o
Card_Game: CMakeFiles/Card_Game.dir/src/main.cpp.o
Card_Game: CMakeFiles/Card_Game.dir/src/sound.cpp.o
Card_Game: CMakeFiles/Card_Game.dir/src/sprite.cpp.o
Card_Game: CMakeFiles/Card_Game.dir/src/structures.cpp.o
Card_Game: CMakeFiles/Card_Game.dir/src/texture_loader.cpp.o
Card_Game: CMakeFiles/Card_Game.dir/src/third_parties/glad.c.o
Card_Game: CMakeFiles/Card_Game.dir/build.make
Card_Game: /Library/Developer/CommandLineTools/SDKs/MacOSX11.1.sdk/System/Library/Frameworks/OpenGL.framework/OpenGL.tbd
Card_Game: /usr/local/lib/libglfw.3.3.dylib
Card_Game: ../lib/libikpMP3.dylib
Card_Game: ../lib/libirrklang.dylib
Card_Game: CMakeFiles/Card_Game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/archiejames/Desktop/cardgame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable Card_Game"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Card_Game.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Card_Game.dir/build: Card_Game

.PHONY : CMakeFiles/Card_Game.dir/build

CMakeFiles/Card_Game.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Card_Game.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Card_Game.dir/clean

CMakeFiles/Card_Game.dir/depend:
	cd /Users/archiejames/Desktop/cardgame/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/archiejames/Desktop/cardgame /Users/archiejames/Desktop/cardgame /Users/archiejames/Desktop/cardgame/build /Users/archiejames/Desktop/cardgame/build /Users/archiejames/Desktop/cardgame/build/CMakeFiles/Card_Game.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Card_Game.dir/depend

