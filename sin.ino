/* automatically generated, do not edit */

#include <stdbool.h>
#include <stdint.h>

#define digitalWrite_pin_2 digitalWrite
#define digitalWrite_pin_3 digitalWrite
#define digitalWrite_pin_4 digitalWrite
#define digitalWrite_pin_5 digitalWrite
void output_Serial(uint8_t arg2) {
  Serial.print("sec:");
  Serial.print(arg2);
  Serial.print('\n');
}

#include <stdint.h>
#include <stdbool.h>
#include <string.h>


static uint8_t s0[(1)] = {(0)};
static size_t s0_idx = (0);

uint8_t s0_gen(void) {
  return (((s0)[s0_idx]) + (1)) % (15);
}

bool output_Serial_guard(void) {
  return true;
}

uint8_t output_Serial_arg0(void) {
  return (s0)[s0_idx];
}

bool digitalWrite_pin_4_guard(void) {
  return true;
}

int16_t digitalWrite_pin_4_arg0(void) {
  return 4;
}

bool digitalWrite_pin_4_arg1(void) {
  return ((bool [(6)]){(false), (false), (true), (true), (true), (false)})[((((s0)[s0_idx]) >= (0)) && (((s0)[s0_idx]) < (3))) ? 0 : ((((s0)[s0_idx]) == (3)) ? 1 : ((((s0)[s0_idx]) == (4)) ? 2 : (((((s0)[s0_idx]) >= (5)) && (((s0)[s0_idx]) < (13))) ? 3 : ((((s0)[s0_idx]) == (13)) ? 4 : (5)))))];
}

bool digitalWrite_pin_5_guard(void) {
  return true;
}

int16_t digitalWrite_pin_5_arg0(void) {
  return 5;
}

bool digitalWrite_pin_5_arg1(void) {
  return ((bool [(6)]){(true), (true), (true), (false), (true), (true)})[((((s0)[s0_idx]) >= (0)) && (((s0)[s0_idx]) < (3))) ? 0 : ((((s0)[s0_idx]) == (3)) ? 1 : ((((s0)[s0_idx]) == (4)) ? 2 : (((((s0)[s0_idx]) >= (5)) && (((s0)[s0_idx]) < (13))) ? 3 : ((((s0)[s0_idx]) == (13)) ? 4 : (5)))))];
}

bool digitalWrite_pin_2_guard(void) {
  return true;
}

int16_t digitalWrite_pin_2_arg0(void) {
  return 2;
}

bool digitalWrite_pin_2_arg1(void) {
  return ((bool [(6)]){(true), (true), (false), (false), (false), (true)})[((((s0)[s0_idx]) >= (0)) && (((s0)[s0_idx]) < (3))) ? 0 : ((((s0)[s0_idx]) == (3)) ? 1 : ((((s0)[s0_idx]) == (4)) ? 2 : (((((s0)[s0_idx]) >= (5)) && (((s0)[s0_idx]) < (13))) ? 3 : ((((s0)[s0_idx]) == (13)) ? 4 : (5)))))];
}

bool digitalWrite_pin_3_guard(void) {
  return true;
}

int16_t digitalWrite_pin_3_arg0(void) {
  return 3;
}

bool digitalWrite_pin_3_arg1(void) {
  return ((bool [(6)]){(false), (true), (true), (true), (true), (true)})[((((s0)[s0_idx]) >= (0)) && (((s0)[s0_idx]) < (3))) ? 0 : ((((s0)[s0_idx]) == (3)) ? 1 : ((((s0)[s0_idx]) == (4)) ? 2 : (((((s0)[s0_idx]) >= (5)) && (((s0)[s0_idx]) < (13))) ? 3 : ((((s0)[s0_idx]) == (13)) ? 4 : (5)))))];
}

bool delay_guard(void) {
  return true;
}

uint32_t delay_arg0(void) {
  return 1000;
}

void step(void) {
  uint8_t s0_tmp;
  if ((output_Serial_guard)()) {
    (output_Serial)(((output_Serial_arg0)()));
  };
  if ((digitalWrite_pin_4_guard)()) {
    (digitalWrite_pin_4)(((digitalWrite_pin_4_arg0)()), ((digitalWrite_pin_4_arg1)()));
  };
  if ((digitalWrite_pin_5_guard)()) {
    (digitalWrite_pin_5)(((digitalWrite_pin_5_arg0)()), ((digitalWrite_pin_5_arg1)()));
  };
  if ((digitalWrite_pin_2_guard)()) {
    (digitalWrite_pin_2)(((digitalWrite_pin_2_arg0)()), ((digitalWrite_pin_2_arg1)()));
  };
  if ((digitalWrite_pin_3_guard)()) {
    (digitalWrite_pin_3)(((digitalWrite_pin_3_arg0)()), ((digitalWrite_pin_3_arg1)()));
  };
  if ((delay_guard)()) {
    (delay)(((delay_arg0)()));
  };
  (s0_tmp) = ((s0_gen)());
  ((s0)[s0_idx]) = (s0_tmp);
  (s0_idx) = ((++(s0_idx)) % (1));
}

void setup()
{
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop()
{
  step();
}
