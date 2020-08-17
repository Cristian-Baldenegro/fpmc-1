LIBDIR=../lib
CXXFLAGS= -Ofast -I.

target=$(LIBDIR)/libmodel_AAttbar_UFO.a

all: $(target)

objects=HelAmps_AAttbar_UFO.o Parameters_AAttbar_UFO.o rambo.o read_slha.o

$(target): $(objects)
	$(AR) cru $@ $(objects)
	ranlib $(target)

.PHONY: clean

clean:
	rm -f $(target)
	rm -f $(objects)

