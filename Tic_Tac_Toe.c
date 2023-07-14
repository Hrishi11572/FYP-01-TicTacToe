// Tic Tac Toe //
#include<stdio.h>
#include<stdlib.h>

char element[] = { '0' , '1' , '2' , '3' , '4' , '5' , '6' , '7' , '8' , '9' } ;

void printmyGame()
{    system("clear") ;
    printf(" ===  My Tic Tac Toe Game === \n\n") ;
    printf("        |      |       \n") ;
    printf("    %c   |  %c   |   %c    \n" , element[1] , element[2] , element[3]) ;
    printf(" _______|______|______ \n") ;
    printf("        |      |       \n") ;
    printf("    %c   |  %c   |   %c   \n" , element[4] , element[5] , element[6]) ;
    printf(" _______|______|______ \n") ;
    printf("        |      |       \n") ;
    printf("    %c   |  %c   |   %c  \n" , element[7] , element[8] , element[9]) ;
    printf("        |      |      \n") ;
    
}

int Wincondition()
{
    if( element[1] == element[4] && element[4]==element[7]) return 1 ;
    if( element[2] == element[5] && element[5]==element[8]) return 1 ;
    if( element[3] == element[6] && element[6]==element[9]) return 1 ;

    if( element[1] == element[2] && element[2]==element[3]) return 1 ;
    if( element[4] == element[5] && element[5]==element[6]) return 1 ;
    if( element[7] == element[8] && element[8]==element[9]) return 1 ;
    
    if( element[1] == element[5] && element[5]==element[9]) return 1 ;
    if( element[7] == element[5] && element[5]==element[3]) return 1 ;
    
    int count = 0 ;
    for( int i =1 ; i<=9 ; i++)
    {
        if( element[i] == 'X' || element[i] == 'O')
        {
            count ++ ;
        }
    }
    if( count == 9 ) return 0 ;

     return -1 ;
}

int main()
{  
    char ply1[20] , ply2[20]; 

    printf("Player 1  , enter your name : ") ;
     scanf("%s" , ply1) ;

    printf("Player 2 ,  enter your name : ") ; 
     scanf("%s" , ply2) ;
    
    // Starting the Game //
    printmyGame() ;
     
    //declaring players as 1 and 2 //
    int player = 1 ;
    int current = -1  ; // Depicts continuing Game //
    int input  ;
    char mark ;
    int result ;

   while( current == -1 )
   {
       
    player = (player%2 != 0) ? 1 : 2 ;

   // For Player 1 mark = X , for Player 2 mark = O //
    mark  = (player == 1) ? 'X' : 'O' ;

   // Input //
   printf("Input the position dear player %d : " , player) ;
   scanf("%d" , &input ) ;

   // Threshold Check //
   if( input < 1 || input > 9) {
     printf("Wrong Input\n") ;  exit(0)  ; 
     }

    element[input] = mark ;
    printmyGame() ;


    result = Wincondition() ;
    if( result == 1 )
    { 
        printf("The Winner is player %d" , player) ;
         if( player == 1)
         {
            printf("\nCongrats! %s " , ply1 ) ;
         }

         if( player == 2)
         {
             printf("\nCongrats! %s" , ply2 ) ;
         }
        exit(0) ;

    }
    else if( result == 0 )
    {
        printf(" Bingo ! its a draw ") ;
        exit(0) ;
    }

   player++ ;

   }

    return 0 ;
}
