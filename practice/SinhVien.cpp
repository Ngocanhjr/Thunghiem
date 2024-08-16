#include <stdio.h>
#define sizeOfStudentCode 10
#define sizeOfStudentName 50
#define sizeOfClass 50

struct SinhVien{
    char studentCode [sizeOfStudentCode];
    char name [sizeOfStudentName];
};
typedef SinhVien SinhVien;
 
void readListOfStudent (SinhVien sv[], int numberOfStudent);
void printListOfStudent (SinhVien sv[], int numberOfStudent);
void sortByStudentCode (SinhVien SV[], int numberOfStudent);
void swap (SinhVien &a, SinhVien &b);
void swap1 ( SinhVien *a, SinhVien *b);
void swap2 ( SinhVien a, SinhVien b);

int main (){
    int numOfStudent;
    printf("Enter number of student in class: ");
    scanf("%d", &numOfStudent);
    getchar();
    SinhVien sv[sizeOfClass];
    readListOfStudent(sv,numOfStudent);
    printf("----------------------------\n");
    printListOfStudent(sv,numOfStudent);
    // check swap
    // SinhVien a = {"112","le thi"};
    // SinhVien b = {"113", "bgo as"};
    // printf("before\n%s %s", a.name,a.studentCode);
    // printf("\n%s %s", b.name,b.studentCode);
    // swap(a,b);
    // printf("\nafter\n%s %s", a.name,a.studentCode);
    // printf("\n%s %s", b.name,b.studentCode);
    
}

void readListOfStudent (SinhVien sv[], int numberOfStudent){
    for (int i =0; i < numberOfStudent; i++){
        printf ("Student %d:", i + 1);
        printf ("\nEnter student code: ");
        fgets(sv[i].studentCode, sizeOfStudentCode, stdin);
        printf ("Enter name of student: ");
        fgets(sv[i].name,sizeOfStudentName,stdin);
    }
}

void printListOfStudent (SinhVien sv[], int numberOfStudent){
    for ( int i = 0; i < numberOfStudent; i++){
        printf ("Student %d:\n", i + 1);
        printf("Student code: %s", sv[i].studentCode);
        printf("Student name: %s", sv[i].name);
    }
}

void sortByStudentCode (SinhVien sv[], int numberOfStudent){
    //selection sort
    for (int i = 0; i < numberOfStudent - 1; i++ ){
        int min_pos = i;
        for ( int j = i + 1; j < numberOfStudent; j++){
            if( sv[i].studentCode > sv[j].studentCode){
                min_pos = j;
            }
        }
        swap(sv[i],sv[min_pos]);
    }
}
void swap ( SinhVien &a, SinhVien &b){
    SinhVien c = a;
    a = b;
    b = c;
}
void swap1 ( SinhVien *a, SinhVien *b){
    SinhVien c = *a;
    *a = *b;
    *b = c;
}

void swap2 ( SinhVien a, SinhVien b){
    SinhVien c = a;
    a = b;
    b = c;
}
