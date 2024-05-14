# !!! Обязательно использовать табуляцию.

# make не будет искать файлы с перечисленными ниже именами.
.PHONY: all, assemble, run, clean

# Команда на полную сборку проекта.
all: assemble

# Сборка из исходников.
assemble: main.c
	gcc -Wall main.c -O3 -o main	

# Сборка и сбор информации в файл. ВРЕМЕННО.
run: assemble
	./main >> result.txt

# Удаление ненужных файла.
clean:
	rm -rf main
	rm -rf result.txt