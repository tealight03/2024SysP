#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int opt;
    int seccess_message = 0;
    int remove_directory = 0;

    while ((opt = getopt(argc, argv, "vd")) != -1) {
        switch (opt) {
            case 'v':
                seccess_message = 1;
                break;
	    case 'd':
		remove_directory = 1;
		break;
            default :
                fprintf(stderr, "사용법 : rm [옵션] [파일]\n");
                return 1;
        }
    }

    if (optind >= argc) {
        printf("사용법: %s [디렉토리 경로]\n", argv[0]);
        return 1;
    }

    for (int i = optind; i < argc; i++) {
        struct stat file_stat;
	char *file = argv[i];

	if (stat(file, &file_stat) == 0) {
            if (S_ISDIR(file_stat.st_mode)) {
            	int result = rmdir(file);
                if (result == 0) {
                    if(seccess_message){
                        printf("removed '%s'\n", argv[i]);
                    }
                } else {
                    if(seccess_message){
                        printf("rm: cannot remove '%s'\n", argv[i]);
                    }
                return 1;
                }
            } else {
            	int result = remove(file);
        	if (result == 0) {
            	    if(seccess_message){
                	printf("removed '%s'\n", argv[i]);
            	    }
        	} else {
            	    if(seccess_message){
                	printf("rm: cannot remove '%s'\n", argv[i]);
                    }
            	return 1;
        	}
            }
    	} else {
            printf("Failed to retrieve file status.\n");
    	}

        return 0;
    }
}