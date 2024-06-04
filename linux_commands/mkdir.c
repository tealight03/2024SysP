#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int opt;
    int seccess_message = 0;

    while ((opt = getopt(argc, argv, "v")) != -1) {
	switch (opt) {
	    case 'v':
		seccess_message = 1;
		break;
	    default :
		fprintf(stderr, "사용법 : mkdir [옵션] [파일]\n");
                return 1;
	}
    }
	
    if (optind >= argc) {
        printf("사용법: %s [디렉토리 경로]\n", argv[0]);
        return 1;
    }

    for (int i = optind; i < argc; i++) {
    	char *dirPath = argv[i];

    	int result = mkdir(dirPath, 0777);
    	if (result == 0) {
            if(seccess_message){
		printf("mkdir: created directory '%s'\n", argv[i]);
	    }
    	} else {
            printf("디렉토리 생성에 실패했습니다.\n");
            return 1;
    	}

        return 0;
    }
}