all:
	@gcc -o main *.c

run:
	./main 5.txt 10 saida5.txt

valgrind:
	@valgrind --leak-check=full ./main 1.txt 2 saida1.txt

clean:
	@rm -rf main