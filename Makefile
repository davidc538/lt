C_FILES=lt_lib.c lt_vector.c lt_list.c lt_binary_tree.c main.c
H_FILES=lt_lib.h lt_vector.h lt_list.h lt_binary_tree.h

all: lt_test_gcc_d lt_test_gcc lt_test_clang_d lt_test_clang

clean:
	rm lt_test_gcc_d lt_test_gcc lt_test_clang_d lt_test_clang

lt_test_gcc_d: $(C_FILES) $(H_FILES)
	gcc $(C_FILES) -g -o lt_test_gcc_d

lt_test_gcc: $(C_FILES) $(H_FILES)
	gcc $(C_FILES) -O3 -o lt_test_gcc

lt_test_clang_d: $(C_FILES) $(H_FILES)
	clang $(C_FILES) -g -o lt_test_clang_d

lt_test_clang: $(C_FILES) $(H_FILES)
	clang $(C_FILES) -O3 -o lt_test_clang

