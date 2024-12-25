## Краткое описание

Графический калькулятор и графопостроитель. 

UML диаграммы к проекту хранятся в директории [images](images).

В файле [constants.h](src/ui/constants.h) присутствуют константы `WINDOW_WIDTH` и `WINDOW_HEIGHT`, отвечащие за ширину и высоту окна.


## Инструкция по сборке и запуску 

####  Если у Вас Linux, пропустите шаги 1 - 5 и просто запустите скрипт [run.sh](run.sh).

1) Убедитесь, что у Вас установлен homebrew и введите следующие команды:

  ```sh
  brew install g++;
  brew install cmake;
  ```

2) Склонируйте удаленный репозиторий, предварительно установив git:

  ```sh
  git clone git@gitlab.com:fakepr1kol2005/graphing-calculator.git
  ```

3) Выполните сборку проекта:

  ```sh
  cmake -B build;
  cmake --build build --target graph_calc
  ```

5) Запустите симуляцию:
  ```sh
  bin/graph_calc
  ```
// TODO : translate to english