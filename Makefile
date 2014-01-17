all:
	$(CC) $(CFLAGS) -std=c11 -strict -o iChuj main.c udp.c udplite.c
