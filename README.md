# 🖥️ MyOS – Build My Own Operating System

🚀 This project documents the journey of building a simple operating system from scratch using **C, Assembly, and GRUB**.

---

# 📌 Project Goal

To understand how an OS works internally by building it step-by-step:

* Booting process
* Kernel development
* Hardware interaction
* Memory & process management

---

# ⚙️ Requirements (Cross-Platform)

## 🐧 Ubuntu / Debian

```bash
sudo apt update
sudo apt install build-essential nasm qemu grub-pc-bin xorriso gcc-multilib
```

---

## 🍎 macOS

```bash
brew install nasm qemu xorriso
brew install i686-elf-gcc
```

> ⚠️ macOS does not support `gcc -m32` easily → use cross-compiler

---

## 🪟 Windows

### ✅ Recommended: WSL (Windows Subsystem for Linux)

```powershell
wsl --install
```

Then inside WSL (Ubuntu):

```bash
sudo apt update
sudo apt install build-essential nasm qemu grub-pc-bin xorriso gcc-multilib
```

> ⚠️ Native Windows setup is complex → use WSL

---

# 🧱 Build Stages (Roadmap)

## 🚀 Phase 0: Setup

### 🎯 Goal:

Prepare development environment

### ✅ Tools:

* GCC (with 32-bit support)
* NASM
* QEMU
* GRUB
* Make

---

## 🧠 Phase 1: Booting (✔ Completed)

### 🎯 Goal:

Boot OS and print text on screen

### 🛠️ What was built:

* Multiboot-compliant kernel
* GRUB bootloader integration
* VGA text output

### 📂 Key Files:

* `boot/boot.asm`
* `kernel/kernel.c`
* `linker.ld`
* `iso/boot/grub/grub.cfg`

### ▶️ Run:

```bash
make
qemu-system-x86_64 -cdrom myos.iso
```

### 🎉 Output:

```text
Hello OS
```

---

## 🖥️ Phase 2: Screen Driver (⏳ Next)

### 🎯 Goal:

Improve output system

### 📌 Features to add:

* print() function
* clear screen
* cursor movement

---

## ⌨️ Phase 3: Keyboard Input

### 🎯 Goal:

Take input from user

### 📌 Features:

* Keyboard interrupt handling
* Key mapping
* Display typed characters

---

## ⏱️ Phase 4: Interrupt Handling

### 🎯 Goal:

Handle hardware interrupts

### 📌 Concepts:

* IDT (Interrupt Descriptor Table)
* IRQ handling

---

## 🧮 Phase 5: Memory Management

### 🎯 Goal:

Manage RAM

### 📌 Features:

* Paging
* Heap allocation (malloc-like system)

---

## 🔁 Phase 6: Multitasking

### 🎯 Goal:

Run multiple processes

### 📌 Features:

* Context switching
* Scheduler

---

## 💾 Phase 7: File System

### 🎯 Goal:

Read/write files

---

## 💻 Phase 8: Shell

### 🎯 Goal:

User interaction system

### Example:

```bash
help
clear
echo Hello
```

---

# 🏗️ Project Structure

```text
myOS/
├── boot/
│   └── boot.asm
├── kernel/
│   └── kernel.c
├── iso/
│   └── boot/
│       ├── kernel.bin
│       └── grub/
│           └── grub.cfg
├── linker.ld
├── Makefile
└── myos.iso
```

---

# 🧠 What I Learned

* How bootloaders work
* How kernel starts execution
* Direct hardware interaction (VGA memory)
* Linking Assembly + C

---

# 🔥 Future Goals

* GUI support
* Networking
* USB drivers

---

# 🤝 Contributing

Feel free to fork and improve this project!

---

# 🙌 Author

**Anup Kumar Singh**

---

⭐ Star this repo if you like it!

