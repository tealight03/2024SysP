#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int opt;
    int verbose = 0;
    int quiet = 0;
    int num_plus = 0;

    int num_lines = 10;

    while ((opt = getopt(argc, argv, "vqn:")) != -1) {
        switch (opt) {
            case 'v':
                verbose = 1;
                break;
            case 'q':
                quiet = 1;
                break;
            case 'n':
		if (optarg[0] == '+')
		    num_plus = 1;
                num_lines = atoi(optarg);
                break;
            default:
                fprintf(stderr, "사용법: %s [옵션] [파일]\n", argv[0]);
                return 1;
        }
    }

    if (optind >= argc) {
        fprintf(stderr, "사용법: %s [옵션] [파일]\n", argv[0]);
        return 1;
    }

    for (int i = optind; i < argc; i++) {
        const char *file_name = argv[i];

        FILE *file = fopen(file_name, "r");
        if (file == NULL) {
            perror("fopen");
            continue;
        }

        if ((verbose || argc-optind >= 2) && !quiet) {
            printf("==> %s <==\n", file_name);
        }

	char buffer[100];
        char lines[100][100];
        int lineCount = 0;
        int startLine = 0;
	int endLine = 0;

        while (fgets(buffer, sizeof(buffer), file) != NULL) {
            strcpy(lines[lineCount], buffer);
            lineCount++;
    	}

        startLine = (lineCount > num_lines) ? (lineCount - num_lines) : 0;
	if(num_plus)
	    startLine = num_lines-1;
        endLine = lineCount;

        for (int j = startLine; j < endLine; j++) {
            printf("%s", lines[j]);
        }

        if (!(i == argc-1) && !quiet){
            printf("\n");
        }

        fclose(file);
    }

    return 0;
}