# 👻 GhostScriptor

> A (soon to be) powerful scripting-like language made in C++

---

## 💣 What Is GhostScriptor?

GhostScriptor is a cybersec themed instruction processor that reads commands from a simple text file and performs actions - from recon to whatever madness you script into it.


---

## 📦 Dependencies

Before you unleash the beast, make sure the following is installed on your system:

- 🔍 [Nmap](https://nmap.org/download.html) — for scanning & mapping networks

> More tools will be supported as the script evolves. Stay tuned.

---

## 🚀 Getting Started

1. Open the file: `/input/instructions.txt`
2. Write your commands line by line
3. Run GhostScriptor.exe
4. GhostScriptor will execute your instructions

---

## 🧠 Supported Commands

| Command  | Description |
|----------|-------------|
| `TARGET` | Set the target (IP or domain) |
| `NMAP`   | Run an Nmap scan on the target |
| `PING`   | Ping the target to check reachability |
| `HALT`   | Pause execution until a key is pressed |
| `CLEAR`  | Clear the console for cleaner output |

---

## 🛠️ Roadmap

- [ ] Add command chaining and logic operators  
- [ ] Include more pentest tools (e.g. Dirb, Nikto, custom scripts)  
- [ ] Output logging & report generation  
- [ ] Interactive mode  

---

## 💬 Final Words

GhostScriptor is still in its early stages, but it’s being built with love, caffeine, and a slight obsession with terminal aesthetics. This tool should **NOT** be used for malicious purposes and has been created for educational purposes only.
