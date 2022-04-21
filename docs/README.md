# Увод в обектно-ориентираното програмиране

## Какво е Обект в програмирането?

***Обектно-ориентираното програмиране***, или ***ООП***, е подход за разрешаване на проблеми, в който всички изчисления се изпълняват посредством обекти. ***Обектът*** е един компонент от програма, който е наясно как да извърши определени действия и как да взаимодейства с други елементи на програмата. Обектите стоят в основата на обектно-ориентираното програмиране. Пример за обект е един човек. Логично, човекът има ***име***, като това име се счита за ***свойство/качество*** на човека. Също така, човекът трябва да може да извършва ***определени действия***, като да тича, да се храни, да шофира. Тези действия се считат за ***методи*** на човека.

Организацията на кода в обектно-ориентираното програмиране се върти около употребата на обекти. Когато всички обекти са на лице, те могат да взаимодействат помежду си по такъв начин, че нещо да се случи. Да кажем, че имаме програма, където човек се качва в колата си и отива от точка А до точка Б. Започваме като опишем обектите човек и кола. Това включва и методите им: човекът знае как да шофира кола, а колата знае, че човекът ще я управлява. Когато създадете обектите си, вие навръзвате логиката им, за да може човекът да се качи в колата и да я шофира.

#

## Класове и обекти

Класът може да бъде възприет като скелетът на един обект. Класът е нищо повече от една концепция, а обектът е олицетворението на тази концепция. Преди да създадете обект, първо трябва да напишете клас за него. Нека използваме отново примера с човека. Ние искаме да опишем човека и той да може да извърши някакво действие. Един клас с името “Човек” ще предостави модел на това какво трябва един човек да върши и как трябва да изглежда. За да използвате човекът във вашата програма, трябва да създадете обект като използвате класа “Човек”. Имайки обекта, вече е възможно да опишем човека и да му добавим действия.

Класовете са доста полезни в програмирането. Какво би следвало да направим ако например искаме да имаме не един човек, а 100? Вместо да описваме всеки един от тях в отделен клас, ще използваме класа “Човек” и ще създадем 100 обекта от тип “Човек”. На всеки от тях трябва да дадем име и други качества, но базовата структура на това как изглежда човека и какви качества има е една и съща.

#
## Методи и Функции

Когато създавате обекти, искате те да могат да извършат някакво действие. Тук в картинката идват методите. Методът в обектно-ориентираното програмиране е процедура, която е свързана с някакъв клас. Методът дефинира поведението на обектите, които са създадени от този клас. Иначе казано, методът е действие, което обектът може да извършва. Връзката между метод и клас се нарича “binding”, буквално преведено като “обвързване”. Нека вземем пример с обект от тип “Човек”, създаден чрез класът Човек. Методите обвързани с този клас могат да бъдат действия като ходене, шофиране, спане, учене и т.н. Важно е да се запомни, че има разлика между метод и функция!
Функията е комбинация от инструкции, които са подредени в определен ред, за да се постигне даден резултат. Обикновено функциите изискват входни данни (аргументи) и връщат някаква стойност. Например, нека разгледаме шофирането на кола. Трябва да използваме изминатата дистанция и изразходваното гориво, за да пресметнем пробега. Можем да си напишем функция, която да извърши това пресмятане. Аргументите на функцията ще бъдат точно изминатата дистанция и използваното гориво, а резултатът ще бъде пробегът. Във всеки един момент, в който желаете да узнаете пробега, просто ще извършите извикване на функцията.
Тук обаче идва въпросът ‘Е, добре де, ама това по какво се различава от методите?’. Функциите са независими и не са асоциирани с клас. Можете да ги използвате където желаете във вашата програма и не ви е нужен обект, за да ги използвате.
Но, какво ако решим да асоциираме функцията ни с обект от тип ‘Кола’? Например, искате да покажете пробега на колата на нейното табло. В този случай, изчислението на пробега от функция ще стане метод, защото то вече е процедура, която е свързана с класа ‘Кола’. Всеки път, когато създавате нов обект от тип ‘Кола’ посредством класа ‘Кола’, методът за изчисление на пробега ще бъде част от вашите обекти. Сега действието, което колата може да извърши, е да изчисли пробега. То е същото изчисление, което би могло да се получи от извикване на функцията за пробег, но веч логиката е свързана с колата, правейки тази функция метод.
ООП Концепции
Обектно-ориентираното програмиране се уповава на няколко концепции. Тези концепции се прилагат чрез употребата на класове, обекти, методи, но също така е доста полезно да ги разгледаме малко по-обстойно. Четирите основни концепции на обектно-ориентираното програмиране са абстракция, енкапсулация, наследяване и полиморфизъм. 
****ВАЖНО!!! За контролно №1 е нужно да знаете само какво представлява енкапсулацията! За останалите три концепции не е нужно да четете, освен ако не ви е интересно!
Започваме с абстракцията. С абстракция можем да “скрием” някои детайли за обектите и да покажем само най-важната информация свързана с тях. Това намалява сложността и увеличава ефективността. Например, за един човек може да има много начини да го опишем в детайли. Обаче, ако само името му и възрастта му са ни нужни в определен контекст, само те ще се използват. 
Енкапсулацията
Енкапсулация наричаме, когато скрием вътрешни механизми на работа и структури от данни зад дефиниран интерфейс. Това не позволява да се случи злоупотреба с данните. Енкапсулацията е като защитна обвивка около нашата логика и данните ни, която предотвратява те да бъдат достъпени произволно от код извън тази обвивка. Когато говорим за енкапсулация, имаме предвид модификаторите за достъп като public и private. Нека използваме за пример кола и нейния собственик. Качествата (properties) на колата са енкапсулирани от нейния собственик. Собственикът може да кара колата си, но не може да смени нейния цвят или нейния двигател, например.
Наследяването
Наследяването е процес, който позволява нови класове да се създават от вече съществуващи такива и да наследяват техните общи характеристики. Например, можем да използваме класът Човек, за да създадем два нови класа - Жена и Мъж. Новите класове наследяват качествата на класа Човек, което ни спестява доста код. Всеки нов клас притежава както общи качества от класа Човек, така и уникални лично свои качества, но е много по-лесно да добавим тези уникални качества към вече съществуващ клас, вместо да започнем да пишем код отново от нулата. Наследяването е пример за преизползване на код, което правим ООП много ефикасно за извършване на определени задачи.
Полиморфизъм
Полиморфизъм  означава да има едно име за много различни форми на дадено нещо. Това означава, че качествата на обектите могат да се променят в зависимост от това коя форма се използва. Или по друг начин казано, обектите менят своите качества според контекста. Например, един обект от тип “Човек” може да се счита за собственик, когато кара колата си, но също и за работник, когато е на работа.

#
## Обобщение
Обектно-ориентираното програмиране, или ООП, е подход за разрешаване на проблеми, в който всички изчисления се изпълняват посредством обекти. 

Обектът е един компонент от програма, който е наясно как да извърши определени действия и как да взаимодейства с други елементи на програмата. 

Класът може да бъде възприет като скелетът на един обект. Класът е нищо повече от една концепция, а обектът е олицетворението на тази концепция. За да създадем обект, първо трябва да имаме дефиниран клас. Обектите имат качества (properties) и могат да извършват действия.

Методът е процедура свързана с даден клас и дефинира поведението на обектите, които са създадени от този клас. Функцията е комбинация от инструкции подредени по определен начин, така че да се постигне даден резултат. Функциите са независими и НЕ са свързани с класове.

Обектно-ориентираното програмиране използва набор от концепции като: абстракция, енкапсулация, наследяване и полиморфизъм. Тези концепции се прилагат на практика чрез класове, обекти и методи.

#
# Резултати след прочитането на материала
След прочитане на материала би трябвало да можете:

- Да обясните накратко как работи ООП
- Да дадете дефиниции на понятията обект, клас, метод
- Да може да обясните разликата между метод и функция
- Да сте наясно с 4-те концепции на ООП

***ВАЖНО! За контролно №1 е важно да сте наясно и да можете да обясните само концепцията на енкапсулацията!!!***
