## Опис процесу переходу між системами координат
### Полярні до декартових координат:

1. $x=r⋅cos⁡(\theta)$ : Якщо точку в полярних координатах з радіусом $r$ і кутом $\theta$ проєктувати на горизонтальну вісь, ми отримуємо її декартову координату $x$.

2. $y = r \cdot \sin(\theta)$ : Так само, вертикальна проєкція точки на декартову систему координат дорівнює $r$ множеному на синус кута.

### Декартові до полярних координат:

1. $r = \sqrt{x^2 + y^2}$ : Визначити радіус $r$ потрібно за теоремою Піфагора де $r$ є гіпотенузою, а $x$ і $y$ - це катети.

2. $\theta = \arctan\left(\frac{y}{x}\right)$: Кут $\theta$ можна знайти, взявши арктангенс відношення $y$ до $x$. 

### Від Декартової до Сферичної

1. **Радіус-вектора**: $r = \sqrt{x^2 + y^2 + z^2}$ визначається через теорему Піфагора в трьохвимірному просторі.

2. **Полярний кут** $\theta$ (кут від осі Z): $\theta = \arccos\left(\frac{z}{r}\right)$. Це відношення вектора проєкції на вісь $z$ до довжини вектора $r$ вказує, як сильно вектор нахилений відносно осі Z.

3. **Азимутальний кут** $\phi$ (кут від осі X у площині XY): $\phi = \arctan\left(\frac{y}{x}\right)$. Азимутальний кут визначає положення вектора в площині XY.

### Від Сферичної до Декартової

1. **Координата** $x$: $x = r \cdot \sin(\theta) \cdot \cos(\phi)$. Визначається через множення радіуса на синус полярного кута і косинус азимутального кута.

2. **Координата** $y$: $y = r \cdot \sin(\theta) \cdot \sin(\phi)$. Аналогічно координаті $x$, але з синусом азимутального кута.

3. **Координата** $z$: $z = r \cdot \cos(\theta)$. Множення радіуса на косинус полярного кута, що дає проєкцію на вісь $z$.

## Результати перевірки

Перевірка результатів перетворень здійснювалася за допомогою функції isEqual.
Функція isEqual перевіряє, чи рівні два об'єкти з урахуванням невеликої похибки.

```c++
bool Cartesian::isEqual(const Cartesian& other) const {
    return (fabs(x - other.x) < 1e-6) && (fabs(y - other.y) < 1e-6) && (fabs(z - other.z) < 1e-6);
}

bool Polar::isEqual(const Polar& other) const {
    return (fabs(r - other.r) < 1e-6) && (fabs(theta - other.theta) < 1e-6);
}

bool Spherical::isEqual(const Spherical& other) const {
    return (fabs(r - other.r) < 1e-6) && (fabs(theta - other.theta) < 1e-6) && (fabs(phi - other.phi) < 1e-6);
}
```

Результат перевірки:
 ![[t1_results.jpg]]

## Результати бенчмаркінгу

<center> <b>Таблиця результатів виконання програми </b></center>

| декартова система координат 2D | декартова система координат 3D | полярна система координат | через об'єм сфери | велика колова відстань |
| :----------------------------: | :----------------------------: | :-----------------------: | :---------------: | :--------------------: |
|           0,0055084            |           0,0071504            |         0,0046803         |     0,0058225     |       0,0056887        |
|           0,0054330            |           0,0070955            |         0,0046254         |     0,0072655     |       0,0057034        |
|           0,0064390            |           0,0070540            |         0,0046034         |     0,0071134     |       0,0068481        |
|           0,0054405            |           0,0071219            |         0,0046196         |     0,0074871     |       0,0052953        |
|           0,0054189            |           0,0071237            |         0,0046655         |     0,0071759     |       0,0053204        |

<center> <b>Діаграма середніх значень часу роботи (в секундах) </b></center>
![[t3_diagram.jpg]]

## Висновки

Ефективність вибору системи координат залежить від конкретної задачі:
- **Декартова система** підходить для прямолінійних рухів та при невеликих відстанях.
- **Полярна система** ефективна для задач, що стосуються кутових рухів коли об'єкт розташований навколо фіксованої точки.
- **Сферична система**— підходить для тривимірних об'єктів, що мають сферичну симетрію, таких як планети. Ефективно використовувати при великих відстанях.