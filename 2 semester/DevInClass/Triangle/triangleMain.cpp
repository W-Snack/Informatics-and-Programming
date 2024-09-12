#include <iostream>
#include <cmath>

/* Задание: дописать пропущенные методы, выделить функции, классы,
заменить часть функций перегрузкой операторов.

ЦЕЛЬ: main() должен стать хорошо читаемой структрутой, чтобы было понятно, что происходит во всей программе (без комментариев),
но при этом помещался бы на одном экране.

! В main() вносить свои изменения структуры программы запрещено. Только заменять действия на аналоги, реализованные в
функциях или с использованием классов. СТРУКТУРА ДОЛЖНА ОСТАТЬСЯ ИСХОДНОЙ.

На гитхабе должно появиться 4 коммита:
0. дописал методы
1. выделил функции
2. выделил классы и применил принципы ООП
3. заменил часть функций операторами

То есть по окончании каждого этапа делайте коммит.

Подсказки:
0. Возможные классы, которые проглядыываются в программе:
- класс МЕНЮ (объединяет функции, относящиеся к меню взаимодействия с пользователем),
- класс ТОЧКА (для хранения координат)
- класс ТРЕУГОЛЬНИК (в конструкторах должны отображаться все способы задания треугольника).

1. Функции:
- различные функции меню (показать меню 1 уровня, показать меню 2 уровня и т.д.),
- функции ввода и проверки корректности данных,
- функции различных действий над треугольником: проверка на существование, подсчёт площади и т.д.

Указание. На этапе создания классов предполагается, что объект класса создаётся не в данной функции, а после неё.
Не лепите ввод данных и конструктор в один метод. Функции ввода данных - функции МЕНЮ, а создание объекта (точки, например) -
функции соответствующего класса.

Пример допустимой реализации:
Через 3 метода:
1) метод ввода значений (метод класса меню) - inputSides
2) метод ввода треугльника (метод класса треугольник) -inputTriangle

Далее используется перечисление - enum Type {bySides, byBaseAndHeight, byPointsCoords};

Triange tr1;
tr1.inputTriangle(bySides);

void inputTriangle(Type _type) {
  switch (_type) {
   case bySides:
     int side1, side2, side3;
     inputSides(&side1, &side2, &side3);   // тут сидит ввод значений
     Triange temp(side1, side2, side3);    // тут создаётся треугольник с указанными полями
     this = temp;
     break;
   // ...
  }
}

или

void inputTriangle(Type _type) {
  switch (_type) {
   case bySides:
     int side1, side2, side3;
     inputSides(&side1, &side2, &side3);   // тут сидит ввод значений
     this->side1 = side1;                  // тут изменяется уже существующий треугольник, заполнение указанными полями
     this->side2 = side2;
     this->side3 = side3;
     break;
   // ...
  }
}

*/
void InputTriangle_bySides(int AB, int BC, int AC) {
    while (1) {
        std::cout << "Input 3 side of triangle (between space): ";
        std::cin >> AB >> BC >> AC;
        if (!(AB + BC > AC && AB + AC > BC && AC + BC > AB)) {
            std::cout << "Input error: triangle dont exist" << std::endl;
            std::cout << "Try again" << std::endl;
            continue;
        }
        break;
    }
}
void  InputTriangle_byBaseAndHeight(int AB, int h) {
    std::cout << "Input base of triangle: ";
    std::cin >> AB;
    std::cout << "Input height of triangle: ";
    std::cin >> h;
}
void InputTriangle_byPointsCoords(int* A, int* B, int* C) {
    std::cout << "Input 1st point's coordinates (between space): ";
    std::cin >> A[0] >> A[1];
    std::cout << "Input 2nd point's coordinates (between space): ";
    std::cin >> B[0] >> B[1];
    std::cout << "Input 3rd point's coordinates (between space): ";
    std::cin >> C[0] >> C[1];
}

void ShowMenuLevel1(){
    std::cout << "Ways to define a triangle:" << std::endl
        << "1) by three sides," << std::endl
        << "2) by base and height," << std::endl
        << "3) by three points" << std::endl
        << "Input: ";
}
void ShowMenuLevel2() {
    std::cout << "Methods: 1) get square," << std::endl
        << "2) get perimeter, " << std::endl
        << "3) get type of triangle," << std::endl
        << "4) compare with another triangle by square," << std::endl
        << "5) back to first menu," << std::endl
        << "0) exit," << std::endl
        << "Input: ";
}

float TriangleSquarebySides(int AB, int BC, int AC) {
    float p = (AB + BC + AC) * 0.5;
    float S = sqrt(p * (p - AB) * (p - BC) * (p - AC));
    return S;
}

float TriangleSquarebyBaseAndHeight(int AB, int h) {
    float S = 0 / 5 * h * AB;
    return S;
}
float TriangleSquarebyCoords(int* A, int* B, int* C) {
    float S = 0.5 * abs((((A[0] - C[0]) * (B[1] - C[1])) - ((A[1] - C[1]) * (B[0] - C[0]))));
    return S;
}

float TrianglePerimeterbySides(int AB, int BC, int AC) {
    float p = AB + BC + AC;
    return p;
}


float TrianglePerimeterbyCoords(int* A, int* B, int* C) {
    float p = sqrt((B[0] - A[0]) ^ 2 + (B[1] - A[1]) ^ 2) + sqrt((C[0] - B[0]) ^ 2 + (C[1] - B[1]) ^ 2) + sqrt((C[0] - A[0]) ^ 2 + (C[1] - A[1]) ^ 2);
    return p;
}

void TriangleTypebySides(int AB, int BC, int AC) {
    if (AB = BC = AC) {
        std::cout << "Triangle is equilateral" << std::endl;
    }
    else if ((AB = BC != AC) || (AC = BC != AB) || (AC = AB != BC)) {
        std::cout << "Triangle is isosceles" << std::endl;
    }
    else if (((AB ^ 2) == ((BC ^ 2) + (AC ^ 2))) || ((AC ^ 2) == ((BC ^ 2) + (AB ^ 2))) || ((BC ^ 2) == ((AB ^ 2) + (AC ^ 2)))) {
        std::cout << "Right triangle" << std::endl;
    }
    else {
        std::cout << "Triangle is scalene" << std::endl;
    }
}

void TriangleTypebyCoords(int* A, int* B, int* C) {
    int l1 = sqrt((B[0] - A[0]) ^ 2 + (B[1] - A[1]) ^ 2);
    int l2 = sqrt((C[0] - B[0]) ^ 2 + (C[1] - B[1]) ^ 2);
    int l3 = sqrt((C[0] - A[0]) ^ 2 + (C[1] - A[1]) ^ 2);
    if (l1 = l2 = l3) {
        std::cout << "Triangle is equilateral" << std::endl;
    }
    else if ((l1 = l2 != l3) || (l3 = l2 != l1) || (l3 = l1 != l2)) {
        std::cout << "Triangle is isosceles" << std::endl;
    }
    else if ((l1 ^ 2 == l2 ^ 2 + l3 ^ 2) || (l3 ^ 2 == l2 ^ 2 + l1 ^ 2) || (l2 ^ 2 == l1 ^ 2 + l3 ^ 2)) {
        std::cout << "Right triangle" << std::endl;
    }
    else {
        std::cout << "Triangle is scalene" << std::endl;
    }
}


enum Type { bySides, byBaseAndHeight, byPointsCoords };

int main() {
  int user_choosen;
  int AB, BC, AC;
  int A[2], B[2], C[2];
  int h;
  float p, S;
  bool exit_flag = false, back_flag;

  Type _inputType;

  while (!exit_flag) {
    back_flag = false;
    std::cin >> user_choosen;

    switch (user_choosen) {
    case 1:
      _inputType = bySides;
      InputTriangle_bySides( AB,  BC,  AC);
      break;
    case 2:
      _inputType = byBaseAndHeight;
      InputTriangle_byBaseAndHeight(AB, h);
      break;
    case 3:
      _inputType = byPointsCoords;
      InputTriangle_byPointsCoords(A, B, C);
      break;
    default:
      std::cout << "Input error: error in input" << std::endl;
    }

    while (!back_flag) {
      
      std::cin >> user_choosen;

      switch (user_choosen) {
      case 0:
        exit_flag = true;
        break;
      case 1:
        if (_inputType == bySides) {
          if (AB + BC > AC && AB + AC > BC && AC + BC > AB) {
              S = TriangleSquarebySides(AB, BC, AC);
            std::cout << "Square of triangle: S = " << S << std::endl;
          } else {
            std::cout << "Input error: triangle dont exist" << std::endl;
          }
        } else if (_inputType == byBaseAndHeight) {
            if (AB && h) {
                S = TriangleSquarebyBaseAndHeight(AB, h);
                std::cout << "Square of triangle: S = " << S << std::endl;
            }else {
                std::cout << "Input error: triangle dont exist" << std::endl;
            }
        } else if (_inputType == byPointsCoords) {
            S = TriangleSquarebyCoords(A, B, C);
            if (S > 0) {
                std::cout << "Square of triangle: S = " << S << std::endl;
            }else {
                std::cout << "Input error: triangle dont exist" << std::endl;
            }
        }
        system("pause");
        system("cls");
        break;
      case 2:
        if (_inputType == bySides) {
            if (AB && BC && AC) {
                p = TrianglePerimeterbySides(AB, BC, AC);
                std::cout << "Perimeter of triangle: p = " << p << std::endl;
          }
            else {
                std::cout << "Input error: triangle dont exist" << std::endl;
            }
        }
        else if (_inputType == byBaseAndHeight) {
          std::cout << "Input error: we couldn't find perimeter by your parameters" << std::endl;
        }
        else if (_inputType == byPointsCoords) {
            p = TrianglePerimeterbyCoords(A, B, C);
            std::cout << "Perimeter of triangle: p = " << p << std::endl;
        }
        break;
      case 3:
        // your code
        // Types of triangles:
        // equilateral - равносторонний,
        // isosceles - равнобедренный,
        // right triangle - прямоугольный,
        // scalene - произвольный.
          if (_inputType == bySides) {
              TriangleTypebySides();
          }
          else if (_inputType == byBaseAndHeight) {
              std::cout << "Input error: we couldn't find type of triangle by your parameters" << std::endl;
          }
          else if (_inputType == byPointsCoords) {
              TriangleTypebyCoords();
          }
          
        break;
      case 4:
          int S2;
          std::cout << "Input square of another triangle" << std::endl << "Input:";
          std::cin >> S2;
          if (_inputType == bySides) {
              if (AB + BC > AC && AB + AC > BC && AC + BC > AB) {               
                  S = TriangleSquarebySides(AB, BC, AC);
              }
              else {
                  std::cout << "Input error: triangle dont exist" << std::endl;
              }
          }
          else if (_inputType == byBaseAndHeight) {
              if (AB && h) {
                  S = TriangleSquarebyBaseAndHeight(AB, h);
              }
              else {
                  std::cout << "Input error: triangle dont exist" << std::endl;
              }
          }
          else if (_inputType == byPointsCoords) {
              S = TriangleSquarebyCoords(A, B, C);
              if (S > 0) {
              }
              else {
                  std::cout << "Input error: triangle dont exist" << std::endl;
              }
          }
          if (S > S2) {
              std::cout << "Square of your triangle bigger then another" << std::endl;
          }
          else if (S2 > S) {
              std::cout << "Square of another triangle bigger then your" << std::endl;
          }
          else {
              std::cout << "Squares are equals" << std::endl;
          }
        break;
      case 5:
        back_flag = true;
        break;
      default:
        std::cout << "Input error: error in input" << std::endl;
      }

      if (back_flag || exit_flag) {
        system("cls");
        std::cout << "Last parameters: ";
        if (_inputType == bySides) {
          std::cout << AB << "x" << BC << "x" << AC << std::endl;
        }
        else if (_inputType == byBaseAndHeight) {
          std::cout << "a = " << AB << ", h = " << h << std::endl;
        }
        else if (_inputType == byPointsCoords) {
          std::cout << "(" << A[0] << ", " << A[1] << ")" << ", ";
          std::cout << "(" << B[0] << ", " << B[1] << ")" << ", ";
          std::cout << "(" << C[0] << ", " << C[1] << ")" << std::endl;
        }
      }
      break;
    }
  }
  system("cls");
  std::cout << "Goodbay!" << std::endl;
}
