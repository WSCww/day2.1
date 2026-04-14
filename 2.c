/*===============================================
*   文件名称：2.c
*   创 建 者：     
*   创建日期：2026年04月14日
*   描    述：
================================================*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>  // 包含 close、read 函数的头文件
#include <string.h>  // 可选，用于字符串处理

int main(int argc, char *argv[])
{
    int fd;
    // 打开文件：可读可写 | 不存在则创建，权限0664（最终权限受umask影响）
    fd = open("1.txt", O_RDWR | O_CREAT, 0664); // 110 110 100 对应八进制0664

    if(-1 == fd){
        // 打开失败
        perror("open fail\n");
        return -1;
    }

    printf("fd is %d\n",fd);

    // 定义读取相关变量
    ssize_t ret;  // read 函数返回值类型为ssize_t，而非size_t（修正类型）
    char buf[1024] = {0};  // 初始化缓冲区

    // 从文件描述符fd读取最多8字节数据到buf
    ret = read(fd, buf, 8);

    if(ret == -1){
        perror("read fail\n");
        return -1;
    }

    // 打印读取到的内容
    printf("%s\n",buf);

    // 关闭文件描述符
    close(fd);

    return 0;
}
