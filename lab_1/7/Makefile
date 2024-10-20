all: exe

exe: 	main.c
		gcc main.c -o lab1_7
		touch test_file
		mkdir test_dir

clean:
		-rm lab1_7 2>/dev/null
		rmdir test_dir
		rm test_file