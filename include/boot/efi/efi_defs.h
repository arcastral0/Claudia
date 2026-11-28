/*
 * Copyright (c) 2026 Kash Hopkins
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef EFI_EFIDEFS_H
#define EFI_EFIDEFS_H 1

#include "efi.h"
#include "efi_io.h"
#include "efi_types.h"
#include <stddef.h>
#include <stdint.h>

typedef struct {
  uint64_t Signature;
  uint32_t Revision;
  uint32_t HeaderSize;
  uint32_t CRC32;
  uint32_t Reserved;
} EfiTableHeader;

typedef struct {
  EfiTableHeader Hdr;
  uint16_t *FirmwareVendor;
  uint32_t FirmwareRevision;
  EfiHandle ConsoleInHandle;
  EfiSimpleTextInputProtocol *ConIn;
  EfiHandle ConsoleOutHandle;
  EfiSimpleTextOutputProtocol *ConOut;
  // ...
} EfiSystemTable;

#endif
