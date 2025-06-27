# The following variables contains the files used by the different stages of the build process.
set(GAME_CAT_R4_VSC_MPLAB_default_XC32_FILE_TYPE_assemble)
set_source_files_properties(${GAME_CAT_R4_VSC_MPLAB_default_XC32_FILE_TYPE_assemble} PROPERTIES LANGUAGE ASM)
set(GAME_CAT_R4_VSC_MPLAB_default_XC32_FILE_TYPE_assembleWithPreprocess)
set_source_files_properties(${GAME_CAT_R4_VSC_MPLAB_default_XC32_FILE_TYPE_assembleWithPreprocess} PROPERTIES LANGUAGE ASM)
set(GAME_CAT_R4_VSC_MPLAB_default_XC32_FILE_TYPE_compile
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_CONTROL_HAL/Control_HAL_23K256.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_CONTROL_HAL/Control_HAL_24CSM01.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_CONTROL_HAL/Control_HAL_JOYSTICK.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_CONTROL_HAL/Control_HAL_MCP2518FD.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_CONTROL_HAL/Control_HAL_SST25VF016.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_DRIVERS_HAL/Driver_SAMD_ADC.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_DRIVERS_HAL/Driver_SAMD_GCLK.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_DRIVERS_HAL/Driver_SAMD_PM.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_DRIVERS_HAL/Driver_SAMD_PORT.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_DRIVERS_HAL/Driver_SAMD_SERCOM1_I2CM.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_DRIVERS_HAL/Driver_SAMD_SERCOM2_SPIM.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_DRIVERS_HAL/Driver_SAMD_SERCOM3_SPIM.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_DRIVERS_HAL/Driver_SAMD_SERCOM4_SPIM.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_DRIVERS_HAL/Driver_SAMD_SYSCTRL.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_FreeRTOS/Portable/ARM_CM0/port.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_FreeRTOS/Portable/MemMang/heap_4.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_FreeRTOS/event_groups.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_FreeRTOS/list.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_FreeRTOS/queue.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_FreeRTOS/tasks.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_FreeRTOS/timers.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_INTERRUPTIONS/Interruption_TRAP.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_MAIN/Function_MAIN.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_MAIN/Storage_DELAY.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_STREAMS/Stream_CTRL_LEDC.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_TASK/Settings_TASKS.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_TASK/Task_CTRL_CANC.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_TASK/Task_CTRL_LEDC.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_TASK/Task_EXEC_MUXC.c")
set_source_files_properties(${GAME_CAT_R4_VSC_MPLAB_default_XC32_FILE_TYPE_compile} PROPERTIES LANGUAGE C)
set(GAME_CAT_R4_VSC_MPLAB_default_XC32_FILE_TYPE_compile_cpp)
set_source_files_properties(${GAME_CAT_R4_VSC_MPLAB_default_XC32_FILE_TYPE_compile_cpp} PROPERTIES LANGUAGE CXX)
set(GAME_CAT_R4_VSC_MPLAB_default_XC32_FILE_TYPE_link)
set(GAME_CAT_R4_VSC_MPLAB_image_name "GAME_CAT_R4_VSC.elf")


# The output directory of the final image.
set(GAME_CAT_R4_VSC_MPLAB_output_dir "${CMAKE_CURRENT_SOURCE_DIR}/../../../_output")
