#!/usr/bin/env python3
'''
script for automatic header generation
**************************************
some macros are pretty redundant, hence a generator script can avoid copy-paste-mistakes
'''
current_version = 200

def create_ddr_h():
    filename = "ddr.h"
    src = generic_head(filename)
    
    src += "#define d(A) d_(A)\n"
    src += "#define d_(A) DDR ## _ ## A\n\n"
    
    src += generic_foot(filename)
    
    save(src, "pio/" + filename)

def generic_head(filename):
    head = "/***\n * " + filename + "\n * This file is part of the PIO library.\n * For license information see \"pio.h\" in the parent directory.\n */\n\n"
    head += "#if !defined(PIOLIB) || PIOLIB < " + str(current_version) + "\n#error This file should not be included directly. Use \"pio.h\" instead.\n#endif\n\n"
    guard = "PIO_" + filename.replace(".", "_").upper()
    head += "#ifndef " + guard + "\n#define " + guard + "\n\n"
    return head

def generic_foot(filename):
    guard = "PIO_" + filename.replace(".", "_").upper()
    foot = "#endif // " + guard + "\n"
    return foot

def save(text, path):
    text_file = open(path, "w")
    text_file.write(text)
    text_file.close()

def main():
    print("Starting header generation...")
    create_ddr_h()

if __name__ == "__main__":
    main()
