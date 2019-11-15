all:
	@mkdir -p build && cd build && cmake -Wno-dev .. && $(MAKE)
