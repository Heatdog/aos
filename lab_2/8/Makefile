all: exe

exe: 	main.c
		gcc main.c -o lab2_8
		truncate -s 5K test
		echo "mephi mephi mephi" > test

clean:
		-rm lab2_8 test parent child 2>/dev/null