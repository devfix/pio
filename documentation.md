# Documentation

## Available Commands

### DDR - Pin Direction Configuration

#### set_ddr<PIN0, PIN1, ...>();
Configures several pins as output pins.
#### clear_ddr<PIN0, PIN1, ...>();
Configures several pins as input pins.

### PORT - Pin State Manipulation
#### set_port<PIN0, PIN1, ...>();
Sets the state of the pins to high (output pins) or enables the pull-up resistors of the pins (input pins).
#### clear_port<PIN0, PIN1, ...>();
Sets the state of the pins to low (output pins) or disables the pull-up resistors of the pins (input pins).

### PIN - Pin State Acquisition
#### get_pin<PIN0, PIN1, ...>();
Returns the state of several pins.  
If two pins have the same bit number, their state can not be distinguished! The result only tells, if at least one of them is high.  
Example:
```c++
uint8_t v = get_pin<LA0, LB2>();
```
LA0 and LB2 are distinguishable. So *v* can have these values:

| value | pin states |
|-------|------------|
| 0x00  | ¬LB2 ¬LA0  |
| 0x01  | ¬LB2  LA0  |
| 0x04  |  LB2 ¬LA0  |
| 0x05  |  LB2  LA0  |

```c++
uint8_t v = get_pin<LA1, LB1>();
```
LA1 and LB1 are not distinguishable:
get
| value | pin states |
|-------|------------|
| 0x00  | ¬LB1 ¬LA1  |
| 0x02  | ¬LB1  LA1  **or** LB1 ¬LA1 **or** LB1 LA1 |
