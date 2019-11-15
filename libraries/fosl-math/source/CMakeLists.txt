project(math)

add_library(
	${PROJECT_NAME}

	util.cpp
	math/util.h
)

target_include_directories(
	${PROJECT_NAME} PUBLIC

	${PROJECT_SOURCE_DIR}
)

set_target_properties(
	${PROJECT_NAME}

	PROPERTIES
	COMPILE_FLAGS "${MCU}"
)
