C_FILES=lt_lib.c lt_vector.c lt_list.c lt_binary_tree.c main.c
H_FILES=lt_lib.h lt_vector.h lt_list.h lt_binary_tree.h

all: debug_gcc debug_clang release_gcc release_clang

clean:
	rm lt_debug_gcc lt_release_gcc lt_debug_clang lt_release_clang

debug_gcc: $(C_FILES) $(H_FILES)
	gcc $(C_FILES) -g -o lt_debug_gcc

release_gcc: $(C_FILES) $(H_FILES)
	gcc $(C_FILES) -O3 -o lt_release_gcc

debug_clang: $(C_FILES) $(H_FILES)
	clang $(C_FILES) -g -o lt_debug_clang

release_clang: $(C_FILES) $(H_FILES)
	clang $(C_FILES) -O3 -o lt_release_clang

