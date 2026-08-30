# **Slot Machine Game (C++)**
A C++ console based slot machine game developed for users on Windows. The game features a text UI with custom console text and background colouring, bet validation, chip management, a secret cheat code and an integrated Gambling Helpline reference

## **Features**
* *Source Control:* Uses GitHub to help manage history and rollback changes if needed, Repository: https://github.com/NZAntivist/SlotMachine
* *Dynamic Terminal Colouring:* Utilizes native Windows API console attributes (```SetConsoleTextAttribute```) to deliver coloured outputs for menus, messages and slot symbols.
* *Slot Machine Engine:* Features Random Number Generation to generate numbers for 3 spinning wheels with values between 2 and 7.
* *Pay-out System:*
  * Jackpot (7-7-7): 10x pay-out with rainbow celebration message
  * Super Win (any 3 of a kind): 5x pay-out.
  * Pair (any 2 of a kind): 3x pay-out
* *Input Handling and Validation:* Safe ```std::cin``` validation prevents crashing on invalid inputs (such as non-numeric characters, bets exceeding current chips, or negative values)
* *Cheat Code System:* A single use chip boost hidden in the credits and main menu to award extra chips.
* *Responsible Gaming:* Built-in option detailing local New Zealand helpline contact details.

## **Technical Specifications**
* *Language:* C++11
* *Platform:* Windows (```<Windows.h>```)
* *Education Provider:* Media Design School, Auckland, New Zealand
* *Author:* Sophie Jennings

## **Getting Started**
### **Prerequisites**
* *Operating System:* Windows 7/10/11
* *Compiler (if needed):* Any C++11 compliant compiler that supports the Windows SDK
### **How to play**
1. *Launch the game:* Run the compiled binary. Press Enter on the welcome screen.
2. *Main Menu Navigation:* Enter the corresponding number option to select an action:
    * 1\) ```Play Game```: Place a bet and spin the slots.
    * 2\) ```Credits```: View project credits and hints.
    * 3\) ```Quit Game```: Exit the application safely.
    * 4\) ```Gambling Helpline```: View support resources.
    * 5\) ```Cheat Code```: Trigger a single-use 1,000 chip boost.
### **Gameplay:**
* Enter desired chip bet when prompted.
* Match numbers across the 3 reels to earn multipliers.

## **Controls & Input**
* *Numeric Entry (0-9):* Select menu choices and submit bet amounts.
* *Enter Key:* Confirm selection or advance past pause screens

## **License**
Copyright (c) Media Design School. All rights reserved. Developed for academic coursework.
