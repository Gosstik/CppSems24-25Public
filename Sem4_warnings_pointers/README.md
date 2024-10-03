# Семинар 5

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

## Различия указателей и массивов

1) Массиву нельзя присваивать, инкрементировать или прибавлять к нему числа.
2) `sizeof(ptr)` возвращает размер указателя, а `sizeof(array)` — размер массива * sizeof(type). **ЗАМЕЧАНИЕ**: при передаче в функцию, `sizeof()` от массива будет 8, независимо от того, какого размера массив принимается в аргументах.
3) В случае принятия в функцию массив может быть неявно скастован к поинтеру, также и
обратно. Поэтому делать перегрузку по этому принципу нельзя.

Массивы разной длины — это формально разные типы.

## TODO

Флаги оптимизации
