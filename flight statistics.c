#include<stdio.h>
#include<string.h>

void populate_list(char[]);
void count_flights(char[], int*, int*);
void display_frequency(int, int);

int main()
{
    char flights[100];
    int tk=0, pc=0;
    printf("Enter the list of flights:\n");
    populate_list(flights);
    count_flights(flights, &tk, &pc);
    display_frequency(tk, pc);



    return 0;
}

void populate_list(char flights[])
{
    int checker=0;
    char temp[100];
    do
    {

        gets(temp);
        if(temp[0]!='P' && temp[1]!='C')
        {
            if(temp[0]!='T' && temp[1]!='K')
            {
                if(temp[0]!='E'&& temp[1]!='x' && temp[2]!='i' && temp[3]!='t')
                {
                    printf("\nWrong flight code! Flight code should start with PC or TK!\n");
                    checker=1;
                }


            }

        }
        if((temp[3]<'0' || temp[3]>'9') && checker==0)
        {
            if(temp[0]!='E'&& temp[1]!='x' && temp[2]!='i' && temp[3]!='t')
            {
                printf("\nWrong flight code! Flight code format is IATA code + flight number\n");
                checker=1;
            }
        }
        if(temp[2]!=' ' && checker==0)
        {
            if(temp[0]!='E'&& temp[1]!='x' && temp[2]!='i' && temp[3]!='t')
            {
                printf("\nWrong flight code! Flight code format is IATA code + flight number!\n");
                checker=1;
            }
        }


        if(checker==0)
        {
            strcat(flights, temp);
        }
        checker=0;




    }
    while(temp[0]!='E'&& temp[1]!='x' && temp[2]!='i' && temp[3]!='t');


}
void count_flights(char flights[],int* tk, int* pc)
{
    int x;
    for(x=0; x<100; x++)
    {
        if(flights[x]=='P' && flights[x+1]=='C')
        {
            (*pc)++;
        }
        if(flights[x]=='T' && flights[x+1]=='K')
        {
            (*tk)++;
        }

    }

}

void display_frequency(int tk, int pc)
{
    printf("\nStatistics today:\n");
    printf("Turkish Airlines (TK): %d", tk);
    printf("\nPegasus Airlines (PC): %d", pc);
}
