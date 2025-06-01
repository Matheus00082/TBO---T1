all:
	@gcc -o main *.c -lm

run:
	@valgrind --leak-check=full ./main 1.txt 3 saida.txt

clean:
	@rm -rf main