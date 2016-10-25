C_FILES=lt_lib.c lt_vector.c lt_list.c lt_binary_tree.c main.c
H_FILES=lt_lib.h lt_vector.h lt_list.h lt_binary_tree.h
R_FLAGS=-O3 -s
D_FLAGS=-g

all: lt_test_gcc_d lt_test_gcc lt_test_clang_d lt_test_clang lt_test_tcc_d lt_test_tcc

clean:
	rm lt_test_gcc_d lt_test_gcc lt_test_clang_d lt_test_clang lt_test_tcc_d lt_test_tcc

lt_test_gcc_d: $(C_FILES) $(H_FILES)
	gcc $(C_FILES) $(D_FLAGS) -o lt_test_gcc_d

lt_test_gcc: $(C_FILES) $(H_FILES)
	gcc $(C_FILES) $(R_FLAGS) -o lt_test_gcc

lt_test_clang_d: $(C_FILES) $(H_FILES)
	clang $(C_FILES) $(D_FLAGS) -o lt_test_clang_d

lt_test_clang: $(C_FILES) $(H_FILES)
	clang $(C_FILES) $(R_FLAGS) -O3 -o lt_test_clang

lt_test_tcc_d: $(C_FILES) $(H_FILES)
	tcc $(C_FILES) $(D_FLAGS) -o lt_test_tcc_d

lt_test_tcc: $(C_FILES) $(H_FILES)
	tcc $(C_FILES) $(R_FLAGS) -O3 -o lt_test_tcc
