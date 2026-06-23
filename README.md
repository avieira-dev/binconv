<div align="center">

<h1>binconv</h1>

<p>A lightweight command-line tool for number system conversions (decimal, binary and future bases).</p>

<p>
  <img src="https://img.shields.io/badge/status-in%20development-f39c12?style=flat-square"/>
  <img src="https://img.shields.io/badge/language-C-A8B9CC?style=flat-square&logo=c&logoColor=white"/>
  <img src="https://img.shields.io/badge/build-CMake-8a63d2?style=flat-square&logo=cmake&logoColor=white"/>
</p>

</div>

---

> [!WARNING]  
> This project is currently under active development. Features may be incomplete, unstable, or subject to change, and bugs may be present.


---

## Table of Contents

- [Overview](#overview)
- [Features](#features-v1)
- [Build and Execute](#build-and-execute)
- [Planned Features](#planned-features)
- [Project Structure](#project-structure)
- [Philosophy](#philosophy)
- [Developer](#developer)
- [License](#license)

---

## Overview

**binconv** is a CLI utility designed to convert numbers between different numeral systems, starting with decimal and binary.

---

## Features (V1)

- Decimal → Binary conversion
- Binary → Decimal conversion
- Interactive terminal menu
- Continuous execution until user exit

---

## Build and Execute

```bash
mkdir build
cd build

cmake ..
cmake --build .
./binconv
```

---

## Planned Features

- Hexadecimal support
- Octal support

---

## Project Structure

```text
binconv/
├── include/
├── src/
├── build/
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
- Incremental feature expansion

---

## Developer

**Alexandre Vieira**  
GitHub: [@avieira-dev](https://github.com/avieira-dev)

---

## License

Distributed under the [MIT License](LICENSE). See `LICENSE` for details.