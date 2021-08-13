#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define max 9001

int adj_mat[max][max];
int main()
{
  int i, j, n,deg = 0,edge=0,hand;

    double total_time;
    clock_t start,end;

    printf("How many Vertices : ");
    scanf("%d",&n);

    srand(2);
    start=clock();

    for(i=0; i<n; i++)
        {
        for(j=0; j<n; j++)
        {
                if(i<j)
            {
                adj_mat[i][j] = rand()%2;
                adj_mat[j][i] = adj_mat[i][j];
                if(adj_mat[i][j]==1)
                edge++;

            }
            if(i==j)
               {
                   adj_mat[i][j] = rand()%2;
                   if(adj_mat[i][j]==1)
                   edge++;
               }
            }
        }

    deg = 0;
     printf("Total Edge is : %d \n",edge);
    for ( i = 0 ; i < n ; i++ )
    {

        for ( j = 0 ; j < n ; j++ )
            if ( adj_mat[i][j] == 1)
               {
                   deg++;
                if(i==j)
                   deg++;
               }

    }
    printf("Total Degree of Vertex is : %d\n",deg);
    hand=deg/2;
    printf("The number of edge is=(Sum of degree/2)=(%d/2)=%d\n",deg,hand);
    if(hand==edge)
        printf("So Handshaking Theorem is proved\n");
    else
        printf("Handshaking Theorem is not proved\n");
    end=clock();
    total_time=((double)(end-start)/CLOCKS_PER_SEC)*pow(10,9);

     printf("Execution time is : %1f ns \n",total_time);
     printf("\n");

     return 0;
}

