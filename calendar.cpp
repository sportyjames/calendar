#include <iostream>
#include <string>

using namespace std;

int main()
{

    //declare variables
    int y, c, m, w,year, monthlen;
    string month;

    //get user input
    printf("Enter month and year: (leave a space between them)：\n");
    scanf("%d%d", &year, &m);
    y = year % 100;//last 2 digits of year
    c = y / 100;//first 2 digits of year

     if (m == 1 || m == 2) { //determine if month is 1 or 2
         y--;
         m += 12;//turn month 1 or 2 to 13 or 14.
     }
     w = y + y / 4 + c / 4 - 2 * c + 13 * (m + 1) / 5 + 1 - 1;//蔡勒公式
     while (w < 0)
     {
         //make sure the remainder is positive
         w += 7;
     }
     w %= 7; //calculate the day for 1st of certain month


    //month
    switch(m)
     {
         case 03 :
              month = "March" ;
              break;
         case 04 :
              month = "April" ;
              break;
         case 05 :
              month = "May" ;
              break;
         case 06 :
              month = "June" ;
              break;
         case 07 :
              month = "July" ;
              break;
         case 8 :
              month = "August" ;
              break;
         case 9 :
              month = "September" ;
              break;
         case 10 :
              month = "Octomber" ;
              break;
         case 11 :
              month = "November" ;
              break;
         case 12 :
              month = "December" ;
              break;
         case 13 :
              month = "January";
              break;
         case 14 :
              month = "Febuary" ;
              break;
     }

     //month number
     switch(m)
     {
         case 03 :
              monthlen = 31 ;
              break;
         case 04 :
              monthlen = 30 ;
              break;
         case 05 :
              monthlen = 31 ;
              break;
         case 06 :
              monthlen = 30 ;
              break;
         case 07 :
              monthlen = 31 ;
              break;
         case 8 :
              monthlen = 31 ;
              break;
         case 9 :
              monthlen = 30 ;
              break;
         case 10 :
              monthlen = 31 ;
              break;
         case 11 :
              monthlen = 30 ;
              break;
         case 12 :
              monthlen = 31 ;
              break;
         case 13 :
              monthlen = 31 ;
              break;
         case 14 :
              if((year%4==0 && year%100!=0 )||(year%400==0)) //determine leap year
              {
                  monthlen = 29 ;
              }
              else
              {
                  monthlen = 28;
              }
              break;
    }




     printf ("\n");

     //make a calendar
     printf ("         Calendar - %d\n\n", year);

     // Print the current month name
     printf("\n  ------------%s-------------\n",
               month.c_str());

     // Print the columns
     printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    // Print appropriate spaces
    int k;
    for (k = 0; k < w; k++)
    {
        printf("     ");
    }


    for (int j = 1; j <= monthlen; j++)
    {
        printf("%5d", j);

        //confused about this part
        if (++k > 6)
        {
            k = 0;
            printf("\n");
        }

    }

    //confused about this part
    if (k)
        printf("\n");

    //confused about this part
    w = k;

    return 0;
}
