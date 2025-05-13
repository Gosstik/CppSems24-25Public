# Семинар 7. Санитайзеры и дебагер. Касты (приведения типов)

## Casts

- static_cast &mdash; пользуемся, когда запрещено неявное приведение типа
- reinterpret_cast &mdash; полезно, когда мы получаем сырую память или знам, что оба типа имеют одинаковое представление в памяти (типы только формально разные). Если размер типов не совпадает &mdash; UB. Можно приводить только к ссылке или указателю.
- const_cast &mdash; использовать, если нам передали константный тип, но мы знаем, что на самом деле он раньше не был константным. Если передать аргумент, который с самого начала программы был const &mdash; UB.
- C-style cast &mdash; пробует применить последовательность из преобразований. Смотри [cppreference](https://en.cppreference.com/w/cpp/language/explicit_cast).
- dynamic_cast &mdash; пока не рассматриваем

## Sanitizers

Виды санитайзеров:

- address
- leak (подмножество address)
- undefined
- thread (не будем смотреть)

Флаги компиляции:

```bash
g++ -fsanitize=address main.cpp
g++ -fsanitize=undefined main.cpp

g++ -fsanitize=address,undefined main.cpp
```

При использовании только флагов выше в отчёте об ошибке вместо строк из исходника может писаться (a.out+0x2d22). Чтобы показывались ссылки на строки из исходника, нужно добавить флаги `-g` и `-O0`:

```bash
clang++ -std=c++20 -O0 -g -fsanitize=address,undefined main.cpp
```

Не все санитайзеры можно комбинировать между собой, так что просто перечислить все не получится. Обычно можно в качестве второго санитайзера указывать `undefined`, но вот использовать `address` + `thread` не рекомендуется.

Можно явно посмотреть, во что превращается ваш код, скомпилировав его в godbolt.

Когда добавляется флаг санитайзеров, вызовы некоторых функций в программе заменяются на другие, в которых расставлены определённые проверки (выход за границы массива, переполнение и т.п.). Отсюда 2 вывода:

1) Проверки санитайзерами происходят **в рантайме**, поэтому некорректный код тоже вполне себе будет компилироваться.
2) Добавление санитайзеров замедляет программу.

Задания в контестах обычно запускаются с санитайзерами. Локально тоже следует тестировать с ними.

Самые распространённые ошибки, отлавливаемые address санитайзером:

- heap use after free
- stack use after scope
- double free or corruption
- heap-buffer-overflow (выход за границы массива)

## Debugger

There are different debuggers for different platforms:

- MacOS: `GDB` or `LLDB`
- Windows: `Visual Studio Windows Debugger` or `GDB`
- Linux: `GDB` (or `LLDB` ???)

To use debugger, you have to compile your `.cpp` file with `-g` flag:

```bash
g++ -g -std=c++20 main.cpp
```

### GDB

Installation:

```bash
sudo apt-get install build-essential gdb
```

### vscode

#### Installation

For correct work you have to install extensions:

- `ms-vscode.cpptools`
- `ms-vscode.cpptools-extension-pack`

If you use `clangd`, you have to add to `User Settings (JSON)` line:

```json
"C_Cpp.intelliSenseEngine": "disabled", // required for debugger
```

#### Usage

- Open `Run` on the top, then `Add configuration...`
- Add your custom configuration

- On activity bar (left upper corner) open `Run And Debug`.
- `Create a launch.json file`
- Copy content of [.vscode](./vscode/.vscode) to your folder
- `Tasks: configure default build task`


#### Concepts

`Attach` and `Launch` --- types of `request` in configuration.

- Break Points
- Step through the code
- Inside debug window
  - Variables
  - Watches
  - Call Stack

- Debug console:

```text
-exec bt
-exec print <expression>
```

#### Links

- [vscode debug](https://code.visualstudio.com/docs/editor/debugging)
- [vscode c++ debug](https://code.visualstudio.com/docs/cpp/launch-json-reference)


Преза с работой санитайзера: <https://www.usenix.org/sites/default/files/conference/protected-files/serebryany_atc12_slides.pdf>
<https://clang.llvm.org/docs/AddressSanitizer.html>
<https://clang.llvm.org/docs/UndefinedBehaviorSanitizer.html>
Пример из раста: <https://cacm.acm.org/research/safe-systems-programming-in-rust/>
GC in golang: <https://tip.golang.org/doc/gc-guide>
GDB reference: <https://www.cs.princeton.edu/courses/archive/fall16/cos432/hw2/gdb-refcard.pdf>
Исходники рантайма Address Sanitizer: <https://github.com/llvm/llvm-project/blob/main/llvm/lib/Transforms/Instrumentation/AddressSanitizer.cpp>
