#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void printLineNum(FILE *file) {
    char line[BUFSIZ];
    int lineNumber = 1;

    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%6d  %s", lineNumber, line);
        lineNumber++;
    }
}

void printLineExist(FILE *file) {
    char line[BUFSIZ];
    int lineNumber = 1;

    while (fgets(line, sizeof(line), file) != NULL) {
	if (line[0] == '\n') {
	    printf("\n");
	} else {
	    printf("%6d  %s", lineNumber, line);
            lineNumber++;
	}
    }
}

void printLineDollar(FILE *file) {
    char line[BUFSIZ];

    while (fgets(line, sizeof(line), file) != NULL) {
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '$';
            printf("%s\n", line);
        } else if (len == 0) {
            printf("$\n");
        } else {
            printf("%s\n", line);
        }
    }
}

void printTabExpanded(FILE *file) {
    int c;

    while ((c = getc(file)) != EOF) {
        if (c == '\t') {
            putchar('^');
	    putchar('I');
        } else {
            putchar(c);
        }
    }
}

void printShowAll(FILE *file) {
    int c;

    while ((c = getc(file)) != EOF) {
        if (c == '\t') {
            putchar('^');
            putchar('I');
        } else if (c == '\n') {
            putchar('$');
	    putchar(c);
        } else {
	    putchar(c);
	}
    }
}

void printSqueezedLines(FILE *file) {
    char line[BUFSIZ];
    int emptyLine = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        if (line[0] == '\n') {
            if (emptyLine == 0) {
                printf("%s", line);
                emptyLine = 1;
            }
        } else {
            printf("%s", line);
            emptyLine = 0;
        }
    }
}

int main(int argc, char *argv[]) {
    int c;
    int line_number = 0;
    int line_dollar = 0;
    int tab_expanded = 0;
    int line_exist = 0;
    int show_all = 0;
    int squeeze_line = 0;
    int opt;

    while ((opt = getopt(argc, argv, "AbEnsT")) != -1) {
        switch (opt) {
	    case 'b':
		line_exist = 1;
		break;
	    case 'n':
                line_number = 1;
                break;
            case 'E':
                line_dollar = 1;
                break;
	    case 'T':
		tab_expanded = 1;
		break;
	    case 'A':
		show_all = 1;
		break;
	    case 's':
		squeeze_line = 1;
		break;
	    Defualt:
                fprintf(stderr, "사용법: %s [option] [file] ...\n", argv[0]);
                return 1;
        }
    }

    for (int i = optind; i < argc; i++) {
	FILE *file = fopen(argv[i], "r");
        if (file == NULL) {
            fprintf(stderr, "파일을 열 수 없습니다: %s\n", argv[i]);
            continue;
        }
	
	if (squeeze_line) {
	    printSqueezedLines(file);
	} else if (show_all) {
	    printShowAll(file);
	} else if (line_exist) {
	    printLineExist(file);
	} else if (tab_expanded) {
            printTabExpanded(file);
        } else if (line_dollar) {
            printLineDollar(file);
        } else if (line_number) {
	    printLineNum(file);
        } else {
	    while ((c = getc(file)) != EOF)
                putc(c, stdout);
	}

        fclose(file);
    }

    return 0;
}