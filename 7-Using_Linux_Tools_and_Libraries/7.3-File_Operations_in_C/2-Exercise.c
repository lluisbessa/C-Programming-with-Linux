#include <stdio.h>

int main(int argc,char **argv){
    FILE *ifile;
    int i,num,grade;
    double total = 0.0;
    if (argc == 2) {
        ifile = fopen(argv[1], "r");
        while(fscanf(ifile, "%d", &grade) != EOF) {
            total += (double) grade;
            num++;
        }
        total = total / (double) num;
        printf("Class average grade is: %.2lf.\n", total);
    } else {
        printf("Usage: ./program fileWithGrades\n");
    }
}
