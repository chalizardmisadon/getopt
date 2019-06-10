#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

//Global / Command Line Variables
char global_intf[16];
char global_mcast[16];

char global_clnt_id[16];
char global_op_id[16];
int global_ver;

struct sockaddr_in host_ucast;
int sockfd_ucast;
struct sockaddr_in host_mcast;
int sockfd_mcast;

void parse_cli_options(int argc, char *argv[])
{
	static bool help_flag = false;
	static bool verbose_flag = false;
	static int rx_route_local = 1;

	static bool board_flag = false;
	static bool mcast_flag = false;


	static struct option long_options[] = {
		//Set flags
		{"help",	no_argument,	0,	'h'},
		{"verbose",	no_argument,	0,	'v'},

		//Get board argument
		{"board",	required_argument,	0,	'b'},
		{"mcast",	required_argument,	0,	'm'},
		{"intf",	required_argument,	0,	'f'},

		//Test specific argument
		{"test",		required_argument,	0,	't'},
		{"rx-local",	no_argument,	&rx_route_local,	1},
		{"rx-ip",		no_argument,	&rx_route_local,	0},
		{"tx-inc",		required_argument,	0,	'n'},
	};

	int op_index = 0;
	int c;

	while ((c = getopt_long(argc, argv, "hvb:m:f:t:x:", long_options, &op_index)) != -1) {
		switch(c) {
			//Set Flag
			case 'h': { help_flag = true; } break;
			case 'v': { verbose_flag = true; } break;

			//Get board argument
			case 'b': {
				struct in_addr ip_addr;
				if (1 == inet_pton(AF_INET, optarg, &ip_addr)) {
					host_ucast.sin_family = AF_INET;
					host_ucast.sin_addr.s_addr = ip_addr.s_addr;
					host_ucast.sin_port = 6755;
					if (board_flag) printf("Switch to board-ip: '%s'\n", optarg);
					else printf("Set new board-ip: '%s'\n", optarg);
					board_flag = true;
				} else {
					printf("Failed to parse board-ip: '%s'\n", optarg);
					if (board_flag) {
						ip_addr.s_addr = ntohl(host_ucast.sin_addr.s_addr);
						printf("Board-ip is kept as: '%s'.\n", inet_ntoa(ip_addr));
					} else printf("Please enter a valid IPv4 address.\n");
				}
			} break;
			case 'm': {
				struct in_addr ip_addr;
				if (1 == inet_pton(AF_INET, optarg, &ip_addr)) {
					host_mcast.sin_family = AF_INET;
					host_mcast.sin_addr.s_addr = ip_addr.s_addr;
					host_mcast.sin_port = 6755;
					if (mcast_flag) printf("Switch receiving mcast-ip to: '%s'\n", optarg);
					else printf("Set new receiving mcast-ip: '%s'\n", optarg);
					mcast_flag = true;
				} else {
					printf("Failed to parse receiving mcast-ip: '%s'.\n", optarg);
					if (mcast_flag) {
						ip_addr.s_addr = ntohl(host_mcast.sin_addr.s_addr);
						printf("Receiving mcast-ip is kept as: '%s'\n", inet_ntoa(ip_addr));
					} else printf("Please enter a valid IPv4 address.\n");
				}
			} break;
			case 'f': {
				sockfd_ucast = 
			} break;
		}
	}
}



int main (int argc, char *argv[])
{
	char *host;
	char *intf;

	char test_str[8];
	int test_num;



	exit(0);
}