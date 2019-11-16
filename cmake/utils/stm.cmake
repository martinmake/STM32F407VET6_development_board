set(MCU "-mcpu=${CPU} -mfpu=${FPU} -mfloat-abi=${FLOAT_ABI} -D${DEVICE} -mthumb")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${MCU}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${MCU}")
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} ${MCU}")
add_definitions("-DUSE_HAL_DRIVER")

if(NOT UPLOADTOOL)
	set(
		UPLOADTOOL st-flash
		CACHE STRING "Set default upload tool: st-flash"
	)
	find_program(UPLOADTOOL st-flash)
endif()

if(NOT UPLOADTOOL_ADDR)
	set(
		UPLOADTOOL_ADDR 0x08000000
		CACHE STRING "Set default upload tool start address: 0x08000000"
	)
endif()

if(NOT INFOTOOL)
	set(
		INFOTOOL st-info
		CACHE STRING "Set default info tool: st-info"
	)
	find_program(INFOTOOL st-info)
endif()

if(NOT SERIALTOOL)
	set(
		SERIALTOOL tio
		CACHE STRING "Set default serial tool: tio"
	)
	find_program(INFOTOOL tio)
endif()

if(NOT SERIALTOOL_BAUDRATE)
	set(
		SERIALTOOL_BAUDRATE 9200
		CACHE STRING "Set default serial tool baudrate: 9200"
	)
endif()

if(NOT SERIALTOOL_SERIAL_PORT)
	set(
		SERIALTOOL_SERIAL_PORT /dev/ttyUSB0
		CACHE STRING "Set default serial tool serial port: /dev/ttyUSB0"
	)
endif()

if(NOT SERIALTOOL_VCP_PORT)
	set(
		SERIALTOOL_VCP_PORT /dev/ttyACM0
		CACHE STRING "Set default serial tool vcp port: /dev/ttyACM0"
	)
endif()

if(
	NOT ((CMAKE_BUILD_TYPE MATCHES Release) OR
	(CMAKE_BUILD_TYPE MATCHES RelWithDebInfo) OR
	(CMAKE_BUILD_TYPE MATCHES Debug) OR
	(CMAKE_BUILD_TYPE MATCHES MinSizeRel))
)
	set(
		CMAKE_BUILD_TYPE Release
		CACHE STRING "Choose cmake build type: Debug Release RelWithDebInfo MinSizeRel"
		FORCE
	)
endif()

message(STATUS "Current uploadtool is: ${UPLOADTOOL}")
message(STATUS "Current device is set to: ${DEVICE}")
message(STATUS "Current math is set to: ${MATH}")
message(STATUS "Current CPU is set to: ${CPU}")
message(STATUS "Current FPU is set to: ${FPU}")
message(STATUS "Current float ABI is set to: ${FLOAT_ABI}")

function(add_stm_executable)
	set(options)
	set(args NAME LINKER_SCRIPT)
	set(list_args)
	cmake_parse_arguments(
		PARSE_ARGV 0
		executable
		"${options}"
		"${args}"
		"${list_args}"
	)
	set(sources ${executable_UNPARSED_ARGUMENTS})

	if(NOT DEFINED executable_NAME)
		message(FATAL_ERROR "No NAME was given.")
	endif()
	if(NOT DEFINED executable_LINKER_SCRIPT)
		message(FATAL_ERROR "No linker script was given for ${executable_NAME}.")
	endif()
	if(NOT DEFINED sources)
		message(FATAL_ERROR "No source files given for ${executable_NAME}.")
	endif()

	# set file names
	set(elf_file ${executable_NAME}.elf)
	set(bin_file ${executable_NAME}.bin)
	set(hex_file ${executable_NAME}.hex)
	set(lst_file ${executable_NAME}.lst)
	set(map_file ${executable_NAME}.map)

	# elf file
	add_executable(${elf_file} ${sources})

	set_target_properties(
		${elf_file}

		PROPERTIES
			LINK_FLAGS "-T${executable_LINKER_SCRIPT} -Wl,--gc-sections -Wl,-Map,${map_file}"
	)

	add_custom_command(
		OUTPUT ${bin_file}
		COMMAND
			${OBJCOPY} -O binary ${elf_file} ${bin_file}
		COMMAND
			${SIZE_TOOL} ${SIZE_ARGS} ${elf_file}
		DEPENDS ${elf_file}
	)

	add_custom_command(
		OUTPUT ${hex_file}
		COMMAND
			${OBJCOPY} -O ihex ${elf_file} ${hex_file}
		DEPENDS ${elf_file}
	)

	add_custom_command(
		OUTPUT ${lst_file}
		COMMAND
			${OBJDUMP} -d ${elf_file} > ${lst_file}
		DEPENDS ${elf_file}
	)

	add_custom_target(
		${executable_NAME}
		ALL
		DEPENDS ${bin_file} ${hex_file} ${lst_file}
	)

	set_target_properties(
		${executable_NAME}

		PROPERTIES
			OUTPUT_NAME "${elf_file}"
	)

	# clean
	get_directory_property(clean_files ADDITIONAL_MAKE_CLEAN_FILES)
	set_directory_properties(
		PROPERTIES
		 ADDITIONAL_MAKE_CLEAN_FILES "${map_file}"
	)

	# st-flash
	add_custom_target(
		upload_${executable_NAME}

		${UPLOADTOOL} write ${bin_file} ${UPLOADTOOL_ADDR}

		DEPENDS ${bin_file}
		COMMENT "Uploading ${bin_file} to ${DEVICE}"
	)

	# disassemble
	add_custom_target(
		disassemble_${executable_NAME}

		${OBJDUMP} -h -S ${elf_file} > ${executable_NAME}.lst

		DEPENDS ${elf_file}
	)
endfunction()

# st-info
add_custom_target(
	status

	${INFOTOOL} --probe

	COMMENT "Get status from ${DEVICE}"
)

# tio
add_custom_target(
	connection_over_serial_port

	sudo ${SERIALTOOL} -b ${SERIALTOOL_BAUDRATE} -d 8 -s 1 -p none -e -mINLCRNL ${SERIALTOOL_SERIAL_PORT}

	COMMENT "Connect to ${DEVICE} over UART"
)

# tio
add_custom_target(
	connection_over_virtual_com_port

	sudo ${SERIALTOOL} -e -mINLCRNL ${SERIALTOOL_VCP_PORT}

	COMMENT "Connect to ${DEVICE} over VCP"
)
