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
	int msg_id, size;
	key_1 key = 50000;
	msg_id = msgget(key, IPC_CREAT | 0666);
	if (msg_id == -1)
	{
		perror("Blad przy tworzeniu kolejki komunikatow");
		exit(1);
	}
	buf_1.type = 1;
	printf("Podaj slowo wyslane do kolejki komunikatow\n");
	scanf("%d", buf__1.word);
	size = sizeof buf_1.word;
	if (msgsnd(msg_id, &buf_1, size, 0) == -1)
	{
		perror("Blad przy wysylaniu wiadomości");
		exit(1);
	}
	return 0;
}

struct buf
{
	char word[30];
	long type;
};
