all: build run

build:
	rm A; \
	g++ -o A -I /opt/miniconda3/lib/ -L /opt/miniconda3/lib/ -lpython3.7m -lm A.cpp -framework Python

run:
	LD_LIBRARY_PATH=/opt/miniconda3/lib/ ./A