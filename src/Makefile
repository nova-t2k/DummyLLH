CXX=g++
AR=ar
LD_SHARED=g++

ROOTLIBS := $(shell root-config --glibs --libs)  -lMinuit 
ROOTINCLUDES := $(shell root-config --prefix)/include 
ROOTCFLAGS := $(shell root-config --cflags) -I../

INCDIR = -I. 
LIBDIR = ../lib

UNAME := $(shell uname)

ifneq ($(UNAME), Darwin)
EXPORT_DYNAMIC="-Wl,-export-dynamic"
endif

#CLHEPINC = $(CLHEP_BASE_DIR)/include
#CLHEPLIB = -L$(CLHEP_BASE_DIR)/lib -l$(CLHEP_LIB)

CXXFLAGS   = -Wall -O3 -g -fPIC -fopenmp $(ROOTCFLAGS) $(INCDIR) -Werror -std=c++11

SYSLIB     = -lm -lg2c
LINK_ARGS_BIN = $(SYSLIB) $(ROOTLIBS) $(LIBDIR)
SOFLAGS= -shared $(EXPORT_DYNAMIC) $(ROOTCFLAGS) #-fopenmp 
LDFLAGS=
ARFLAGS= rcsv

%.o:%.cpp
	g++ -c $(CXXFLAGS) $<
#	g++ -c $(LINK_ARGS_BIN) $(CXXFLAGS) $<

libEXTLLH: libEXTLLH.a $(LIBDIR)/libEXTLLH.so

libEXTLLH.a: ExampleExternalLLH.o
	$(AR) $(ARFLAGS) $@ $^

$(LIBDIR)/libEXTLLH.so: libEXTLLH.a ExampleExternalLLH.o
	$(LD_SHARED) $(SOFLAGS) $^ -o $@ $(LIB_OBJECTS) $(ROOTLIBS) -L$(LIBDIR) 

clean:
	rm -f $(LIBDIR)/libEXTLLH.so	
	rm -f *.o lib*

distclean:
	rm -fv *~ *.o *.so *.a lib*
