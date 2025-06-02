all:
	@gcc -o main *.c -lm

run:
	@valgrind --leak-check=full ./main 5.txt 10 saida5.txt

clean:
	@rm -rf main