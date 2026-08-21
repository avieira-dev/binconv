<div align="center">
    <h1>binconv</h1>
    <p>A lightweight command-line tool for number system conversions.</p>
    <p>
        <img src="https://img.shields.io/badge/status-in%20development-f39c12?style=flat-square"/>
        <img src="https://img.shields.io/badge/language-C-A8B9CC?style=flat-square&logo=c&logoColor=white"/>
        <img src="https://img.shields.io/badge/build-CMake-8a63d2?style=flat-square&logo=cmake&logoColor=white"/>
    </p>
</div>

---

## Overview

**binconv** is a lightweight CLI utility designed to convert numbers between different numeral systems, currently supporting decimal and binary conversions.

> [!WARNING]  
> This project is currently under active development. Features may be incomplete, unstable, or subject to change, and bugs may be present.

---

## Table of Contents

- [Roadmap](#roadmap)
- [Build and Execute](#build-and-execute)
- [Project Structure](#project-structure)
- [Philosophy](#philosophy)
- [Author](#author)
- [License](#license)

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
│       ├── convert.h
│       ├── input.h
│       ├── menu.h
│       └── signal.h
├── src/
│   ├── application.c
│   ├── convert.c
│   ├── input.c
│   ├── main.c
│   ├── menu.c
│   └── signal.c
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