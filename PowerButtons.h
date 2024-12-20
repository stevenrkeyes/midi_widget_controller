#ifndef POWERBUTTONS_H
#define POWERBUTTONS_H

#include "limits.h"
#include <Bounce2.h>
#include "ConsoleWidget.h"
#include "pins.h"

#define POWER_BUTTONS_NUM 5

constexpr int POWER_BUTTONS_PINS[] = { POWER_BUTTONS_BUTTON1_PIN,
                                       POWER_BUTTONS_BUTTON2_PIN,
                                       POWER_BUTTONS_BUTTON3_PIN,
                                       POWER_BUTTONS_BUTTON4_PIN,
                                       POWER_BUTTONS_BUTTON5_PIN };

constexpr int POWER_BUTTONS_LED_PINS[] = { POWER_BUTTONS_LED1_PIN,
                                           POWER_BUTTONS_LED2_PIN,
                                           POWER_BUTTONS_LED3_PIN,
                                           POWER_BUTTONS_LED4_PIN,
                                           POWER_BUTTONS_LED5_PIN };

class PowerButtons : public ConsoleWidget {
public:
  PowerButtons();
  void setup() override;
  void CheckDataSendHID() override;
  void UpdateAnimationFrame() override;

private:
  bool activated[POWER_BUTTONS_NUM] = {false};
  unsigned long pressTimesMs[POWER_BUTTONS_NUM] = { ULONG_MAX };
  Bounce buttons[POWER_BUTTONS_NUM];
};

#endif
