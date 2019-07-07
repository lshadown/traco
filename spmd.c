/*****************************************************************************
commmand line arguments: 
Unbalanced, but use Block Distribution
S0: {[i,j,k] -> [-i] }
S1: {[i,j] -> [-i] }
T0: {[i,j,k] -> [0,j,0,i,0,k,0] }
T1: {[i,j] -> [1,j,0,i,0,0,0] }
****************************************************************************/

#include "runtime.h"

#include <stdio.h>
#include <math.h>
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))

int _suif_nproc = 0;
extern void (**volatile _suif_aligned_task_f)(int);

static void doall_body(int _my_id)
    {
    int global_lb, global_ub;
    int block_size;
    int lb, ub;
    int _counter0 = 1;
    int _counter1 = 1;
    int _my_nprocs = suif_num_total_ids();
    int t1, t2, t4, t6;
    int S[9999+1][9999+1];
    int N;

    global_lb = 0;
    global_ub = N-2;
    block_size = max(0,(global_ub-global_lb+1+(_my_nprocs-1))/_my_nprocs);
    lb = global_lb+_my_id*block_size;
    ub = min(global_ub,lb+block_size-1);

    for (t2 = 1; t2 <= N-1; t2++)
        {
        for (t4 = max(-t2+1,-ub); t4 <= min(0,-lb); t4++)
            {
            for (t6 = 0; t6 <= t4+t2-1; t6++)
                {
                S[-t4][t2] = max(S[-t4][t6+(-t4)]+S[t6+(-t4)+1][t2],S[-t4][t2]);
                }
            }
        }
    for (t2 = 1; t2 <= N-1; t2++)
        {
        for (t4 = max(-t2+1,-ub); t4 <= min(0,-lb); t4++)
            {
            S[-t4][t2] = (max(S[-t4][t2],S[-t4+1][t2-1]))+(max(-t4,t2));
            }
        }
    }

extern int _suif_start(int argc, char **argv, char **envp)
    {
    double time;
    suif_counter_init_range(1);

    *_suif_aligned_task_f = doall_body;
    time = suif_clock();
    suif_doall(doall_body);
    time = suif_clock() - time;
    printf("Executed program %s on %d processors in %lf seconds\n",
           argv[0], suif_num_total_ids(), time);

    return 0;
    }