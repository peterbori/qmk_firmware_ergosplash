
#pragma once

// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM 250

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define QUICK_TAP_TERM 0

// Apply the modifier on keys that are tapped during a short hold of a modtap
#define PERMISSIVE_HOLD

// Using the right side as master
#define MASTER_RIGHT
//#define SPLIT_HAND_PIN B1
#define SPLIT_USB_DETECT
//#define SPLIT_USB_TIMEOUT 2500

// If your PC does not recognize Keyball, try setting this macro. This macro
// increases the firmware size by 200 bytes, so it is disabled by default, but
// it has been reported to work well in such cases.
#define SPLIT_WATCHDOG_ENABLE 	


#ifdef PS2_MOUSE_ENABLE
#define PS2_MOUSE_SCROLL_BTN_MASK 0x05
#define PS2_MOUSE_SCROLL_BTN_SEND 500
#endif