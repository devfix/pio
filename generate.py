#!/usr/bin/env python3
'''
script for automatic header generation
**************************************
some macros are pretty redundant, hence a generator script can avoid copy-paste-mistakes
'''

import string

current_version = 200
guard = "PIOLIB_H"
lib_dir = "pio/src/"
debug = False
pin_pre = "LEAD_"

code = ""


def create_head():
    global code
    global guard
    
    src = "#ifndef " + guard + "\n"
    src += "#define " + guard + "\n"
    code += src


def create_pins_h():
    global code
    global debug
    global pin_pre
    
    if debug:
        code += "// SECTION PINS\n"
        
    code += "#define b(PIN) b_(PIN)\n"
    code += "#define b_(_PIN_) B ## _ ## _PIN_\n\n"
    
    for p in string.ascii_uppercase[:6]:
        for i in range(0, 8):
            code += "static const unsigned char " + pin_pre + p + str(i) + " = " + ('0x%02x' % (1<<i)) + ";\n"
            code += "#define B_" + pin_pre + p + str(i) + " " + str(i) +"\n"
        code += "\n"
    
    code += "\n\n"
    

def create_ddr_h():
    global code
    global debug
    global pin_pre
    
    if debug:
        code += "// SECTION DDR\n"
    
    code += "#define d(PIN) d_(PIN)\n"
    code += "#define d_(_PIN_) DDR ## _ ## _PIN_\n\n"
    
    for p in string.ascii_uppercase[:6]:
        code += "#ifdef DDR" + p + "\n"
        for i in range(0, 8):
            code += "  #define DDR_" + pin_pre + p + str(i) + " DDR" + p + "\n"
        code += "#endif // DDR" + p + "\n\n"
    
    code += "\n\n"
    

def create_port_h():
    global code
    global debug
    global pin_pre
    
    if debug:
        code += "// SECTION PORT\n"
    
    code += "#define o(PIN) o_(PIN)\n"
    code += "#define o_(_PIN_) PORT ## _ ## _PIN_\n\n"
    
    for p in string.ascii_uppercase[:6]:
        code += "#ifdef PORT" + p + "\n"
        for i in range(0, 8):
            code += "  #define PORT_" + pin_pre + p + str(i) + " PORT" + p + "\n"
        code += "#endif // PORT" + p + "\n\n"
    
    code += "\n\n"
    

def create_pin_h():
    global code
    global debug
    global pin_pre
    
    if debug:
        code += "// SECTION PORT\n"
    
    code += "#define i(PIN) i_(PIN)\n"
    code += "#define i_(_PIN_) PIN ## _ ## _PIN_\n\n"
    
    for p in string.ascii_uppercase[:6]:
        code += "#ifdef PIN" + p + "\n"
        for i in range(0, 8):
            code += "  #define PIN_" + pin_pre + p + str(i) + " PIN" + p + "\n"
        code += "#endif // PIN" + p + "\n\n"
    
    code += "\n\n"


def create_foot():
    global code
    global guard
    
    src = "#endif // " + guard + "\n"
    code += src


def append(path):
    global code
    
    f = open(path, "r")
    if not f.mode == 'r':
        raise RuntimeError("fopen failed")
    code += f.read() + "\n\n"
    f.close()
   

def compress():
    global code
    
    while code.find("\n\t") != -1 or code.find("\n ") != -1 or code.find("\n\n") != -1:
        code = code.replace("\n\t", "\n")
        code = code.replace("\n ", "\n")
        code = code.replace("\n\n", "\n")
    
    
def save(text, path):
    text_file = open(path, "w")
    text_file.write(text)
    text_file.close()


def main():
    global code
    global debug
    
    print("Starting header generation...")
    
    append("parts/copyright.h")
    create_head()
    append("parts/generic.h")
    create_pins_h()
    create_ddr_h()
    create_port_h()
    create_pin_h()
    create_foot()
    
    if not debug:
        compress()
        
    save(code, lib_dir + "/pio.h")

if __name__ == "__main__":
    main()
