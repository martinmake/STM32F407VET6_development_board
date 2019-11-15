project(tty)

add_library(
	${PROJECT_NAME}

	./tty.cpp
	./tty.h
)

target_include_directories(
	${PROJECT_NAME} PUBLIC

	${PROJECT_SOURCE_DIR}

	${util_SOURCE_DIR}
	${math_SOURCE_DIR}
)

set_target_properties(
	${PROJECT_NAME}

	PROPERTIES
	COMPILE_FLAGS "${MCU}"
)
