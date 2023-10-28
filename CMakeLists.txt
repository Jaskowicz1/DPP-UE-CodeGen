cmake_minimum_required (VERSION 3.20)

project ("CodeGen" VERSION 1.0 DESCRIPTION "A program which creates Unreal Engine functions from DPP code.")

file(GLOB src_code CONFIGURE_DEPENDS "src/*.h" "src/*.cpp" "src/*/*.h" "src/*/*.cpp")

# Add source to this project's executable.
add_executable(${PROJECT_NAME}
	${src_code}
)

set_target_properties(${PROJECT_NAME} PROPERTIES
	CMAKE_STANDARD 17
	CMAKE_STANDARD_REQUIRED ON
)
