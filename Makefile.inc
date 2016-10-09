
LIB_DIR	  := src
INC_DIR	  := cq
KFFT_DIR  := src/ext/kissfft

CXX	?= g++
CC	?= gcc
AR	?= ar
RANLIB	?= ranlib

#VALGRIND	?= valgrind -q

GENERAL_FLAGS	:= -I. -I$(INC_DIR) -I$(LIB_DIR) -I$(KFFT_DIR) -I$(KFFT_DIR)/tools -Dkiss_fft_scalar=double

CFLAGS := $(GENERAL_FLAGS) $(CFLAGS) 
CXXFLAGS := $(GENERAL_FLAGS) $(CXXFLAGS)

LDFLAGS := $(LDFLAGS) 
PF_LDFLAGS := $(LDFLAGS) -lsndfile

LIB	:= libcq.a

LIB_HEADERS	:= \
	$(INC_DIR)/CQBase.h \
	$(INC_DIR)/CQKernel.h \
	$(INC_DIR)/ConstantQ.h \
	$(INC_DIR)/CQSpectrogram.h \
	$(INC_DIR)/CQInverse.h \
	$(INC_DIR)/Chromagram.h \
	$(LIB_DIR)/Pitch.h \
	$(LIB_DIR)/dsp/FFT.h \
	$(LIB_DIR)/dsp/KaiserWindow.h \
	$(LIB_DIR)/dsp/MathUtilities.h \
	$(LIB_DIR)/dsp/nan-inf.h \
	$(LIB_DIR)/dsp/Resampler.h \
	$(LIB_DIR)/dsp/SincWindow.h \
	$(LIB_DIR)/dsp/Window.h \
	$(KFFT_DIR)/kiss_fft.h \
	$(KFFT_DIR)/tools/kiss_fftr.h

LIB_SOURCES	:= \
	$(LIB_DIR)/CQKernel.cpp \
	$(LIB_DIR)/ConstantQ.cpp \
	$(LIB_DIR)/CQSpectrogram.cpp \
	$(LIB_DIR)/CQInverse.cpp \
	$(LIB_DIR)/Chromagram.cpp \
	$(LIB_DIR)/Pitch.cpp \
	$(LIB_DIR)/dsp/FFT.cpp \
	$(LIB_DIR)/dsp/KaiserWindow.cpp \
	$(LIB_DIR)/dsp/MathUtilities.cpp \
	$(LIB_DIR)/dsp/Resampler.cpp \
	$(LIB_DIR)/dsp/SincWindow.cpp \
	$(KFFT_DIR)/kiss_fft.c \
	$(KFFT_DIR)/tools/kiss_fftr.c

LIB_OBJECTS  := $(LIB_SOURCES:.cpp=.o)
LIB_OBJECTS  := $(LIB_OBJECTS:.c=.o)

OBJECTS	     := $(SOURCES:.cpp=.o)
OBJECTS	     := $(OBJECTS:.c=.o)

PF_SOURCES := $(TEST_DIR)/processfile.cpp
PF_OBJECTS := $(PF_SOURCES:.cpp=.o) $(OBJECTS)

LIBS	:= -lpthread

default:   all

all:	   libs $(PF)

libs:	   $(LIB)

$(PF):	$(PF_OBJECTS)
	$(CXX) -o $@ $^ $(LIBS) $(PF_LDFLAGS)

$(LIB):	$(LIB_OBJECTS)
	$(RM) -f $@
	$(AR) cr $@ $^
	$(RANLIB) $@

clean:		
	rm -f $(OBJECTS) $(PF_OBJECTS)

distclean:	clean

depend:
	makedepend -Y -fMakefile.inc $(SOURCES) $(PF_SOURCES) $(HEADERS)

# DO NOT DELETE

src/CQKernel.o: src/dsp/MathUtilities.h src/dsp/nan-inf.h src/dsp/FFT.h
src/CQKernel.o: src/dsp/Window.h
src/ConstantQ.o: src/dsp/Resampler.h src/dsp/MathUtilities.h
src/ConstantQ.o: src/dsp/nan-inf.h src/dsp/FFT.h
src/CQInverse.o: src/dsp/Resampler.h src/dsp/MathUtilities.h
src/CQInverse.o: src/dsp/nan-inf.h src/dsp/FFT.h
src/Chromagram.o: src/Pitch.h
src/Pitch.o: src/Pitch.h
src/dsp/FFT.o: src/dsp/FFT.h src/dsp/MathUtilities.h src/dsp/nan-inf.h
src/dsp/KaiserWindow.o: src/dsp/KaiserWindow.h src/dsp/MathUtilities.h
src/dsp/KaiserWindow.o: src/dsp/nan-inf.h
src/dsp/MathUtilities.o: src/dsp/MathUtilities.h src/dsp/nan-inf.h
src/dsp/Resampler.o: src/dsp/Resampler.h src/dsp/MathUtilities.h
src/dsp/Resampler.o: src/dsp/nan-inf.h src/dsp/KaiserWindow.h
src/dsp/Resampler.o: src/dsp/SincWindow.h
src/dsp/SincWindow.o: src/dsp/SincWindow.h
src/ext/kissfft/kiss_fft.o: src/ext/kissfft/_kiss_fft_guts.h
src/ext/kissfft/kiss_fft.o: src/ext/kissfft/kiss_fft.h
src/ext/kissfft/tools/kiss_fftr.o: src/ext/kissfft/tools/kiss_fftr.h
src/ext/kissfft/tools/kiss_fftr.o: src/ext/kissfft/kiss_fft.h
src/ext/kissfft/tools/kiss_fftr.o: src/ext/kissfft/_kiss_fft_guts.h
cq/CQKernel.o: cq/CQParameters.h
cq/ConstantQ.o: cq/CQBase.h cq/CQParameters.h cq/CQKernel.h
cq/CQSpectrogram.o: cq/ConstantQ.h cq/CQBase.h cq/CQParameters.h
cq/CQSpectrogram.o: cq/CQKernel.h
cq/CQInverse.o: cq/CQBase.h cq/CQKernel.h cq/CQParameters.h
cq/Chromagram.o: cq/CQBase.h
src/dsp/MathUtilities.o: src/dsp/nan-inf.h
src/ext/kissfft/tools/kiss_fftr.o: src/ext/kissfft/kiss_fft.h
