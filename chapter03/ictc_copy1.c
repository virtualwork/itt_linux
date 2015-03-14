#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char block[1024];
	int in, out;
	int nread;

	in = open(argv[1], O_RDONLY);
	out = open(argv[2], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	while ((nread = read(in, block, sizeof(block))) > 0)
		write(out, block, nread);

	exit(0);
}
