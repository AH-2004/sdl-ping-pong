name = main

files = main.cpp objects.cpp
libs = -l SDL2 -l SDL2main -l SDL2_image

make:
	g++ $(files) $(libs) -o $(name);
	clear
	./$(name)

build_dir = dist

.SILENT: clean
clean:
	rm -f ./$(name)
	rm -rf $(build_dir)

build: clean
	mkdir $(build_dir)
	g++ $(files) $(libs) -o $(build_dir)/$(name)
	cp -r assets $(build_dir)
