/* automatically generated, do not edit */

#include <stdbool.h>
#include <stdint.h>

#define digitalWrite_pin_2 digitalWrite
#define digitalWrite_pin_2_2 digitalWrite
#define digitalWrite_pin_2_3 digitalWrite
#define digitalWrite_pin_2_4 digitalWrite
#define digitalWrite_pin_2_5 digitalWrite
#define digitalWrite_pin_2_6 digitalWrite
#define digitalWrite_pin_3 digitalWrite
#define digitalWrite_pin_3_2 digitalWrite
#define digitalWrite_pin_3_3 digitalWrite
#define digitalWrite_pin_3_4 digitalWrite
#define digitalWrite_pin_3_5 digitalWrite
#define digitalWrite_pin_3_6 digitalWrite
#define digitalWrite_pin_4 digitalWrite
#define digitalWrite_pin_4_2 digitalWrite
#define digitalWrite_pin_4_3 digitalWrite
#define digitalWrite_pin_4_4 digitalWrite
#define digitalWrite_pin_4_5 digitalWrite
#define digitalWrite_pin_4_6 digitalWrite
#define digitalWrite_pin_5 digitalWrite
#define digitalWrite_pin_5_2 digitalWrite
#define digitalWrite_pin_5_3 digitalWrite
#define digitalWrite_pin_5_4 digitalWrite
#define digitalWrite_pin_5_5 digitalWrite
#define digitalWrite_pin_5_6 digitalWrite
void output_Serial(int8_t arg2) {
  Serial.print("sec:");
  Serial.print(arg2);
  Serial.print('\n');
}

#include <stdint.h>
#include <stdbool.h>
#include <string.h>


static bool s1[(1)] = {(true)};
static int8_t s0[(1)] = {(0)};
static size_t s1_idx = (0);
static size_t s0_idx = (0);

bool s1_gen(void) {
  return (s1)[s1_idx];
}

int8_t s0_gen(void) {
  return (((s0)[s0_idx]) == (14)) ? 0 : (((s1)[s1_idx]) ? ((s0)[s0_idx]) + (1) : ((s0)[s0_idx]));
}

bool output_Serial_guard(void) {
  return true;
}

int8_t output_Serial_arg0(void) {
  return (((s0)[s0_idx]) == (14)) ? 0 : (((s1)[s1_idx]) ? ((s0)[s0_idx]) + (1) : ((s0)[s0_idx]));
}

bool digitalWrite_pin_4_6_guard(void) {
  return ((((s0)[s0_idx]) == (14)) ? 0 : (((s1)[s1_idx]) ? ((s0)[s0_idx]) + (1) : ((s0)[s0_idx]))) == (14);
}

int16_t digitalWrite_pin_4_6_arg0(void) {
  return 4;
}

bool digitalWrite_pin_4_6_arg1(void) {
  return false;
}

bool digitalWrite_pin_5_6_guard(void) {
  return ((((s0)[s0_idx]) == (14)) ? 0 : (((s1)[s1_idx]) ? ((s0)[s0_idx]) + (1) : ((s0)[s0_idx]))) == (14);
}

int16_t digitalWrite_pin_5_6_arg0(void) {
  return 5;
}

bool digitalWrite_pin_5_6_arg1(void) {
  return true;
}

bool digitalWrite_pin_2_6_guard(void) {
  return ((((s0)[s0_idx]) == (14)) ? 0 : (((s1)[s1_idx]) ? ((s0)[s0_idx]) + (1) : ((s0)[s0_idx]))) == (14);
}

int16_t digitalWrite_pin_2_6_arg0(void) {
  return 2;
}

bool digitalWrite_pin_2_6_arg1(void) {
  return true;
}

bool digitalWrite_pin_3_6_guard(void) {
  return ((((s0)[s0_idx]) == (14)) ? 0 : (((s1)[s1_idx]) ? ((s0)[s0_idx]) + (1) : ((s0)[s0_idx]))) == (14);
}

int16_t digitalWrite_pin_3_6_arg0(void) {
  return 3;
}

bool digitalWrite_pin_3_6_arg1(void) {
  return true;
}

bool digitalWrite_pin_4_5_guard(void) {
  return ((((s0)[s0_idx]) == (14)) ? 0 : (((s1)[s1_idx]) ? ((s0)[s0_idx]) + (1) : ((s0)[s0_idx]))) == (13);
}

int16_t digitalWrite_pin_4_5_arg0(void) {
  return 4;
}

bool digitalWrite_pin_4_5_arg1(void) {
  return true;
}

bool digitalWrite_pin_5_5_guard(void) {
  return ((((s0)[s0_idx]) == (14)) ? 0 : (((s1)[s1_idx]) ? ((s0)[s0_idx]) + (1) : ((s0)[s0_idx]))) == (13);
}

int16_t digitalWrite_pin_5_5_arg0(void) {
  return 5;
}

bool digitalWrite_pin_5_5_arg1(void) {
  return true;
}

bool digitalWrite_pin_2_5_guard(void) {
  return ((((s0)[s0_idx]) == (14)) ? 0 : (((s1)[s1_idx]) ? ((s0)[s0_idx]) + (1) : ((s0)[s0_idx]))) == (13);
}

int16_t digitalWrite_pin_2_5_arg0(void) {
  return 2;
}

bool digitalWrite_pin_2_5_arg1(void) {
  return false;
}

bool digitalWrite_pin_3_5_guard(void) {
  return ((((s0)[s0_idx]) == (14)) ? 0 : (((s1)[s1_idx]) ? ((s0)[s0_idx]) + (1) : ((s0)[s0_idx]))) == (13);
}

int16_t digitalWrite_pin_3_5_arg0(void) {
  return 3;
}

bool digitalWrite_pin_3_5_arg1(void) {
  return true;
}

bool digitalWrite_pin_4_4_guard(void) {
  return (((((s0)[s0_idx]) == (14)) ? 0 : (((s1)[s1_idx]) ? ((s0)[s0_idx]) + (1) : ((s0)[s0_idx]))) >= (5)) && (((((s0)[s0_idx]) == (14)) ? 0 : (((s1)[s1_idx]) ? ((s0)[s0_idx]) + (1) : ((s0)[s0_idx]))) < (13));
}

int16_t digitalWrite_pin_4_4_arg0(void) {
  return 4;
}

bool digitalWrite_pin_4_4_arg1(void) {
  return true;
}

bool digitalWrite_pin_5_4_guard(void) {
  return (((((s0)[s0_idx]) == (14)) ? 0 : (((s1)[s1_idx]) ? ((s0)[s0_idx]) + (1) : ((s0)[s0_idx]))) >= (5)) && (((((s0)[s0_idx]) == (14)) ? 0 : (((s1)[s1_idx]) ? ((s0)[s0_idx]) + (1) : ((s0)[s0_idx]))) < (13));
}

int16_t digitalWrite_pin_5_4_arg0(void) {
  return 5;
}

bool digitalWrite_pin_5_4_arg1(void) {
  return false;
}

bool digitalWrite_pin_2_4_guard(void) {
  return (((((s0)[s0_idx]) == (14)) ? 0 : (((s1)[s1_idx]) ? ((s0)[s0_idx]) + (1) : ((s0)[s0_idx]))) >= (5)) && (((((s0)[s0_idx]) == (14)) ? 0 : (((s1)[s1_idx]) ? ((s0)[s0_idx]) + (1) : ((s0)[s0_idx]))) < (13));
}

int16_t digitalWrite_pin_2_4_arg0(void) {
  return 2;
}

bool digitalWrite_pin_2_4_arg1(void) {
  return false;
}

bool digitalWrite_pin_3_4_guard(void) {
  return (((((s0)[s0_idx]) == (14)) ? 0 : (((s1)[s1_idx]) ? ((s0)[s0_idx]) + (1) : ((s0)[s0_idx]))) >= (5)) && (((((s0)[s0_idx]) == (14)) ? 0 : (((s1)[s1_idx]) ? ((s0)[s0_idx]) + (1) : ((s0)[s0_idx]))) < (13));
}

int16_t digitalWrite_pin_3_4_arg0(void) {
  return 3;
}

bool digitalWrite_pin_3_4_arg1(void) {
  return true;
}

bool digitalWrite_pin_4_3_guard(void) {
  return ((((s0)[s0_idx]) == (14)) ? 0 : (((s1)[s1_idx]) ? ((s0)[s0_idx]) + (1) : ((s0)[s0_idx]))) == (4);
}

int16_t digitalWrite_pin_4_3_arg0(void) {
  return 4;
}

bool digitalWrite_pin_4_3_arg1(void) {
  return true;
}

bool digitalWrite_pin_5_3_guard(void) {
  return ((((s0)[s0_idx]) == (14)) ? 0 : (((s1)[s1_idx]) ? ((s0)[s0_idx]) + (1) : ((s0)[s0_idx]))) == (4);
}

int16_t digitalWrite_pin_5_3_arg0(void) {
  return 5;
}

bool digitalWrite_pin_5_3_arg1(void) {
  return true;
}

bool digitalWrite_pin_2_3_guard(void) {
  return ((((s0)[s0_idx]) == (14)) ? 0 : (((s1)[s1_idx]) ? ((s0)[s0_idx]) + (1) : ((s0)[s0_idx]))) == (4);
}

int16_t digitalWrite_pin_2_3_arg0(void) {
  return 2;
}

bool digitalWrite_pin_2_3_arg1(void) {
  return false;
}

bool digitalWrite_pin_3_3_guard(void) {
  return ((((s0)[s0_idx]) == (14)) ? 0 : (((s1)[s1_idx]) ? ((s0)[s0_idx]) + (1) : ((s0)[s0_idx]))) == (4);
}

int16_t digitalWrite_pin_3_3_arg0(void) {
  return 3;
}

bool digitalWrite_pin_3_3_arg1(void) {
  return true;
}

bool digitalWrite_pin_4_2_guard(void) {
  return ((((s0)[s0_idx]) == (14)) ? 0 : (((s1)[s1_idx]) ? ((s0)[s0_idx]) + (1) : ((s0)[s0_idx]))) == (3);
}

int16_t digitalWrite_pin_4_2_arg0(void) {
  return 4;
}

bool digitalWrite_pin_4_2_arg1(void) {
  return false;
}

bool digitalWrite_pin_5_2_guard(void) {
  return ((((s0)[s0_idx]) == (14)) ? 0 : (((s1)[s1_idx]) ? ((s0)[s0_idx]) + (1) : ((s0)[s0_idx]))) == (3);
}

int16_t digitalWrite_pin_5_2_arg0(void) {
  return 5;
}

bool digitalWrite_pin_5_2_arg1(void) {
  return true;
}

bool digitalWrite_pin_2_2_guard(void) {
  return ((((s0)[s0_idx]) == (14)) ? 0 : (((s1)[s1_idx]) ? ((s0)[s0_idx]) + (1) : ((s0)[s0_idx]))) == (3);
}

int16_t digitalWrite_pin_2_2_arg0(void) {
  return 2;
}

bool digitalWrite_pin_2_2_arg1(void) {
  return true;
}

bool digitalWrite_pin_3_2_guard(void) {
  return ((((s0)[s0_idx]) == (14)) ? 0 : (((s1)[s1_idx]) ? ((s0)[s0_idx]) + (1) : ((s0)[s0_idx]))) == (3);
}

int16_t digitalWrite_pin_3_2_arg0(void) {
  return 3;
}

bool digitalWrite_pin_3_2_arg1(void) {
  return true;
}

bool digitalWrite_pin_4_guard(void) {
  return (((((s0)[s0_idx]) == (14)) ? 0 : (((s1)[s1_idx]) ? ((s0)[s0_idx]) + (1) : ((s0)[s0_idx]))) >= (0)) && (((((s0)[s0_idx]) == (14)) ? 0 : (((s1)[s1_idx]) ? ((s0)[s0_idx]) + (1) : ((s0)[s0_idx]))) < (3));
}

int16_t digitalWrite_pin_4_arg0(void) {
  return 4;
}

bool digitalWrite_pin_4_arg1(void) {
  return false;
}

bool digitalWrite_pin_5_guard(void) {
  return (((((s0)[s0_idx]) == (14)) ? 0 : (((s1)[s1_idx]) ? ((s0)[s0_idx]) + (1) : ((s0)[s0_idx]))) >= (0)) && (((((s0)[s0_idx]) == (14)) ? 0 : (((s1)[s1_idx]) ? ((s0)[s0_idx]) + (1) : ((s0)[s0_idx]))) < (3));
}

int16_t digitalWrite_pin_5_arg0(void) {
  return 5;
}

bool digitalWrite_pin_5_arg1(void) {
  return true;
}

bool digitalWrite_pin_2_guard(void) {
  return (((((s0)[s0_idx]) == (14)) ? 0 : (((s1)[s1_idx]) ? ((s0)[s0_idx]) + (1) : ((s0)[s0_idx]))) >= (0)) && (((((s0)[s0_idx]) == (14)) ? 0 : (((s1)[s1_idx]) ? ((s0)[s0_idx]) + (1) : ((s0)[s0_idx]))) < (3));
}

int16_t digitalWrite_pin_2_arg0(void) {
  return 2;
}

bool digitalWrite_pin_2_arg1(void) {
  return true;
}

bool digitalWrite_pin_3_guard(void) {
  return (((((s0)[s0_idx]) == (14)) ? 0 : (((s1)[s1_idx]) ? ((s0)[s0_idx]) + (1) : ((s0)[s0_idx]))) >= (0)) && (((((s0)[s0_idx]) == (14)) ? 0 : (((s1)[s1_idx]) ? ((s0)[s0_idx]) + (1) : ((s0)[s0_idx]))) < (3));
}

int16_t digitalWrite_pin_3_arg0(void) {
  return 3;
}

bool digitalWrite_pin_3_arg1(void) {
  return false;
}

bool delay_guard(void) {
  return true;
}

uint32_t delay_arg0(void) {
  return 1000;
}

void step(void) {
  bool s1_tmp;
  int8_t s0_tmp;
  if ((output_Serial_guard)()) {
    (output_Serial)(((output_Serial_arg0)()));
  };
  if ((digitalWrite_pin_4_6_guard)()) {
    (digitalWrite_pin_4_6)(((digitalWrite_pin_4_6_arg0)()), ((digitalWrite_pin_4_6_arg1)()));
  };
  if ((digitalWrite_pin_5_6_guard)()) {
    (digitalWrite_pin_5_6)(((digitalWrite_pin_5_6_arg0)()), ((digitalWrite_pin_5_6_arg1)()));
  };
  if ((digitalWrite_pin_2_6_guard)()) {
    (digitalWrite_pin_2_6)(((digitalWrite_pin_2_6_arg0)()), ((digitalWrite_pin_2_6_arg1)()));
  };
  if ((digitalWrite_pin_3_6_guard)()) {
    (digitalWrite_pin_3_6)(((digitalWrite_pin_3_6_arg0)()), ((digitalWrite_pin_3_6_arg1)()));
  };
  if ((digitalWrite_pin_4_5_guard)()) {
    (digitalWrite_pin_4_5)(((digitalWrite_pin_4_5_arg0)()), ((digitalWrite_pin_4_5_arg1)()));
  };
  if ((digitalWrite_pin_5_5_guard)()) {
    (digitalWrite_pin_5_5)(((digitalWrite_pin_5_5_arg0)()), ((digitalWrite_pin_5_5_arg1)()));
  };
  if ((digitalWrite_pin_2_5_guard)()) {
    (digitalWrite_pin_2_5)(((digitalWrite_pin_2_5_arg0)()), ((digitalWrite_pin_2_5_arg1)()));
  };
  if ((digitalWrite_pin_3_5_guard)()) {
    (digitalWrite_pin_3_5)(((digitalWrite_pin_3_5_arg0)()), ((digitalWrite_pin_3_5_arg1)()));
  };
  if ((digitalWrite_pin_4_4_guard)()) {
    (digitalWrite_pin_4_4)(((digitalWrite_pin_4_4_arg0)()), ((digitalWrite_pin_4_4_arg1)()));
  };
  if ((digitalWrite_pin_5_4_guard)()) {
    (digitalWrite_pin_5_4)(((digitalWrite_pin_5_4_arg0)()), ((digitalWrite_pin_5_4_arg1)()));
  };
  if ((digitalWrite_pin_2_4_guard)()) {
    (digitalWrite_pin_2_4)(((digitalWrite_pin_2_4_arg0)()), ((digitalWrite_pin_2_4_arg1)()));
  };
  if ((digitalWrite_pin_3_4_guard)()) {
    (digitalWrite_pin_3_4)(((digitalWrite_pin_3_4_arg0)()), ((digitalWrite_pin_3_4_arg1)()));
  };
  if ((digitalWrite_pin_4_3_guard)()) {
    (digitalWrite_pin_4_3)(((digitalWrite_pin_4_3_arg0)()), ((digitalWrite_pin_4_3_arg1)()));
  };
  if ((digitalWrite_pin_5_3_guard)()) {
    (digitalWrite_pin_5_3)(((digitalWrite_pin_5_3_arg0)()), ((digitalWrite_pin_5_3_arg1)()));
  };
  if ((digitalWrite_pin_2_3_guard)()) {
    (digitalWrite_pin_2_3)(((digitalWrite_pin_2_3_arg0)()), ((digitalWrite_pin_2_3_arg1)()));
  };
  if ((digitalWrite_pin_3_3_guard)()) {
    (digitalWrite_pin_3_3)(((digitalWrite_pin_3_3_arg0)()), ((digitalWrite_pin_3_3_arg1)()));
  };
  if ((digitalWrite_pin_4_2_guard)()) {
    (digitalWrite_pin_4_2)(((digitalWrite_pin_4_2_arg0)()), ((digitalWrite_pin_4_2_arg1)()));
  };
  if ((digitalWrite_pin_5_2_guard)()) {
    (digitalWrite_pin_5_2)(((digitalWrite_pin_5_2_arg0)()), ((digitalWrite_pin_5_2_arg1)()));
  };
  if ((digitalWrite_pin_2_2_guard)()) {
    (digitalWrite_pin_2_2)(((digitalWrite_pin_2_2_arg0)()), ((digitalWrite_pin_2_2_arg1)()));
  };
  if ((digitalWrite_pin_3_2_guard)()) {
    (digitalWrite_pin_3_2)(((digitalWrite_pin_3_2_arg0)()), ((digitalWrite_pin_3_2_arg1)()));
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
  (s1_tmp) = ((s1_gen)());
  (s0_tmp) = ((s0_gen)());
  ((s1)[s1_idx]) = (s1_tmp);
  ((s0)[s0_idx]) = (s0_tmp);
  (s1_idx) = ((++(s1_idx)) % (1));
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
