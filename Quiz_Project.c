#define _GNU_SOURCE
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#define QNO 30
#define totques 10
#define size 200


void asked(char option[size], const char option1[size], const char option2[size],
           const char option3[size], const char option4[size],const char correct[size], const char category[size],FILE * fp,int *);

void Display();
void show_record();
void reset_score();
void help();
void edit_score(float, char []);
int main()
{
    char text[size],option1[size], option2[size], option3[size], option4[size], option[size], correct[size], category[size];
    char empty[256][256];
    int i,j,k;
    int arr[QNO],x,loc;
    time_t t;
    char line[256];
    int score = 0;
    int count;
    char choice;
    char playername[20];
    FILE * fp;
    FILE * output;
    fp = fopen("Quiz.txt","r");
    output = fopen("NewText.txt","w");
    if(fp == NULL)
    {
        printf("\n\n\n \t\t\t Quiz File Can't Be OPENED \t\t\t \n\n\n");
    }
    if(output == NULL)
    {
        printf("\n\n\n \t\t\t NewText File Can't Be CREATED \t\t\t \n\n\n");
    }

    Display();

mainhome:
    system("cls");
    printf("\t\t\t   C PROGRAM QUIZ GAME\n");
    printf("\n\t\t______________");

    printf("\n\t\t\t   MAIN MENU");
    printf("\n\t\t >    1 START");
    printf("\n\t\t >    2 HIGHEST SCORE ");
    printf("\n\t\t >    3 RESET SCORE");
    printf("\n\t\t >    4 HELP           ");
    printf("\n\t\t >    5 QUIT             ");
    printf("\n\t\t______________\n\n");
    choice=toupper(getch());
    if (choice=='2')
    {
        show_record();
        goto mainhome;
    }
    else if (choice=='4')
    {
        help();
        getch();
        goto mainhome;
    }
    else if (choice=='3')
    {
        reset_score();
        getch();
        goto mainhome;
    }
    else if (choice=='5')
        exit(1);
    else if(choice=='1')
    {
        system("cls");

        printf("\n\n\n\n\n\n\n\n\n\n\t\t\tResister your name:");
        gets(playername);

        system("cls");
        printf("\n ------------------  Welcome %s to C Program Quiz Game --------------------------",playername);
        printf("\n\n Here are some tips you might wanna know before playing:");
        printf("\n -------------------------------------------------------------------------");
        printf("\n >> You will be asked a total of 10 questions. Each right answer will be awarded 4 points.");
        printf("\n    By this way you can score a highest total of 40 points!!!!!..........");
        printf("\n >> You will be given 4 options and you have to press A, B ,C or D for the");
        printf("\n    right option.");
        printf("\n >> No negative marking for wrong answers!");
        printf("\n\n\t!!!!!!!!!!!!! ALL THE BEST !!!!!!!!!!!!!");
        printf("\n\n\n Press Y  to start the game!\n");
        printf("\n Press any other key to return to the main menu!");
        if (toupper(getch())=='Y')
        {
            goto home;
        }
        else
        {
            goto mainhome;
            system("cls");
        }

home:
        system("cls");
        count=0;
        printf("\n\n\n\n\t!Press any key to Start the Game!");
        if(toupper(getch())=='p')
        {
            goto game;
        }
game:

        k = 0;

        for (i = 0; i < 30; i++)
        {
            arr[i] = 10 * i + 1;
        }

        for (j = 0; j < totques; j++)
        {
            srand((unsigned)time(&t));
            x = rand() % 3;
            loc = (3 * j) + x;

            for (i = arr[3 * j]; i < arr[loc]; i++)
            {
                fgets(empty[k],sizeof(empty[k]),fp);
                k++;
            }

            for (i = 1; i <= 10; i++)
            {
                fgets(line,sizeof(line),fp);
                if(i==1)
                {
                    printf("\n\n\n\n\n\nQ%d) %s",j+1,line);
                    fprintf(output,"Q%d) %s",j+1,line);

                }

                if(i==2)
                {
                    fputs(line,output);
                }

                if(i == 3)
                    strncpy(option1,line,30);

                if(i == 4)
                    strncpy(option2,line,30);

                if(i == 5)
                    strncpy(option3,line,30);

                if(i == 6)
                    strncpy(option4,line,30);

                if (i >1&&i<=7)
                {
                    printf("%s",line);

                }
                if (i == 8)
                    strncpy(correct,line,30);

                if (i == 9)
                    strncpy(category,line,30);
            }


            asked(option, option1, option2, option3, option4, correct, category,output,&score);

            if(j!=9)
            {

                if (arr[loc] + 10 < arr[3 * (j + 1)])
                {
                    for (i = arr[loc] + 10; i < arr[3 * (j + 1)]; i++)
                    {
                        fgets(empty[k],sizeof(empty[k]),fp);
                        k++;
                    }
                }
            }


            system("cls");
        }

        fprintf(output," \n You got total %d out of 40 ",score);

        fclose(fp);

        fclose(output);

        output = fopen("Newtext.txt","r");

        while(fgets(line,sizeof(line),output))
        {
            printf("%s",line);

        }

        fclose(output);
        system("pause");
        return 0;
    }
    else
    {
        printf("        !!!Enter valid option!!!  \n  ");
        system("pause");
        system("cls");
        goto mainhome;
    }
}
    void asked(char option[size], const char option1[size], const char option2[size], const char option3[size], const char option4[size],
               const char correct[size], const char category[size],FILE * fp,int *score)
    {
        printf("Your Option : ");
        scanf("%str",&option[0]);
        fflush(stdin);
        option[1] = '\0';
        strupr(option);

        char correctanswer[size];
        char wronganswer[size];

        fprintf(fp,"%s \n",category);

        if (option[0] == correct[0])
        {
            if (option[0] == option1[0])
                fprintf(fp," \nYou entered correct answer : %s  \n ", option1);
            if (option[0] == option2[0])
                fprintf(fp," \nYou entered correct answer : %s  \n ", option2);
            if (option[0] == option3[0])
                fprintf(fp," \nYou entered correct answer : %s  \n ", option3);
            if (option[0] == option4[0])
                fprintf(fp," \nYou entered correct answer : %s  \n ", option4);

            *score += 4;

            fprintf(fp," \n You are awarded 4 marks for this correct answer \n ");
        }
        else
        {

            if (correct[0] == option1[0])
                strncpy(correctanswer, option1,24);
            if (correct[0] == option2[0])
                strncpy(correctanswer, option2,24);
            if (correct[0] == option3[0])
                strncpy(correctanswer, option3,24);
            if (correct[0] == option4[0])
                strncpy(correctanswer, option4,24);

            correctanswer[24] = '\0';

            if (option[0] == option1[0])
                strncpy(wronganswer, option1,24);
            if (option[0] == option2[0])
                strncpy(wronganswer, option2,24);
            if (option[0] == option3[0])
                strncpy(wronganswer, option3,24);
            if (option[0] == option4[0])
                strncpy(wronganswer, option4,24);

            wronganswer[24] = '\0';

            fprintf(fp," You entered     : %s \n", wronganswer);
            fprintf(fp," Correct answer  : %s \n", correctanswer);
            fprintf(fp," \n You are awarded 0 marks for this wrong answer \n ");
        }

        fprintf(fp," -----------------------------------------------------------------------------\n");
        fprintf(fp," -----------------------------------------------------------------------------\n");
    }
    void show_record()
    {
        system("cls");
        char name[20];
        float scr;
        FILE *f;
        f=fopen("score.txt","r");
        fscanf(f,"%s%f",name,&scr);
        fflush(stdin);
        printf("\n\n\t\t*********************");
        printf("\n\n\t\t %s has secured the Highest Score %0.2f",name,scr);
        printf("\n\n\t\t*********************");
        fclose(f);
        getch();
    }

    void reset_score()
    {
        system("cls");
        float sc;
        char nm[20];
        FILE *fp;
        fp=fopen("score.txt","r+");
        fscanf(fp,"%s%f",nm,&sc);
        fflush(stdin);
        sc=0;
        fprintf(fp,"%s,%.2f",nm,sc);
        fclose(fp);
    }

    void help()
    {
        system("cls");
        printf("\n\n                              HELP");
        printf("\n >> You will be asked a total of 10 questions. Each right answer will be awarded 4 points.");
        printf("\n    By this way you can score a highest total of 40 points!!!!!..........");
        printf("\n >> You will be given 4 options and you have to press A, B ,C or D for the");
        printf("\n    right option.");
        printf("\n >> No negative marking for wrong answers!");

        printf("\n\n\t********BEST OF LUCK************");
    }

    void edit_score(float score, char plnm[20])
    {
        system("cls");
        float sc;
        char nm[20];
        FILE *fp;
        fp=fopen("score.txt","r");
        fscanf(fp,"%s%f",nm,&sc);
        fflush(stdin);
        if (score>=sc)
        {
            sc=score;
            fclose(fp);
            fp=fopen("score.txt","w");
            fprintf(fp,"%s\n%.2f",plnm,sc);
            fclose(fp);
        }
    }
    void Display()
    {
        printf("\n\n\n\n\n\n");
        printf("\n\t   +-------+                          ___       ___                                              ");
        printf("\n\t   |       |      |         |            |                /                                              ");
        printf("\n\t   |       |      |         |            |               /                                               ");
        printf("\n\t   |       |      |         |            |              /                                                ");
        printf("\n\t   |    // |      |         |            |             /                                                 ");
        printf("\n\t   |   //  |      |         |            |            /                                                  ");
        printf("\n\t   +--//---+      |___|         _|_        /___                                          \n\n  ");
         system("pause");
        system("cls");
         const int trigger = 500; // ms
    const int numDots = 4;
    const char prompt[] = "Loading";
    int load=0;
    while (load<3) {
        printf("\r%*s\r%s", sizeof(prompt) - 1 + numDots, "", prompt);
        fflush(stdout);


        for (int i = 0; i < numDots; i++) {
            usleep(trigger * 1000);
            fputc('.', stdout);
            fflush(stdout);
        }
        load++;
     }
    }