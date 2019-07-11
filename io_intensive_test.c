#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"


int main(int argc, char const *argv[])
{
    int k, n=4, id;

    for (k=0; k <n; k++) {
        id = fork();
        if (id < 0) {
            printf(1, "%d failed in fork!\n", getpid());
        }
        else if (id > 0) {
            printf(1, "Parent %d creating child %d!\n", getpid(), id);
        } else { //child
            printf(1, "Child %d created\n", getpid());
            int fd;
            char *buf = "testtesttesttest";
            for (int i=0; i < 100; i++) {
                char* file_name = (char*)malloc(20 * sizeof(char));
                file_name[0] = id + 57;
                fd = open(file_name, O_WRONLY);
                write (fd, buf, 16);
                close (fd);
            }
            break;
        }
    }
    
    exit();
}