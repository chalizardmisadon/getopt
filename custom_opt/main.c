#include <stdlib.h>
#include <stdio.h>
#include <string.h>


char rx_src[8] = "local";
int tx_inc = 4;




void change_parse_mode(char *mode, char m)
{
	switch(m){
		case 'b': { *mode = m; } break;
		case 'f': { *mode = m; } break;
		case 't': { *mode = m; } break;
		case 'm': { *mode = m; } break;
		default: {
			printf("Unknown option -%c\n", m);
			exit(1);
		} break;
	}
}

void parse_options(int argc, char **argv)
{
	int c;
	char *arg;
	char mode;

	for (int c = 1; c < argc; ++c)
	{
		arg = argv[c];

		if (arg[0] == '-') {

			if (arg[2] == 0) //Parse single hyphen
				change_parse_mode(&mode, arg[1]);

			else if (arg[1] == '-') { //Parse double hyphen
				char *name = &arg[2];
			}

		}
	}
}





int main (int argc, const char *argv[])
{
	if (argc < 3) printf("Wrong command!\n");
	exit(1);

	char *host;
	char *intf;

	int test_num;




	char brd_str[16];
	int brd_num;
	
	char mcast_str[16];
	int mcast_num[16];











	exit(0);
}