{
 "cells": [
  {
   "cell_type": "markdown",
   "id": "71d0aa81",
   "metadata": {},
   "source": [
    "# Зачетная работа по предмету “Системы компьютерной математики”."
   ]
  },
  {
   "cell_type": "markdown",
   "id": "2c3e084a",
   "metadata": {},
   "source": [
    "## Задача: 9. Как растет число обусловленности для случайной матрицы?"
   ]
  },
  {
   "cell_type": "markdown",
   "id": "c222a160",
   "metadata": {},
   "source": [
    "### Выполнил: Фомин Владимир Михайлович \n",
    "### Преподаватель: Золотых Николай Юрьевич"
   ]
  },
  {
   "cell_type": "markdown",
   "id": "19b370d1",
   "metadata": {},
   "source": [
    "Цель данной задачи – экспериментально выяснить зависимость числа обусловленности $ \\mbox{cond}_1 A_n $ от порядка случайной матрицы. Экспериментальным путем необходимо выяснить, что $ \\mbox{cond}_1 A_n $ в среднем растет как показательная функция от $ {n} $ , а именно, что для большинства матриц $$ c_1 n^p \\le \\mbox{cond}_1 A_n \\le c_2 n^p $$\n"
   ]
  },
  {
   "cell_type": "markdown",
   "id": "df48b054",
   "metadata": {},
   "source": [
    "**Импорт необходимых библиотек**\n"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 1,
   "id": "4d5b464e",
   "metadata": {},
   "outputs": [],
   "source": [
    "import numpy as np\n",
    "import random\n",
    "from matplotlib import pyplot\n",
    "%matplotlib inline"
   ]
  },
  {
   "cell_type": "markdown",
   "id": "08cf7137",
   "metadata": {},
   "source": [
    "**Создаем функцию для отрисовки графика со значениями числа обусловленности** "
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 2,
   "id": "94ec9802",
   "metadata": {},
   "outputs": [],
   "source": [
    "def loglogGraph(x, y, settings, TitleName, XlabelName, YlabelName):                            \n",
    "    pyplot.loglog(x, y, settings)                                                \n",
    "    pyplot.title(TitleName)                                                                   \n",
    "    pyplot.xlabel(XlabelName)                                                                 \n",
    "    pyplot.ylabel(YlabelName)                                                                 \n",
    "    pyplot.grid()  "
   ]
  },
  {
   "cell_type": "markdown",
   "id": "0611de88",
   "metadata": {},
   "source": [
    "**Необходимо определить число экспериментов или максимальное значение ранга матрицы** "
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 3,
   "id": "a35792ea",
   "metadata": {},
   "outputs": [],
   "source": [
    "nMax = 100"
   ]
  },
  {
   "cell_type": "markdown",
   "id": "d57d1a25",
   "metadata": {},
   "source": [
    "**Создаем массив со значениями числа обусловленности и массив с рангами матриц, а также для значений показательных функций**"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 4,
   "id": "7b06dce6",
   "metadata": {},
   "outputs": [],
   "source": [
    "c1_n_p = []\n",
    "c2_n_p = []\n",
    "Conds = []\n",
    "n = [i for i in range(1, nMax+1)]"
   ]
  },
  {
   "cell_type": "markdown",
   "id": "342aa74b",
   "metadata": {},
   "source": [
    "**Создадим цикл для вычисления значения числа обусловленности матриц**"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 5,
   "id": "0c9cfa70",
   "metadata": {},
   "outputs": [],
   "source": [
    "for i in range(len(n)):\n",
    "    A = np.random.normal(loc=0.0, scale=1.0, size=(n[i], n[i]))\n",
    "    Conds.append(np.linalg.cond(A))"
   ]
  },
  {
   "cell_type": "markdown",
   "id": "a786eb0c",
   "metadata": {},
   "source": [
    "**Подберем аргументы показательных функций**"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 6,
   "id": "d3bc0645",
   "metadata": {},
   "outputs": [],
   "source": [
    "c1 = 0.01\n",
    "c2 = 2 \n",
    "p = 2"
   ]
  },
  {
   "cell_type": "markdown",
   "id": "f764df2c",
   "metadata": {},
   "source": [
    "**Создадим цикл для вычисления значения показательных функций**"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 7,
   "id": "705a7ac9",
   "metadata": {},
   "outputs": [],
   "source": [
    "for i in range(len(n)):\n",
    "    c1_n_p.append(c1*(n[i]**p))\n",
    "    c2_n_p.append(c2*(n[i]**p))"
   ]
  },
  {
   "cell_type": "markdown",
   "id": "f70ece3a",
   "metadata": {},
   "source": [
    "**Построим график чисел обусловленности и показательных функций** $ c_1 n^p $ , $ c_2 n^p $ "
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 8,
   "id": "61704d01",
   "metadata": {},
   "outputs": [
    {
     "data": {
      "image/png": "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\n",
      "text/plain": [
       "<Figure size 432x288 with 1 Axes>"
      ]
     },
     "metadata": {
      "needs_background": "light"
     },
     "output_type": "display_data"
    }
   ],
   "source": [
    "loglogGraph(n, Conds,'.b', 'Значение чисел обусловленности','Порядок матрицы','Число обусловленности')\n",
    "loglogGraph(n,c1_n_p,'g' ,'Значение чисел обусловленности','Порядок матрицы','Число обусловленности')\n",
    "loglogGraph(n,c2_n_p, 'r', 'Значение чисел обусловленности','Порядок матрицы','Число обусловленности')"
   ]
  },
  {
   "cell_type": "markdown",
   "id": "4395cacc",
   "metadata": {},
   "source": [
    "# Вывод:"
   ]
  },
  {
   "cell_type": "markdown",
   "id": "a56b1eba",
   "metadata": {},
   "source": [
    "В ходе работы я испытал серию случайных матриц $ A_n $. Для каждой матрицы было найдено число обусловленности и построен график зависимости порядка матрицы $ n $ от числа обусловленности $ $. Необходимо было доказать ,что для большинства матриц $$ c_1 n^p \\le \\mbox{cond}_1 A_n \\le c_2 n^p $$\n",
    "Для этого я необходимо было подобрал $ p $, $ c_1 $ , $ c_2 $ и в тех же осях нарисовал графики функций $ c_1 n^p $ , $ c_2 n^p $ , что наглядно доказывает данную зависимость\n"
   ]
  }
 ],
 "metadata": {
  "celltoolbar": "Необработанный формат ячейки",
  "kernelspec": {
   "display_name": "Python 3 (ipykernel)",
   "language": "python",
   "name": "python3"
  },
  "language_info": {
   "codemirror_mode": {
    "name": "ipython",
    "version": 3
   },
   "file_extension": ".py",
   "mimetype": "text/x-python",
   "name": "python",
   "nbconvert_exporter": "python",
   "pygments_lexer": "ipython3",
   "version": "3.9.7"
  }
 },
 "nbformat": 4,
 "nbformat_minor": 5
}
