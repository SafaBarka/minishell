#include "header.h"
void ft_write(char *s)
{
    write(1, s, strlen(s));
}
int main(int argc , char *argv[] , char *envp[])
{
  ft_write("safa\n");
}