# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kjuszcza/magisterka/freertos

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kjuszcza/magisterka/freertos/build

# Include any dependencies generated for this target.
include CMakeFiles/main.elf.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/main.elf.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/main.elf.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.elf.dir/flags.make

CMakeFiles/main.elf.dir/home/kjuszcza/magisterka/board_config/src/board_config.c.obj: CMakeFiles/main.elf.dir/flags.make
CMakeFiles/main.elf.dir/home/kjuszcza/magisterka/board_config/src/board_config.c.obj: /home/kjuszcza/magisterka/board_config/src/board_config.c
CMakeFiles/main.elf.dir/home/kjuszcza/magisterka/board_config/src/board_config.c.obj: CMakeFiles/main.elf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kjuszcza/magisterka/freertos/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/main.elf.dir/home/kjuszcza/magisterka/board_config/src/board_config.c.obj"
	/home/kjuszcza/zephyr-sdk-0.13.2/arm-zephyr-eabi/bin/arm-zephyr-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/main.elf.dir/home/kjuszcza/magisterka/board_config/src/board_config.c.obj -MF CMakeFiles/main.elf.dir/home/kjuszcza/magisterka/board_config/src/board_config.c.obj.d -o CMakeFiles/main.elf.dir/home/kjuszcza/magisterka/board_config/src/board_config.c.obj -c /home/kjuszcza/magisterka/board_config/src/board_config.c

CMakeFiles/main.elf.dir/home/kjuszcza/magisterka/board_config/src/board_config.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.elf.dir/home/kjuszcza/magisterka/board_config/src/board_config.c.i"
	/home/kjuszcza/zephyr-sdk-0.13.2/arm-zephyr-eabi/bin/arm-zephyr-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kjuszcza/magisterka/board_config/src/board_config.c > CMakeFiles/main.elf.dir/home/kjuszcza/magisterka/board_config/src/board_config.c.i

CMakeFiles/main.elf.dir/home/kjuszcza/magisterka/board_config/src/board_config.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.elf.dir/home/kjuszcza/magisterka/board_config/src/board_config.c.s"
	/home/kjuszcza/zephyr-sdk-0.13.2/arm-zephyr-eabi/bin/arm-zephyr-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kjuszcza/magisterka/board_config/src/board_config.c -o CMakeFiles/main.elf.dir/home/kjuszcza/magisterka/board_config/src/board_config.c.s

CMakeFiles/main.elf.dir/src/main.c.obj: CMakeFiles/main.elf.dir/flags.make
CMakeFiles/main.elf.dir/src/main.c.obj: ../src/main.c
CMakeFiles/main.elf.dir/src/main.c.obj: CMakeFiles/main.elf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kjuszcza/magisterka/freertos/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/main.elf.dir/src/main.c.obj"
	/home/kjuszcza/zephyr-sdk-0.13.2/arm-zephyr-eabi/bin/arm-zephyr-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/main.elf.dir/src/main.c.obj -MF CMakeFiles/main.elf.dir/src/main.c.obj.d -o CMakeFiles/main.elf.dir/src/main.c.obj -c /home/kjuszcza/magisterka/freertos/src/main.c

CMakeFiles/main.elf.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.elf.dir/src/main.c.i"
	/home/kjuszcza/zephyr-sdk-0.13.2/arm-zephyr-eabi/bin/arm-zephyr-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kjuszcza/magisterka/freertos/src/main.c > CMakeFiles/main.elf.dir/src/main.c.i

CMakeFiles/main.elf.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.elf.dir/src/main.c.s"
	/home/kjuszcza/zephyr-sdk-0.13.2/arm-zephyr-eabi/bin/arm-zephyr-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kjuszcza/magisterka/freertos/src/main.c -o CMakeFiles/main.elf.dir/src/main.c.s

CMakeFiles/main.elf.dir/components/CMSIS/Device/ST/STM32F2xx/Source/Templates/gcc/startup_stm32f207xx.s.obj: CMakeFiles/main.elf.dir/flags.make
CMakeFiles/main.elf.dir/components/CMSIS/Device/ST/STM32F2xx/Source/Templates/gcc/startup_stm32f207xx.s.obj: ../components/CMSIS/Device/ST/STM32F2xx/Source/Templates/gcc/startup_stm32f207xx.s
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kjuszcza/magisterka/freertos/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building ASM object CMakeFiles/main.elf.dir/components/CMSIS/Device/ST/STM32F2xx/Source/Templates/gcc/startup_stm32f207xx.s.obj"
	/home/kjuszcza/zephyr-sdk-0.13.2/arm-zephyr-eabi/bin/arm-zephyr-eabi-gcc $(ASM_DEFINES) $(ASM_INCLUDES) $(ASM_FLAGS) -o CMakeFiles/main.elf.dir/components/CMSIS/Device/ST/STM32F2xx/Source/Templates/gcc/startup_stm32f207xx.s.obj -c /home/kjuszcza/magisterka/freertos/components/CMSIS/Device/ST/STM32F2xx/Source/Templates/gcc/startup_stm32f207xx.s

CMakeFiles/main.elf.dir/components/CMSIS/Device/ST/STM32F2xx/Source/Templates/gcc/startup_stm32f207xx.s.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing ASM source to CMakeFiles/main.elf.dir/components/CMSIS/Device/ST/STM32F2xx/Source/Templates/gcc/startup_stm32f207xx.s.i"
	/home/kjuszcza/zephyr-sdk-0.13.2/arm-zephyr-eabi/bin/arm-zephyr-eabi-gcc $(ASM_DEFINES) $(ASM_INCLUDES) $(ASM_FLAGS) -E /home/kjuszcza/magisterka/freertos/components/CMSIS/Device/ST/STM32F2xx/Source/Templates/gcc/startup_stm32f207xx.s > CMakeFiles/main.elf.dir/components/CMSIS/Device/ST/STM32F2xx/Source/Templates/gcc/startup_stm32f207xx.s.i

CMakeFiles/main.elf.dir/components/CMSIS/Device/ST/STM32F2xx/Source/Templates/gcc/startup_stm32f207xx.s.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling ASM source to assembly CMakeFiles/main.elf.dir/components/CMSIS/Device/ST/STM32F2xx/Source/Templates/gcc/startup_stm32f207xx.s.s"
	/home/kjuszcza/zephyr-sdk-0.13.2/arm-zephyr-eabi/bin/arm-zephyr-eabi-gcc $(ASM_DEFINES) $(ASM_INCLUDES) $(ASM_FLAGS) -S /home/kjuszcza/magisterka/freertos/components/CMSIS/Device/ST/STM32F2xx/Source/Templates/gcc/startup_stm32f207xx.s -o CMakeFiles/main.elf.dir/components/CMSIS/Device/ST/STM32F2xx/Source/Templates/gcc/startup_stm32f207xx.s.s

CMakeFiles/main.elf.dir/components/CMSIS/Device/ST/STM32F2xx/Source/Templates/system_stm32f2xx.c.obj: CMakeFiles/main.elf.dir/flags.make
CMakeFiles/main.elf.dir/components/CMSIS/Device/ST/STM32F2xx/Source/Templates/system_stm32f2xx.c.obj: ../components/CMSIS/Device/ST/STM32F2xx/Source/Templates/system_stm32f2xx.c
CMakeFiles/main.elf.dir/components/CMSIS/Device/ST/STM32F2xx/Source/Templates/system_stm32f2xx.c.obj: CMakeFiles/main.elf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kjuszcza/magisterka/freertos/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/main.elf.dir/components/CMSIS/Device/ST/STM32F2xx/Source/Templates/system_stm32f2xx.c.obj"
	/home/kjuszcza/zephyr-sdk-0.13.2/arm-zephyr-eabi/bin/arm-zephyr-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/main.elf.dir/components/CMSIS/Device/ST/STM32F2xx/Source/Templates/system_stm32f2xx.c.obj -MF CMakeFiles/main.elf.dir/components/CMSIS/Device/ST/STM32F2xx/Source/Templates/system_stm32f2xx.c.obj.d -o CMakeFiles/main.elf.dir/components/CMSIS/Device/ST/STM32F2xx/Source/Templates/system_stm32f2xx.c.obj -c /home/kjuszcza/magisterka/freertos/components/CMSIS/Device/ST/STM32F2xx/Source/Templates/system_stm32f2xx.c

CMakeFiles/main.elf.dir/components/CMSIS/Device/ST/STM32F2xx/Source/Templates/system_stm32f2xx.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.elf.dir/components/CMSIS/Device/ST/STM32F2xx/Source/Templates/system_stm32f2xx.c.i"
	/home/kjuszcza/zephyr-sdk-0.13.2/arm-zephyr-eabi/bin/arm-zephyr-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kjuszcza/magisterka/freertos/components/CMSIS/Device/ST/STM32F2xx/Source/Templates/system_stm32f2xx.c > CMakeFiles/main.elf.dir/components/CMSIS/Device/ST/STM32F2xx/Source/Templates/system_stm32f2xx.c.i

CMakeFiles/main.elf.dir/components/CMSIS/Device/ST/STM32F2xx/Source/Templates/system_stm32f2xx.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.elf.dir/components/CMSIS/Device/ST/STM32F2xx/Source/Templates/system_stm32f2xx.c.s"
	/home/kjuszcza/zephyr-sdk-0.13.2/arm-zephyr-eabi/bin/arm-zephyr-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kjuszcza/magisterka/freertos/components/CMSIS/Device/ST/STM32F2xx/Source/Templates/system_stm32f2xx.c -o CMakeFiles/main.elf.dir/components/CMSIS/Device/ST/STM32F2xx/Source/Templates/system_stm32f2xx.c.s

# Object files for target main.elf
main_elf_OBJECTS = \
"CMakeFiles/main.elf.dir/home/kjuszcza/magisterka/board_config/src/board_config.c.obj" \
"CMakeFiles/main.elf.dir/src/main.c.obj" \
"CMakeFiles/main.elf.dir/components/CMSIS/Device/ST/STM32F2xx/Source/Templates/gcc/startup_stm32f207xx.s.obj" \
"CMakeFiles/main.elf.dir/components/CMSIS/Device/ST/STM32F2xx/Source/Templates/system_stm32f2xx.c.obj"

# External object files for target main.elf
main_elf_EXTERNAL_OBJECTS =

main.elf: CMakeFiles/main.elf.dir/home/kjuszcza/magisterka/board_config/src/board_config.c.obj
main.elf: CMakeFiles/main.elf.dir/src/main.c.obj
main.elf: CMakeFiles/main.elf.dir/components/CMSIS/Device/ST/STM32F2xx/Source/Templates/gcc/startup_stm32f207xx.s.obj
main.elf: CMakeFiles/main.elf.dir/components/CMSIS/Device/ST/STM32F2xx/Source/Templates/system_stm32f2xx.c.obj
main.elf: CMakeFiles/main.elf.dir/build.make
main.elf: librtos.a
main.elf: libhal.a
main.elf: CMakeFiles/main.elf.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kjuszcza/magisterka/freertos/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable main.elf"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.elf.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.elf.dir/build: main.elf
.PHONY : CMakeFiles/main.elf.dir/build

CMakeFiles/main.elf.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.elf.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.elf.dir/clean

CMakeFiles/main.elf.dir/depend:
	cd /home/kjuszcza/magisterka/freertos/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kjuszcza/magisterka/freertos /home/kjuszcza/magisterka/freertos /home/kjuszcza/magisterka/freertos/build /home/kjuszcza/magisterka/freertos/build /home/kjuszcza/magisterka/freertos/build/CMakeFiles/main.elf.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main.elf.dir/depend

