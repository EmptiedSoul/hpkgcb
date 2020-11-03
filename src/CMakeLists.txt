cmake_minimum_required(VERSION 3.18.4)
project(libhpkgcb)
set(GCC_FLAGS -O3 -Wall -Wextra -Werror -pedantic -DNDEBUG)
add_library(hpkgcb SHARED 
	main.c
	)
add_library(hpkgcb_static STATIC 
	main.c
	)
add_executable(usage 
	EXCLUDE_FROM_ALL 
	usage.c
	)
target_compile_options(usage PUBLIC 
	${GCC_FLAGS}
	)
target_link_libraries(usage 
	hpkgcb
	)
target_compile_options(hpkgcb PUBLIC 
	${GCC_FLAGS}
	)
target_compile_options(hpkgcb_static PUBLIC 
	${GCC_FLAGS}
	)
set_target_properties(hpkgcb_static 
	PROPERTIES 
	OUTPUT_NAME hpkgcb
	PUBLIC_HEADER hpkgcb.h
	)
set_target_properties(hpkgcb
	PROPERTIES
	OUTPUT_NAME hpkgcb
	PUBLIC_HEADER hpkgcb.h
	)
install(TARGETS hpkgcb hpkgcb_static
	LIBRARY DESTINATION "lib"
	PUBLIC_HEADER DESTINATION "include"
	)
