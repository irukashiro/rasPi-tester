
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(void) {
    int fd;
    int gpio_num;

    scanf("使用するピン=%d", &gpio_num);

    /* GPIO操作ファイル生成 */
    fd = open("/sys/class/gpio/export", O_RDWR);
    dprintf(fd, "%d", gpio_num);  // gpio_numを直接書き込む
    close(fd);
    sleep(1);

    /* GPIOを出力に変更 */
    fd = open("/sys/class/gpio/gpio15/direction", O_RDWR);
    write(fd, "out", 3);  // "out"はそのまま
    close(fd);

    /* GPIOの出力をON */
    printf("GPIO%d にvalue 書き込みます！\n", gpio_num);
    fd = open("/sys/class/gpio/gpio15/value", O_RDWR);
    write(fd, "1", 1);  // ONの場合、"1"を書き込む
    close(fd);
    sleep(10);

    /* GPIO操作ファイル削除 */
    fd = open("/sys/class/gpio/unexport", O_RDWR);
    dprintf(fd, "%d", gpio_num);  // gpio_numを直接書き込む
    close(fd);

    return 0;
}

    
