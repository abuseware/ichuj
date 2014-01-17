all:
	$(CC) $(CFLAGS) -std=c11 -o iChuj main.c udp.c udplite.c
