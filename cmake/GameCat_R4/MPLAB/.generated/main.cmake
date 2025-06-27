# cmake files support debug production
include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(GameCat_R4_MPLAB_library_list )

# Handle files with suffix s, for group default-XC32
if(GameCat_R4_MPLAB_default_XC32_FILE_TYPE_assemble)
add_library(GameCat_R4_MPLAB_default_XC32_assemble OBJECT ${GameCat_R4_MPLAB_default_XC32_FILE_TYPE_assemble})
    GameCat_R4_MPLAB_default_XC32_assemble_rule(GameCat_R4_MPLAB_default_XC32_assemble)
    list(APPEND GameCat_R4_MPLAB_library_list "$<TARGET_OBJECTS:GameCat_R4_MPLAB_default_XC32_assemble>")
endif()

# Handle files with suffix S, for group default-XC32
if(GameCat_R4_MPLAB_default_XC32_FILE_TYPE_assembleWithPreprocess)
add_library(GameCat_R4_MPLAB_default_XC32_assembleWithPreprocess OBJECT ${GameCat_R4_MPLAB_default_XC32_FILE_TYPE_assembleWithPreprocess})
    GameCat_R4_MPLAB_default_XC32_assembleWithPreprocess_rule(GameCat_R4_MPLAB_default_XC32_assembleWithPreprocess)
    list(APPEND GameCat_R4_MPLAB_library_list "$<TARGET_OBJECTS:GameCat_R4_MPLAB_default_XC32_assembleWithPreprocess>")
endif()

# Handle files with suffix [cC], for group default-XC32
if(GameCat_R4_MPLAB_default_XC32_FILE_TYPE_compile)
add_library(GameCat_R4_MPLAB_default_XC32_compile OBJECT ${GameCat_R4_MPLAB_default_XC32_FILE_TYPE_compile})
    GameCat_R4_MPLAB_default_XC32_compile_rule(GameCat_R4_MPLAB_default_XC32_compile)
    list(APPEND GameCat_R4_MPLAB_library_list "$<TARGET_OBJECTS:GameCat_R4_MPLAB_default_XC32_compile>")
endif()

# Handle files with suffix cpp, for group default-XC32
if(GameCat_R4_MPLAB_default_XC32_FILE_TYPE_compile_cpp)
add_library(GameCat_R4_MPLAB_default_XC32_compile_cpp OBJECT ${GameCat_R4_MPLAB_default_XC32_FILE_TYPE_compile_cpp})
    GameCat_R4_MPLAB_default_XC32_compile_cpp_rule(GameCat_R4_MPLAB_default_XC32_compile_cpp)
    list(APPEND GameCat_R4_MPLAB_library_list "$<TARGET_OBJECTS:GameCat_R4_MPLAB_default_XC32_compile_cpp>")
endif()


add_executable(${GameCat_R4_MPLAB_image_name} ${GameCat_R4_MPLAB_library_list})
set_target_properties(${GameCat_R4_MPLAB_image_name} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${GameCat_R4_MPLAB_output_dir})

target_link_libraries(${GameCat_R4_MPLAB_image_name} PRIVATE ${GameCat_R4_MPLAB_default_XC32_FILE_TYPE_link})

# Add the link options from the rule file.
GameCat_R4_MPLAB_link_rule(${GameCat_R4_MPLAB_image_name})

# Add bin2hex target for converting built file to a .hex file.
string(REGEX REPLACE [.]elf$ .hex GameCat_R4_MPLAB_image_name_hex ${GameCat_R4_MPLAB_image_name})
add_custom_target(GameCat_R4_MPLAB_Bin2Hex ALL
    COMMAND ${MP_BIN2HEX} ${GameCat_R4_MPLAB_output_dir}/${GameCat_R4_MPLAB_image_name}
    BYPRODUCTS ${GameCat_R4_MPLAB_output_dir}/${GameCat_R4_MPLAB_image_name_hex}
    COMMENT Convert built file to .hex)
add_dependencies(GameCat_R4_MPLAB_Bin2Hex ${GameCat_R4_MPLAB_image_name})



