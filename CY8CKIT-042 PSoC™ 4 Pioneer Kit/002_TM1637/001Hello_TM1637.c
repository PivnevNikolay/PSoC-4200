/**-----------------------------------------------------------------------
 *\date  29.08.2023
 *\brief
 *
 * Идея и примеры взяты отсюда:                https://github.com/GyverLibs/GyverTM1637
 *                                             https://alexgyver.ru/tm1637_display
 * The idea and examples are taken from here:  https://github.com/GyverLibs/GyverTM1637
 *                                             https://alexgyver.ru/tm1637_display
 *\ authors ScuratovaAnna, PivnevNikolay
 *\ сode debugging PivnevNikolay 
 *************************************************************************/

#include "project.h"

/* 
*  void  CyDelay(uint32 milliseconds);
*  void  CyDelayUs(uint16 microseconds);
*  void  CyDelayFreq(uint32 freq);
*  void  CyDelayCycles(uint32 cycles);
*/

#define ADDR_FIXED 0x44
#define ADDR_AUTO 0x40
const uint8_t digitHEX[] = { 0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f, 0x00, 0x40 };  //0~9
//*************************************************************************************************************
//                          H     E     L     L     O                   1     6     3     7            D     i     S     P
uint8_t Hello_world[] = { 0x76, 0x79, 0x38, 0x38, 0x3f, 0x00, 0x00, 0x06, 0x7d, 0x4f, 0x07, 0x00, 0x3f, 0x10, 0x6d, 0x73,
     //                        l     A     Y                               0    1    2    3    4    5    6    7    8    9
                          0x06, 0x77, 0x6e, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f };
//*************************************************************************************************************
uint8_t lastData[4];
uint8_t PointData;
uint8_t Cmd_DispCtrl;
uint8_t Cmd_SetData;
uint8_t Cmd_SetAddr;
//************************************************************************************************************

void clear(void);
void display(uint8_t BitAddr, uint8_t DispData);
void sendByte(uint8_t BitAddr, int8_t sendData);
void brightness_(uint8_t brightness, uint8_t SetData, uint8_t SetAddr);
 int write_Byte(uint8_t wr_data);
void update(void);
void displayByte(uint8_t DispData[]);
void send_Array(uint8_t sendData[]);
void start(void);
void stop(void);
void display_Byte(uint8_t bit0, uint8_t bit1, uint8_t bit2, uint8_t bit3);
void runningString(uint8_t DispData[], uint8_t amount, int delayMs);

int main(void) {
  CyGlobalIntEnable;

  clear();
  brightness_(7, 0x40, 0xc0);  // brightness, 0 - 7 (min - max)
  clear();
  display_Byte(0x3f, 0x06, 0x5b, 0x4f);
  CyDelay(1000);  //delay 1 seconds
  clear();
  display_Byte(0x66, 0x6d, 0x7d, 0x07);
  CyDelay(1000);  //delay 1 seconds

  for (;;) {
    runningString(Hello_world, sizeof(Hello_world), 350);
  }
}

void clear(void) {
  display(0x00, 0x7f);
  display(0x01, 0x7f);
  display(0x02, 0x7f);
  display(0x03, 0x7f);
  lastData[0] = 0x00;
  lastData[1] = 0x00;
  lastData[2] = 0x00;
  lastData[3] = 0x00;
}

void display(uint8_t BitAddr, uint8_t DispData) {
  uint8_t SegData;
  lastData[BitAddr] = digitHEX[DispData];
  SegData = digitHEX[DispData] + PointData;
  sendByte(BitAddr, SegData);
}

void sendByte(uint8_t BitAddr, int8_t sendData) {
  start();
  write_Byte(ADDR_FIXED);
  stop();
  start();
  write_Byte(BitAddr | 0xc0);
  write_Byte(sendData);
  stop();
  start();
  write_Byte(Cmd_DispCtrl);
  stop();
}

void brightness_(uint8_t brightness, uint8_t SetData, uint8_t SetAddr) {
  Cmd_SetData = SetData;
  Cmd_SetAddr = SetAddr;
  Cmd_DispCtrl = 0x88 + brightness;
  update();
}

int write_Byte(uint8_t wr_data) {
  uint8_t i;
  for (i = 0; i < 8; i++) {
    CLK_Write(0u);
    if (wr_data & 0x01) {
      DIO_Write(1u);
    } else DIO_Write(0u);
    wr_data >>= 1;
    CLK_Write(1u);
  }
  CLK_Write(0u);
  DIO_Write(1u);
  CLK_Write(1u);
  uint8_t ack = 1;
  CyDelayUs(50);
  if (DIO_Read() == 0) {
    DIO_Write(0u);
    ack = 0;
  }
  CyDelayUs(50);
  return ack;
}

void update(void) {
  displayByte(lastData);
}

void displayByte(uint8_t DispData[]) {
  uint8_t SegData[4];
  for (uint8_t i = 0; i < 4; i++) {
    lastData[i] = DispData[i];
    SegData[i] = DispData[i] + PointData;
  }
  send_Array(SegData);
}

void send_Array(uint8_t sendData[]) {
  start();
  write_Byte(ADDR_AUTO);
  stop();
  start();
  write_Byte(Cmd_SetAddr);
  for (uint8_t i = 0; i < 4; i++) {
    write_Byte(sendData[i]);
  }
  stop();
  start();
  write_Byte(Cmd_DispCtrl);
  stop();
}

void start(void) {
  CLK_Write(1u);
  DIO_Write(1u);
  DIO_Write(0u);
  CLK_Write(0u);
}

void stop(void) {
  CLK_Write(0u);
  DIO_Write(0u);
  CLK_Write(1u);
  DIO_Write(1u);
}

void display_Byte(uint8_t bit0, uint8_t bit1, uint8_t bit2, uint8_t bit3) {
  uint8_t dispArray[] = { bit0, bit1, bit2, bit3 };
  displayByte(dispArray);
}

void runningString(uint8_t DispData[], uint8_t amount, int delayMs) {
  uint8_t segm_data[amount + 8];
  for (uint8_t i = 0; i < 4; i++) {
    segm_data[i] = 0x00;
  }
  for (uint8_t i = 0; i < amount; i++) {
    segm_data[i + 4] = DispData[i];
  }
  for (uint8_t i = amount + 4; i < amount + 8; i++) {
    segm_data[i] = 0x00;
  }
  for (uint8_t i = 0; i <= amount + 4; i++) {
    display_Byte(segm_data[i], segm_data[i + 1], segm_data[i + 2], segm_data[i + 3]);
    CyDelay(delayMs);
  }
}