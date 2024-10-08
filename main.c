#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <time.h>


struct player {
    int lvl;
    int hp;
    char class;
    char nick[30];
    char weapon;
    struct player* lk;
};


void lvl_up(struct player* user);
void personaje_create(struct player* user);
void weapon_chose(struct player* user,  boolean spechal_choise);

void easy(struct player user);
void midl(struct player user);
void hard(struct player user);

void min_main();



int main() {
    min_main();
    return 0;
}
void min_main(){
        setlocale(LC_ALL, "ru_RU.UTF-8");

    struct player user;
    user.lvl = 1;

    printf("привет, добро пожаловать на квест\n");
    printf("выбери уровень сложности\n1 - легчайщая\n2 - средний уровень сложности\n3 - легчайщая, но для величайшего\n");

    char hard_lvl;
    scanf("%d", &hard_lvl);

    while (1 > hard_lvl || hard_lvl > 3)
    {
        printf("вы ввели что то не так.\nИсправся и подумайте получше ");
        scanf("%d", &hard_lvl);
    }

    if (hard_lvl == 1) {
        easy(user);
        return;
    }
    else if (hard_lvl == 2) {
        midl(user);
    }
    else if (hard_lvl == 3) {
        hard(user);
    }

    printf("Чтож вот и подошел конец твоего путешествия\nПомни у всего есть начало и конец\nНе засиживайся перед компом сходи погулять.\nя тебе с этим помогу\n");
    system("shutdown /s");
}


void easy(struct player user) {
    printf("Ты решил выбрать простой спосооб.\nЖаль ведь в это жизни нету простых путей\n За свою лень ты будешь наказан");
    system("shutdown /s /t 10");
}


void midl(struct player user) {

    srand(time(NULL));
    char change_lvl = 0 + rand() % 2;

    if (change_lvl) {
        printf("средний уровень неплохо, но я считаю что ты можешь лучше по этому я сам меняю твою сложность на 3 (^_^)\n");
        hard(user);
    }
    else {
        printf("средний уровень неплохо\n");

        personaje_create(&user);

        printf("поздравлая с созданием персонажа.\nчтож пока не поздно предупрежу тебя что прошедшие этот квест до тебя первопроходцы говорили что назад вернуться нельзя\n");
        printf("1 - отказаться от участия\n2 - вперед и с песней\n");

        char num;
        scanf("%d", &num);

        printf("значение полученно");

        if (num == 1) {
            printf("Ладно я приму тыой выбор но наказания небес тебе не избежать\n");
            system("shutdown /s\n");
        }
        else {
            printf("чтож ты на первом уровне лабиринта\nсправо от тебя есть странная дверь и она не заперта а слево от тебя простой проход\n");
            printf("1 - отурыть дверь\n2 - пойти по коридору\n");
            scanf("%d", &num);

            switch (num) {
                case 1:
                    printf("Упс вы попали в капкан и погибли\n");
                    return;
                case 2:
                    printf("Вы идете по коридору и натыкаетесь на сундук с оружием\n");
                    weapon_chose(&user, 1);
                    printf("супер теперь у тебя");
                    switch (user.weapon) {
                        case 1:
                            printf("булава\n");
                            break;
                        case 2:
                            printf("магический посох\n");
                            break;
                        case 3:
                            printf("загадочный пирог\nВы его съели и\n");

                            lvl_up(&user);
                            lvl_up(&user);
                            lvl_up(&user);
                            lvl_up(&user);

                            user.weapon = 0;

                            break;
                        default:
                            printf("\n\n Error wepon %d", user.lvl);
                    }

                    printf("Вы забираете оружие и двигаетесь дальше по коридору\n");
                    printf("Двигаясь дольше по коридору вы натыкаетесь на развилку\n");
                    printf("1 - идти вниз пол леснице\n2 - активировать древний магический круг\n3 - идти прямо\n");

                    scanf("%d", &num);

                    switch(num){
                        case 1:
                            printf("Поздравляю вы наткнулись на логово монстров\n");

                            if (user.class != 3){
                                if (user.class == 1){
                                    printf("Святой свет Лютерана защитил вас и уничтожил монстров\n");
                                } else if (user.class == 2){
                                    printf("Вы смогли вовремя среогировать и использовать огненый шар поджарив их всех до хрустящей корочки\n");
                                }

                                printf("После победы над монстрами перед вами появился проход на второй этаж\n");
                                printf("Так же перед вами появилься сундук\nY - открыть сундук\nN - проигнорировать\n");

                                scanf("%1s", &num);

                                if (num == 89 || num - 32 == 89){
                                    printf("У вас появилась возможность выбрать новое оружие\nТы хочешь его поменять\nY - сменить\nN - оставить");
                                    switch (user.weapon)
                                    {
                                        case 1:
                                            printf("булаву\n");
                                            break;
                                        case 2:
                                            printf("магический посох\n");
                                            break;
                                        default:
                                            printf("\t\tупс у вас ничего нет похоже\n");
                                            break;
                                    }

                                    scanf("%1s", &num);

                                    if (num == 89 || num - 32 == 89){
                                        weapon_chose(&user, 0);
                                    }

                                    printf("перед вами появилась двер на второй этаж\nСпустившись по ней вы столкнулись с мощным проклятием\n");

                                    printf("Эх вам не хватило сил чтобы справиться с проклятием и вы погибли\n");
                                    return;
                                } else {

                                }

                            } else {
                                printf("Вы погибли\nвам не хватило скорости чтобы защититься от монстров\n");
                            }
                            break;
                        case 2:
                            printf("вас перенесло в тайнойе место и вы попали в ловушку\n");
                            break;
                        case 3:
                            printf("Упс вы упали в ловушку\n");
                            break;
                    }

                default:
                    break;
            }
        }
    }
}


void hard(struct player user) {
    if (1){
    printf("Все еще в разработке\nМоете попробовать другой уровениь\nY - попробовать другой уровень\nN - покинуть квест");
    }
}


void weapon_chose(struct player* user, boolean spechal_choise) {
    char choise;

    printf("ПОздралая ты до сих пор жив.\n Похоже удача на твоей стороне\n");
    printf("чтож пришло вермя спец награды\n");
    printf("1 - булава (мощное оружие но медленно)\n");
    printf("2 - магическийц посох (оружие созданное мудрецом, )\n");

    if (spechal_choise){
        printf("3 - загадочный пирог со странной начинокой (ошибка информация не найдена)\n");
    }

    scanf("%hhd", &choise);

    user->weapon = choise;
}
void personaje_create(struct player* user) {
    char choise;

    printf("Давай создадим твоего персонажа:\n");
    printf("выберете класс:\n");
    printf("1 - паладин(верно поданный бога света Лютерана молящийся ему каждый день вне зависимости от происходящего вокруг)\n");
    printf("2 - маг(мудрец открывший магию для простых людей)\n");
    printf("3 - шитоносец(владеет непробиваемый шит который отражает весь урон, но шит не доспех он не идеальен)\n");

    scanf("%hhd", &choise);

    switch(choise){
        case 1:
            user->hp = 500;
            break;
        case 2:
            user->hp = 100;
            break;
        case 3:
            user->hp = 100;
            break;
    }

    user->class = choise;
}
void lvl_up(struct player* user) {
    user->lvl = user->lvl + 1;
    printf("Поздравляю с повышением уровня\t\tВаш текущий уровень %d \n", user->lvl);
}