/*
 * Copyright (c) 2026 Kash Hopkins
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#ifndef EFI_EFIIO_H
#define EFI_EFIIO_H 1

#include "efi_types.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct EfiSimpleTextInputProtocol EfiSimpleTextInputProtocol;
typedef struct EfiSimpleTextOutputProtocol EfiSimpleTextOutputProtocol;

typedef struct {
  uint16_t ScanCode;
  uint16_t UnicodeChar;
} EfiInputKey;

typedef EfiStatus(EFI_API *EfiInputReset)(EfiSimpleTextInputProtocol *This,
                                          bool ExtendedVerification);

typedef EfiStatus(EFI_API *EfiInputReadKey)(EfiSimpleTextInputProtocol *This,
                                            EfiInputKey *Key);

struct EfiSimpleTextInputProtocol {
  EfiInputReset Reset;
  EfiInputReadKey ReadKeyStroke;
  EfiEvent WaitForKey;
};

typedef EfiStatus(EFI_API *EfiTextReset)(EfiSimpleTextOutputProtocol *This,
                                         bool ExtendedVerification);

typedef EfiStatus(EFI_API *EfiTextString)(EfiSimpleTextOutputProtocol *This,
                                          uint16_t *String);

struct EfiSimpleTextOutputProtocol {
  EfiTextReset Reset;
  EfiTextString OutputString;
  // ...
};

#endif
