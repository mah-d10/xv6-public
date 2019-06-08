#include "types.h"
#include "user.h"

int main(int argc, char* argv[])
{
    invoked_syscalls(atoi(argv[1]));
    exit();
}