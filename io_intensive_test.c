#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"


int main(int argc, char const *argv[])
{
    int n = 6;

    for (int i=0; i < n; i++) {
        int rc = fork();
        if (rc < 0)
        {
            printf(1, "failed in fork!\n");
        }
        if (rc > 0) 
        {
            while (wait() <= 0)
            {
            }

            printf(1, "parent %d creating child %d!\n", getpid(), rc);
            int fd;
            char *buffer = "123456789";
            for (int i=0; i < 100; i++) 
            {
                char* file = (char*)malloc(15 * sizeof(char));
                file[0] = rc;
                fd = open(file, O_WRONLY);
                write (fd, buffer, 10);
                close (fd);
            }

        }
        if(rc == 0) 
        { 
            printf(1, "Child %d created\n", getpid());
            int fd;
            char *buffer = "123456789";
            for (int i=0; i < 100; i++) 
            {
                char* file = (char*)malloc(15 * sizeof(char));
                file[0] = rc;
                fd = open(file, O_WRONLY);
                write (fd, buffer, 10);
                close (fd);
            }
            break;
        }
    }
    
    exit();
}