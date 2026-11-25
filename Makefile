CC			:= clang
CFLAGS		:= -target x86_64-unknown-windows -ffreestanding -fshort-wchar -mno-red-zone -nostdlib
LD			:= lld-link
LDFLAGS		:= -subsystem:efi_application -entry:efi_main

BUILD_DIR 	:= build
ISO_DIR		:= $(BUILD_DIR)/iso

EFI_BIN		:= $(BUILD_DIR)/BOOTX64.EFI
FAT_IMG		:= $(BUILD_DIR)/Claudia.img

OS_IMAGE	?= $(ISO_DIR)/Claudia.iso

include boot/module.mk

.PHONY: all clean run qemu

all: $(OS_IMAGE)

$(BUILD_DIR)/%.o: boot/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(EFI_BIN): $(BOOT_OBJS)
	$(LD) $(LDFLAGS) $(BOOT_OBJS) -out:$@

$(FAT_IMG): $(EFI_BIN)
	dd if=/dev/zero of=$@ bs=1M count=64
	mformat -i $@ -F ::
	mmd -i $@ ::/EFI
	mmd -i $@ ::/EFI/BOOT
	mcopy -i $@ $< ::/EFI/BOOT

$(OS_IMAGE): $(FAT_IMG) | $(ISO_DIR)
	cp $< $(ISO_DIR)/
	xorriso -as mkisofs -R -f -e $(notdir $<) -no-emul-boot -o $@ $(ISO_DIR)

$(BUILD_DIR) $(ISO_DIR):
	mkdir -p $@

clean: 
	rm -rf $(BUILD_DIR)

run: qemu

qemu: $(OS_IMAGE)
	qemu-system-x86_64 \
		-m 2048 \
		-smp 4 \
		-bios /usr/share/edk2/ovmf/OVMF_CODE.fd \
		-cdrom $(OS_IMAGE)

