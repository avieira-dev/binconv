<div align="center">
    <h1>binconv</h1>
    <p>A lightweight command-line tool for number system conversions.</p>
    <p>
        <img src="https://img.shields.io/badge/version-v1.0.0-4c1?style=flat-square"/>
        <img src="https://img.shields.io/badge/status-stable-2ea44f?style=flat-square"/>
        <img src="https://img.shields.io/badge/platform-Linux-FCC624?style=flat-square&logo=linux&logoColor=black"/>
        <img src="https://img.shields.io/badge/maintenance-active-1f6feb?style=flat-square"/>
        <img src="https://img.shields.io/badge/language-C-A8B9CC?style=flat-square&logo=c&logoColor=white"/>
        <img src="https://img.shields.io/badge/build-CMake-8a63d2?style=flat-square&logo=cmake&logoColor=white"/>
        <img src="https://img.shields.io/badge/license-MIT-6e7781?style=flat-square"/>
    </p>
</div>

---

## Overview

**binconv** is a lightweight CLI utility designed to convert numbers between different numeral systems, currently supporting decimal and binary conversions.

> [!IMPORTANT]  
> **binconv v1.0.0** is now stable.

---

## Table of Contents

- [Showcase](#showcase)
- [Roadmap](#roadmap)
- [Build and Execute](#build-and-execute)
- [Project Structure](#project-structure)
- [Philosophy](#philosophy)
- [Author](#author)
- [License](#license)

---

## Showcase

<p align="center">
    <em>Interactive menu option selection</em><br>
    <img src="./assets/screenshots/screenshot-01.png" alt="Interactive menu option selection" width="500"/><br><br>
    <em>Decimal to binary conversion</em><br>
    <img src="./assets/screenshots/screenshot-02.png" alt="Decimal to binary conversion" width="500"/><br><br>
    <em>Help and available commands</em><br>
    <img src="./assets/screenshots/screenshot-03.png" alt="Help" width="500"/>
</p>

---

## Roadmap

| Feature                        | Status                      |
|--------------------------------|-----------------------------|
| Decimal → Binary conversion    | ████████████████████ `100%` |
| Binary → Decimal conversion    | ████████████████████ `100%` |
| Hexadecimal support            | ░░░░░░░░░░░░░░░░░░░░ `0%`   |
| Octal support                  | ░░░░░░░░░░░░░░░░░░░░ `0%`   |

---

## Build and Execute

```bash
mkdir build && cd build
cmake .. && cmake --build .
./binconv
```

--- 

## Project Structure

```text
binconv/
├── build/
├── include/
│   └── binconv/
│       ├── application.h
│       ├── banner.h
│       ├── colors.h
│       ├── convert.h
│       ├── help.h
│       ├── input.h
│       ├── menu.h
│       ├── signal.h
│       └── terminal.h
├── src/
│   ├── application.c
│   ├── banner.c
│   ├── convert.c
│   ├── help.c
│   ├── input.c
│   ├── main.c
│   ├── menu.c
│   ├── signal.c
│   └── terminal.c
├── .gitignore
├── CMakeLists.txt
├── LICENSE
└── README.md
```

---

## Philosophy

This project prioritizes:

- Low-level understanding of number systems
- Minimal external dependencies
- Clear separation between input handling and conversion logic
- Safe input processing
- Modular architecture
- Incremental feature expansion

---

## Author

**Alexandre Vieira**  
GitHub: [@avieira-dev](https://github.com/avieira-dev)

---

## License

Distributed under the [MIT License](LICENSE). See `LICENSE` for details.