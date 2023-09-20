#include "get_next_line.h"
#include <stdio.h>

int ft_strlen(char *s)
{
	int i = 0;
	while(s[i])
		i++;
	return i;
}

char *ft_strdup(char *s)
{
	int i = 0;
	int len;
	char *dup;
	len = ft_strlen(s);
	dup = malloc(len + 1);
	if(!dup)
		return NULL;
	while(s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = 0;
	return dup;
}

char *get_next_line(int fd)
{
	char buf;
	char line[7000000];
	int i = 0;
	int n;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	n = read(fd, &buf, 1);
	while (n > 0)
	{
		line[i] = buf;
		i++;
		if (buf == '\n')
			break;
		n = read(fd, &buf, 1);
	}
	line[i] = 0;
	if (n <= 0 && i == 0)
		return NULL;
	return ft_strdup(line);
}

/*
#include <stdio.h>
#include <fcntl.h>
int main(void)
{
	int fd;
	char *line;
	fd = open("text.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	while(line)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
	close(fd);
	return 0;
	
}
*/
