#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>

#define P1 'X'
#define P2 'O'

int brPoteza = 9,p1p2;
char tabela[3][3];

void printEmpTabela();
void prinTabela();
int proveraPolja(int x, int y);
char proveraPobednika();
void kompjuter();


main()
{
    int i, j, x, y,izbor,greska;
    char pobednik = ' ';
    

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            tabela[i][j] = ' ';
        }
    }

    printf("\nZelite li da igrate protiv 1.)kompjutera ili 2.)protiv drugog igraca?: ");
    while (1) {
        scanf("%d", &izbor);
        if (izbor == 1 || izbor == 2)
            break;
        else
            printf("\nUneti opciju 1 za komp ili opciju 2 za igraca");
    }

    printEmpTabela();

    while (1)
    {
        //P1
        while (1)
        {
            p1p2 = 1;
            puts("Igrac 1: ");
            scanf("%d%d", &x, &y);
            x--;
            y--;
            greska=proveraPolja(x, y);
            if (!greska) continue;
            prinTabela();
            putchar('\n');
            pobednik = proveraPobednika();
            break;
        }
        if (pobednik != ' ') break;
        if (!brPoteza)break;
        //KOMP
        if (izbor == 1)
        {
            p1p2 = 2;
            kompjuter();
            prinTabela();
            pobednik = proveraPobednika();
            
        }

        //P2
        else if (izbor == 2)
        {
            while (1)
            {
                p1p2 = 2;
                puts("Igrac 2: ");
                scanf("%d%d", &x, &y);
                x--;
                y--;
                greska=proveraPolja(x, y);
                if (!greska) continue;
                prinTabela();
                pobednik = proveraPobednika();
                break;
            }
            
        }
        if (pobednik != ' ') break;
        if (!brPoteza)break;
    }
 
    if (pobednik == P1)
        printf("\nPobedio je igrac 1!");
    else if(pobednik==P2)
        printf("\nPobedio je igrac 2!");
    else
        printf("\nIgra je neresena");
}

void kompjuter()
{
    srand(time(0));
    int x, y;
    
    do {
        x = rand() % 3;
        y = rand() % 3;
    } while (tabela[x][y] != ' ');
    brPoteza--;
    tabela[x][y] = P2;
}

void prinTabela()
{
    printf("  %c | %c | %c ", tabela[0][0], tabela[0][1], tabela[0][2]);
    printf("\n ---|---|---\n");
    printf("  %c | %c | %c ", tabela[1][0], tabela[1][1], tabela[1][2]);
    printf("\n ---|---|---\n");
    printf("  %c | %c | %c ", tabela[2][0], tabela[2][1], tabela[2][2]);
    printf("\n");
}
void printEmpTabela()
{
    printf("\n   1.1 | 1.2 | 1.3 ");
    printf("\n   ----|-----|----\n");
    printf("   2.1 | 2.2 | 2.3 ");
    printf("\n   ----|-----|----\n");
    printf("   3.1 | 3.2 | 3.3 ");
    printf("\n");
}

int proveraPolja(int x, int y)
{
    while (1) {
        if (tabela[x][y] != ' ')
        {
            printf("Greska!\n");
            return 0;
            break;
            
        }
        else {
            if(p1p2==1)
                tabela[x][y] = P1;
            else if(p1p2==2)
                tabela[x][y] = P2;
            brPoteza--;
            return 1;
            break;
        }
    }
}

char proveraPobednika()
{
    int i, j;
    char pobednik;
    for (i = 0; i < 3; i++)
    {
        if ((tabela[i][0] == tabela[i][1] && tabela[i][0] == tabela[i][2])&&tabela[i][0]!=' ')
        {
            return tabela[i][0];
        }
       
        else if ((tabela[0][i] == tabela[1][i] && tabela[0][i] == tabela[2][i]) && tabela[0][i] != ' ')
        {
            return tabela[0][i];
        }
    }

    if ((tabela[0][0] == tabela[1][1] && tabela[0][0] == tabela[2][2]) && tabela[0][0] != ' ')
    {
       return tabela[0][0];
    }

    else if ((tabela[0][2] == tabela[1][1] && tabela[0][2] == tabela[2][0]) && tabela[2][0] != ' ')
    {
        return tabela[0][2];
    }
    else
    return  ' ';
    
}