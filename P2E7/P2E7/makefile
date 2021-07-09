# Makefile para el (P2E7)
# ejecutar como make 

programa: main.o glist.o contacto.o
	$(CC) -o $@ $^

main.o: main.c glist.h contacto.h
	$(CC) -c $<

glist.o: glist.c glist.h
	$(CC) -c $<

contacto.o: contacto.c contacto.h
	$(CC) -c $<

clean:
	-rm *.o

.PHONY = clean