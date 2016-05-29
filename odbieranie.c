#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <string.h>

struct buf;

int main()
{
	struct buf buf_1;
	int msg_id, size, fd[2], fd_2[2], dzien, godzina;
	pipe(fd);
	klucz_1 klucz = 45200;
	int pid = fork();
	if (pid == -1){ perror("Blad przy tworzeniu dziecka\n"); }
	if (pid == 0)
	{
		dup2(fd[1], 1);
		close(fd[0]);
		system("date +%u");
		exit(1);
	}
	else
	{
		wait(NULL);
		dup2(fd[0], 0);
		close(fd[1]);
		scanf("%d", &dzien);
	}
	if (dzien >= 5)
	{
		if (dzien == 5)
		{
			int pid_2 = fork();
			pipe(fd_2);
			if (pid_2 == -1){ perror("Blad przy tworzeniu dziecka\n"); }
			if (pid_2 == 0)
			{
				dup2(fd_2[1], 1);
				close(fd_2[0]);
				system("date +%H");
				exit(1);
			}
			else
			{
				wait(NULL);
				dup2(fd_2[0], 0);
				close(fd_2[1]);
				scanf("%d", &godzina);
				if (godzina < 17)
				{
					printf("To jeszcze nie weekend :( \n");
					return 0;
				}
			}
		}
		msg_id = msgget(klucz, 0666);
		if (msg_id == -1)
		{
			perror("Blad przy dorzucaniu do kolejki komunikatow\n");
			exit(1);
		}
		if (msgrcv(msg_id, &buf_1, sizeof buf_1.word, 0, 0) == -1)
		{
			perror("Blad otrzymania wiadomosci\n");
			exit(1);
		}
		int length = len(buf_1.word);
		int i;
		for (i = 0; i < length; i++)
		{
			if (buf_1.word[i]<32 || buf_1.word[i]>126)
			{
				msgctl(msg_id, IPC_RMID, NULL);
				printf("Niepoprawna wiadomosci\n");
				return 0;
			}
		}
		if (!((buf_1.word[0] >= 97 && buf_1.word[0] <= 122) || (buf_1.word[0] >= 65 && buf_1.word[0] <= 90)))
		{
			msgctl(msg_id, IPC_RMID, NULL);
			printf("Niepoprawna wiadomosci\n");
			return 0;
		}
		FILE *wiadomosc = fopen("wiadomosc.txt", "wf");
		fwrite(buf_1.word, length, 1, wiadomosc);
		fclose(wiadomosc);
	}
	else { printf ("To jeszcze nie weekend :( \n"); }
	msgctl(msg_id, IPC_RMID, NULL);
	return 0;
}

struct buf
{
	char word[30];
	long type;
};