MODULE    := boot
BOOT_SRCS := $(wildcard $(MODULE)/*.c)
BOOT_OBJS := $(patsubst $(MODULE)/%.c,$(BUILD_DIR)/%.o,$(BOOT_SRCS))
