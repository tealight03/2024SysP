#include <utime.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int opt;
    int update_atime = 0;
    int update_mtime = 0;
    int create_file = 0;

    time_t change_time = time(NULL);

    while ((opt = getopt(argc, argv, "amct:d:")) != -1) {
        switch (opt) {
            case 'a':
                update_atime = 1;
                break;
            case 'm':
                update_mtime = 1;
                break;
	    case 'c':
		create_file = 1;
		break;
	    case 'd':
                {
                    struct tm tm_time = { 0 };
                    sscanf(optarg, "%d-%d-%d %d:%d:%d",
                        &tm_time.tm_year, &tm_time.tm_mon, &tm_time.tm_mday,
                        &tm_time.tm_hour, &tm_time.tm_min, &tm_time.tm_sec);
                    tm_time.tm_year -= 1900;
                    tm_time.tm_mon -= 1;
                    change_time = mktime(&tm_time);
                }
                break;
	    case 't':
		{
		    struct tm tm_time = { 0 };
                    sscanf(optarg, "%2d%2d%2d%2d%2d.%2d",
           		&tm_time.tm_year, &tm_time.tm_mon, &tm_time.tm_mday,
             		&tm_time.tm_hour, &tm_time.tm_min, &tm_time.tm_sec);
		    tm_time.tm_year += 100;
                    tm_time.tm_mon -= 1;
		    tm_time.tm_isdst = -1;
                    change_time = mktime(&tm_time);
		    break;
		}
            default:
                fprintf(stderr, "사용법: touch [option] [file]\n");
                return 1;
        }
    }

    if (optind >= argc) {
        fprintf(stderr, "파일 이름이 제공되지 않았습니다.\n");
        return 1;
    }

    for (int i = optind; i < argc; i++) {
        struct stat file_info;
        struct utimbuf new_times;

        if (stat(argv[i], &file_info) == -1) {
            if(!create_file){
		FILE *file = fopen(argv[i], "w");
            	fclose(file);
	    }
            continue;
        }

        if (update_atime) {
            new_times.actime = change_time;
            new_times.modtime = file_info.st_mtime;
        } else if (update_mtime) {
            new_times.actime = file_info.st_atime;
            new_times.modtime = change_time;
        } else {
            new_times.actime = change_time;
            new_times.modtime = change_time;
        }

        if (utime(argv[i], &new_times) != 0) {
            fprintf(stderr, "파일을 업데이트할 수 없습니다: %s\n", argv[i]);
        }
    }

    return 0;
}