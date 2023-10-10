#include <stdio.h>

int main(int argc, const char * argv[]) {
        //const char * argv[] = {"./a.out", "192.168.1.5", "9999"};
        int i;

        printf("argc=%d\n", argc);

        for (i = 0; i < argc; i++) {
                printf("%s\n", argv[i]);
        }

        return 0;
}

