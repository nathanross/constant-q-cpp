
CFLAGS := -Wall -O3 -ffast-math -msse -msse2 -mfpmath=sse -fPIC -I/usr/lib/x86_64-linux-gnu/

CXXFLAGS := $(CFLAGS) -std=c++11

include Makefile.inc

