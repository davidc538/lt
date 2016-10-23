all: debug_gcc debug_clang release_gcc release_clang

clean:
	rm lt_debug_gcc lt_release_gcc lt_debug_clang lt_release_clang

debug_gcc: main.c lt_vector.c lt_vector.h lt_list.c lt_list.h lt_lib.c lt_lib.h
	gcc main.c lt_vector.c lt_list.c lt_lib.c -g -o lt_debug_gcc

release_gcc: main.c lt_vector.c lt_vector.h lt_list.c lt_list.h lt_lib.c lt_lib.h
	gcc main.c lt_vector.c lt_list.c lt_lib.c -Os -o lt_release_gcc

debug_clang: main.c lt_vector.c lt_vector.h lt_list.c lt_list.h lt_lib.c lt_lib.h
	clang main.c lt_vector.c lt_list.c lt_lib.c -g -o lt_debug_clang

release_clang: main.c lt_vector.c lt_vector.h lt_list.c lt_list.h lt_lib.c lt_lib.h
	clang main.c lt_vector.c lt_list.c lt_lib.c -Os -o lt_release_clang
