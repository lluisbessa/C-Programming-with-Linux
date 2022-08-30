#include <stdio.h>

int main(int argc,char **argv){
    FILE *ifile;
    int i,num,grade;
    double total = 0.0;
    if (argc == 2) {
        ifile = fopen(argv[1], "r");
        fscanf(ifile, "%d", &num);
        for (i=0; i<num; i++){
            fscanf(ifile,"%d", &grade);
            total += (double) grade;
        }
        total = total / (double) num;
        printf("Class average grade is: %.2lf.\n", total);
    } else {
        printf("Usage: ./program fileWithGrades\n");
    }
}
