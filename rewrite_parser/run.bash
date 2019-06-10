make

./myparser < input/zero_error.c > ./test/zero_error.out
./myparser < input/syntactic_error.c > ./test/syntactic_error.out
./myparser < input/semantic_error.c > ./test/semantic_error.out
