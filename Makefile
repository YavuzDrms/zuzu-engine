CXX := g++
CC  := gcc

# Dizinler
SRC_DIR := src
BUILD_DIR := build
INC_DIR := include
LIB_DIR := lib

# Derleme ayarları
CXXFLAGS := -std=c++17 -Wall -I$(INC_DIR)
CFLAGS   := -Wall -I$(INC_DIR)

# GLFW + Windows OpenGL kütüphaneleri
LIBS := -L$(LIB_DIR) -lglfw3 -lopengl32 -lgdi32

# Alt klasörlerdeki tüm .cpp ve .c dosyalarını topla
rwildcard = $(foreach d,$(wildcard $1/*),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

CPPS := $(call rwildcard,$(SRC_DIR),*.cpp)
CS   := $(call rwildcard,$(SRC_DIR),*.c)

# .o dosyaları
CPP_OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(CPPS))
C_OBJS   := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(CS))

OBJS := $(CPP_OBJS) $(C_OBJS)

# Çıktı
TARGET := $(BUILD_DIR)/program.exe

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LIBS)

# .cpp dosyaları derleme
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@if not exist "$(dir $@)" mkdir "$(dir $@)"
	$(CXX) $(CXXFLAGS) -c $< -o $@

# .c dosyaları derleme
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@if not exist "$(dir $@)" mkdir "$(dir $@)"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@if exist $(BUILD_DIR) rmdir /s /q $(BUILD_DIR)

.PHONY: all clean
