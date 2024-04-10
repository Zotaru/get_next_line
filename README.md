# Get_next_line

### Project from the second circle 

The goal of the project is to create of function that take a file descryptor and return a line. The project permit to understand how files are opened, read and closed in an OS,
and how they are interpreted by a programming language for further analysis.

### Language : ![C language](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)

### Usage : 

```C
# include "get_next_line.h"

int main(void)
{
  	int		fd;
	char	*line;

	line = NULL;
	fd = open("file_name", O_RDONLY);
	while (get_next_line(fd, &line))
	{
		printf(line);
	}
	close(fd);
}
```
> The result will print the file in the terminal

### Some tester:
1. [Tripouille](https://github.com/Tripouille/gnlTester)
2. [Station Tester](https://github.com/kodpe/gnl-station-tester)
