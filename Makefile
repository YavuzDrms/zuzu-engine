CXX := g++

# Dizinler
SRC_DIR := src
BUILD_DIR := build
INC_DIR := include

# Derleme ayarları
CXXFLAGS := -std=c++17 -Wall -I$(INC_DIR)

# GLFW kütüphaneleri (build klasöründe)
LIB_DIR := $(BUILD_DIR)
LIBS := -L$(LIB_DIR) 

# src altındaki tüm .cpp dosyalarını (alt dizinler dahil) topla
rwildcard = $(foreach d,$(wildcard $1/*),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))
SRCS := $(call rwildcard,$(SRC_DIR),*.cpp)

# build klasöründeki .o dosyaları
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# Hedef dosya
TARGET := $(BUILD_DIR)/program.exe

# Varsayılan hedef
all: $(TARGET)

# Linkleme
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LIBS)

# Her .cpp -> .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@if not exist "$(dir $@)" mkdir "$(dir $@)"
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Temizlik
clean:
	@if exist $(BUILD_DIR) rmdir /s /q $(BUILD_DIR)

.PHONY: all clean
