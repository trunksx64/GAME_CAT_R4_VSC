# The following functions contains all the flags passed to the different build stages.

set(PACK_REPO_PATH "/home/xDNA/.mchp_packs" CACHE PATH "Path to the root of a pack repository.")

function(GAME_CAT_R4_VSC_MPLAB_default_XC32_assemble_rule target)
    set(options
        "-g"
        "${ASSEMBLER_PRE}"
        "-mprocessor=ATSAMD21G18A"
        "-Wa,--defsym=__MPLAB_BUILD=1${MP_EXTRA_AS_POST},--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--gdwarf-2,-I${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_DRIVERS_HAL"
        "-mdfp=${PACK_REPO_PATH}/Microchip/SAMD21_DFP/3.6.144/samd21a")
    list(REMOVE_ITEM options "")
    target_compile_options(${target} PRIVATE "${options}")
    target_compile_definitions(${target} PRIVATE "__DEBUG")
    target_include_directories(${target}
        PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_CONTROL_HAL"
        PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_MAIN"
        PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_INTERRUPTIONS"
        PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_STREAMS"
        PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_TASK"
        PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_FreeRTOS"
        PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_FreeRTOS/Include"
        PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_FreeRTOS/Portable/ARM_CM0"
        PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_FreeRTOS/Portable/MemMang")
endfunction()
function(GAME_CAT_R4_VSC_MPLAB_default_XC32_assembleWithPreprocess_rule target)
    set(options
        "-x"
        "assembler-with-cpp"
        "-g"
        "${MP_EXTRA_AS_PRE}"
        "${DEBUGGER_NAME_AS_MACRO}"
        "-mprocessor=ATSAMD21G18A"
        "-Wa,--defsym=__MPLAB_BUILD=1${MP_EXTRA_AS_POST},--defsym=__MPLAB_DEBUG=1,--gdwarf-2,--defsym=__DEBUG=1")
    list(REMOVE_ITEM options "")
    target_compile_options(${target} PRIVATE "${options}")
    target_compile_definitions(${target}
        PRIVATE "__DEBUG"
        PRIVATE "XPRJ_MPLAB=MPLAB")
endfunction()
function(GAME_CAT_R4_VSC_MPLAB_default_XC32_compile_rule target)
    set(options
        "-g"
        "${CC_PRE}"
        "-x"
        "c"
        "-c"
        "-mprocessor=ATSAMD21G18A"
        "-fno-common"
        "-mdfp=${PACK_REPO_PATH}/Microchip/SAMD21_DFP/3.6.144/samd21a")
    list(REMOVE_ITEM options "")
    target_compile_options(${target} PRIVATE "${options}")
    target_compile_definitions(${target}
        PRIVATE "__DEBUG"
        PRIVATE "__DEBUG"
        PRIVATE "XPRJ_MPLAB=MPLAB")
    target_include_directories(${target}
        PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_DRIVERS_HAL"
        PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_CONTROL_HAL"
        PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_MAIN"
        PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_INTERRUPTIONS"
        PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_STREAMS"
        PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_TASK"
        PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_FreeRTOS"
        PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_FreeRTOS/Include"
        PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_FreeRTOS/Portable/ARM_CM0"
        PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_FreeRTOS/Portable/MemMang"
        PRIVATE "${PACK_REPO_PATH}/ARM/CMSIS/6.1.0/CMSIS/Core/Include")
endfunction()
function(GAME_CAT_R4_VSC_MPLAB_default_XC32_compile_cpp_rule target)
    set(options
        "-g"
        "${CC_PRE}"
        "${DEBUGGER_NAME_AS_MACRO}"
        "-mprocessor=ATSAMD21G18A"
        "-frtti"
        "-fexceptions"
        "-fno-check-new"
        "-fenforce-eh-specs"
        "-fno-common"
        "-mdfp=${PACK_REPO_PATH}/Microchip/SAMD21_DFP/3.6.144/samd21a")
    list(REMOVE_ITEM options "")
    target_compile_options(${target} PRIVATE "${options}")
    target_compile_definitions(${target}
        PRIVATE "__DEBUG"
        PRIVATE "XPRJ_MPLAB=MPLAB")
    target_include_directories(${target}
        PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_DRIVERS_HAL"
        PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_CONTROL_HAL"
        PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_MAIN"
        PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_INTERRUPTIONS"
        PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_STREAMS"
        PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_TASK"
        PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_FreeRTOS"
        PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_FreeRTOS/Include"
        PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_FreeRTOS/Portable/ARM_CM0"
        PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../../SAMD_FreeRTOS/Portable/MemMang"
        PRIVATE "${PACK_REPO_PATH}/ARM/CMSIS/6.1.0/CMSIS/Core/Include")
endfunction()
function(GAME_CAT_R4_VSC_MPLAB_link_rule target)
    set(options
        "-g"
        "${MP_EXTRA_LD_PRE}"
        "${DEBUGGER_OPTION_TO_LINKER}"
        "${DEBUGGER_NAME_AS_MACRO}"
        "-mprocessor=ATSAMD21G18A"
        "-Wl,--defsym=__MPLAB_BUILD=1${MP_EXTRA_LD_POST},--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=_min_heap_size=128,-Map=mem.map,--report-mem,--memorysummary,memoryfile.xml"
        "-mdfp=${PACK_REPO_PATH}/Microchip/SAMD21_DFP/3.6.144/samd21a")
    list(REMOVE_ITEM options "")
    target_link_options(${target} PRIVATE "${options}")
    target_compile_definitions(${target} PRIVATE "XPRJ_MPLAB=MPLAB")
endfunction()
