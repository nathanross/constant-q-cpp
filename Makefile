
CFLAGS := -Wall -O3 -ffast-math -msse -msse2 -mfpmath=sse -fPIC -I/usr/lib/x86_64-linux-gnu/

#CFLAGS := -g -fPIC -I../vamp-plugin-sdk

CXXFLAGS := $(CFLAGS) -std=c++11

PLUGIN_LDFLAGS := -shared -Wl,--version-script=vamp/vamp-plugin.map

VAMPSDK_DIR := /usr/lib/x86_64-linux-gnu/

PLUGIN_EXT := .so

include Makefile.inc

