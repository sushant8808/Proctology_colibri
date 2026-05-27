#ifndef DAC8552_H
#define DAC8552_H

#include <QObject>
// Minimal DAC8552 test via /dev/spidevX.Y
// Usage examples:
//   ./dac8552_spidev /dev/spidev0.0 A 32768
//   ./dac8552_spidev /dev/spidev0.0 B 65535
//   ./dac8552_spidev /dev/spidev0.0 A v 1.650 3.300   // 1.65V with Vref=3.3V
//
// Notes:
// - Uses SPI mode 1 (CPOL=0, CPHA=1) since DAC8552 clocks data on the *falling* edge.
// - Sends one 24-bit frame (3 bytes) per write, keeping CS low for the whole frame.


#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <linux/spi/spidev.h>

static int spi_send24(int fd, uint8_t cbyte, uint16_t code, uint32_t hz)
{
    uint8_t tx[3];
    tx[0] = cbyte;
    tx[1] = (uint8_t)((code >> 8) & 0xFF);
    tx[2] = (uint8_t)(code & 0xFF);

    struct spi_ioc_transfer xfer = {
        .tx_buf = (unsigned long)tx,
        .rx_buf = 0,
        .len = sizeof(tx),
        .speed_hz = hz,
        .delay_usecs = 0,
        .bits_per_word = 8,
        .cs_change = 0,   // keep CS asserted only for this frame
    };
    int ret = ioctl(fd, SPI_IOC_MESSAGE(1), &xfer);
    return (ret < 1) ? -1 : 0;
}

static uint16_t volts_to_code(double vout, double vref)
{
    if (vout < 0) vout = 0;
    if (vout > vref) vout = vref;
    double code = (vout * 65535.0) / vref; // unipolar straight binary
    if (code < 0) code = 0;
    if (code > 65535) code = 65535;
    return (uint16_t)(code + 0.5);
}

static uint16_t hapros_to_code(uint16_t powerwatt)
{
//    double code ; // unipolar straight binary
//    if (powerwatt < 0) code = 0;
//    if (powerwatt > 15) code = 15;

//    code = 65535;
//    return (uint16_t)(code + 0.5);
}
class DAC8552 : public QObject
{
    Q_OBJECT
public:
    explicit DAC8552(QObject *parent = nullptr);
    int setDac(short ch, int powerwatt);

signals:

};

#endif // DAC8552_H
