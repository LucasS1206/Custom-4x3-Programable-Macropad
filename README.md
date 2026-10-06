# Custom 4x3 Macropad (with Rotary Encoder & OLED)
A custom 4x3 mechanical macropad I designed and built from scratch. This was designed for the intention of a dedicated keypad for a daily computer setup. I used this project as an opportunity to walk through the entire hardware development process from designing the circuit board in KiCad to writing the embedded C firmware in QMK.

## System Features
Layout: A 4x3 grid (12 keys) for custom shortcuts and macros.

Rotary Encoder: An EC11 clickable dial for master volume and media control.

Display: A 1.3" SH1106 OLED screen for real-time visual feedback.

Microcontroller: Pro Micro RP2040.

Firmware: Custom QMK integration, giving me complete control over every key switch, screen display, and dial action.

## Hardware Design (KiCad)
The hardware architecture and PCB were developed using KiCad 10.0:

Schematics: Built a 4x3 switch matrix with diodes to prevent key ghosting, alongside the specific pin routing for the encoder and microcontroller.

PCB Layout: Routed a compact, custom circuit board.

Iterative Design: During the layout phase, I caught and fixed an orientation error with the microcontroller footprint and adjusted the top-layer copper pour clearances to make sure the board would manufacture correctly without short-circuiting.

## QMK Firmware
The /Firmware directory contains the configuration files (keymap.c, keyboard.json, config.h, and rules.mk) required to run the system. Because the encoder's push-button is wired directly to its own pin (GP11) instead of the main matrix, I wrote custom C polling logic and internal pull-up initialization so the system reads it correctly.

## Repository Structure
/Hardware: The primary KiCad 10.0 design files (.kicad_pro, .kicad_sch, .kicad_pcb).

/Firmware: The custom QMK configuration source files.

/Docs: System documentation, including a PDF of the schematic, KiCad 3D board renders, and hardware layout notes.
