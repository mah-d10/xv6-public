#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char const* argv[])
{
    int n = 6;

    for (int i = 0; i < n; i++) 
    {
        double res = 0;
        int rc = fork();
        if (rc < 0) 
        {
            printf(1, "%d failed in fork!\n", getpid());
        }
        if (rc > 0)
        {
            while (wait() <= 0)
            {
            }
            
            printf(1, "parent %d creating child %d!\n", getpid(), rc);
            for (int k = 0; k < 100000; k++) 
            {
                res = res * 69 * 69;
            }
        } 
        if(rc == 0) 
        {
            printf(1, "child %d created\n", getpid());
            for (int k = 0; k < 100000; k++)
            {
                res = res * 0.1 * 0.2;
            }
            break;
        }
    }
    exit();
}