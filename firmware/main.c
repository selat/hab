#include <libopencm3/cm3/common.h>
#include <libopencm3/stm32/f1/rcc.h>
#include <libopencm3/stm32/gpio.h>

static void delay_seconds(int seconds) {
  int i = 72000000 / 2 / 4 * seconds;
  while (i > 0) {
    i--;
    __asm__("nop");
  }
}

int main(void) {
  rcc_clock_setup_in_hse_8mhz_out_72mhz();

  rcc_periph_clock_enable(RCC_GPIOC);
  gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_2_MHZ, GPIO_CNF_OUTPUT_PUSHPULL,
                GPIO13);

  while (1) {
    gpio_toggle(GPIOC, GPIO13);
    delay_seconds(1);
  }
}
