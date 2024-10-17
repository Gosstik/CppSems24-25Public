# Семинар 4. Флаги компиляции. Этапы компиляции

## Флаги компиляции

- `-Wall` &mdash; базовые проверки корректности кода на наличие нежелательных или потенциально опасных конструкций
- `-Wextra` &mdash; дополнительные варнинги, которых нет в `-Wall`
- `-Werror` &mdash; вместо warning-а компилятор будет кидать error (то есть на выходе не будет получаться исполняемый файл)
- `-Wpedantic` `-pedantic` &mdash; проверяет соответствие стандарту ISO C++ (например, VLA запрещены)

Примеры:

```bash
g++ -Wall -Wextra -Wpedantic
g++ -Wall -Wextra -Wpedantic -Werror # warnings will be errors
g++ -Wparentheses -Wunused-variable program.cpp # show only specific warnings
g++ -Wall -Werror -Wno-error=unused-variable program.cpp # -Wunused-variable will remain warning, not an error
g++ -Wall -Werror -Wno-unused-variable program.cpp # -Wunused-variable will not be even a warning
```

Больше флагов компиляции, какие ошибки включает в себя `-Wall`, а какие `-Wextra` и многое другое можно посмотреть [по ссылке](https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html).

## Этапы компиляции

1) Препроцессинг &mdash; подставляется содержимое директив препроцессора (`#include`, `#define`, `#ifndef`, ...). Два вида скобок в `#include`: угловые и кавычки. Первые используются для поиска хедеров в стандартных директориях, вторые &mdash; в локальной по отношению к компилируемому файлу. Команда:

   ```bash
   g++ -E main.cpp > main_preproc.cpp
   ```

2) Компиляция &mdash; исходный код на C++ преобразовывается в ассемблерный (.cpp -> .s). Команда:

   ```bash
   g++ -S file.cpp
   ```

3) Ассемблирование &mdash; ассемблерный код преобразовывается **почти полностью** в объектный файл (.s -> .o). Объектный файл содержит машинные инструкции, которые понятны процессору. Команда:

   ```bash
   g++ -c file.cpp
   ```

   Полученный файл можно посмотреть с помощью `cat file.o` и `hd file.o` (hex dump).

4) Линковка &mdash; генерация из объектного файла (или нескольких объектных файлов) исполняемого файла. Тут подключаются динамиче ские библиотеки и подставляются адреса функций (потому что в библиотеках могут быть только объявления функций). Эта стадия нужна, чтобы нам можно было писать код в нескольких файлах и не нужно было каждый раз перекомпилировать большую библиотеку.

Самые частые ошибки линковщика:

- `undefined reference`
- `double definition`

На каждый из этапов выше компилятор вызывает соответствующие программы. Например:
`c1plus` &mdash; для компиляции
`as` &mdash; для ассемблирования
`collect2` &mdash; для линковки


## TODO

- Флаги оптимизации.
- Разница между Undefined behavior, unspecified behavior и implementation defined behavior + примеры.
