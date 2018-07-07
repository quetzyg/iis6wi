#
# IIS Website Information v0.2
# Last updated: 24/10/2011
#
# Copyright (C) 2011 Quetzy Garcia <quetzyg@altek.org>
#

CC = gcc
OUT = iis6wi
LIBS = `xml2-config --libs`
CFLAGS = `xml2-config --cflags` -g -W -ansi
FILES = iis6wi.o main.o
REMOVE = /bin/rm -f

$(OUT): $(FILES)
	$(CC) $(FILES) -o $(OUT) $(LIBS)
	@echo -e "\nBuild complete!"

clean:
	$(REMOVE) *.o
	$(REMOVE) $(OUT)
