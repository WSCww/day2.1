/*===============================================
*   文件名称：1.c
*   创 建 者：     
*   创建日期：2026年04月13日
*   描    述：
================================================*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h> // 包含 close 函数的头文件

int main(int argc, char *argv[])
{
    int fd;
    // 打开文件
    // 注意：原截图中的 110 110 应该是输入错误，标准权限为 0664
    fd = open("1.txt",O_RDWR | O_CREAT, 0664); 

    if(-1 == fd){
        // 打开失败
        perror("open fail\n");
        return -1;
    }

    printf("fd is %d\n",fd);
    
    // 关闭文件描述符
    close(fd);
    
    return 0;
}
 
