#include <unistd.h>
#include <fcntl.h>

void main(void)
{
    const char text[] = "This a very trash program, haha as you know, it is trash\n";
    (void)write(1, text, sizeof(text) - 1);
    return;
}
