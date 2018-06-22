CXX=g++
CXXFLAGS=-g -I. -Wall -O3
SRCS=$(wildcard *.cpp)
BINS=$(SRCS:.cpp=.bin)
.PHONY:all clean debug
all:$(BINS)
.SUFFIXES:.cpp .bin
.cpp.bin:
	$(CXX) $(CXXFLAGS) -o $@ $<
debug:
	@echo $(SRCS);
	@echo $(BINS);
clean:
	rm -rf $(BINS)
