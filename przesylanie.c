#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

struct buf;

int main()
{
	struct buf buf_1;
	int buf_id, size;
	buf_id = buf_get(klucz, IPC_CREAT | 0666);
	klucz_1 klucz = 45200;
	if (buf_id == -1)
	{
		perror("Blad przy tworzeniu kolejki komunikatow");
		exit(1);
	}
	buf_1.type = 1;
	printf("Podaj slowo wyslane do kolejki komunikatow\n");
	scanf("%d", buf__1.word);
	size = sizeof buf_1.word;
	if (buf_wys(buf_id, &buf_1, size, 0) == -1)
	{
		perror("Blad przy wysylaniu wiadomo�ci");
		exit(1);
	}
	return 0;
}

struct buf
{
	char word[30];
	long type;
};
