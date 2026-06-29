#include <stdio.h>

int main(int argc, char** argv) {
        if (argc != 2) return 0;
        for (int i = 0; argv[1][i]; ++i) {
                putchar(argv[1][i] - i);
        }
        putchar('\n');
        return 0;
}
