# c/cpp only
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} THISSRCS)

# interface
add_library(${student_name}_${mass_spring_target_name} INTERFACE)
target_link_libraries(${student_name}_${mass_spring_target_name} INTERFACE
    stage nodes_system usd geometry usdShade Eigen3::Eigen autodiff igl::core igl_restricted::triangle
)
target_include_directories(${student_name}_${mass_spring_target_name} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

# static lib
if(THISSRCS)
    message(STATUS "[Found SRC for utility lib]")
    add_library(
        ${student_name}_${mass_spring_target_name}_static STATIC
        ${THISSRCS}
    )
    target_include_directories(${student_name}_${mass_spring_target_name}_static PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(${student_name}_${mass_spring_target_name}_static
        stage nodes_system usd geometry usdShade Eigen3::Eigen autodiff igl::core igl_restricted::triangle
    )

    # link to the interface
    target_link_libraries(
        ${student_name}_${mass_spring_target_name} INTERFACE
        ${student_name}_${mass_spring_target_name}_static
    )
endif()

set(${student_name}_${mass_spring_target_name}_AVAILABLE TRUE PARENT_SCOPE)
