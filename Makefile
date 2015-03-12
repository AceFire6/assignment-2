.SUFFIXES:
.SUFFIXES: .cpp .o

CC=g++
FLAGS=-std=c++11
SOURCES=src/main.cpp src/volimage.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXE_NAME=volimage

default: $(OBJECTS)
	$(CC) $(SOURCES) -o build/$(EXE_NAME) $(FLAGS)

.cpp.o:
	$(CC) -c $< -o $@ $(FLAGS)

clean:
	rm -f $(OBJECTS) build/$(EXE_NAME) build/*.raw build/*.dat

run:
	cd ./build && ./$(EXE_NAME) $(ARGS)

run-tests:
	cd ./build && ./$(EXE_NAME) mri_raws/MRI
	cd ./build && ./$(EXE_NAME) mri_raws/MRI -x 0 dashXOut
	cd ./build && ./$(EXE_NAME) mri_raws/MRI -d 0 1 dashDOut
	cd ./build && ./$(EXE_NAME) mri_raws/MRI -g 0 dashGOut