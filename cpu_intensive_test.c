#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char const* argv[])
{
    int k, n = 4, id;
    double x=0, z;


    for (k=0; k <n; k++) 
    {
        id = fork();
        if (id < 0) {
            printf(1, "%d failed in fork!\n", getpid());
        }
        if (id > 0)
        {
            while (wait() <= 0)
            {
                /* code */
            }
            
            printf(1, "Parent %d creating child %d!\n", getpid(), id);
            for (z = 0; z < 100000; z++) 
            {
                x = x * 69 * 69;
            }
        } 
        if(id == 0) 
        {
            printf(1, "Child %d created\n", getpid());
            for (z = 0; z < 100000; z++)
            {
                x = x * 0.1 * 0.2;
            }
            break;
        }
    }
    exit();
}