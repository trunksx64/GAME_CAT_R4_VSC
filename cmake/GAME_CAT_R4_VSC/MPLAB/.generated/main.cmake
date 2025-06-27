# cmake files support debug production
include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(GAME_CAT_R4_VSC_MPLAB_library_list )

# Handle files with suffix s, for group default-XC32
if(GAME_CAT_R4_VSC_MPLAB_default_XC32_FILE_TYPE_assemble)
add_library(GAME_CAT_R4_VSC_MPLAB_default_XC32_assemble OBJECT ${GAME_CAT_R4_VSC_MPLAB_default_XC32_FILE_TYPE_assemble})
    GAME_CAT_R4_VSC_MPLAB_default_XC32_assemble_rule(GAME_CAT_R4_VSC_MPLAB_default_XC32_assemble)
    list(APPEND GAME_CAT_R4_VSC_MPLAB_library_list "$<TARGET_OBJECTS:GAME_CAT_R4_VSC_MPLAB_default_XC32_assemble>")
endif()

# Handle files with suffix S, for group default-XC32
if(GAME_CAT_R4_VSC_MPLAB_default_XC32_FILE_TYPE_assembleWithPreprocess)
add_library(GAME_CAT_R4_VSC_MPLAB_default_XC32_assembleWithPreprocess OBJECT ${GAME_CAT_R4_VSC_MPLAB_default_XC32_FILE_TYPE_assembleWithPreprocess})
    GAME_CAT_R4_VSC_MPLAB_default_XC32_assembleWithPreprocess_rule(GAME_CAT_R4_VSC_MPLAB_default_XC32_assembleWithPreprocess)
    list(APPEND GAME_CAT_R4_VSC_MPLAB_library_list "$<TARGET_OBJECTS:GAME_CAT_R4_VSC_MPLAB_default_XC32_assembleWithPreprocess>")
endif()

# Handle files with suffix [cC], for group default-XC32
if(GAME_CAT_R4_VSC_MPLAB_default_XC32_FILE_TYPE_compile)
add_library(GAME_CAT_R4_VSC_MPLAB_default_XC32_compile OBJECT ${GAME_CAT_R4_VSC_MPLAB_default_XC32_FILE_TYPE_compile})
    GAME_CAT_R4_VSC_MPLAB_default_XC32_compile_rule(GAME_CAT_R4_VSC_MPLAB_default_XC32_compile)
    list(APPEND GAME_CAT_R4_VSC_MPLAB_library_list "$<TARGET_OBJECTS:GAME_CAT_R4_VSC_MPLAB_default_XC32_compile>")
endif()

# Handle files with suffix cpp, for group default-XC32
if(GAME_CAT_R4_VSC_MPLAB_default_XC32_FILE_TYPE_compile_cpp)
add_library(GAME_CAT_R4_VSC_MPLAB_default_XC32_compile_cpp OBJECT ${GAME_CAT_R4_VSC_MPLAB_default_XC32_FILE_TYPE_compile_cpp})
    GAME_CAT_R4_VSC_MPLAB_default_XC32_compile_cpp_rule(GAME_CAT_R4_VSC_MPLAB_default_XC32_compile_cpp)
    list(APPEND GAME_CAT_R4_VSC_MPLAB_library_list "$<TARGET_OBJECTS:GAME_CAT_R4_VSC_MPLAB_default_XC32_compile_cpp>")
endif()


add_executable(${GAME_CAT_R4_VSC_MPLAB_image_name} ${GAME_CAT_R4_VSC_MPLAB_library_list})
set_target_properties(${GAME_CAT_R4_VSC_MPLAB_image_name} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${GAME_CAT_R4_VSC_MPLAB_output_dir})

target_link_libraries(${GAME_CAT_R4_VSC_MPLAB_image_name} PRIVATE ${GAME_CAT_R4_VSC_MPLAB_default_XC32_FILE_TYPE_link})

# Add the link options from the rule file.
GAME_CAT_R4_VSC_MPLAB_link_rule(${GAME_CAT_R4_VSC_MPLAB_image_name})

# Add bin2hex target for converting built file to a .hex file.
string(REGEX REPLACE [.]elf$ .hex GAME_CAT_R4_VSC_MPLAB_image_name_hex ${GAME_CAT_R4_VSC_MPLAB_image_name})
add_custom_target(GAME_CAT_R4_VSC_MPLAB_Bin2Hex ALL
    COMMAND ${MP_BIN2HEX} ${GAME_CAT_R4_VSC_MPLAB_output_dir}/${GAME_CAT_R4_VSC_MPLAB_image_name}
    BYPRODUCTS ${GAME_CAT_R4_VSC_MPLAB_output_dir}/${GAME_CAT_R4_VSC_MPLAB_image_name_hex}
    COMMENT Convert built file to .hex)
add_dependencies(GAME_CAT_R4_VSC_MPLAB_Bin2Hex ${GAME_CAT_R4_VSC_MPLAB_image_name})



