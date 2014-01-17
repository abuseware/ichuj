all:
	$(CC) $(CFLAGS) -std=c11 -pedantic -o iChuj main.c udp.c udplite.c
