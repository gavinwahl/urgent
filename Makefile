urgent:
	$(CC) $(CFLAGS) urgent.c -lX11 -o urgent

install: urgent
	install -m 0755 urgent /usr/local/bin

clean:
	-rm urgent

.PHONY: install
