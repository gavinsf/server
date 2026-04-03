all: test

run:
	cmake -S . -B build
	cmake --build build
	./build/server

test:
	cmake -S . -B build
	cmake --build build
	ctest --test-dir build --output-on-failure

test-only:
	cmake --build build --target unit_tests
	ctest --test-dir build --output-on-failure

clean:
	rm -rf build	