#include "core/powerSave.h"
#include <interface.h>

#define BTN_UP   3
#define BTN_DOWN   8
#define BTN_LEFT   9
#define BTN_RIGHT   14
#define BTN_OK   0
/***************************************************************************************
** Function name: _setup_gpio()
** Location: main.cpp
** Description:   initial setup for the device
***************************************************************************************/
void _setup_gpio() { 
    pinMode(BTN_UP, INPUT_PULLUP);
    pinMode(BTN_DOWN, INPUT_PULLUP);
    pinMode(BTN_LEFT, INPUT_PULLUP);
    pinMode(BTN_RIGHT, INPUT_PULLUP);
    pinMode(BTN_OK, INPUT_PULLUP);

    // Mặc định cho Bruce biết board này dùng nút bấm
    bruceConfig.startupApp = "Main Menu"; 
    Serial.println(F("Bruce Interface: S3 Custom Buttons Initialized (3, 8, 9, 14, 0)"));
}

/***************************************************************************************
** Function name: _post_setup_gpio()
** Location: main.cpp
** Description:   second stage gpio setup to make a few functions work
***************************************************************************************/
void _post_setup_gpio() {}

/***************************************************************************************
** Function name: getBattery()
** location: display.cpp
** Description:   Delivers the battery value from 1-100
***************************************************************************************/
int getBattery() { return 0; }

/*********************************************************************
** Function: setBrightness
** location: settings.cpp
** set brightness value
**********************************************************************/
void _setBrightness(uint8_t brightval) {}

/*********************************************************************
** Function: InputHandler
** Handles the variables PrevPress, NextPress, SelPress, AnyKeyPress and EscPress
**********************************************************************/
void InputHandler(void) {
    checkPowerSaveTime();
    
    // Reset trạng thái trước khi quét mới
    PrevPress = false;
    NextPress = false;
    SelPress  = false;
    AnyKeyPress = false;
    EscPress  = false;

    // 1. Kiểm tra nếu CÓ BẤT KỲ nút nào được nhấn
    if (digitalRead(BTN_UP) == LOW || digitalRead(BTN_DOWN) == LOW || 
        digitalRead(BTN_LEFT) == LOW || digitalRead(BTN_RIGHT) == LOW || 
        digitalRead(BTN_OK) == LOW) 
    {
        // Nếu màn hình đang ngủ, nhấn nút bất kỳ để đánh thức
        if (!wakeUpScreen()) {
            AnyKeyPress = true;
        } else {
            // Nếu vừa tỉnh dậy thì bỏ qua lệnh này để tránh bấm nhầm vào menu
            goto END;
        }
    }

    // 2. Gán lệnh cụ thể cho từng nút (LOW = Đang nhấn)
    if (digitalRead(BTN_UP) == LOW)    { PrevPress = true; } // Cuộn lên
    if (digitalRead(BTN_DOWN) == LOW)  { NextPress = true; } // Cuộn xuống
    if (digitalRead(BTN_LEFT) == LOW)  { EscPress = true;  } // Quay lại / Thoát
    if (digitalRead(BTN_OK) == LOW)    { SelPress = true;  } // Chọn / Enter
    if (digitalRead(BTN_RIGHT) == LOW) { NextPress = true; } // Sang phải (map vào Next cho tiện)

END:
    // 3. Chống dội phím (Debounce) và đợi nhả phím
    if (AnyKeyPress || PrevPress || NextPress || SelPress || EscPress) {
        long tmp = millis();
        // Đợi phím được nhả ra hoặc tối đa 200ms để không bị trượt menu quá nhanh
        while ((millis() - tmp) < 200 && (
            digitalRead(BTN_UP) == LOW || digitalRead(BTN_DOWN) == LOW || 
            digitalRead(BTN_LEFT) == LOW || digitalRead(BTN_RIGHT) == LOW || 
            digitalRead(BTN_OK) == LOW
        )) {
            yield(); // Giúp ESP32 không bị Watchdog Reset
        }
    }
}
/*********************************************************************
** Function: keyboard
** location: mykeyboard.cpp
** Starts keyboard to type data
**********************************************************************/
String keyboard(String mytext, int maxSize, String msg) {}

/*********************************************************************
** Function: powerOff
** location: mykeyboard.cpp
** Turns off the device (or try to)
**********************************************************************/
void powerOff() {}

/*********************************************************************
** Function: checkReboot
** location: mykeyboard.cpp
** Btn logic to turn off the device (name is odd btw)
**********************************************************************/
void checkReboot() {}
