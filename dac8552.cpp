#include "dac8552.h"
#include <QDebug>

DAC8552::DAC8552(QObject *parent) : QObject(parent)
{

}

int DAC8552::setDac(short ch, int powerwatt)
{
//    qDebug()<<Q_FUNC_INFO<<ch<<powerwatt;
    if(ch>=0 &&ch<2){
        const char *dev = "/dev/colibri-spi-cs0";
        uint8_t control;
        if (ch == 0) {
            control = 0x10;      // 0b0001_0000 : Write data & LOAD DAC A, Buffer Select = A, PD=00
        } else if (ch == 1) {
            control = 0x24;      // 0b0010_0100 : Write data & LOAD DAC B, Buffer Select = B, PD=00
        } else {
//            qDebug()<<Q_FUNC_INFO<<"Channel must be A or B\n";
            return 1;
        }

        int fd = open(dev, O_RDWR);
        if (fd < 0) { perror("open spidev"); return 1; }

        // Configure SPI: mode 1, 8 bits/word, 1 MHz (safe default)
        uint8_t mode = SPI_MODE_1;
        uint8_t bpw  = 8;
        uint32_t hz  = 1000000;

        if (ioctl(fd, SPI_IOC_WR_MODE, &mode) < 0) { perror("SPI_IOC_WR_MODE"); return 1; }
        if (ioctl(fd, SPI_IOC_WR_BITS_PER_WORD, &bpw) < 0) { perror("SPI_IOC_WR_BITS_PER_WORD"); return 1; }
        if (ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &hz) < 0) { perror("SPI_IOC_WR_MAX_SPEED_HZ"); return 1; }

        uint16_t code = 0;
        code = (uint16_t)powerwatt;


        if (spi_send24(fd, control, code, hz) < 0) {
            perror("spi xfer");
            close(fd);
            return 1;
        }

//        qDebug()<<Q_FUNC_INFO<<"Wrote channel" <<ch<<code;
        close(fd);
        return 0;
    }
    else{
//        qDebug()<<Q_FUNC_INFO<<"invalid channel value";
        return 1;
    }






}
