//existing problems from the excercise: the open cell 2 and 3 also check the mines, revealing them, should give player the ability to flag the mines
//solution being made: add a boolean expression, too lazy to add flagging

#include <stdio.h>
#include <stdlib.h>
#define M 10//Y
#define N 10//X, I think(?)
#define MINE -1
#define EMPTY " ."
#define FLAG " x"
#define UNREVEALED " #"
/*Ma?ng B lu?u ba?ng dô` mi`n*/
int B[M][N];
/*Ma?ng T lu?u tra?ng tha´i ca´c o^*/
int T[M][N];
int minesLeft = 0;

void count_mines(){
    int compX, compY;
    for(int currY = 0; currY < M; currY++){
    for(int currX = 0; currX < N; currX++){
        if (B[currY][currX] == 0){ //check3x3                               calc3x3
                                     for(int indexY = -1; indexY < 2; indexY++){compY = currY + indexY;
        if (compY !=-1 && compY < M) for(int indexX = -1; indexX < 2; indexX++){compX = currX + indexX;
        if (compX !=-1 && compX < N && !(indexY == 0 && indexX == 0)){
            if (B[compY][compX] == -1){
                B[currY][currX]++;
            };
        };
        };
        };
        };
    };
    };
    
}

void printMap1(){
    printf(" ");
    for (int i = 0; i<N; i++)//print x grid
        printf("%2d", i);
    printf("\n");
    for (int currY= 0; currY < M; currY++){/*1*/printf("%d", currY);
    for (int currX= 0; currX < N; currX++){/*2*/
        if (!(B[currY][currX]))
            printf(EMPTY);
        else if (B[currY][currX] == -1)
            printf(FLAG);
        else
            printf("%2d", B[currY][currX]);
    /*2*/};
    printf("\n");/*1*/};
    return;
}

void printMap2(){
    printf(" ");
    for (int i = 0; i<N; i++)//print x grid
        printf("%2d", i);
    printf("\n");
    for (int currY= 0; currY < M; currY++){/*1*/printf("%d", currY);
    for (int currX= 0; currX < N; currX++){/*2*/
        if (!(T[currY][currX])) /*the extra check differ from printMap1()*/
            printf(UNREVEALED);
        else if (!(B[currY][currX]))
            printf(EMPTY);
        else if (B[currY][currX] == -1)
            printf(FLAG);
        else
            printf("%2d", B[currY][currX]);
    /*2*/};
    printf("\n");/*1*/};
}

int count_remain(){
    int g = 0;
    for (int currY= 0; currY < M; currY++){/*1*/
    for (int currX= 0; currX < N; currX++){/*2*/
        if (!(T[currY][currX]))
            g++;
    /*2*/};
    /*1*/};
    return g;
}


void open_cell_3(int r, int c){
    if (T[r][c] == 1)
        return;
    T[r][c] = 1;
    if (B[r][c] == 0){
    int compX, compY, currY = r, currX = c;
    if (B[currY][currX] == 0){ //check3x3                               calc3x3
                                     for(int indexY = -1; indexY < 2; indexY++){compY = currY + indexY;
        if (compY !=-1 && compY < M) for(int indexX = -1; indexX < 2; indexX++){compX = currX + indexX;
        if (compX !=-1 && compX < N && !(indexY == 0 && indexX == 0 && B[compY][compX] != -1)){
        	open_cell_3(compY, compX);
        };
        };
        };
        };
    };
    
}

void seeding(int A1,int B1, int percen, int seed){
    if (seed == 0)
        srand(rand());
    else srand(seed);
    for (int currY= 0; currY < M; currY++){/*1*/
    for (int currX= 0; currX < N; currX++){/*2*/
    //if (!(currY == A1 && currX == B1)){
    if (!(rand() % percen)){
        B[currY][currX] = -1;
        if (B[currY][currX] == -1)
            minesLeft++;
    }
        //};
    /*2*/};
    /*1*/};
}

void init(){
    for (int i = 0; i<M; i++){
        for (int j = 0; j<N; j++){
            T[i][j] = 0;
            B[i][j] = 0;
        }
    };
    return;
}



int main()
{
    int inputY,inputX, play = 1, win, percen, seed;
    while (play){
    init();
    printf("type in probability of a mine each tile, the first tile remains as not a mine (1-99 in a 100): ");
    scanf("%d", &percen);
    percen = 100/percen;
    printf("set seed for generation (0/1 for default, take a number from RANDOM.ORG for true randomness): ");
    scanf("%d", &seed);
    printf("make your first move (type in \"[row] [col]\"): ");
    scanf("%d%d", &inputY, &inputX);
    if (inputY == 177013|| inputX == 21022009)
        break;//cheatcode, stop the game
    
    seeding(inputY, inputX, percen, seed);
    
    B[inputY][inputX] = 0;
    count_mines();
    open_cell_3(inputY,inputX);
    printMap2();
    win = 1;
    
    while (!(count_remain()== minesLeft)){
        printf("\n current left: %d  | existing mines: %d  | your move (type in \"[row] [col]\"): ", count_remain(), minesLeft);
        scanf("%d%d", &inputY, &inputX);
        if (inputY == 177013|| inputX == 21022009)
            break;//cheatcode, win
        if (inputY == 230|| inputX == 6671)
            printMap1();//cheatcode, show the whole map, then crash the game (side effect bug)
        open_cell_3(inputY,inputX);
        printMap2();
        if (B[inputY][inputX] == -1){
            printf("Dumbass, or unlucky");
            win = 0;
            break;
        };
    };
    if (win){
    for (int i = rand() % ((400 + 1 - 1) + 1); i > 0; i--){
        printf("congratulation");
        for (int j = rand() % (3 + 1 - 0) + 0; j > 0; j--){
            printf("\t");
        };
        if (!(rand() % 13))
            printf("\n");
    };
    };
    printf("\n");
    printf("play again (1/0)? ");
    scanf("%d", &play);
    };
    return 0;
}
