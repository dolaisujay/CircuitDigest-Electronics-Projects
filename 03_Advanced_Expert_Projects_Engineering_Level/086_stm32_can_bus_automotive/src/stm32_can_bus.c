// STM32 CAN Bus Interface
#include "stm32f4xx_hal.h"

CAN_HandleTypeDef hcan;

int main(void) {
  HAL_Init();
  // Initialize CAN1 @ 500kbps Baud Rate
  while(1) {
    // Transmit & Receive CAN frames
  }
}
