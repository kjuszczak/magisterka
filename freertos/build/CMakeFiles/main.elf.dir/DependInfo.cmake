
# Consider dependencies only in project.
set(CMAKE_DEPENDS_IN_PROJECT_ONLY OFF)

# The set of languages for which implicit dependencies are needed:
set(CMAKE_DEPENDS_LANGUAGES
  "ASM"
  )
# The set of files for implicit dependencies of each language:
set(CMAKE_DEPENDS_CHECK_ASM
  "/home/kjuszcza/magisterka/freertos/components/CMSIS/Device/ST/STM32F2xx/Source/Templates/gcc/startup_stm32f207xx.s" "/home/kjuszcza/magisterka/freertos/build/CMakeFiles/main.elf.dir/components/CMSIS/Device/ST/STM32F2xx/Source/Templates/gcc/startup_stm32f207xx.s.obj"
  )
set(CMAKE_ASM_COMPILER_ID "GNU")

# Preprocessor definitions for this target.
set(CMAKE_TARGET_DEFINITIONS_ASM
  "HSE_VALUE=8000000"
  "STM32F207xx"
  )

# The include file search paths:
set(CMAKE_ASM_TARGET_INCLUDE_PATH
  "../include"
  "../../board_config/include"
  "../components/FreeRTOS-Kernel/include"
  "../components/FreeRTOS-Kernel/portable/GCC/ARM_CM3"
  "../components/STM32F2xx_HAL_Driver/Inc"
  "../components/CMSIS/Device/ST/STM32F2xx/Include"
  "../components/CMSIS/Core/Include"
  )

# The set of dependency files which are needed:
set(CMAKE_DEPENDS_DEPENDENCY_FILES
  "/home/kjuszcza/magisterka/freertos/components/CMSIS/Device/ST/STM32F2xx/Source/Templates/system_stm32f2xx.c" "CMakeFiles/main.elf.dir/components/CMSIS/Device/ST/STM32F2xx/Source/Templates/system_stm32f2xx.c.obj" "gcc" "CMakeFiles/main.elf.dir/components/CMSIS/Device/ST/STM32F2xx/Source/Templates/system_stm32f2xx.c.obj.d"
  "/home/kjuszcza/magisterka/board_config/src/board_config.c" "CMakeFiles/main.elf.dir/home/kjuszcza/magisterka/board_config/src/board_config.c.obj" "gcc" "CMakeFiles/main.elf.dir/home/kjuszcza/magisterka/board_config/src/board_config.c.obj.d"
  "/home/kjuszcza/magisterka/board_config/src/hal_it.c" "CMakeFiles/main.elf.dir/home/kjuszcza/magisterka/board_config/src/hal_it.c.obj" "gcc" "CMakeFiles/main.elf.dir/home/kjuszcza/magisterka/board_config/src/hal_it.c.obj.d"
  "/home/kjuszcza/magisterka/board_config/src/hal_msp.c" "CMakeFiles/main.elf.dir/home/kjuszcza/magisterka/board_config/src/hal_msp.c.obj" "gcc" "CMakeFiles/main.elf.dir/home/kjuszcza/magisterka/board_config/src/hal_msp.c.obj.d"
  "/home/kjuszcza/magisterka/freertos/src/main.c" "CMakeFiles/main.elf.dir/src/main.c.obj" "gcc" "CMakeFiles/main.elf.dir/src/main.c.obj.d"
  "/home/kjuszcza/magisterka/freertos/src/stm32f2xx_it.c" "CMakeFiles/main.elf.dir/src/stm32f2xx_it.c.obj" "gcc" "CMakeFiles/main.elf.dir/src/stm32f2xx_it.c.obj.d"
  )

# Targets to which this target links.
set(CMAKE_TARGET_LINKED_INFO_FILES
  "/home/kjuszcza/magisterka/freertos/build/CMakeFiles/rtos.dir/DependInfo.cmake"
  "/home/kjuszcza/magisterka/freertos/build/CMakeFiles/hal.dir/DependInfo.cmake"
  )

# Fortran module output directory.
set(CMAKE_Fortran_TARGET_MODULE_DIR "")
