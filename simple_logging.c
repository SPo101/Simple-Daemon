# /var/log/syslog
#include <syslog.h>

int main(int argc, char *argv[]){
	openlog(argv[0], LOG_CONS, LOG_USER);
	syslog(LOG_INFO, "Logging... sa kf");
	closelog();
}
